/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   inverse_dynamics_interface_franka_inria.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Feb 10, 2025
 *
 * Refer to the header file for a description of this module.
 *
 * -------------------------------------------------------------------
 */

// ROS
#include <rclcpp/exceptions/exceptions.hpp>

// Inverse dynamics interface
#include "inverse_dynamics_interface_franka_inria/get_MassMatrix.hpp"
#include "inverse_dynamics_interface_franka_inria/get_CoriolisMatrix.hpp"
#include "inverse_dynamics_interface_franka_inria/get_GravityVector.hpp"
#include "inverse_dynamics_interface_franka_inria/get_FrictionTorque.hpp"
#include "inverse_dynamics_interface_franka_inria/inverse_dynamics_interface_franka_inria.hpp"

namespace inverse_dynamics_interface_franka_inria

{
void InverseDynamicsInterfaceFrankaInria::initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr, const std::string&,
                                                     const std::string&)
{}

Eigen::MatrixXd InverseDynamicsInterfaceFrankaInria::getInertiaMatrix(const Eigen::VectorXd& joint_positions) const
{
  return get_MassMatrix_partial(joint_positions.cast<float>()).cast<double>();
}

Eigen::VectorXd InverseDynamicsInterfaceFrankaInria::getCoriolisVector(const Eigen::VectorXd& joint_positions,
                                                                       const Eigen::VectorXd& joint_velocities) const
{
  return get_CoriolisMatrix(joint_positions, joint_velocities) * joint_velocities;
}

Eigen::VectorXd InverseDynamicsInterfaceFrankaInria::getGravityVector(const Eigen::VectorXd& joint_positions) const
{
  return get_gravityvector(joint_positions);
}

Eigen::VectorXd InverseDynamicsInterfaceFrankaInria::getFrictionVector(const Eigen::VectorXd& joint_velocities) const
{
  return get_friction(joint_velocities);
}

Eigen::VectorXd InverseDynamicsInterfaceFrankaInria::getExternalTorques(const Eigen::VectorXd&, const Eigen::Matrix<double, 6, 1>&) const
{
  throw rclcpp::exceptions::UnimplementedError("`getExternalTorques` is not implemented because this plugin can not compute the Jacobian matrix. "
                                               "Please use an external robot-agnostic library.");
}

Eigen::VectorXd InverseDynamicsInterfaceFrankaInria::getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                                                                const Eigen::VectorXd& joint_accelerations, const Eigen::Matrix<double, 6, 1>&) const
{
  return getInertiaMatrix(joint_positions) * joint_accelerations + getCoriolisVector(joint_positions, joint_velocities) +
         getGravityVector(joint_positions) + getFrictionVector(joint_velocities);
}
}  // namespace inverse_dynamics_interface_franka_inria

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(inverse_dynamics_interface_franka_inria::InverseDynamicsInterfaceFrankaInria,
                       inverse_dynamics_interface::InverseDynamicsInterface)
