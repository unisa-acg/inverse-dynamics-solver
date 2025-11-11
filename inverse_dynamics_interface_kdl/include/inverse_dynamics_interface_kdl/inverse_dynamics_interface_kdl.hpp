/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   inverse_dynamics_interface_kdl.hpp
 * Author:  Enrico Ferrentino, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Dec 3, 2019
 *
 * This is an implementation of InverseDynamicsInterface using the
 * general-purpose, robot-agnostic KDL library.
 *
 * -------------------------------------------------------------------
 */

#pragma once

// Standard libraries
#include <string>

// Eigen
#include <eigen3/Eigen/Core>

// ROS
#include <rclcpp/node_interfaces/node_parameters_interface.hpp>

// KDL
#include <kdl/chain.hpp>
#include <kdl/chaindynparam.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/jacobian.hpp>
#include <kdl/jntspaceinertiamatrix.hpp>

// Inverse Dynamics Interface
#include <inverse_dynamics_interface/inverse_dynamics_interface.hpp>

namespace inverse_dynamics_interface_kdl
{

class InverseDynamicsInterfaceKDL : public inverse_dynamics_interface::InverseDynamicsInterface
{
public:
  InverseDynamicsInterfaceKDL() {}

  /**
   * @brief Refer to the superclass documentation
   *
   * This method must be called before any other.
   *
   * @throw ParameterUninitializedException if the required parameters are not found in \e parameters_interface
   * @throw InvalidParameterValueException if the parameters are not valid, i.e. \e robot_description is malformed, the kinematic chain's root and tip
   * are not correctly configured, or the gravity vector is not coherent
   */
  void initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr parameters_interface, const std::string& param_namespace = "",
                  const std::string& robot_description = "") override;

  /**
   * @brief Refer to the superclass documentation
   */
  Eigen::MatrixXd getInertiaMatrix(const Eigen::VectorXd& joint_positions) const override;

  /**
   * @brief Refer to the superclass documentation
   */
  Eigen::VectorXd getCoriolisVector(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities) const override;

  /**
   * @brief Refer to the superclass documentation
   */
  Eigen::VectorXd getGravityVector(const Eigen::VectorXd& joint_positions) const override;

  /**
   * @brief Refer to the superclass documentation
   */
  Eigen::VectorXd getFrictionVector(const Eigen::VectorXd&) const override;

  /**
   * @brief Refer to the superclass documentation
   * @throw std::runtime_error if the KDL interface fails to compute Jacobian
   */
  Eigen::MatrixXd getJacobian(const Eigen::VectorXd& joint_positions) const override;

  /**
   * @brief Refer to the superclass documentation
   */
  Eigen::VectorXd getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                             const Eigen::VectorXd& joint_accelerations,
                             const Eigen::Matrix<double, 6, 1>& external_wrench = Eigen::VectorXd::Zero(6)) const override;

private:
  /**
   * @brief Verify that the interface has been correctly initialized
   * @throw UninitializedException if the interface is not initialized
   */
  void verifyInitialization_() const;

  /**
   * @brief Parse robot description from URDF and retrieves friction parameters
   * @throw InvalidParameterValueException if the robot description parsing fails
   */
  void parseFrictionFromURDF_(const std::string& robot_description);

  bool initialized_ = false;
  unsigned int number_of_joints_;
  KDL::Chain chain_;
  std::unique_ptr<KDL::ChainDynParam> dynamics_;
  std::unique_ptr<KDL::ChainJntToJacSolver> jacobian_solver_;

  // Kinematic/dynamic variables are allocated in the `initialize` method for real-time safeness; they are declared with smart pointers because all
  // the methods in this class are `const`, and this would not allow changing their values if they were not declared with pointers
  std::unique_ptr<KDL::JntArray> kdl_joint_positions_;
  std::unique_ptr<KDL::JntArray> kdl_joint_velocities_;
  std::unique_ptr<KDL::Jacobian> jacobian_;
  std::unique_ptr<KDL::JntSpaceInertiaMatrix> M_;
  std::unique_ptr<KDL::JntArray> c_;
  std::unique_ptr<KDL::JntArray> g_;
  Eigen::VectorXd friction_;  // coulomb friction [Nm]
  Eigen::VectorXd damping_;   // viscous friction [Nm/(rad/s)]
};

}  // namespace inverse_dynamics_interface_kdl
