/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   franka_inria_inverse_dynamics_solver.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Feb 10, 2025
 *
 * Refer to the header file for a description of this module.
 *
 * -------------------------------------------------------------------
 */

// Inverse dynamics solver
#include "franka_inria_inverse_dynamics_solver/get_MassMatrix.h"
#include "franka_inria_inverse_dynamics_solver/get_CoriolisMatrix.h"
#include "franka_inria_inverse_dynamics_solver/get_GravityVector.h"
#include "franka_inria_inverse_dynamics_solver/get_FrictionTorque.h"
#include "franka_inria_inverse_dynamics_solver/franka_inria_inverse_dynamics_solver.h"

using namespace franka_inria_inverse_dynamics_solver;

void InverseDynamicsSolverFrankaInria::initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr, const std::string&,
                                                  const std::string&)
{}

Eigen::MatrixXd InverseDynamicsSolverFrankaInria::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  return get_MassMatrix_partial(joint_positions.cast<float>()).cast<double>();
}

Eigen::VectorXd InverseDynamicsSolverFrankaInria::getCoriolisVector(const Eigen::VectorXd& joint_positions,
                                                                    const Eigen::VectorXd& joint_velocities) const
{
  return get_CoriolisMatrix(joint_positions, joint_velocities) * joint_velocities;
}

Eigen::VectorXd InverseDynamicsSolverFrankaInria::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  return get_gravityvector(joint_positions);
}

Eigen::VectorXd InverseDynamicsSolverFrankaInria::getFrictionVector(const Eigen::VectorXd& joint_velocities) const
{
  return get_friction(joint_velocities);
}

Eigen::VectorXd InverseDynamicsSolverFrankaInria::getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                                                             const Eigen::VectorXd& joint_accelerations) const
{
  return inverse_dynamics_solver::InverseDynamicsSolver::getTorques(joint_positions, joint_velocities, joint_accelerations) +
         getFrictionVector(joint_velocities);
}

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(franka_inria_inverse_dynamics_solver::InverseDynamicsSolverFrankaInria, inverse_dynamics_solver::InverseDynamicsSolver)
