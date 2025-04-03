/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   kdl_inverse_dynamics_solver.h
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

#include <kdl/chaindynparam.hpp>
#include <inverse_dynamics_solver/inverse_dynamics_solver.h>

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

private:
  /**
   * @brief Verify that the solver has been correctly initialized
   */
  void verifyInitialization_() const;

  bool initialized_ = false;
  unsigned int number_of_joints_;
  KDL::Chain chain_;
  std::shared_ptr<KDL::ChainDynParam> solver_;
};

}  // namespace kdl_inverse_dynamics_solver
