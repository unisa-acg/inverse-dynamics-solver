# planar_3r_description

This is a lightweight description package for the 2R planar robot.
The description is contained in the [URDF file](./urdf/planar_3r.urdf.xacro), and can be visualized through the [launch file](./launch/display.launch.py).

The kinematic/dynamic parameters are taken from the following book:

> 'Robotics: modelling, planning and control' (2009) by B. Siciliano, L. Sciavicco, L. Villani, G. Oriolo, 1st ed., Springer, section 2.9.1. DOI: [https://doi.org/10.1007/978-1-84628-642-1](https://doi.org/10.1007/978-1-84628-642-1)

## Visualize the robot

```bash
ros2 launch planar_3r_description display.launch.py
```
