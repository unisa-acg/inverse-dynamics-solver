# ur10_inverse_dynamics_solver

## Contents

This dynamics solver for the real UR10 robot is based on a model identified at current level by the following paper:

> V. Petrone, E. Ferrentino and P. Chiacchio, "The Dynamic Model of the UR10 Robot and Its ROS2 Integration," in IEEE Transactions on Industrial Informatics, doi: 10.1109/TII.2025.3534415.

The library [InverseDynamicsSolverUR10](./include/ur10_inverse_dynamics_solver/ur10_inverse_dynamics_solver.h) depends on the following files, automatically generated with MATLAB:

* [getCoriolisCurrents](./include/ur10_inverse_dynamics_solver/getCoriolisCurrents.h): given the 6X1 vector of positions and the 6X1 vector of velocities, both in joint space, it computes the 6x1 vector of currents related to Coriolis effects, expressed in `A`;
* [getCurrents](./include/ur10_inverse_dynamics_solver/getCurrents.h): given the 6X1 vector of positions, the 6X1 vector of velocities and the 6X1 vector of accelerations, all in joint space, it computes the 6x1 vector of currents without the friction effect, expressed in `A`.
* [getGravityCurrents](./include/ur10_inverse_dynamics_solver/getGravityCurrents.h): given the 6x1 vector of positions in joint space, it computes the 6x1 vector of currents due to gravity, expressed in `A`;
* [getInertiaCurrents](./include/ur10_inverse_dynamics_solver/getInertiaCurrents.h): given the 6x1 vector of positions in joint space, it computes the 6x6 inertia matrix, expressed in `A*s^2`;

The dynamics solver implements the [inverse_dynamics_solver::InverseDynamicsSolver](../inverse_dynamics_solver/README.md) class.
Since methods that output torques are expected by the parent, this plugin uses the previously discussed current-based methods, along with the motor gains, to implement the parent class' methods.

## How to build

To build this package, run the following from the root of your colcon workspace:

```bash
colcon build --packages-up-to ur10_inverse_dynamics_solver
source install/setup.bash
```

## Demo

You can evaluate the solver using the [demo](../inverse_dynamics_solver/demo/evaluate_solver.cpp), whose configuration for the UR10 robot is provided though a [launch file](./launch/evaluate_solver_ur10.launch.py).
The demo reads a bag file containing a sequence of `sensor_msgs/msg/JointState` messages and, for each state, computes the corresponding torques according to the `InverseDynamicsSolverUR10` solver, which are saved in another bag file.

### Run the demo

To launch the UR10 demo, run the following:

```bash
ros2 launch ur10_inverse_dynamics_solver evaluate_solver_ur10.launch.py
```

By default, the demo reads the [`ur10_exciting_trajectory.db3`](./bagfiles/ur10_exciting_trajectory.db3) bag file, and produces the output under the `ur10_exciting_trajectory_real_torques` folder (created under the current working directory), with the computed torques written on the `/torques` topic.
You can change this configuration with

```bash
ros2 launch ur10_inverse_dynamics_solver evaluate_solver_ur10.launch.py input_bag:=<my_bag_file> output_bag:=<my_output_folder> topic:=<my_output_topic>
```

### Visualize the results

Please refer to [the parent class documentation](../inverse_dynamics_solver/README.md#visualize-the-results) to visualize the results, i.e. the evaluation of joint torque signals on `input_bag`, stored in `output_bag`.

## How to test

The test consists in validating the solver against a trajectory, on which reference joint positions, velocities and accelerations are stored, and ground-truth joint efforts are specified.
The ground truth is computed with MATLAB, by using an estimated model in regressive form.
The test checks that this library computes the same values as the ground truth.

To build and execute the test, run the following:

```bash
colcon test --packages-select ur10_inverse_dynamics_solver
```

To see the results, run the following:

```bash
colcon test-result --all --verbose
```

The expected output is the following:

```text
build/ur10_inverse_dynamics_solver/Testing/20240510-0742/Test.xml: 1 test, 0 errors, 0 failures, 0 skipped
build/ur10_inverse_dynamics_solver/test_results/ur10_inverse_dynamics_solver/launch_test_ur10_inverse_dynamics_solver.launch.py.xunit.xml: 2 tests, 0 errors, 0 failures, 0 skipped

Summary: 3 tests, 0 errors, 0 failures, 0 skipped
```

### Optional analysis

If you wish to see the INFO messages printed on console during the test, run the following:

```bash
colcon test --packages-select ur10_inverse_dynamics_solver --event-handlers console_cohesion+
```

The expected output should contain the following line:

```text
100% tests passed, 0 tests failed out of 1
```

### Further details

The reference bag file [validation_trajectory.db3](./test/bagfiles/validation_trajectory.db3) was originally computed for ROS Noetic.
It was converted for ROS2 Humble with the `rosbags-convert` tool.
Given the `<ros1_bag_file>`, the following command has been launched to generate the ROS2 bag file:

```bash
rosbags-convert --src <ros1_bag_file>.bag --dst validation_trajectory/ --src-typestore ros1_noetic --dst-typestore ros2_humble
```

The output is then generated in the `validation_trajectory/` local folder, containing the new bag file and [metadata.yaml](./test/bagfiles/metadata.yaml).

**Note 1:** If you don't have `rosbags-convert` in your system, you can install it with

```bash
pip3 install rosbags>=0.9.11
```

**Note 2:** It is possible that `rosbags-convert` is not in your Python path by default.
However, you can launch its executable with

```bash
~/.local/bin/rosbags-convert --help
```

For more details about this tool, please see [this guide](https://docs.openvins.com/dev-ros1-to-ros2.html).

## Citation

If you find this work useful, please cite it as

```bibtex
@article{Petrone_2025,
    title={The Dynamic Model of the UR10 Robot and Its ROS2 Integration},
    ISSN={1941-0050},
    url={http://dx.doi.org/10.1109/tii.2025.3534415},
    DOI={10.1109/tii.2025.3534415},
    journal={IEEE Transactions on Industrial Informatics},
    publisher={Institute of Electrical and Electronics Engineers (IEEE)},
    author={Petrone, Vincenzo and Ferrentino, Enrico and Chiacchio, Pasquale},
    year={2025},
    pages={1–11}
}
```
