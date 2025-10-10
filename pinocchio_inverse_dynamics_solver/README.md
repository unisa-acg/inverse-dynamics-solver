# pinocchio_inverse_dynamics_solver

## Contents

This is an implementation of [`InverseDynamicsSolver`](../inverse_dynamics_solver/README.md) using the general-purpose KDL dynamics solver based on [pluginlib](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Pluginlib.html).

It uses the [Pinocchio library](https://gepettoweb.laas.fr/doc/stack-of-tasks/pinocchio/devel/doxygen-html/index.html) to read a robot description from a parameter spawned by [xacro](https://github.com/ros/xacro/tree/ros2).
So, in order to use this library, this parameter must be passed via launch files.
Please refer to the [test section](#how-to-test), specifically to the [test launch file](./test/test_pinocchio_inverse_dynamics_solver.py), for an example, and to [the official guide](https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Launch-Main.html) to know how to pass parameters.

## How to build

To build this package, run the following instruction from the root of your colcon workspace:

```bash
colcon build --packages-up-to pinocchio_inverse_dynamics_solver
source install/setup.bash
```

## Demo

You can evaluate the solver using the [demo](../inverse_dynamics_solver/demo/evaluate_solver.cpp), currently configured in a launch file for the [UR10](./launch/evaluate_solver_pinocchio_ur10.launch.py) robot.
The demo reads a bag file containing a sequence of `sensor_msgs/msg/JointState` messages and, for each state, computes the corresponding torques according to the `InverseDynamicsSolverPinocchio` solver, which are saved in another bag file.

### Run the demo

To launch the UR10 demo, run the following:

```bash
ros2 launch pinocchio_inverse_dynamics_solver evaluate_solver_pinocchio_ur10.launch.py
```

By default, the demo reads the [`ur10_exciting_trajectory.db3`](./bagfiles/ur10_exciting_trajectory.db3) bag file, and produces the output under the `ur10_exciting_trajectory_torques_pinocchio` folder (created under the current working directory), with the computed torques written on the `/torques` topic.
You can change this configuration with

```bash
ros2 launch pinocchio_inverse_dynamics_solver evaluate_solver_pinocchio_ur10.launch.py input_bag:=<my_bag_file> output_bag:=<my_output_folder> topic:=<my_output_topic>
```

### Visualize the results

Please refer to [the parent class documentation](../inverse_dynamics_solver/README.md#visualize-the-results) to visualize the results, i.e. the evaluation of joint torque signals on `input_bag`, stored in `output_bag`.

## How to test

This library is tested against a simulated UR10 robot.
The kinematic description is taken from UR's official package, [ur_description](https://github.com/UniversalRobots/Universal_Robots_ROS2_Description/tree/rolling).

The tests consist in checking that, given a fixed joint position and velocity state, the Pinocchio solver returns the expected values for the dynamic components.

To build and execute the test, run the following:

```bash
colcon test --packages-select pinocchio_inverse_dynamics_solver
```

To see the results, run the following:

```bash
colcon test-result --all --verbose
```

The expected output should be the following:

```text
build/pinocchio_inverse_dynamics_solver/Testing/20251010-0811/Test.xml: 1 test, 0 errors, 0 failures, 0 skipped
build/pinocchio_inverse_dynamics_solver/test_results/pinocchio_inverse_dynamics_solver/test_test_pinocchio_inverse_dynamics_solver.py.xunit.xml: 2 tests, 0 errors, 0 failures, 0 skipped

Summary: 3 tests, 0 errors, 0 failures, 0 skipped
```

### Optional analysis

If you wish to see the INFO messages printed on console during the test, run the following:

```bash
colcon test --packages-select pinocchio_inverse_dynamics_solver --event-handlers console_cohesion+
```

The expected output should contain the following line:

```text
100% tests passed, 0 tests failed out of 1
```

## Configuration

The solver can be configured with the following parameters, to be passed via the node parameters interface:

* `robot_description`: a string representing the URDF robot description;
* `tip`: the tip of the kinematic chain to solve the dynamics for
* `gravity`: a 3x1 vector of real numbers describing the gravity effect in `root` frame
    * defaults to `[0, 0, -9.81]`

The [test launch file](./test/test_pinocchio_inverse_dynamics_solver.py) provides an example on how the solver is initialized and configured.
In the following snippet, the user is choosing the solver's `tip` and `gravity` parameters, and is passing the URDF `robot_description` to the node initializing the solver.

```python
# Input arguments
parameters = {
    "robot_description": robot_description,  # String to be retrieved via xacro from the URDF
    "inverse_dynamics_solver_plugin_name": inverse_dynamics_solver_plugin_name,  # String to be chosen by the user
    "ids.tip": "tool0",
    "ids.gravity": [0, 0, -9.81],
}

# The node to test
test_pinocchio_inverse_dynamics_solver_node = Node(
    package="pinocchio_inverse_dynamics_solver",
    executable="pinocchio_inverse_dynamics_solver_test",
    name="test_pinocchio_inverse_dynamics_solver_node",
    parameters=[parameters],
    output="screen",
)
```

Consequently, the [node](./test/test_pinocchio_inverse_dynamics_solver.cpp) retrieves the parameters...

```cpp
// Instantiate the node
rclcpp::NodeOptions node_options;
node_options.automatically_declare_parameters_from_overrides(true);
node_ = rclcpp::Node::make_shared("pinocchio_inverse_dynamics_solver_test", node_options);
// Get robot_description parameter
robot_description_ = node_->get_parameter_or<std::string>("robot_description", "");
// Load parameters
node_->get_parameter("inverse_dynamics_solver_plugin_name", inverse_dynamics_solver_plugin_name_);
```

... loads the solver via `pluginlib`...

```cpp
// Initialize inverse dynamics solver class loader
inverse_dynamics_solver_loader_ =
    std::make_unique<InverseDynamicsSolverLoader>("inverse_dynamics_solver", "inverse_dynamics_solver::InverseDynamicsSolver");
// Load KDL inverse dynamics solver plugin
inverse_dynamics_solver_ = inverse_dynamics_solver_loader_->createUniqueInstance(inverse_dynamics_solver_plugin_name_);
```

... and initializes the solver:

```cpp
// Initialize inverse dynamics solver
inverse_dynamics_solver_->initialize(node_->get_node_parameters_interface(), "ids", robot_description_);  // or ...
inverse_dynamics_solver_->initialize(node_->get_node_parameters_interface(), "ids");
```

**Note 1:** the `ids` namespace passed to `initialize` must be the same as the one chosen when configuring the `parameters` in the launch file.

**Note 2:** passing `robot_description_` to `initialize` is not mandatory, as it is retrieved by the node parameters interface as well.
