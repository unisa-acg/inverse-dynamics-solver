/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   test_pinocchio_ids_on_3r_planar.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Oct 29, 2025
 *
 * This is a test for InverseDynamicsInterfacePinocchio on the 3R
 * planar robot.
 *
 * -------------------------------------------------------------------
 */

// ROS2
#include <rclcpp/rclcpp.hpp>

// PluginLib
#include <pluginlib/class_loader.hpp>

// Gtest
#include <gtest/gtest.h>

// Inverse Dynamics Interface
#include <inverse_dynamics_interface/inverse_dynamics_interface.hpp>
#include <inverse_dynamics_interface/exceptions.hpp>

// This class shares parameters and data across all tests
class SharedData
{
  typedef pluginlib::ClassLoader<inverse_dynamics_interface::InverseDynamicsInterface> InverseDynamicsInterfaceLoader;
  friend class InverseDynamicsInterfacePinocchio;

  const char* ROBOT_DESCRIPTION_PARAM = "robot_description";

  std::shared_ptr<rclcpp::Node> node_;
  std::string inverse_dynamics_interface_plugin_name_;
  std::vector<double> link_lengths_;
  std::string robot_description_;
  std::unique_ptr<InverseDynamicsInterfaceLoader> loader_;

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
    node_ = rclcpp::Node::make_shared("pinocchio_ids_on_3r_planar_test", node_options);

    // Get robot_description parameter
    robot_description_ = node_->get_parameter_or<std::string>(ROBOT_DESCRIPTION_PARAM, "");

    // Load parameters
    ASSERT_TRUE(node_->get_parameter("inverse_dynamics_interface_plugin_name", inverse_dynamics_interface_plugin_name_));
    ASSERT_TRUE(node_->get_parameter("link_lengths", link_lengths_));

    // Initialize inverse dynamics interface class loader
    loader_ = std::make_unique<InverseDynamicsInterfaceLoader>("inverse_dynamics_interface", "inverse_dynamics_interface::InverseDynamicsInterface");
    ASSERT_TRUE(bool(loader_)) << "Failed to instantiate ClassLoader<InverseDynamicsInterface>";
  }

public:
  pluginlib::UniquePtr<inverse_dynamics_interface::InverseDynamicsInterface> createUniqueInstance(const std::string& name) const
  {
    return loader_->createUniqueInstance(name);
  }

  static const SharedData& instance()
  {
    static SharedData instance;
    return instance;
  }
  static void release()
  {
    SharedData& shared = const_cast<SharedData&>(instance());
    shared.loader_.reset();
  }
};

// This class implements the tests
class InverseDynamicsInterfacePinocchio : public ::testing::Test
{
protected:
  void operator=(const SharedData& data)
  {
    node = data.node_;
    inverse_dynamics_interface_plugin_name = data.inverse_dynamics_interface_plugin_name_;
    link_lengths = data.link_lengths_;
    robot_description = data.robot_description_;
  }

  void SetUp() override
  {
    *this = SharedData::instance();

    // Load Pinocchio inverse dynamics interface plugin
    RCLCPP_INFO_STREAM(node->get_logger(), "Loading " << inverse_dynamics_interface_plugin_name);
    dynamics = SharedData::instance().createUniqueInstance(inverse_dynamics_interface_plugin_name);
    ASSERT_TRUE(bool(dynamics)) << "Failed to load plugin: " << inverse_dynamics_interface_plugin_name;
    RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_interface_plugin_name << " loaded.");
  }

public:
  void initializeInterface(const std::string& robot_description_param = "")
  {
    if (robot_description_param.empty())
    {
      ASSERT_NO_THROW(dynamics->initialize(node->get_node_parameters_interface(), "ids"));
    }
    else
    {
      ASSERT_NO_THROW(dynamics->initialize(node->get_node_parameters_interface(), "ids", robot_description_param));
    }
    RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_interface_plugin_name << " initialized.");
  }

  rclcpp::Node::SharedPtr node;
  std::string inverse_dynamics_interface_plugin_name;
  std::vector<double> link_lengths;
  std::string robot_description;
  pluginlib::UniquePtr<inverse_dynamics_interface::InverseDynamicsInterface> dynamics;
};

// Tests
// Test 1
/**
 * @brief verifies that the interface can be initialized when the robot description is passed as an input argument
 */
TEST_F(InverseDynamicsInterfacePinocchio, TestInitializationFromInputArgument)
{
  initializeInterface(robot_description);
}

// Test 2
/**
 * @brief verifies that the interface can be initialized when the robot description is passed through the node parameters interface
 */
