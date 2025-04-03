/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   ur10_inverse_dynamics_solver.h
 * Author:  Antonio Annunziata, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Jun 23, 2023
 *
 * This is an implementation of the InverseDynamicsSolver interface
 * from inverse_dynamics_solver, using regressive form of the UR10
 * dynamic model estimated on MATLAB.
 *
 * -------------------------------------------------------------------
 */

#pragma once

#include <inverse_dynamics_solver/inverse_dynamics_solver.h>

namespace ur10_inverse_dynamics_solver
{

// Motor gains
static const double K1 = 13.5841;
static const double K2 = 14.2959;
static const double K3 = 11.3716;
static const double K4 = 11.2408;
static const double K5 = 11.7681;
static const double K6 = 11.7682;

static const unsigned short int NUMBER_OF_JOINTS = 6;
typedef Eigen::Matrix<double, NUMBER_OF_JOINTS, 1> Vector6d;
typedef Eigen::Matrix<double, NUMBER_OF_JOINTS, NUMBER_OF_JOINTS> Matrix6d;

class InverseDynamicsSolverUR10 : public inverse_dynamics_solver::InverseDynamicsSolver
{
public:
  InverseDynamicsSolverUR10() {}

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

private:
  /**
   * @brief This method returns the numerical computation of the friction current vector
   *
   * @param[in] joint_velocities joint velocities in [rad/s]
   *
   * @return Returns a 6-by-1 vector with joint currents due to friction (expressed in [A])
   */
  Eigen::VectorXd getFrictionCurrents_(const Eigen::VectorXd& joint_velocities) const;

  /**
   * @brief This method returns the matrix K of motor drive gains, such that tau = K*i
   *
   * @return Returns a 6-by-6 diagonal matrix containing joint motor drive gains (expressed in [Nm/A]).
   */
  Eigen::MatrixXd getDriveGainsMatrix_() const;
};

}  // namespace ur10_inverse_dynamics_solver
