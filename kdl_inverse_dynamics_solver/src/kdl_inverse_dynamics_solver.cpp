/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   kdl_inverse_dynamics_solver.cpp
 * Author:  Enrico Ferrentino, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Dec 3, 2019
 *
 * Refer to the header file for a description of this module.
 *
 * -------------------------------------------------------------------
 */

// URDF
#include <urdf/model.hpp>

// KDL
#include <kdl/segment.hpp>
#include <kdl_parser/kdl_parser.hpp>

// Inverse Dynamics Solver
#include <inverse_dynamics_solver/exceptions.hpp>
#include "kdl_inverse_dynamics_solver/kdl_inverse_dynamics_solver.hpp"

using namespace kdl_inverse_dynamics_solver;

void InverseDynamicsSolverKDL::initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr parameters_interface,
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
      throw inverse_dynamics_solver::ParameterUninitializedException("Parameter 'robot_description' not set in kdl_inverse_dynamics_solver.");
    }
    robot_description_local = robot_description_param.as_string();
  }
  else
  {
    robot_description_local = robot_description;
  }

  // Build kinematic tree
  KDL::Tree robot_tree;
  if (!kdl_parser::treeFromString(robot_description_local, robot_tree))
  {
    throw inverse_dynamics_solver::InvalidParameterValueException("The KDL parser cannot parse the URDF loaded in 'robot_description'.");
  }

  // Get root name
  rclcpp::Parameter root_param = rclcpp::Parameter();
  std::string root;
  if (parameters_interface->has_parameter(ns + "root"))
  {
    parameters_interface->get_parameter(ns + "root", root_param);
    root = root_param.as_string();
  }
  else
  {
    root = robot_tree.getRootSegment()->first;
  }

  // Get tip name
  rclcpp::Parameter tip_param = rclcpp::Parameter();
  std::string tip;
  if (parameters_interface->has_parameter(ns + "tip"))
  {
    parameters_interface->get_parameter(ns + "tip", tip_param);
    tip = tip_param.as_string();
  }
  else
  {
    throw inverse_dynamics_solver::ParameterUninitializedException("Failed to find parameter 'tip'.");
  }

  // Get kinematic chain
  if (!robot_tree.getChain(root, tip, chain_))
  {
    throw inverse_dynamics_solver::InvalidParameterValueException("Failed to find chain from robot root " + root + " to end-effector " + tip + ".");
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
  number_of_joints_ = chain_.getNrOfJoints();
  solver_ = std::make_shared<KDL::ChainDynParam>(chain_, KDL::Vector(gravity[0], gravity[1], gravity[2]));
  parseFrictionFromURDF_(robot_description_local);

  // Track plugin initialization
  initialized_ = true;
}

Eigen::MatrixXd InverseDynamicsSolverKDL::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();

  KDL::JntArray kdl_joint_positions(number_of_joints_);
  KDL::JntSpaceInertiaMatrix H(number_of_joints_);

  kdl_joint_positions.data = joint_positions;

  solver_->JntToMass(kdl_joint_positions, H);

  return H.data;
}

Eigen::VectorXd InverseDynamicsSolverKDL::getCoriolisVector(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities) const
{
  verifyInitialization_();

  KDL::JntArray kdl_joint_positions(number_of_joints_);
  KDL::JntArray kdl_joint_velocities(number_of_joints_);
  KDL::JntArray C(number_of_joints_);

  kdl_joint_positions.data = joint_positions;
  kdl_joint_velocities.data = joint_velocities;

  solver_->JntToCoriolis(kdl_joint_positions, kdl_joint_velocities, C);

  return C.data;
}

Eigen::VectorXd InverseDynamicsSolverKDL::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();

  KDL::JntArray kdl_joint_positions(number_of_joints_);
  KDL::JntArray g(number_of_joints_);

  kdl_joint_positions.data = joint_positions;

  solver_->JntToGravity(kdl_joint_positions, g);

  return g.data;
}

Eigen::VectorXd InverseDynamicsSolverKDL::getFrictionVector(const Eigen::VectorXd& joint_velocities) const
{
  verifyInitialization_();
  return static_friction_.cwiseProduct(joint_velocities.cwiseSign()) + viscous_friction_.cwiseProduct(joint_velocities);
}

void InverseDynamicsSolverKDL::verifyInitialization_() const
{
  if (!initialized_)
  {
    throw inverse_dynamics_solver::UninitializedException();
  }
}

void InverseDynamicsSolverKDL::parseFrictionFromURDF_(const std::string& robot_description)
{
  // Parse the URDF again to extract joint friction coefficients
  urdf::Model urdf_model;
  if (!urdf_model.initString(robot_description))
  {
    throw inverse_dynamics_solver::InvalidParameterValueException(
        "Failed to parse URDF string.");
  }

  static_friction_.resize(number_of_joints_);
  viscous_friction_.resize(number_of_joints_);

  for (unsigned int i = 0; i < chain_.getNrOfSegments(); ++i)
  {
    const KDL::Segment seg = chain_.getSegment(i);
    const std::string joint_name = seg.getJoint().getName();

    if (urdf_model.joints_.find(joint_name) != urdf_model.joints_.end())
    {
      urdf::JointSharedPtr joint = urdf_model.joints_.at(joint_name);
      if (joint->dynamics)
      {
        if (joint->dynamics->friction)
        {
          static_friction_(i) = joint->dynamics->friction;  // coulomb/static friction
        }
        if (joint->dynamics->damping)
        {
          viscous_friction_(i) = joint->dynamics->damping; // viscous friction
        }
      }
    }
  }
}

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(kdl_inverse_dynamics_solver::InverseDynamicsSolverKDL, inverse_dynamics_solver::InverseDynamicsSolver)
