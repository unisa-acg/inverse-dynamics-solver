/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   inverse_dynamics_interface_franka_inria.hpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Feb 10, 2025
 *
 * This is an implementation of the InverseDynamicsInterface interface
 * from inverse_dynamics_interface, using the Franka Emika's Panda
 * (FER) dynamic model, estimated in
 *
 * C. Gaz, M. Cognetti, A. Oliva, P. Robuffo Giordano, A. De Luca,
 * "Dynamic identification of the Franka Emika Panda robot with
 * retrieval of feasible parameters using penalty-based optimization",
 * IEEE Robotics and Automation Letters, 2019.
 *
 * The MATLAB code is available at
 * https://github.com/marcocognetti/FrankaEmikaPandaDynModel
 *
 * -------------------------------------------------------------------
 */

#pragma once

#include <inverse_dynamics_interface/inverse_dynamics_interface.hpp>

namespace inverse_dynamics_interface_franka_inria
{
class InverseDynamicsInterfaceFrankaInria : public inverse_dynamics_interface::InverseDynamicsInterface
{
public:
  InverseDynamicsInterfaceFrankaInria() {}

  /**
   * @brief Refer to the superclass documentation
   *
   * No parameter is required for this class. This method shall be called without passing any argument.
   */
  void initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr = nullptr, const std::string& = "",
                  const std::string& = "") override;

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
  Eigen::VectorXd getFrictionVector(const Eigen::VectorXd& joint_velocities) const override;

  /**
   * @brief Refer to the superclass documentation
   * @throw UnimplementedError
   */
  Eigen::MatrixXd getJacobian(const Eigen::VectorXd& joint_positions) const override;

  /**
   * @brief Refer to the superclass documentation
   * @note \p external_wrench is ignored as external torques can not be computed
   */
  Eigen::VectorXd getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                             const Eigen::VectorXd& joint_accelerations,
                             const Eigen::Matrix<double, 6, 1>& external_wrench = Eigen::VectorXd::Zero(6)) const override;
};

}  // namespace inverse_dynamics_interface_franka_inria