TEST_F(InverseDynamicsInterfacePinocchio, TestInitializationFromNodeParametersInterface)
{
  initializeInterface();
}

// Test 3
/**
 * @brief verifies that the interface can be initialized when the root link is empty
 */
TEST_F(InverseDynamicsInterfacePinocchio, TestInitializationWithEmptyRoot)
{
  std::string root = node->get_parameter("empty_root.root").as_string();
  std::string tip = node->get_parameter("empty_root.tip").as_string();
  RCLCPP_INFO_STREAM(node->get_logger(),
                     "Initializing " << inverse_dynamics_interface_plugin_name << " with root '" << root << "' and tip '" << tip << "'.");
  ASSERT_NO_THROW(dynamics->initialize(node->get_node_parameters_interface(), "empty_root"));
  RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_interface_plugin_name << " initialized.");
}

// Test 4
/**
 * @brief verifies that the interface can not be initialized when the tip link is empty
 */
TEST_F(InverseDynamicsInterfacePinocchio, FailedInitialization)
{
  std::string root = node->get_parameter("empty_tip.root").as_string();
  std::string tip = node->get_parameter("empty_tip.tip").as_string();
  RCLCPP_INFO_STREAM(node->get_logger(),
                     "Initializing " + inverse_dynamics_interface_plugin_name << " with root '" << root << "' and tip '" << tip << "'.");
  ASSERT_THROW(dynamics->initialize(node->get_node_parameters_interface(), "empty_tip"), inverse_dynamics_interface::ParameterUninitializedException);
  RCLCPP_ERROR_STREAM(node->get_logger(), inverse_dynamics_interface_plugin_name << " not initialized.");
}

// Test 5
/**
 * @brief verifies that method getJacobian returns the expected values
 */
TEST_F(InverseDynamicsInterfacePinocchio, getJacobian)
{
  // Number of joints
  const unsigned short int N_JOINTS = 3;

  // Joint states the jacobian will be evaluated on
  Eigen::VectorXd q(N_JOINTS);
  Eigen::VectorXd h(6);

  // Jacobian reference
  Eigen::MatrixXd jacobian_ref = Eigen::MatrixXd::Zero(6, N_JOINTS);

  // Kinematic parameters
  double a1 = link_lengths[0];
  double a2 = link_lengths[1];
  double a3 = link_lengths[2];

  // Initialize joint positions
  q(0) = 1.2947;
  q(1) = 0.2911;
  q(2) = -1.2749;
  double q1 = q(0);
  double q2 = q(1);
  double q3 = q(2);

  // Initialize external wrench
  h(0) = 1.11;
  h(1) = 2.22;
  h(2) = 3.33;
  h(3) = 4.44;
  h(4) = 5.55;
  h(5) = 6.66;

  // Initialize Jacobian reference
  jacobian_ref(0, 0) = -a1 * sin(q1) - a2 * sin(q1 + q2) - a3 * sin(q1 + q2 + q3);
  jacobian_ref(0, 1) = -a2 * sin(q1 + q2) - a3 * sin(q1 + q2 + q3);
  jacobian_ref(0, 2) = -a3 * sin(q1 + q2 + q3);
  jacobian_ref(1, 0) = a1 * cos(q1) + a2 * cos(q1 + q2) + a3 * cos(q1 + q2 + q3);
  jacobian_ref(1, 1) = a2 * cos(q1 + q2) + a3 * cos(q1 + q2 + q3);
  jacobian_ref(1, 2) = a3 * cos(q1 + q2 + q3);
  jacobian_ref.row(5) = Eigen::VectorXd::Ones(N_JOINTS);

  // Initialize external torques reference
  Eigen::VectorXd torques_ref = jacobian_ref.transpose() * h;

  // Get the Jacobian
  initializeInterface();
  Eigen::MatrixXd jacobian = dynamics->getJacobian(q);
  Eigen::VectorXd torques = dynamics->getExternalTorques(q, h);

  // Test the dynamics
  const double ABS_ERROR = 1e-8;
  for (unsigned int j = 0; j < N_JOINTS; j++)
  {
    for (unsigned int i = 0; i < 6; i++)
    {
      EXPECT_NEAR(jacobian(i, j), jacobian_ref(i, j), ABS_ERROR) << "Element (" << i << "," << j << ") of Jacobian matrix is beyond tolerance";
    }
    EXPECT_NEAR(torques(j), torques_ref(j), ABS_ERROR) << "Element " << j << " of external torques is beyond tolerance";
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
