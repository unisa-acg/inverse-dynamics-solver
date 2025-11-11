/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   test_kdl_ids_on_2r_planar.cpp
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Oct 29, 2025
 *
 * This is a test for InverseDynamicsSolverKDL on the 2R planar robot.
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
#include <inverse_dynamics_solver/inverse_dynamics_solver.hpp>
#include <inverse_dynamics_solver/exceptions.hpp>

// This class shares parameters and data across all tests
class SharedData
{
  typedef pluginlib::ClassLoader<inverse_dynamics_solver::InverseDynamicsSolver> InverseDynamicsSolverLoader;
  friend class InverseDynamicsSolverKDLTest;

  const char* ROBOT_DESCRIPTION_PARAM = "robot_description";

  std::shared_ptr<rclcpp::Node> node_;
  std::string inverse_dynamics_solver_plugin_name_;
  std::vector<double> link_lengths_;
  std::vector<double> com_;
  std::vector<double> mass_;
  std::vector<double> inertia_;
  std::vector<double> gravity_;
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
    node_ = rclcpp::Node::make_shared("kdl_ids_on_2r_planar_test", node_options);

    // Get robot_description parameter
    robot_description_ = node_->get_parameter_or<std::string>(ROBOT_DESCRIPTION_PARAM, "");

    // Load parameters
    ASSERT_TRUE(node_->get_parameter("inverse_dynamics_solver_plugin_name", inverse_dynamics_solver_plugin_name_));
    ASSERT_TRUE(node_->get_parameter("link_lengths", link_lengths_));
    ASSERT_TRUE(node_->get_parameter("com", com_));
    ASSERT_TRUE(node_->get_parameter("mass", mass_));
    ASSERT_TRUE(node_->get_parameter("inertia", inertia_));
    ASSERT_TRUE(node_->get_parameter("kdl.gravity", gravity_));

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
    link_lengths = data.link_lengths_;
    com = data.com_;
    mass = data.mass_;
    inertia = data.inertia_;
    gravity = data.gravity_;
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
  std::vector<double> link_lengths;
  std::vector<double> com;
  std::vector<double> mass;
  std::vector<double> inertia;
  std::vector<double> gravity;
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
 * @brief verifies that the solver can be initialized when the root link is empty
 */
TEST_F(InverseDynamicsSolverKDLTest, TestInitializationWithEmptyRoot)
{
  std::string root = node->get_parameter("empty_root.root").as_string();
  std::string tip = node->get_parameter("empty_root.tip").as_string();
  RCLCPP_INFO_STREAM(node->get_logger(),
                     "Initializing " << inverse_dynamics_solver_plugin_name << " with root '" << root << "' and tip '" << tip << "'.");
  ASSERT_NO_THROW(inverse_dynamics_solver->initialize(node->get_node_parameters_interface(), "empty_root"));
  RCLCPP_INFO_STREAM(node->get_logger(), inverse_dynamics_solver_plugin_name << " initialized.");
}

// Test 4
/**
 * @brief verifies that the solver can not be initialized when the tip link is empty
 */
TEST_F(InverseDynamicsSolverKDLTest, FailedInitialization)
{
  std::string root = node->get_parameter("empty_tip.root").as_string();
  std::string tip = node->get_parameter("empty_tip.tip").as_string();
  RCLCPP_INFO_STREAM(node->get_logger(),
                     "Initializing " + inverse_dynamics_solver_plugin_name << " with root '" << root << "' and tip '" << tip << "'.");
  ASSERT_THROW(inverse_dynamics_solver->initialize(node->get_node_parameters_interface(), "empty_tip"),
               inverse_dynamics_solver::ParameterUninitializedException);
  RCLCPP_ERROR_STREAM(node->get_logger(), inverse_dynamics_solver_plugin_name << " not initialized.");
}

// Test 5
/**
 * @brief verifies that method getDynamicParameters returns the expected values
 */
TEST_F(InverseDynamicsSolverKDLTest, TestDynamicParameters)
{
  // Number of joints
  const unsigned short int N_JOINTS = 2;

  // Joint states the dynamics will be evaluated on
  Eigen::VectorXd q(N_JOINTS);
  Eigen::VectorXd dq(N_JOINTS);
  Eigen::VectorXd ddq(N_JOINTS);

  // Ground-truth for dynamic components
  Eigen::MatrixXd B_ref(N_JOINTS, N_JOINTS);
  Eigen::MatrixXd C_ref(N_JOINTS, N_JOINTS);
  Eigen::VectorXd g_ref(N_JOINTS);
  Eigen::VectorXd torque_ref(N_JOINTS);

  // Kinematic parameters
  double a1 = link_lengths[0];
  double l1 = com[0];
  double l2 = com[1];
  double m1 = mass[0];
  double m2 = mass[1];
  double I1 = inertia[0];
  double I2 = inertia[1];
  double G = -gravity[1];

  // Initialize joint positions
  q(0) = M_PI_4;
  q(1) = -M_PI / 8;
  double q1 = q(0);
  double q2 = q(1);

  // Initialize joint velocities
  dq(0) = -0.5;
  dq(1) = 0.25;
  double dq1 = dq(0);
  double dq2 = dq(1);

  // Initialize joint accelerations
  ddq(0) = 0.25;
  ddq(1) = -0.125;
  double ddq1 = ddq(0);
  double ddq2 = ddq(1);

  // Initialize inertia reference
  B_ref(0, 0) = I1 + m1 * pow(l1, 2) + I2 + m2 * (pow(a1, 2) + pow(l2, 2) + 2 * a1 * l2 * cos(q2));
  B_ref(0, 1) = I2 + m2 * (pow(l2, 2) + a1 * l2 * cos(q2));
  B_ref(1, 0) = B_ref(0, 1);
  B_ref(1, 1) = I2 + m2 * pow(l2, 2);

  // Initialize Coriolis reference
  double h = -m2 * a1 * l2 * sin(q2);
  C_ref(0, 0) = h * dq2;
  C_ref(0, 1) = h * (dq1 + dq2);
  C_ref(1, 0) = -h * dq1;
  C_ref(1, 1) = 0.0;
  Eigen::VectorXd c_ref = C_ref * dq;

  // Initialize gravity reference
  g_ref(0) = (m1 * l1 + m2 * a1) * G * cos(q1) + m2 * l2 * G * cos(q1 + q2);
  g_ref(1) = m2 * l2 * G * cos(q1 + q2);

  // Initialize torque reference
  torque_ref(0) = (I1 + m1 * pow(l1, 2) + I2 + m2 * (pow(a1, 2) + pow(l2, 2) + 2 * a1 * l2 * cos(q2))) * ddq1 +
                  (I2 + m2 * (pow(l2, 2) + a1 * l2 * cos(q2))) * ddq2 - 2 * m2 * a1 * l2 * sin(q2) * dq1 * dq2 -
                  m2 * a1 * l2 * sin(q2) * pow(dq2, 2) + (m1 * l1 + m2 * a1) * G * cos(q1) + m2 * l2 * G * cos(q1 + q2);
  torque_ref(1) = (I2 + m2 * (pow(l2, 2) + a1 * l2 * cos(q2))) * ddq1 + (I2 + m2 * pow(l2, 2)) * ddq2 + m2 * a1 * l2 * sin(q2) * pow(dq1, 2) +
                  m2 * l2 * G * cos(q1 + q2);

  // Evaluate the solver
  initializeSolver();
  std::tuple<Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> dyn_params = inverse_dynamics_solver->getDynamicParameters(q, dq);
  Eigen::MatrixXd B = std::get<0>(dyn_params);
  Eigen::MatrixXd c = std::get<1>(dyn_params);
  Eigen::MatrixXd g = std::get<2>(dyn_params);
  Eigen::VectorXd torque = inverse_dynamics_solver->getTorques(q, dq, ddq);

  // Test the solver
  const double ABS_ERROR = 1e-8;
  for (unsigned int i = 0; i < N_JOINTS; i++)
  {
    for (unsigned int j = 0; j < N_JOINTS; j++)
    {
      EXPECT_NEAR(B(i, j), B_ref(i, j), ABS_ERROR) << "Element (" << i << "," << j << ") of inertia matrix is beyond tolerance";
    }
    EXPECT_NEAR(c(i), c_ref(i), ABS_ERROR) << "Element " << i << " of Coriolis vector is beyond tolerance";
    EXPECT_NEAR(g(i), g_ref(i), ABS_ERROR) << "Element " << i << " of gravity vector is beyond tolerance";
    EXPECT_NEAR(torque(i), torque_ref(i), ABS_ERROR) << "Element " << i << " of torque vector is beyond tolerance";
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
