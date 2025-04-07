/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   test_ur10_inverse_dynamics_solver.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    May 10, 2024
 *
 * This is a test for InverseDynamicsSolverUR10.
 *
 * -------------------------------------------------------------------
 */

// ROS2
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/serialization.hpp>
#include <rosbag2_cpp/reader.hpp>
#include <rosbag2_storage/storage_options.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>

// PluginLib
#include <pluginlib/class_loader.hpp>

// Gtest
#include <gtest/gtest.h>

// Inverse Dynamics Solver
#include <inverse_dynamics_solver/inverse_dynamics_solver.h>
#include "ur10_inverse_dynamics_solver/ur10_inverse_dynamics_solver.h"

// This class shares parameters and data across all tests
class SharedData
{
  typedef pluginlib::ClassLoader<inverse_dynamics_solver::InverseDynamicsSolver> InverseDynamicsSolverLoader;
  friend class InverseDynamicsSolverUR10Test;

  std::shared_ptr<rclcpp::Node> node_;
  std::string inverse_dynamics_solver_plugin_name_;
  std::string bag_filename_;
  std::string topic_name_;
  std::unique_ptr<InverseDynamicsSolverLoader> inverse_dynamics_solver_loader_;

  SharedData(const SharedData&) = delete;  // this is a singleton
  SharedData()
  {
    initialize();
  }

  void initialize()
  {
    // Instantiate the node
    rclcpp::NodeOptions node_options;
    node_options.automatically_declare_parameters_from_overrides(true);
    node_ = rclcpp::Node::make_shared("ur10_inverse_dynamics_solver_test", node_options);

    // Load parameters
    ASSERT_TRUE(node_->get_parameter("inverse_dynamics_solver_plugin_name", inverse_dynamics_solver_plugin_name_));
    ASSERT_TRUE(node_->get_parameter("bag_filename", bag_filename_));
    ASSERT_TRUE(node_->get_parameter("topic_name", topic_name_));

    // Initialize inverse dynamics solver class loader
    inverse_dynamics_solver_loader_ =
        std::make_unique<InverseDynamicsSolverLoader>("inverse_dynamics_solver", "inverse_dynamics_solver::InverseDynamicsSolver");
    ASSERT_TRUE(bool(inverse_dynamics_solver_loader_)) << "Failed to instantiate ClassLoader<InverseDynamicsSolver>";
  }

public:
  pluginlib::UniquePtr<inverse_dynamics_solver::InverseDynamicsSolver> createUniqueInstance(const std::string& name) const
  {
    return inverse_dynamics_solver_loader_->createUniqueInstance(name);
  }

  static const SharedData& instance()
  {
    static SharedData instance;
    return instance;
  }
  static void release()
  {
    SharedData& shared = const_cast<SharedData&>(instance());
    shared.inverse_dynamics_solver_loader_.reset();
  }
};

// This class implements the tests
class InverseDynamicsSolverUR10Test : public ::testing::Test
{
protected:
  void operator=(const SharedData& data)
  {
    node = data.node_;
    inverse_dynamics_solver_plugin_name = data.inverse_dynamics_solver_plugin_name_;
    bag_filename = data.bag_filename_;
    topic_name = data.topic_name_;
  }

  void SetUp() override
  {
    *this = SharedData::instance();

    // Load KDL inverse dynamics solver plugin
    RCLCPP_INFO_STREAM(node->get_logger(), "Loading " << inverse_dynamics_solver_plugin_name);
    inverse_dynamics_solver = SharedData::instance().createUniqueInstance(inverse_dynamics_solver_plugin_name);
    ASSERT_TRUE(bool(inverse_dynamics_solver)) << "Failed to load plugin: " << inverse_dynamics_solver_plugin_name;
    RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_solver_plugin_name << " loaded.");

