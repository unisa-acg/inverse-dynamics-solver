/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   inverse_dynamics_interface_pinocchio.hpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Oct 10, 2025
 *
 * This is an implementation of InverseDynamicsInterface using the
 * general-purpose, robot-agnostic Pinocchio library.
 *
 * -------------------------------------------------------------------
 */

#pragma once

#include <memory>
#include <string>
#include <eigen3/Eigen/Core>
#include <rclcpp/node_interfaces/node_parameters_interface.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/multibody/model.hpp>

#include <inverse_dynamics_interface/inverse_dynamics_interface.hpp>

namespace inverse_dynamics_interface_pinocchio
{

class InverseDynamicsInterfacePinocchio : public inverse_dynamics_interface::InverseDynamicsInterface
{
public:
  InverseDynamicsInterfacePinocchio() {}

  /**
   * @brief Refer to the superclass documentation
   *
   * This method must be called before any other.
   *
   * @throw ParameterUninitializedException if the required parameters are not found in \e parameters_interface
   * @throw InvalidParameterValueException if the parameters are not valid, i.e. \e robot_description is malformed, the kinematic chain's tip is not
   * correctly configured, or the gravity vector is not coherent
   */
  void initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr parameters_interface, const std::string& param_namespace = "",
                  const std::string& robot_description = "") override;

  /**
   * @brief Refer to the superclass documentation
   * @note Calls pinocchio::crba
   * @see https://gepettoweb.laas.fr/doc/stack-of-tasks/pinocchio/devel/doxygen-html/namespacepinocchio.html#aceb2f63122315f978667acb902f21618
   */
  Eigen::MatrixXd getInertiaMatrix(const Eigen::VectorXd& joint_positions) const override;

  /**
   * @brief Refer to the superclass documentation
   * @note Calls pinocchio::computeCoriolisMatrix
   * @see https://gepettoweb.laas.fr/doc/stack-of-tasks/pinocchio/devel/doxygen-html/namespacepinocchio.html#aa8054f1b4946aefea90d819031b98df3
   */
  Eigen::VectorXd getCoriolisVector(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities) const override;

  /**
   * @brief Refer to the superclass documentation
   * @note Calls pinocchio::computeGeneralizedGravity
   * @see https://gepettoweb.laas.fr/doc/stack-of-tasks/pinocchio/devel/doxygen-html/namespacepinocchio.html#ab92fc9acc9c2366729b13ddb594f5cc4
   */
  Eigen::VectorXd getGravityVector(const Eigen::VectorXd& joint_positions) const override;

  /**
   * @brief Refer to the superclass documentation
   */
  Eigen::VectorXd getFrictionVector(const Eigen::VectorXd&) const override;

  /**
   * @brief Refer to the superclass documentation
   * @note Calls pinocchio::computeJointJacobians before pinocchio::getFrameJacobian
   * @see https://gepettoweb.laas.fr/doc/stack-of-tasks/pinocchio/master/doxygen-html/namespacepinocchio.html#ae13e2fae5dd6f8845ef31b32d9868a0d
   */
  Eigen::VectorXd getExternalTorques(const Eigen::VectorXd& joint_positions, const Eigen::Matrix<double, 6, 1>& external_wrench) const override;

  /**
   * @brief Refer to the superclass documentation
   * @note Calls pinocchio::rnea
   * @see https://gepettoweb.laas.fr/doc/stack-of-tasks/pinocchio/devel/doxygen-html/namespacepinocchio.html#a4cdcd1eb63d3a12d29f6df7639899bb6
   */
  Eigen::VectorXd getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                             const Eigen::VectorXd& joint_accelerations,
                             const Eigen::Matrix<double, 6, 1>& external_wrench = Eigen::VectorXd::Zero(6)) const override;

private:
  /**
   * @brief Verify that the solver has been correctly initialized
   * @throw UninitializedException if the solver is not initialized
   */
  void verifyInitialization_() const;

  /**
   * @brief Parse robot description from URDF and retrieves friction parameters
   * @throw InvalidParameterValueException if the robot description parsing fails
   */
  void parseFrictionFromURDF_(const std::string& robot_description);

  std::string tip_;
  std::shared_ptr<pinocchio::Data> data_;
  pinocchio::Model model_;
  unsigned int number_of_joints_;
  bool initialized_ = false;
  Eigen::VectorXd static_friction_;   // static friction [Nm]
  Eigen::VectorXd viscous_friction_;  // viscous friction [Nm/(rad/s)]

  // This variables avoid dynamic allocation and ensure real-time safeness
  pinocchio::Data::Matrix6x jacobian_;
};

}  // namespace inverse_dynamics_interface_pinocchio
