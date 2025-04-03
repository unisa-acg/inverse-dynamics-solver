/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   evaluate_solver.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Feb 5, 2025
 *
 * This demo evaluates the inverse dynamics solver by reading a bag
 * file containing a sequence of joint states, and computes the
 * corresponding torques for each state. Joint accelerations are
 * approximated from velocities.
 *
 * -------------------------------------------------------------------
 */

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/serialization.hpp>
#include <rosbag2_cpp/reader.hpp>
#include <rosbag2_cpp/writer.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <pluginlib/class_loader.hpp>
#include <eigen3/Eigen/Core>
#include <urdf/model.h>
#include "inverse_dynamics_solver/inverse_dynamics_solver.h"

class EvaluateSolverNode : public rclcpp::Node
{
  typedef pluginlib::ClassLoader<inverse_dynamics_solver::InverseDynamicsSolver> InverseDynamicsSolverLoader;

public:
  RCLCPP_SMART_PTR_DEFINITIONS(EvaluateSolverNode)

  EvaluateSolverNode(const std::string& node_name, const rclcpp::NodeOptions options = rclcpp::NodeOptions()) : Node(node_name, options)
  {
    // Read parameters
    std::string plugin_name = this->get_parameter("plugin_name").as_string();
    robot_description_ = this->get_parameter("robot_description").as_string();
    root_link_name_ = this->get_parameter_or<std::string>("ids.root", "");
    tip_link_name_ = this->get_parameter_or<std::string>("ids.tip", "");

    // Load the inverse dynamics solver plugin
    solver_loader_ = std::make_unique<InverseDynamicsSolverLoader>("inverse_dynamics_solver", "inverse_dynamics_solver::InverseDynamicsSolver");
    solver_ = solver_loader_->createUniqueInstance(plugin_name);
    solver_->initialize(this->get_node_parameters_interface(), "ids");

    // Parse URDF and get ordered joint names
    computeOrderedJointNames_();
  }

  void processBag() const
  {
    // Read parameters
    std::string input_bag = this->get_parameter("input_bag").as_string();
    std::string output_bag = this->get_parameter("output_bag").as_string();
    std::string topic = this->get_parameter("topic").as_string();

    // Initialize the rosbag reader
    rclcpp::Serialization<sensor_msgs::msg::JointState> serialization;
    rosbag2_cpp::Reader reader;
    reader.open(input_bag);

    // Initialize the rosbag writer
    rosbag2_cpp::Writer writer;
    writer.open(output_bag);

    // Read joint states
    std::vector<sensor_msgs::msg::JointState> joint_states;
    std::vector<rclcpp::Time> timestamps;
    while (reader.has_next())
    {
      rosbag2_storage::SerializedBagMessageSharedPtr message = reader.read_next();
      rclcpp::SerializedMessage serialized_message(*message->serialized_data);
      sensor_msgs::msg::JointState::SharedPtr joint_state = std::make_shared<sensor_msgs::msg::JointState>();
      serialization.deserialize_message(&serialized_message, joint_state.get());

      if (joint_state)
      {
        // Reorder joint state to match the kinematic chain
        reorderJointState_(*joint_state);
        joint_states.push_back(*joint_state);
        timestamps.push_back(joint_state->header.stamp);
      }
    }

    // Compute accelerations
    std::vector<Eigen::VectorXd> accelerations;
    computeAccelerations_(joint_states, timestamps, accelerations);

    // Evaluate solver and compute torques
    for (std::size_t i = 0; i < joint_states.size(); ++i)
    {
      Eigen::VectorXd positions = Eigen::Map<const Eigen::VectorXd>(joint_states[i].position.data(), joint_states[i].position.size());
      Eigen::VectorXd velocities = Eigen::Map<const Eigen::VectorXd>(joint_states[i].velocity.data(), joint_states[i].velocity.size());
      Eigen::VectorXd torques = solver_->getTorques(positions, velocities, accelerations[i]);

      writer.write(joint_states[i], topic + "_gt", timestamps[i]);
      sensor_msgs::msg::JointState output_msg = joint_states[i];
      output_msg.effort.assign(torques.data(), torques.data() + torques.size());
      writer.write(output_msg, topic, timestamps[i]);
    }
  }

private:
  /**
   * @brief Fills the list of joint names \e ordered_joint_names_, ordered according to the kinematic chain defined in \e robot_description_,
   * starting from the root link.
   *
   * This function is needed because, typically, joint states recorded through the /joint_states topics are published in alphabetical order which, in
   * general, might not match the kinematic order.
   */
  void computeOrderedJointNames_()
  {
    // Read URDF from robot description
    if (!urdf_model_.initString(robot_description_))
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to parse URDF.");
      throw std::runtime_error("URDF parsing failed.");
    }

    // Clear any previous joint list
    ordered_joint_names_.clear();

