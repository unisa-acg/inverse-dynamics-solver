/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   inverse_dynamics_interface_pinocchio.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Oct 10, 2025
 *
 * Refer to the header file for a description of this module.
 *
 * -------------------------------------------------------------------
 */

// ROS
#include <rclcpp/parameter.hpp>

// URDF
#include <urdf_parser/urdf_parser.h>

// Pinocchio
#include <pinocchio/algorithm/crba.hpp>            // Composite Rigid Body Algorithm
#include <pinocchio/algorithm/frames.hpp>          // Needed for pinocchio::{getFrameJacobian, updateFramePlacements}
#include <pinocchio/algorithm/jacobian.hpp>        // Needed for pinocchio::computeJointJacobians
#include <pinocchio/algorithm/kinematics.hpp>      // Needed for pinocchio::forwardKinematics
#include <pinocchio/algorithm/rnea.hpp>            // Recursive Newton-Euler Algorithm
#include <pinocchio/container/aligned-vector.hpp>  // Needed for pinocchio::container::aligned_vector
#include <pinocchio/multibody/fwd.hpp>             // Needed for pinocchio::FrameIndex
#include <pinocchio/parsers/urdf.hpp>              // Needed for pinocchio::urdf::buildModelFromXML
#include <pinocchio/spatial/fwd.hpp>               // Needed for pinocchio::{Force, SE3}

// Inverse Dynamics Solver
#include <inverse_dynamics_interface/exceptions.hpp>
#include "inverse_dynamics_interface_pinocchio/inverse_dynamics_interface_pinocchio.hpp"

namespace inverse_dynamics_interface_pinocchio
{
void InverseDynamicsInterfacePinocchio::initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr parameters_interface,
                                                   const std::string& param_namespace, const std::string& robot_description)
{
  // Get parameters
  std::string ns = !param_namespace.empty() ? param_namespace + "." : "";

  // Get robot description
  std::string robot_description_local;
  if (robot_description.empty())
  {
    // If the robot_description input argument is empty, try to get the
    // robot_description from the node's parameters.
    rclcpp::Parameter robot_description_param = rclcpp::Parameter();
    if (!parameters_interface->get_parameter("robot_description", robot_description_param))
    {
      throw inverse_dynamics_interface::ParameterUninitializedException(
          "Parameter 'robot_description' not set in inverse_dynamics_interface_pinocchio.");
    }
    robot_description_local = robot_description_param.as_string();
  }
  else
  {
    robot_description_local = robot_description;
  }

  // Get tip name
  rclcpp::Parameter tip_param = rclcpp::Parameter();
  bool tip_found = parameters_interface->has_parameter(ns + "tip");
  if (tip_found)
  {
    parameters_interface->get_parameter(ns + "tip", tip_param);
    tip_ = tip_param.as_string();
    tip_found = !tip_.empty();
  }
  if (!tip_found)
  {
    throw inverse_dynamics_interface::ParameterUninitializedException("Failed to find parameter 'tip'.");
  }

  // Get gravity vector
  rclcpp::Parameter gravity_param = rclcpp::Parameter();
  std::vector<double> gravity(3);
  if (parameters_interface->has_parameter(ns + "gravity"))
  {
    parameters_interface->get_parameter(ns + "gravity", gravity_param);
    gravity = gravity_param.as_double_array();
    if (gravity.size() != 3)
    {
      throw inverse_dynamics_interface::InvalidParameterValueException("Gravity vector must have 3 elements, " + std::to_string(gravity.size()) +
                                                                       " given.");
    }
  }
  else
  {
    gravity = std::vector<double>({ 0, 0, -9.81 });
  }

  // Instantiate the solver
  pinocchio::urdf::buildModelFromXML(robot_description_local, model_);
  data_ = std::make_unique<pinocchio::Data>(model_);
  model_.gravity.linear() = Eigen::Map<const Eigen::Vector3d>(gravity.data());
  number_of_joints_ = model_.nq;

  // Check if tip is included in the model
  if (!model_.existFrame(tip_))
  {
    throw inverse_dynamics_interface::InvalidParameterValueException("Tip frame '" + tip_ + "' not found in robot description.");
  }

  // Allocate kinematic/dynamic variables once for real-time safeness
  jacobian_ = pinocchio::Data::Matrix6x(6, model_.nv);
  zero_ = Eigen::VectorXd::Zero(number_of_joints_);

  // Get friction
  friction_ = Eigen::VectorXd::Zero(number_of_joints_);
  damping_ = Eigen::VectorXd::Zero(number_of_joints_);
  parseFrictionFromURDF_(robot_description_local);

  // Track plugin initialization
  initialized_ = true;
}

