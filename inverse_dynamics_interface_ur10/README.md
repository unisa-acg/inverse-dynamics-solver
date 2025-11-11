# inverse_dynamics_interface_ur10

## Contents

This dynamics interface for the real UR10 robot is based on a model identified at current level by the following paper:

> V. Petrone, E. Ferrentino and P. Chiacchio, "The Dynamic Model of the UR10 Robot and Its ROS2 Integration," in IEEE Transactions on Industrial Informatics, doi: 10.1109/TII.2025.3534415.

The library [InverseDynamicsInterfaceUR10](./include/inverse_dynamics_interface_ur10/inverse_dynamics_interface_ur10.hpp) depends on the following files, automatically generated with MATLAB:

* [getCoriolisCurrents](./include/inverse_dynamics_interface_ur10/getCoriolisCurrents.hpp): given the 6X1 vector of positions and the 6X1 vector of velocities, both in joint space, it computes the 6x1 vector of currents related to Coriolis effects, expressed in `A`;
* [getCurrents](./include/inverse_dynamics_interface_ur10/getCurrents.hpp): given the 6X1 vector of positions, the 6X1 vector of velocities and the 6X1 vector of accelerations, all in joint space, it computes the 6x1 vector of currents without the friction effect, expressed in `A`.
* [getGravityCurrents](./include/inverse_dynamics_interface_ur10/getGravityCurrents.hpp): given the 6x1 vector of positions in joint space, it computes the 6x1 vector of currents due to gravity, expressed in `A`;
* [getInertiaCurrents](./include/inverse_dynamics_interface_ur10/getInertiaCurrents.hpp): given the 6x1 vector of positions in joint space, it computes the 6x6 inertia matrix, expressed in `A*s^2`;

The dynamics interface implements the [inverse_dynamics_interface::InverseDynamicsInterface](../inverse_dynamics_interface/README.md) class.
Since methods that output torques are expected by the parent, this plugin uses the previously discussed current-based methods, along with the motor gains, to implement the parent class' methods.

## How to build

To build this package, run the following from the root of your colcon workspace:

```bash
colcon build --packages-up-to inverse_dynamics_interface_ur10
source install/setup.bash
```

## Demo

You can evaluate the dynamics using the [demo](../inverse_dynamics_interface/demo/evaluate_dynamics.cpp), whose configuration for the UR10 robot is provided though a [launch file](./launch/evaluate_dynamics.launch.py).
The demo reads a bag file containing a sequence of `sensor_msgs/msg/JointState` messages and, for each state, computes the corresponding torques according to the `InverseDynamicsInterfaceUR10` class, which are saved in another bag file.

### Run the demo

To launch the UR10 demo, run the following:

```bash
ros2 launch inverse_dynamics_interface_ur10 evaluate_dynamics.launch.py
```

By default, the demo reads the [`ur10_exciting_trajectory.db3`](./bagfiles/ur10_exciting_trajectory.db3) bag file, and produces the output under the `ur10_exciting_trajectory_real_torques` folder (created under the current working directory), with the computed torques written on the `/torques` topic.
You can change this configuration with

```bash
ros2 launch inverse_dynamics_interface_ur10 evaluate_dynamics.launch.py input_bag:=<my_bag_file> output_bag:=<my_output_folder> topic:=<my_output_topic>
```

### Visualize the results

Please refer to [the parent class documentation](../inverse_dynamics_interface/README.md#visualize-the-results) to visualize the results, i.e. the evaluation of joint torque signals on `input_bag`, stored in `output_bag`.

## How to test

The test consists in validating the dynamics against a trajectory, on which reference joint positions, velocities and accelerations are stored, and ground-truth joint efforts are specified.
The ground truth is computed with MATLAB, by using an estimated model in regressive form.
The test checks that this library computes the same values as the ground truth.

To build and execute the test, run the following:

```bash
colcon test --packages-select inverse_dynamics_interface_ur10
```

To see the results, run the following:

```bash
colcon test-result --all --verbose
```

The expected output is the following:

```text
build/inverse_dynamics_interface_ur10/Testing/20240510-0742/Test.xml: 1 test, 0 errors, 0 failures, 0 skipped
build/inverse_dynamics_interface_ur10/test_results/inverse_dynamics_interface_ur10/launch_test_inverse_dynamics_interface_ur10.launch.py.xunit.xml: 2 tests, 0 errors, 0 failures, 0 skipped

Summary: 3 tests, 0 errors, 0 failures, 0 skipped
```

### Optional analysis

If you wish to see the INFO messages printed on console during the test, run the following:

```bash
colcon test --packages-select inverse_dynamics_interface_ur10 --event-handlers console_cohesion+
```

The expected output should contain the following line:

```text
100% tests passed, 0 tests failed out of 1
```

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