    // Initialize inverse dynamics solver
    RCLCPP_INFO_STREAM(node->get_logger(), "Initializing " << inverse_dynamics_solver_plugin_name);
    ASSERT_NO_THROW(inverse_dynamics_solver->initialize());
    RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_solver_plugin_name << " initialized.");
  }

public:
  rclcpp::Node::SharedPtr node;
  std::string inverse_dynamics_solver_plugin_name;
  std::string bag_filename;
  std::string topic_name;
  pluginlib::UniquePtr<inverse_dynamics_solver::InverseDynamicsSolver> inverse_dynamics_solver;
};

// Tests
// Test 1
/**
 * @brief verifies that method getDynamicParameters returns the expected values
 */
TEST_F(InverseDynamicsSolverUR10Test, TestDynamicParameters)
{
  using ur10_inverse_dynamics_solver::Matrix6d;
  using ur10_inverse_dynamics_solver::NUMBER_OF_JOINTS;
  using ur10_inverse_dynamics_solver::Vector6d;

  // Initialize the rosbag reader
  rclcpp::Serialization<trajectory_msgs::msg::JointTrajectory> serialization;
  RCLCPP_INFO(node->get_logger(), "Opening '%s'", bag_filename.c_str());
  rosbag2_cpp::Reader reader;
  rosbag2_storage::StorageOptions storage_options;
  storage_options.uri = bag_filename;
  storage_options.storage_id = "sqlite3";
  reader.open(storage_options);

  // For each trajectory in the rosbag file, evaluate the dynamics solver
  while (reader.has_next())
  {
    rosbag2_storage::SerializedBagMessageSharedPtr message = reader.read_next();
    if (message->topic_name == topic_name)
    {
      rclcpp::SerializedMessage serialized_message(*message->serialized_data);
      trajectory_msgs::msg::JointTrajectory::SharedPtr trajectory = std::make_shared<trajectory_msgs::msg::JointTrajectory>();
      serialization.deserialize_message(&serialized_message, trajectory.get());
      std::size_t n_waypoints = trajectory->points.size();
      RCLCPP_INFO(node->get_logger(), "Trajectory with %ld waypoints read from %s.", n_waypoints, topic_name.c_str());

      for (std::size_t i = 0; i < n_waypoints; i++)
      {
        // Get the current waypoint
        const trajectory_msgs::msg::JointTrajectoryPoint point = trajectory->points[i];

        // Get the torques from the dynamic model's regressive form
        Vector6d positions = Eigen::Map<const Vector6d>(point.positions.data());
        Vector6d velocities = Eigen::Map<const Vector6d>(point.velocities.data());
        Vector6d accelerations = Eigen::Map<const Vector6d>(point.accelerations.data());
        Vector6d torques = inverse_dynamics_solver->getTorques(positions, velocities, accelerations);

        // Get the torques by explicit computation
        std::tuple<Matrix6d, Vector6d, Vector6d> dynamic_parameters = inverse_dynamics_solver->getDynamicParameters(positions, velocities);
        Matrix6d inertia = std::get<0>(dynamic_parameters);
        Vector6d coriolis = std::get<1>(dynamic_parameters);
        Vector6d gravity = std::get<2>(dynamic_parameters);
        Vector6d friction = inverse_dynamics_solver->getFrictionVector(velocities);
        Vector6d computed_torques = inertia * accelerations + coriolis + gravity + friction;

        // Compare the torques with the ground truth
        const double ABS_ERROR = 1e-6;
        for (std::size_t j = 0; j < NUMBER_OF_JOINTS; ++j)
        {
          EXPECT_NEAR(torques(j), point.effort[j], ABS_ERROR) << "Torque for joint " << j + 1 << " is beyond tolerance at sample " << i;
          EXPECT_NEAR(computed_torques(j), point.effort[j], ABS_ERROR)
              << "Computed torque for joint " << j + 1 << " is beyond tolerance at sample " << i;
        }
      }
    }
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  rclcpp::init(argc, argv);
  int result = RUN_ALL_TESTS();
  SharedData::release();
  return result;
}