    // Find the root link
    urdf::LinkConstSharedPtr root_link = root_link_name_.empty() ? urdf_model_.getRoot() : urdf_model_.getLink(root_link_name_);
    if (!root_link)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to find root link in URDF.");
      throw std::runtime_error("No root link found in URDF.");
    }

    // Recursively traverse the robot chain
    traverseChain_(root_link);
  }

  /**
   * @brief Inserts in \e ordered_joint_names_ the joint names ordered according to the kinematic chain defined in \e robot_description_,
   * starting from \e link.
   *
   * @param[in] link The link to traverse the kinematic chain from
   */
  void traverseChain_(const urdf::LinkConstSharedPtr& link)
  {
    for (const urdf::JointSharedPtr& child_joint : link->child_joints)
    {
      // Get the child joint
      if (!child_joint->child_link_name.empty() && child_joint->child_link_name.compare(tip_link_name_) != 0)
      {
        // Skip fixed joints
        if (child_joint->type != urdf::Joint::FIXED)
        {
          // Add the joint to the list of ordered joint names
          ordered_joint_names_.push_back(child_joint->name);
        }

        // Recurse to the next link in the kinematic chain
        traverseChain_(urdf_model_.getLink(child_joint->child_link_name));
      }
    }
  }

  /**
   * @brief Reorders \e joint_state according to \e ordered_joint_names_.
   *
   * @param[in] joint_state the joint state to reorder
   */
  void reorderJointState_(sensor_msgs::msg::JointState& joint_state) const
  {
    std::vector<double> ordered_positions(ordered_joint_names_.size(), 0.0);
    std::vector<double> ordered_velocities(ordered_joint_names_.size(), 0.0);
    std::vector<double> ordered_efforts(ordered_joint_names_.size(), 0.0);

    // Create a mapping from joint names in the message to their indices
    std::unordered_map<std::string, std::size_t> msg_joint_indices;
    for (std::size_t i = 0; i < joint_state.name.size(); ++i)
    {
      msg_joint_indices[joint_state.name[i]] = i;
    }

    // Reorder joint values based on URDF joint order
    for (std::size_t i = 0; i < ordered_joint_names_.size(); ++i)
    {
      const std::string& joint_name = ordered_joint_names_[i];
      if (msg_joint_indices.find(joint_name) != msg_joint_indices.end())
      {
        std::size_t msg_index = msg_joint_indices[joint_name];
        ordered_positions[i] = joint_state.position[msg_index];
        ordered_velocities[i] = joint_state.velocity[msg_index];
        ordered_efforts[i] = joint_state.effort[msg_index];
      }
      else
      {
        RCLCPP_WARN(this->get_logger(), "Joint %s missing from joint state message.", joint_name.c_str());
      }
    }

    // Update joint state with ordered values
    joint_state.name = ordered_joint_names_;
    joint_state.position = ordered_positions;
    joint_state.velocity = ordered_velocities;
    joint_state.effort = ordered_efforts;
  }

  /**
   * @brief Compute accelerations from velocities defined in \e joint_states, according to a list of timestamps.
   *
   * The backward Euler approximation is used as differentiation method.
   *
   * @param[in] joint_states The joint states to compute the accelerations for
   * @param[in] timestamps The timestamps needed to compute the accelerations
   * @param[out] accelerations The computed accelerations
   */
  static void computeAccelerations_(const std::vector<sensor_msgs::msg::JointState>& joint_states, const std::vector<rclcpp::Time>& timestamps,
                                    std::vector<Eigen::VectorXd>& accelerations)
  {
    accelerations.resize(joint_states.size(), Eigen::VectorXd::Zero(joint_states[0].velocity.size()));
    for (std::size_t i = 1; i < joint_states.size(); ++i)
    {
      double dt = (timestamps[i] - timestamps[i - 1]).seconds();
      if (dt > 0.0)
      {
        Eigen::VectorXd v_prev = Eigen::Map<const Eigen::VectorXd>(joint_states[i - 1].velocity.data(), joint_states[i - 1].velocity.size());
        Eigen::VectorXd v_curr = Eigen::Map<const Eigen::VectorXd>(joint_states[i].velocity.data(), joint_states[i].velocity.size());
        accelerations[i] = (v_curr - v_prev) / dt;
      }
    }
  }

  std::unique_ptr<InverseDynamicsSolverLoader> solver_loader_;
  std::shared_ptr<inverse_dynamics_solver::InverseDynamicsSolver> solver_;
  std::vector<std::string> ordered_joint_names_;
  std::string robot_description_;
  std::string root_link_name_;
  std::string tip_link_name_;
  urdf::Model urdf_model_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  options.automatically_declare_parameters_from_overrides(true);
  EvaluateSolverNode::SharedPtr processor = EvaluateSolverNode::make_shared("evaluate_solver_node", options);
  processor->processBag();
  rclcpp::shutdown();
  return 0;
}
