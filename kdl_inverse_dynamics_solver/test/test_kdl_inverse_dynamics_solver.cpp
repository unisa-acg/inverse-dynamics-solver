/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   test_kdl_inverse_dynamics_solver.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    May 2, 2024
 *
 * This is a test for InverseDynamicsSolverKDL.
 *
 * -------------------------------------------------------------------
 */

// ROS2
#include <rclcpp/rclcpp.hpp>

// PluginLib
#include <pluginlib/class_loader.hpp>

// Gtest
#include <gtest/gtest.h>

// Inverse Dynamics Solver
#include <inverse_dynamics_solver/inverse_dynamics_solver.h>

// This class shares parameters and data across all tests
class SharedData
{
  typedef pluginlib::ClassLoader<inverse_dynamics_solver::InverseDynamicsSolver> InverseDynamicsSolverLoader;
  friend class InverseDynamicsSolverKDLTest;

  const char* ROBOT_DESCRIPTION_PARAM = "robot_description";

  std::shared_ptr<rclcpp::Node> node_;
  std::string inverse_dynamics_solver_plugin_name_;
  std::string robot_description_;
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
    node_ = rclcpp::Node::make_shared("kdl_inverse_dynamics_solver_test", node_options);

    // Get robot_description parameter
    robot_description_ = node_->get_parameter_or<std::string>(ROBOT_DESCRIPTION_PARAM, "");

    // Load parameters
    ASSERT_TRUE(node_->get_parameter("inverse_dynamics_solver_plugin_name", inverse_dynamics_solver_plugin_name_));

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
class InverseDynamicsSolverKDLTest : public ::testing::Test
{
protected:
  void operator=(const SharedData& data)
  {
    node = data.node_;
    inverse_dynamics_solver_plugin_name = data.inverse_dynamics_solver_plugin_name_;
    robot_description = data.robot_description_;
  }

  void SetUp() override
  {
    *this = SharedData::instance();

    // Load KDL inverse dynamics solver plugin
    RCLCPP_INFO_STREAM(node->get_logger(), "Loading " << inverse_dynamics_solver_plugin_name);
    inverse_dynamics_solver = SharedData::instance().createUniqueInstance(inverse_dynamics_solver_plugin_name);
    ASSERT_TRUE(bool(inverse_dynamics_solver)) << "Failed to load plugin: " << inverse_dynamics_solver_plugin_name;
    RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_solver_plugin_name << " loaded.");
  }

public:
  void initializeSolver(const std::string& robot_description_param = "")
  {
    if (robot_description_param.empty())
    {
      ASSERT_NO_THROW(inverse_dynamics_solver->initialize(node->get_node_parameters_interface(), "kdl"));
    }
    else
    {
      ASSERT_NO_THROW(inverse_dynamics_solver->initialize(node->get_node_parameters_interface(), "kdl", robot_description_param));
    }
    RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_solver_plugin_name << " initialized.");
  }

  rclcpp::Node::SharedPtr node;
  std::string inverse_dynamics_solver_plugin_name;
  std::string robot_description;
  pluginlib::UniquePtr<inverse_dynamics_solver::InverseDynamicsSolver> inverse_dynamics_solver;
};

// Tests
// Test 1
/**
 * @brief verifies that the solver can be initialized when the robot description is passed as an input argument
 */
TEST_F(InverseDynamicsSolverKDLTest, TestInitializationFromInputArgument)
{
  initializeSolver(robot_description);
}

// Test 2
/**
 * @brief verifies that the solver can be initialized when the robot description is passed through the node parameters interface
 */
TEST_F(InverseDynamicsSolverKDLTest, TestInitializationFromNodeParametersInterface)
{
  initializeSolver();
}

// Test 3
/**
 * @brief verifies that method getDynamicParameters returns the expected values
 */
