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
#include "ur10_inverse_dynamics_solver/getInertiaCurrents.h"
#include "ur10_inverse_dynamics_solver/getCoriolisCurrents.h"
#include "ur10_inverse_dynamics_solver/getGravityCurrents.h"
#include "ur10_inverse_dynamics_solver/getCurrents.h"
#include "ur10_inverse_dynamics_solver/ur10_inverse_dynamics_solver.h"

using namespace ur10_inverse_dynamics_solver;

void InverseDynamicsSolverUR10::initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr, const std::string&, const std::string&)
{}

Eigen::MatrixXd InverseDynamicsSolverUR10::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  double q[NUMBER_OF_JOINTS];
  double B[NUMBER_OF_JOINTS * NUMBER_OF_JOINTS];
  Vector6d::Map(q) = joint_positions;
  getInertiaCurrents(q, B);
  return getDriveGainsMatrix_() * Matrix6d(B);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getCoriolisVector(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities) const
{
  double q[NUMBER_OF_JOINTS];
  double qd[NUMBER_OF_JOINTS];
  double coriolis_currents[NUMBER_OF_JOINTS];
  Vector6d::Map(q) = joint_positions;
  Vector6d::Map(qd) = joint_velocities;
  getCoriolisCurrents(q, qd, coriolis_currents);
  return getDriveGainsMatrix_() * Vector6d(coriolis_currents);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  double q[NUMBER_OF_JOINTS];
  double gravity_currents[NUMBER_OF_JOINTS];
  Vector6d::Map(q) = joint_positions;
  getGravityCurrents(q, gravity_currents);
  return getDriveGainsMatrix_() * Vector6d(gravity_currents);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getFrictionVector(const Eigen::VectorXd& qd) const
{
  return getDriveGainsMatrix_() * getFrictionCurrents_(qd);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                                                      const Eigen::VectorXd& joint_accelerations) const
{
  double q[NUMBER_OF_JOINTS];
  double qd[NUMBER_OF_JOINTS];
  double qdd[NUMBER_OF_JOINTS];
  double currents[NUMBER_OF_JOINTS];
  Vector6d::Map(q) = joint_positions;
  Vector6d::Map(qd) = joint_velocities;
  Vector6d::Map(qdd) = joint_accelerations;
  getCurrents(q, qd, qdd, currents);
  return getDriveGainsMatrix_() * Vector6d(currents) + getFrictionVector(joint_velocities);
}

Eigen::VectorXd InverseDynamicsSolverUR10::getFrictionCurrents_(const Eigen::VectorXd& joint_velocities) const
{
  // friction current vector
  Vector6d friction_current_vector;

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

  for (long int i = 0; i < joint_velocities.size(); ++i)  // The 'long int' type is to suppress the [-Wsign-compare] warning
    friction_current_vector(i) = f_v(i) * joint_velocities(i) + f_o(i) + f_c(i) / (1 + exp(-alpha(i) * (joint_velocities(i) + ni(i))));

  return friction_current_vector;
}

Eigen::MatrixXd InverseDynamicsSolverUR10::getDriveGainsMatrix_() const
{
  std::vector<double> drive_gains_vector{ K1, K2, K3, K4, K5, K6 };
  return Vector6d(drive_gains_vector.data()).asDiagonal();
}

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(ur10_inverse_dynamics_solver::InverseDynamicsSolverUR10, inverse_dynamics_solver::InverseDynamicsSolver)
