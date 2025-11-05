/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   kdl_inverse_dynamics_solver.hpp
 * Author:  Enrico Ferrentino, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Dec 3, 2019
 *
 * This is an implementation of DynamicsSolver using the
 * general-purpose, robot-agnostic KDL library.
 *
 * -------------------------------------------------------------------
 */

#pragma once

#include <string>
#include <eigen3/Eigen/Core>
#include <kdl/chain.hpp>
#include <kdl/chaindynparam.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/jntspaceinertiamatrix.hpp>
#include <rclcpp/node_interfaces/node_parameters_interface.hpp>

#include <inverse_dynamics_solver/inverse_dynamics_solver.hpp>

namespace kdl_inverse_dynamics_solver
{

class InverseDynamicsSolverKDL : public inverse_dynamics_solver::InverseDynamicsSolver
{
public:
  InverseDynamicsSolverKDL() {}

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
   */
  Eigen::VectorXd getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                             const Eigen::VectorXd& joint_accelerations) const override;

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

  bool initialized_ = false;
  unsigned int number_of_joints_;
  KDL::Chain chain_;
  std::unique_ptr<KDL::ChainDynParam> solver_;
  Eigen::VectorXd static_friction_;   // static friction [Nm]
  Eigen::VectorXd viscous_friction_;  // viscous friction [Nm/(rad/s)]

  // Kinematic/dynamic variables are allocated in the `initialize` method for real-time safeness; they are declared with smart pointers because all
  // the methods in this class are `const`, and this would not allow changing their values if they were not declared with pointers
  std::unique_ptr<KDL::JntArray> kdl_joint_positions_;
  std::unique_ptr<KDL::JntArray> kdl_joint_velocities_;
  std::unique_ptr<KDL::JntSpaceInertiaMatrix> H_;
  std::unique_ptr<KDL::JntArray> c_;
  std::unique_ptr<KDL::JntArray> g_;
};

}  // namespace kdl_inverse_dynamics_solver