Eigen::MatrixXd InverseDynamicsInterfacePinocchio::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();

  // Compute the upper triangular part
  pinocchio::crba(model_, *data_, joint_positions);

  // Compute the whole symmetric matrix
  data_->M.triangularView<Eigen::StrictlyLower>() = data_->M.transpose().triangularView<Eigen::StrictlyLower>();
  return data_->M;
}

Eigen::VectorXd InverseDynamicsInterfacePinocchio::getCoriolisVector(const Eigen::VectorXd& joint_positions,
                                                                     const Eigen::VectorXd& joint_velocities) const
{
  verifyInitialization_();
  pinocchio::computeCoriolisMatrix(model_, *data_, joint_positions, joint_velocities);
  return data_->C * joint_velocities;
}

Eigen::VectorXd InverseDynamicsInterfacePinocchio::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();
  pinocchio::computeGeneralizedGravity(model_, *data_, joint_positions);
  return data_->g;
}

Eigen::VectorXd InverseDynamicsInterfacePinocchio::getFrictionVector(const Eigen::VectorXd& joint_velocities) const
{
  verifyInitialization_();
  return friction_.cwiseProduct(joint_velocities.cwiseSign()) + damping_.cwiseProduct(joint_velocities);
}

Eigen::MatrixXd InverseDynamicsInterfacePinocchio::getJacobian(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();
  pinocchio::computeJointJacobians(model_, *data_, joint_positions);
  pinocchio::getFrameJacobian(model_, *data_, model_.getFrameId(tip_), pinocchio::LOCAL_WORLD_ALIGNED, jacobian_);
  return jacobian_;
}

Eigen::VectorXd InverseDynamicsInterfacePinocchio::getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                                                              const Eigen::VectorXd& joint_accelerations,
                                                              const Eigen::Matrix<double, 6, 1>& external_wrench) const
{
  verifyInitialization_();
  return pinocchio::rnea(model_, *data_, joint_positions, joint_velocities, joint_accelerations) +
         (external_wrench.isZero() ? zero_ : getExternalTorques(joint_positions, external_wrench));
}

void InverseDynamicsInterfacePinocchio::verifyInitialization_() const
{
  if (!initialized_)
  {
    throw inverse_dynamics_interface::UninitializedException();
  }
}

void InverseDynamicsInterfacePinocchio::parseFrictionFromURDF_(const std::string& robot_description)
{
  urdf::ModelInterfaceSharedPtr urdf_model = urdf::parseURDF(robot_description);
  if (!urdf_model)
  {
    throw inverse_dynamics_interface::InvalidParameterValueException("Failed to parse URDF string.");
  }

  std::size_t j = 0;
  for (const std::string& joint_name : model_.names)
  {
    if (urdf_model->joints_.find(joint_name) != urdf_model->joints_.end())
    {
      urdf::JointSharedPtr urdf_joint = urdf_model->joints_.at(joint_name);
      if (urdf_joint->dynamics)
      {
        friction_(j) = urdf_joint->dynamics->friction;  // coulomb friction
        damping_(j) = urdf_joint->dynamics->damping;    // viscous friction
      }
      ++j;
    }
  }
}
}  // namespace inverse_dynamics_interface_pinocchio

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(inverse_dynamics_interface_pinocchio::InverseDynamicsInterfacePinocchio, inverse_dynamics_interface::InverseDynamicsInterface)