TEST_F(InverseDynamicsSolverKDLTest, TestDynamicParameters)
{
  // Number of joints
  const unsigned short int N_JOINTS = 6;

  // Dynamic components references
  Eigen::MatrixXd inertia_ref(N_JOINTS, N_JOINTS);
  Eigen::VectorXd coriolis_ref(N_JOINTS);
  Eigen::VectorXd gravity_ref(N_JOINTS);

  // Joint states the dynamics will be evaluated on
  Eigen::VectorXd joint_positions(N_JOINTS);
  Eigen::VectorXd joint_velocities(N_JOINTS);

  // Initializing joint positions
  joint_positions(0) = 1.2947;
  joint_positions(1) = 0.2911;
  joint_positions(2) = -1.2749;
  joint_positions(3) = -2.3696;
  joint_positions(4) = -2.7176;
  joint_positions(5) = 0.7307;

  // Initializing joint velocities
  joint_velocities(0) = 0.2541;
  joint_velocities(1) = -0.0215;
  joint_velocities(2) = 0.0271;
  joint_velocities(3) = 0.0000;
  joint_velocities(4) = -0.0319;
  joint_velocities(5) = -0.0082;

  // Reference for inertia matrix
  inertia_ref(0, 0) = 7.9568758917431666;
  inertia_ref(0, 1) = -0.15356653813893528;
  inertia_ref(0, 2) = -0.45223815924492533;
  inertia_ref(0, 3) = -0.04274852903377474;
  inertia_ref(0, 4) = 0.017768956060114485;
  inertia_ref(0, 5) = 0.000029405942705745;
  inertia_ref(1, 0) = inertia_ref(0, 1);
  inertia_ref(1, 1) = 8.4360889306976752;
  inertia_ref(1, 2) = 3.1238160066785405;
  inertia_ref(1, 3) = 0.089001667454824171;
  inertia_ref(1, 4) = 0.011606396483416548;
  inertia_ref(1, 5) = -0.00030989423097216068;
  inertia_ref(2, 0) = inertia_ref(0, 2);
  inertia_ref(2, 1) = inertia_ref(1, 2);
  inertia_ref(2, 2) = 2.4987253226594062;
  inertia_ref(2, 3) = 0.16293116855410714;
  inertia_ref(2, 4) = 0.027781234621060101;
  inertia_ref(2, 5) = -0.00030989423097216068;
  inertia_ref(3, 0) = inertia_ref(0, 3);
  inertia_ref(3, 1) = inertia_ref(1, 3);
  inertia_ref(3, 2) = inertia_ref(2, 3);
  inertia_ref(3, 3) = 0.034761083598807779;
  inertia_ref(3, 4) = 0.0058899062997593166;
  inertia_ref(3, 5) = -0.00030989423097216068;
  inertia_ref(4, 0) = inertia_ref(0, 4);
  inertia_ref(4, 1) = inertia_ref(1, 4);
  inertia_ref(4, 2) = inertia_ref(2, 4);
  inertia_ref(4, 3) = inertia_ref(3, 4);
  inertia_ref(4, 4) = 0.0048731364912810386;
  inertia_ref(4, 5) = 0.0;
  inertia_ref(5, 0) = inertia_ref(0, 5);
  inertia_ref(5, 1) = inertia_ref(1, 5);
  inertia_ref(5, 2) = inertia_ref(2, 5);
  inertia_ref(5, 3) = inertia_ref(3, 5);
  inertia_ref(5, 4) = inertia_ref(4, 5);
  inertia_ref(5, 5) = 0.00034000000000000002;

  // Reference for Coriolis vector
  coriolis_ref(0) = 0.026805336072946623;
  coriolis_ref(1) = -0.098732105348253413;
  coriolis_ref(2) = -0.20563364273954066;
  coriolis_ref(3) = -0.016956328985455512;
  coriolis_ref(4) = -0.0032321654684497785;
  coriolis_ref(5) = -0.0000005155190684466;

  // Reference for gravity vector
  gravity_ref(0) = 0.0;
  gravity_ref(1) = -98.259559688518962;
  gravity_ref(2) = -20.91035165315413;
  gravity_ref(3) = 0.37230391574247756;
  gravity_ref(4) = 0.11308941822386981;
  gravity_ref(5) = 0.0;

  // Test the solver
  initializeSolver();
  std::tuple<Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> dyn_params =
      inverse_dynamics_solver->getDynamicParameters(joint_positions, joint_velocities);
  const double ABS_ERROR = 1e-8;
  for (unsigned int i = 0; i < N_JOINTS; i++)
  {
    for (unsigned int j = 0; j < N_JOINTS; j++)
    {
      EXPECT_NEAR(std::get<0>(dyn_params)(i, j), inertia_ref(i, j), ABS_ERROR)
          << "Element (" << i << "," << j << ") of inertia matrix is beyond tolerance";
    }
    EXPECT_NEAR(std::get<1>(dyn_params)(i), coriolis_ref(i), ABS_ERROR) << "Element " << i << " of Coriolis vector is beyond tolerance";
    EXPECT_NEAR(std::get<2>(dyn_params)(i), gravity_ref(i), ABS_ERROR) << "Element " << i << " of gravity vector is beyond tolerance";
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
