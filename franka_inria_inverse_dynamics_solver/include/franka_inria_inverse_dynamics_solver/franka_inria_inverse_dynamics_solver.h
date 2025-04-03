/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   franka_inria_inverse_dynamics_solver.h
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Feb 10, 2025
 *
 * This is an implementation of the InverseDynamicsSolver interface
 * from inverse_dynamics_solver, using the Franka Emika's Panda (FER)
 * dynamic model, estimated in
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

#include <inverse_dynamics_solver/inverse_dynamics_solver.h>

namespace franka_inria_inverse_dynamics_solver
{

static const unsigned short int NUMBER_OF_JOINTS = 7;
typedef Eigen::Matrix<double, NUMBER_OF_JOINTS, 1> Vector7d;
typedef Eigen::Matrix<double, NUMBER_OF_JOINTS, NUMBER_OF_JOINTS> Matrix7d;

class InverseDynamicsSolverFrankaInria : public inverse_dynamics_solver::InverseDynamicsSolver
{
public:
  InverseDynamicsSolverFrankaInria() {}

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
   */
  Eigen::VectorXd getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                             const Eigen::VectorXd& joint_accelerations) const override;
};

}  // namespace franka_inria_inverse_dynamics_solver
