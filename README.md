# Inverse dynamics solver

This is the accompanying code of the paper

> V. Petrone, E. Ferrentino, P. Chiacchio, "A ROS2-based software library for inverse dynamics computation". Under peer-review.

This repository provides a library to solve the inverse dynamics problem for serial manipulators, i.e., it returns torques or dynamic matrices given input joint positions, velocities and accelerations.

The library is implemented in the [`inverse_dynamics_solver` package](./inverse_dynamics_solver/README.md).
The library is inherited by three concrete classes, i.e.,

- A KDL-based solver for simulated robots, based on their robot description defined via Unified Robot Description Format (URDF)
    - You can find it in the [`kdl_inverse_dynamics_solver` package](./kdl_inverse_dynamics_solver/README.md)
- A solver for the real UR10 robot
    - You can find it in the [`ur10_inverse_dynamics_solver` package](./ur10_inverse_dynamics_solver/README.md)
- A solver for the real Franka Emika Robot (FER, aka Panda)
    - You can find it in the [`franka_inria_inverse_dynamics_solver` package](./franka_inria_inverse_dynamics_solver/README.md)

## Dependencies

This code requires the installation of Ubuntu 22.04 and [ROS2 Humble Hawksbill](https://docs.ros.org/en/humble/index.html).

### System dependencies

To install the packages needed by this repo as system-wide dependencies, run the following command from the repository's root folder:

```bash
rosdep install --from-paths . -i
```

### Python dependencies

To install all Python dependencies, run the following commands from the repository's root folder:

```bash
sudo apt install python3-venv -y
python3 -m venv venv --system-site-packages
source venv/bin/activate
pip install -r requirements.txt
```

The dependencies are installed in the virtual environment called [`venv`](./venv/): to deactivate it, simply run `deactivate` in your terminal.

&copy; *2025 Automatic Control Group (DIEM, University of Salerno)*
