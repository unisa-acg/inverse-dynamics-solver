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

// ROS
#include <rclcpp/parameter.hpp>

// KDL
#include <kdl/solveri.hpp>
#include <kdl_parser/kdl_parser.hpp>

// Inverse Dynamics Solver
#include <inverse_dynamics_solver/exceptions.hpp>
#include "kdl_inverse_dynamics_solver/kdl_inverse_dynamics_solver.hpp"

namespace kdl_inverse_dynamics_solver
{
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
  solver_ = std::make_unique<KDL::ChainDynParam>(chain_, KDL::Vector(gravity[0], gravity[1], gravity[2]));
  jacobian_solver_ = std::make_unique<KDL::ChainJntToJacSolver>(chain_);

  // Track plugin initialization
  initialized_ = true;

  // Allocate kinematic/dynamic variables once for real-time safeness
  kdl_joint_positions_ = std::make_unique<KDL::JntArray>(number_of_joints_);
  kdl_joint_velocities_ = std::make_unique<KDL::JntArray>(number_of_joints_);
  jacobian_ = std::make_unique<KDL::Jacobian>(number_of_joints_);
  M_ = std::make_unique<KDL::JntSpaceInertiaMatrix>(number_of_joints_);
  c_ = std::make_unique<KDL::JntArray>(number_of_joints_);
  g_ = std::make_unique<KDL::JntArray>(number_of_joints_);
  zero_ = Eigen::VectorXd::Zero(number_of_joints_);
}

Eigen::MatrixXd InverseDynamicsSolverKDL::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();

  kdl_joint_positions_->data = joint_positions;

  solver_->JntToMass(*kdl_joint_positions_, *M_);

  return M_->data;
}

Eigen::VectorXd InverseDynamicsSolverKDL::getCoriolisVector(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities) const
{
  verifyInitialization_();

  kdl_joint_positions_->data = joint_positions;
  kdl_joint_velocities_->data = joint_velocities;

  solver_->JntToCoriolis(*kdl_joint_positions_, *kdl_joint_velocities_, *c_);

  return c_->data;
}

Eigen::VectorXd InverseDynamicsSolverKDL::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();

  kdl_joint_positions_->data = joint_positions;

  solver_->JntToGravity(*kdl_joint_positions_, *g_);

  return g_->data;
}

Eigen::VectorXd InverseDynamicsSolverKDL::getFrictionVector(const Eigen::VectorXd&) const
{
  // KDL joint model does not include friction, thus it is not able to compute the torque vector
  // associated with joint frictions. In the future, this function could be implemented by
  // reading the friction coefficients present in the URDF.
  verifyInitialization_();
  return zero_;
}

Eigen::MatrixXd InverseDynamicsSolverKDL::getJacobian(const Eigen::VectorXd& joint_positions) const
{
  verifyInitialization_();

  kdl_joint_positions_->data = joint_positions;

  // JntToJac returns E_NOERROR when no error occurs: https://docs.ros.org/en/indigo/api/orocos_kdl/html/chainjnttojacsolver_8cpp_source.html#l00048
  if (jacobian_solver_->JntToJac(*kdl_joint_positions_, *jacobian_) == KDL::SolverI::E_NOERROR)
  {
    return jacobian_->data;
  }
  else
  {
    throw std::runtime_error("Failed to compute Jacobian.");
  }
}

void InverseDynamicsSolverKDL::verifyInitialization_() const
{
  if (!initialized_)
  {
    throw inverse_dynamics_solver::UninitializedException();
  }
}
}  // namespace kdl_inverse_dynamics_solver

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(kdl_inverse_dynamics_solver::InverseDynamicsSolverKDL, inverse_dynamics_solver::InverseDynamicsSolver)
