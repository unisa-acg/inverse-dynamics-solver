# inverse_dynamics_interface_kdl

## Contents

This is an implementation of [`InverseDynamicsInterface`](../inverse_dynamics_interface/README.md) using the general-purpose KDL dynamics implementation based on [pluginlib](https://docs.ros.org/en/rolling/Tutorials/Beginner-Client-Libraries/Pluginlib.html).

It uses the [KDL parser](https://github.com/ros/kdl_parser/tree/rolling) to read a robot description from a parameter spawned by [xacro](https://github.com/ros/xacro/tree/ros2).
So, in order to use this library, this parameter must be passed via launch files.
Please refer to the [test section](#how-to-test), specifically to the [test launch files](#how-to-test), for an example, and to [the official guide](https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Launch-Main.html) to know how to pass parameters.

## How to build

To build this package, run the following instruction from the root of your colcon workspace:

```bash
colcon build --packages-up-to inverse_dynamics_interface_kdl
source install/setup.bash
```

## Demo

You can evaluate the dynamics using the [demo](../inverse_dynamics_interface/demo/evaluate_dynamics.cpp), currently configured in a launch file for the [UR10](./launch/evaluate_dynamics.launch.py) robot.
The demo reads a bag file containing a sequence of `sensor_msgs/msg/JointState` messages and, for each state, computes the corresponding torques according to the `InverseDynamicsInterfaceKDL` class, which are saved in another bag file.

### Run the demo

To launch the UR10 demo, run the following:

```bash
ros2 launch inverse_dynamics_interface_kdl evaluate_dynamics.launch.py
```

By default, the demo reads the [`ur10_exciting_trajectory.db3`](./bagfiles/ur10_exciting_trajectory.db3) bag file, and produces the output under the `ur10_exciting_trajectory_torques` folder (created under the current working directory), with the computed torques written on the `/torques` topic.
You can change this configuration with

```bash
ros2 launch inverse_dynamics_interface_kdl evaluate_dynamics.launch.py input_bag:=<my_bag_file> output_bag:=<my_output_folder> topic:=<my_output_topic>
```

### Visualize the results

Please refer to [the parent class documentation](../inverse_dynamics_interface/README.md#visualize-the-results) to visualize the results, i.e. the evaluation of joint torque signals on `input_bag`, stored in `output_bag`.

## How to test

This library is tested against simple planar 2R and 3R robots.
The kinematic description is taken from custom packages, [`planar_2r_description`](../planar_2r_description/README.md) and [`planar_3r_description`](../planar_3r_description/README.md).

The tests consist in checking that, given a fixed joint position and velocity state, the KDL interface returns the expected values for the dynamic components.
The expected values are not hardcoded, but extracted from formulas available in the following book:

> 'Robotics: modelling, planning and control' (2009) by B. Siciliano, L. Sciavicco, L. Villani, G. Oriolo, 1st ed., Springer, sections 2.9.1 and 7.3.2. DOI: [https://doi.org/10.1007/978-1-84628-642-1](https://doi.org/10.1007/978-1-84628-642-1)

To build and execute the test, run the following:

```bash
colcon test --packages-select inverse_dynamics_interface_kdl
```

To see the results, run the following:

```bash
colcon test-result --all --verbose
```

The expected output should be the following:

```text
build/inverse_dynamics_interface_kdl/Testing/20251111-1319/Test.xml: 2 tests, 0 errors, 0 failures, 0 skipped
build/inverse_dynamics_interface_kdl/test_results/inverse_dynamics_interface_kdl/test_test_kdl_interface_on_2r_planar.py.xunit.xml: 2 tests, 0 errors, 0 failures, 0 skipped
build/inverse_dynamics_interface_kdl/test_results/inverse_dynamics_interface_kdl/test_test_kdl_interface_on_3r_planar.py.xunit.xml: 2 tests, 0 errors, 0 failures, 0 skipped

Summary: 6 tests, 0 errors, 0 failures, 0 skipped
```

### Optional analysis

If you wish to see the INFO messages printed on console during the test, run the following:

```bash
colcon test --packages-select inverse_dynamics_interface_kdl --event-handlers console_cohesion+
```

The expected output should contain the following line:

```text
100% tests passed, 0 tests failed out of 2
```

### Comparison with Pinocchio

This test also assess that the torques computed with `getDynamicComponents` and `getExternalTorques` are equivalent to those computed with [`Pinocchio`](../inverse_dynamics_interface_pinocchio/README.md#comparison-with-kdl).

## Configuration

The interface can be configured with the following parameters, to be passed via the node parameters interface:

* `robot_description`: a string representing the URDF robot description;
* `root`: the root of the kinematic chain to solve the dynamics for
    * defaults to the first link in `robot_description`
* `tip`: the tip of the kinematic chain to solve the dynamics for
* `gravity`: a 3x1 vector of real numbers describing the gravity effect in `root` frame
    * defaults to `[0, 0, -9.81]`

The [test launch file](./test/test_kdl_interface_on_2r_planar.py) provides an example on how the class is initialized and configured.
In the following snippet, the user is choosing the interface's `root`, `tip`, and `gravity` parameters, and is passing the URDF `robot_description` to the node initializing the class.

```python
# Input arguments
parameters = {
    "robot_description": robot_description,  # String to be retrieved via xacro from the URDF
    "inverse_dynamics_interface_plugin_name": inverse_dynamics_interface_plugin_name,  # String to be chosen by the user
    "kdl.root": "base_link",
    "kdl.tip": "flange",
    "kdl.gravity": [0, -9.81, 0],
}

# The node to test
test_kdl_interface_on_2r_planar_node = Node(
    package="inverse_dynamics_interface_kdl",
    executable="kdl_interface_on_2r_planar_test",
    name="test_kdl_interface_on_2r_planar_node",
    parameters=[parameters],
    output="screen",
)
```

Consequently, the [node](./test/test_kdl_interface_on_2r_planar.cpp) retrieves the parameters...

```cpp
// Instantiate the node
rclcpp::NodeOptions node_options;
node_options.automatically_declare_parameters_from_overrides(true);
node_ = rclcpp::Node::make_shared("kdl_interface_on_2r_planar_test", node_options);
// Get robot_description parameter
robot_description_ = node->get_parameter_or<std::string>("robot_description", "");
// Load parameters
node->get_parameter("inverse_dynamics_interface_plugin_name", inverse_dynamics_interface_plugin_name_);
```

... loads the interface via `pluginlib`...

```cpp
// Initialize inverse dynamics interface class loader
loader = std::make_unique<InverseDynamicsInterfaceLoader>("inverse_dynamics_interface", "inverse_dynamics_interface::InverseDynamicsInterface");
// Load KDL inverse dynamics interface plugin
dynamics = loader->createUniqueInstance(inverse_dynamics_interface_plugin_name_);
```

... and initializes the interface:

```cpp
// Initialize inverse dynamics interface
dynamics->initialize(node->get_node_parameters_interface(), "kdl", robot_description_);  // or ...
dynamics->initialize(node->get_node_parameters_interface(), "kdl");
```

**Note 1:** the `kdl` namespace passed to `initialize` must be the same as the one chosen when configuring the `parameters` in the launch file.

**Note 2:** passing `robot_description_` to `initialize` is not mandatory, as it is retrieved by the node parameters interface as well.
