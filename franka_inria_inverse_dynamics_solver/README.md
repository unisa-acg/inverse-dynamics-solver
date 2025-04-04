# franka_inria_inverse_dynamics_solver

## Contents

This dynamics solver for the real Franka Emika (FER) robot is based on a model identified by the following paper:
> C. Gaz, M. Cognetti, A. Oliva, P. Robuffo Giordano, and A. De Luca, "Dynamic Identification of the Franka Emika Panda Robot With Retrieval of Feasible Parameters Using Penalty-Based Optimization," IEEE Robotics and Automation Letters, vol. 4, no. 4, pp. 4147-4154, Oct. 2019, doi: 10.1109/lra.2019.2931248.

The group at INRIA provided the library for the computation of the dynamic parameters, composed by four header files (one per function) and several source files with different implementations.
On top of these, the library [InverseDynamicsSolverFrankaInria](./include/franka_inria_inverse_dynamics_solver/franka_inria_inverse_dynamics_solver.h) has been developed, to include the following files:

* [`get_CoriolisMatrix.h`](./include/franka_inria_inverse_dynamics_solver/get_CoriolisMatrix.h): given the 7X1 vector of positions and the 7X1 vector of velocities, both in joint space, it computes the 7x7 matrix of torques related to centrifugal and Coriolis effects;
    * [`get_CoriolisMatrix_old.cpp`](./src/get_CoriolisMatrix_old.cpp): computes the Coriolis matrix by using temporary variables to store intermediate results of the computation;
        * This function is not actually needed by [the library implementation](./src/franka_inria_inverse_dynamics_solver.cpp), and is kept for legacy purposes only;
    * [`get_CoriolisMatrix.cpp`](./src/get_CoriolisMatrix.cpp): computes the Coriolis matrix directly, without using intermediate variables;
* [`get_FrictionTorque.h`](./include/franka_inria_inverse_dynamics_solver/get_FrictionTorque.h): given the 7X1 vector of velocities, it computes the 7x1 vector of torques due to friction;
* [`get_GravityVector.h`](./include/franka_inria_inverse_dynamics_solver/get_GravityVector.h): given the 7x1 vector of positions in joint space, it computes the 7x1 vector of torques due to gravity;
* [`get_MassMatrix.h`](./include/franka_inria_inverse_dynamics_solver/get_MassMatrix.h): given the 7x1 vector of positions in joint space, it computes the 7x7 inertia matrix.
    * [`get_MassMatrix.cpp`](./src/get_MassMatrix.cpp): computes the inertia matrix by using temporary variables to store intermediate results of the computation;
        * This function is not actually needed by [the library implementation](./src/franka_inria_inverse_dynamics_solver.cpp), and is kept for legacy purposes only;
    * [`get_MassMatrix_parziale.cpp`](./src/get_MassMatrix_parziale.cpp): computes the inertia matrix directly, without using intermediate variables.

The dynamics solver implements the [inverse_dynamics_solver::InverseDynamicsSolver](../inverse_dynamics_solver/README.md) class.

## How to build

To build this package, run the following from the root of your colcon workspace:

```bash
colcon build --packages-up-to franka_inria_inverse_dynamics_solver
source install/setup.bash
```

## Demo

You can evaluate the solver using the [demo](../inverse_dynamics_solver/demo/evaluate_solver.cpp), currently configured in a [launch file](./launch/evaluate_solver_franka.launch.py).
The demo reads a bag file containing a sequence of `sensor_msgs/msg/JointState` messages and, for each state, computes the corresponding torques according to the `InverseDynamicsSolverFrankaInria` solver, which are saved in another bag file.

### Run the demo

To launch the demo, run the following:

```bash
ros2 launch franka_inria_inverse_dynamics_solver evaluate_solver_franka.launch.py
```

By default, the demo reads the [`panda_exciting_trajectory.db3`](./bagfiles/panda_exciting_trajectory.db3) bag file, and produces the output under the `panda_exciting_trajectory_real_torques` folder (created under the current working directory), with the computed torques written to the `/torques` topic.
You can change this configuration with

```bash
ros2 launch franka_inria_inverse_dynamics_solver evaluate_solver_franka.launch.py input_bag:=<my_bag_file> output_bag:=<my_output_folder> topic:=<my_output_topic>
```

### Visualize the results

Please refer to [the parent class documentation](../inverse_dynamics_solver/README.md#visualize-the-results) to visualize the results, i.e. the evaluation of joint torque signals on `input_bag`, stored in `output_bag`.

## Citation

If you find this work useful, please cite it as

```bibtex
@article{Gaz_2019,
    title={Dynamic Identification of the Franka Emika Panda Robot With Retrieval of Feasible Parameters Using Penalty-Based Optimization},
    volume={4},
    ISSN={2377-3774},
    url={http://dx.doi.org/10.1109/lra.2019.2931248},
    DOI={10.1109/lra.2019.2931248},
    number={4},
    journal={IEEE Robotics and Automation Letters},
    publisher={Institute of Electrical and Electronics Engineers (IEEE)},
    author={Gaz, Claudio and Cognetti, Marco and Oliva, Alexander and Robuffo Giordano, Paolo and De Luca, Alessandro},
    year={2019},
    month=oct,
    pages={4147–4154}
}
```
