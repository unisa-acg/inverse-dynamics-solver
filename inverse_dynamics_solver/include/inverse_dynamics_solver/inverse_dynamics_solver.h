/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   inverse_dynamics_solver.h
 * Author:  Enrico Ferrentino, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Dec 3, 2019
 *
 * This class is a plugin interface for dynamic solvers, that are
 * solvers providing the dynamic parameters of a given robot, namely
 * inertia matrix, Coriolis vector, gravity vector and friction
 * vector.
 *
 * -------------------------------------------------------------------
 */

#pragma once

#include <vector>
#include <memory>
#include <eigen3/Eigen/Core>
#include <rclcpp/node_interfaces/node_parameters_interface.hpp>

namespace inverse_dynamics_solver
{

class InverseDynamicsSolver
{
public:
  /**
   * @brief Virtual destructor
   */
  virtual ~InverseDynamicsSolver() {}

  /**
   * @brief Initialize the plugin object
   *
   * Since pluginlib requires the implementation to have a parameterless
   * constructor, the objects are initialized through this method
   *
   * @param[in] parameters_interface the node parameters interface through which the parameters are passed
   * @param[in] param_namespace namespace for the node parameters
   * @param[in] robot_description robot URDF in string format
   */
  virtual void initialize(rclcpp::node_interfaces::NodeParametersInterface::ConstSharedPtr parameters_interface = nullptr,
                          const std::string& param_namespace = "", const std::string& robot_description = "") = 0;

  /**
   * @brief Get all the dynamic parameters at once
   *
   * @param[in] joint_positions joint positions
   * @param[in] joint_velocities joint velocities
   * @return inertia matrix, Coriolis vector, corresponding to C(q,qd)*qd, and gravity vector
   */
  virtual std::tuple<Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> getDynamicParameters(const Eigen::VectorXd& joint_positions,
                                                                                             const Eigen::VectorXd& joint_velocities) const
  {
    return std::make_tuple(getInertiaMatrix(joint_positions), getCoriolisVector(joint_positions, joint_velocities),
                           getGravityVector(joint_positions));
  }

  /**
   * @brief Get the inertia matrix
   *
   * @param[in] joint_positions joint positions
   * @return inertia matrix
   */
  virtual Eigen::MatrixXd getInertiaMatrix(const Eigen::VectorXd& joint_positions) const = 0;

  /**
   * @brief Get the Coriolis vector
   *
   * @param[in] joint_positions joint positions
   * @param[in] joint_velocities joint velocities
   * @return coriolis vector, corresponding to C(q,qd)*qd
   */
  virtual Eigen::VectorXd getCoriolisVector(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities) const = 0;

  /**
   * @brief Get the gravity vector
   *
   * @param[in] joint_positions joint positions
   * @return gravity vector
   */
  virtual Eigen::VectorXd getGravityVector(const Eigen::VectorXd& joint_positions) const = 0;

  /**
   * @brief Get the vector of friction torques
   *
   * @param[in] joint_velocities joint velocities
   * @return friction vector
   */
  virtual Eigen::VectorXd getFrictionVector(const Eigen::VectorXd& joint_velocities) const = 0;

  /**
   * @brief Get the vector of torques due to Coriolis effects, inertia and gravity
   *
   * @param[in] joint_positions joint positions
   * @param[in] joint_velocities joint velocities
   * @param[in] joint_accelerations joint accelerations
   * @return torques vector
   */
  virtual Eigen::VectorXd getTorques(const Eigen::VectorXd& joint_positions, const Eigen::VectorXd& joint_velocities,
                                     const Eigen::VectorXd& joint_accelerations) const
  {
    return getInertiaMatrix(joint_positions) * joint_accelerations + getCoriolisVector(joint_positions, joint_velocities) +
           getGravityVector(joint_positions);
  }

protected:
  InverseDynamicsSolver() {}
};

}  // namespace inverse_dynamics_solver
