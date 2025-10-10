/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   pinocchio_inverse_dynamics_solver.cpp
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
#include <rclcpp/logging.hpp>
#include <rclcpp/logger.hpp>

// Pinocchio
#include <pinocchio/parsers/urdf.hpp>      // Needed for pinocchio::urdf::buildModelFromXML
#include <pinocchio/algorithm/crba.hpp>    // Composite Rigid Body Algorithm
#include <pinocchio/algorithm/rnea.hpp>    // Recursive Newton-Euler Algorithm
#include <pinocchio/algorithm/frames.hpp>  // Needed for pinocchio::{computeFrameJacobian, updateFramePlacements}
#include <pinocchio/multibody/fwd.hpp>     // Needed for pinocchio::{WORLD, FrameIndex, Frame, JointIndex}
#include <pinocchio/spatial/fwd.hpp>       // Needed for pinocchio::{Force, SE3}
#include <pinocchio/container/aligned-vector.hpp>
#include <pinocchio/algorithm/kinematics.hpp>  // Needed for pinocchio::forwardKinematics

// Inverse Dynamics Solver
#include <inverse_dynamics_solver/exceptions.hpp>
#include "pinocchio_inverse_dynamics_solver/pinocchio_inverse_dynamics_solver.hpp"

using namespace pinocchio_inverse_dynamics_solver;

void InverseDynamicsSolverPinocchio::initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr parameters_interface,
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
      throw inverse_dynamics_solver::ParameterUninitializedException("Parameter 'robot_description' not set in pinocchio_inverse_dynamics_solver.");
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
    throw inverse_dynamics_solver::ParameterUninitializedException("Failed to find parameter 'tip'.");
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
      throw inverse_dynamics_solver::InvalidParameterValueException("Gravity vector must have 3 elements, " + std::to_string(gravity.size()) +
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
  model_.gravity.linear() = Eigen::Vector3d(gravity.data());
  number_of_joints_ = model_.nq;

  // Check if tip is included in the model
  if (!model_.existFrame(tip_))
  {
    throw inverse_dynamics_solver::InvalidParameterValueException("Tip frame '" + tip_ + "' not found in robot description.");
  }

  // Track plugin initialization
  initialized_ = true;
}

Eigen::MatrixXd InverseDynamicsSolverPinocchio::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();

  // Compute the upper triangular part
  pinocchio::crba(model_, *data_, joint_positions);

  // Compute the whole symmetric matrix
  data_->M.triangularView<Eigen::StrictlyLower>() = data_->M.transpose().triangularView<Eigen::StrictlyLower>();
  return data_->M;
}

Eigen::VectorXd InverseDynamicsSolverPinocchio::getCoriolisVector(const Eigen::VectorXd& joint_positions,
                                                                  const Eigen::VectorXd& joint_velocities) const
{
  verifyInitialization_();
  pinocchio::computeCoriolisMatrix(model_, *data_, joint_positions, joint_velocities);
  return data_->C * joint_velocities;
}

Eigen::VectorXd InverseDynamicsSolverPinocchio::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();
  pinocchio::computeGeneralizedGravity(model_, *data_, joint_positions);
  return data_->g;
}

Eigen::VectorXd InverseDynamicsSolverPinocchio::getFrictionVector(const Eigen::VectorXd&) const
{
  // Pinocchio joint model does not include friction, thus it is not able to compute the torque vector
  // associated with joint frictions. In the future, this function could be implemented by
  // reading the friction coefficients present in the URDF.
  verifyInitialization_();
  return Eigen::VectorXd::Zero(number_of_joints_);
}

Eigen::VectorXd InverseDynamicsSolverPinocchio::getExternalTorques(const Eigen::VectorXd& joint_positions,
                                                                   const Eigen::Matrix<double, 6, 1>& external_wrench) const
{
  Eigen::VectorXd zero = Eigen::VectorXd::Zero(number_of_joints_);
  return getTorques(joint_positions, zero, zero, external_wrench) - getGravityVector(joint_positions);
}

Eigen::VectorXd InverseDynamicsSolverPinocchio::getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                                                           const Eigen::VectorXd& joint_accelerations,
                                                           const Eigen::Matrix<double, 6, 1>& external_wrench) const
{
  verifyInitialization_();

  // Update frame placements according to FK to get the correct position of the EE frame
  pinocchio::forwardKinematics(model_, *data_, joint_positions, joint_velocities, joint_accelerations);
  pinocchio::updateFramePlacements(model_, *data_);

  // Get the last joint
  const pinocchio::FrameIndex ee_frame_id = model_.getFrameId(tip_);

  // Build the wrench in world frame
  pinocchio::Force f_ee_world(external_wrench.head(3), external_wrench.tail(3));

  // M is the homogenous transform matrix: "oMf" stands for "transform from frame 'f' to origin (world)"
  const pinocchio::SE3 frame_to_world = data_->oMf[ee_frame_id];

  // Convert the force from the world frame to the last frame
  pinocchio::Force f_frame_local = frame_to_world.actInv(f_ee_world);

  // Pinocchio assumes a Force can be applied to possibly every joint: we set a force on the last joint only
  pinocchio::container::aligned_vector<pinocchio::Force> fext(model_.njoints, pinocchio::Force::Zero());
  fext[ee_frame_id] = f_frame_local;
  RCLCPP_INFO_STREAM(rclcpp::get_logger("ids"), "Local forces on frame " << ee_frame_id << ": " << fext[ee_frame_id].toVector().transpose());

  // Get all the forces
  return pinocchio::rnea(model_, *data_, joint_positions, joint_velocities, joint_accelerations, fext);
}

void InverseDynamicsSolverPinocchio::verifyInitialization_() const
{
  if (!initialized_)
  {
    throw inverse_dynamics_solver::UninitializedException();
  }
}

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(pinocchio_inverse_dynamics_solver::InverseDynamicsSolverPinocchio, inverse_dynamics_solver::InverseDynamicsSolver)
