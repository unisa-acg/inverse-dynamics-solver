/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   ur10_inverse_dynamics_solver.cpp
 * Author:  Antonio Annunziata, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Jun 23, 2023
 *
 * Refer to the header file for a description of this module.
 *
 * -------------------------------------------------------------------
 */

// Inverse dynamics solver
#include "ur10_inverse_dynamics_solver/getInertiaCurrents.hpp"
#include "ur10_inverse_dynamics_solver/getCoriolisCurrents.hpp"
#include "ur10_inverse_dynamics_solver/getGravityCurrents.hpp"
#include "ur10_inverse_dynamics_solver/getCurrents.hpp"
#include "ur10_inverse_dynamics_solver/ur10_inverse_dynamics_solver.hpp"

namespace ur10_inverse_dynamics_solver

{
void InverseDynamicsSolverUR10::initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr, const std::string&, const std::string&)
{
  // Allocate kinematic/dynamic variables once for real-time safeness
  q_ = (double*)malloc(NUMBER_OF_JOINTS * sizeof(double));
  qd_ = (double*)malloc(NUMBER_OF_JOINTS * sizeof(double));
  qdd_ = (double*)malloc(NUMBER_OF_JOINTS * sizeof(double));
  H_ = (double*)malloc(NUMBER_OF_JOINTS * NUMBER_OF_JOINTS * sizeof(double));
  c_ = (double*)malloc(NUMBER_OF_JOINTS * sizeof(double));
  g_ = (double*)malloc(NUMBER_OF_JOINTS * sizeof(double));
  currents_ = (double*)malloc(NUMBER_OF_JOINTS * sizeof(double));
}

Eigen::MatrixXd InverseDynamicsSolverUR10::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  Vector6d::Map(q_) = joint_positions;
  getInertiaCurrents(q_, H_);
  return getDriveGainsMatrix_() * Matrix6d(H_);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getCoriolisVector(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities) const
{
  Vector6d::Map(q_) = joint_positions;
  Vector6d::Map(qd_) = joint_velocities;
  getCoriolisCurrents(q_, qd_, c_);
  return getDriveGainsMatrix_() * Vector6d(c_);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  Vector6d::Map(q_) = joint_positions;
  getGravityCurrents(q_, g_);
  return getDriveGainsMatrix_() * Vector6d(g_);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getFrictionVector(const Eigen::VectorXd& joint_velocities) const
{
  return getDriveGainsMatrix_() * getFrictionCurrents_(joint_velocities);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                                                      const Eigen::VectorXd& joint_accelerations) const
{
  Vector6d::Map(q_) = joint_positions;
  Vector6d::Map(qd_) = joint_velocities;
  Vector6d::Map(qdd_) = joint_accelerations;
  getCurrents(q_, qd_, qdd_, currents_);
  return getDriveGainsMatrix_() * Vector6d(currents_) + getFrictionVector(joint_velocities);
}

Vector6d InverseDynamicsSolverUR10::getFrictionCurrents_(const Vector6d& joint_velocities) const
{
  // parameters of the sigmoid friction model
  Vector6d f_v;
  Vector6d f_o;
  Vector6d f_c;
  Vector6d alpha;
  Vector6d ni;

  f_v(0) = 1.064043537306522;
  f_v(1) = 0.994406350204483;
  f_v(2) = 0.679578357403764;
  f_v(3) = 0.315921846615047;
  f_v(4) = 0.224394888674796;
  f_v(5) = 0.235839271499783;

  f_o(0) = -1.006569687742683;
  f_o(1) = 0.956270099079205;
  f_o(2) = -0.811994879948593;
  f_o(3) = -0.176720084521011;
  f_o(4) = -0.192362457059083;
  f_o(5) = -0.245334512427042;

  f_c(0) = 2.050627184327219;
  f_c(1) = -2.401744448718348;
  f_c(2) = 1.647842359055070;
  f_c(3) = 0.468777484116134;
  f_c(4) = 0.475975499951034;
  f_c(5) = 0.597950406691004;

  alpha(0) = 7.946667188885291;
  alpha(1) = -59.953551521104440;
  alpha(2) = 19.825139076376780;
  alpha(3) = 134.8982492898554;
  alpha(4) = 331.4420553811227;
  alpha(5) = 459.1933488839184;

  ni(0) = -0.018479435103176;
  ni(1) = -0.001949874917063;
  ni(2) = -0.005295096397544;
  ni(3) = -0.018576852000623;
  ni(4) = -0.011778095526897;
  ni(5) = -0.012953200294568;

  return f_v.cwiseProduct(joint_velocities) + f_o +
         f_c.cwiseQuotient(Vector6d::Ones() + (-alpha.cwiseProduct(joint_velocities + ni)).array().exp().matrix());
}

Matrix6d InverseDynamicsSolverUR10::getDriveGainsMatrix_() const
{
  Vector6d drive_gains_vector;
  drive_gains_vector << K1, K2, K3, K4, K5, K6;
  return drive_gains_vector.asDiagonal();
}
}  // namespace ur10_inverse_dynamics_solver

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(ur10_inverse_dynamics_solver::InverseDynamicsSolverUR10, inverse_dynamics_solver::InverseDynamicsSolver)
