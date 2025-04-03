from yaml import dump
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    OpaqueFunction,
)
from launch.launch_context import LaunchContext
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import (
    Command,
    FindExecutable,
    LaunchConfiguration,
    PathJoinSubstitution,
)
from launch_ros.substitutions import FindPackageShare


def launch_setup(context: LaunchContext, *args, **kwargs):
    # Panda kinematic description
    ROBOT_NAME = "fer"
    robot_description = Command(
        [
            FindExecutable(name="xacro"),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("franka_description"),
                    "robots",
                    ROBOT_NAME,
                    ROBOT_NAME + ".urdf.xacro",
                ]
            ),
            " ",
            "hand:=false",
        ]
    ).perform(context)

    # We convert the robot description to a YAML-compatible format: without this
    # instruction, special characters in the robot description XML string might
    # compromise passing it as a parameter
    robot_description = dump(robot_description)

    # Launch configuration variables for command-line arguments
    input_bag = LaunchConfiguration("input_bag")
    output_bag = LaunchConfiguration("output_bag")
    topic = LaunchConfiguration("topic")

    # Get path of input bag file
    input_bag = PathJoinSubstitution(
        [FindPackageShare("kdl_inverse_dynamics_solver"), "bagfiles", input_bag]
    )

    # Evaluate solver
    return [
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution(
                    [
                        FindPackageShare("inverse_dynamics_solver"),
                        "launch",
                        "evaluate_solver.launch.py",
                    ]
                )
            ),
            launch_arguments={
                "input_bag": input_bag,
                "output_bag": output_bag,
                "topic": topic,
                "plugin_name": "kdl_inverse_dynamics_solver/InverseDynamicsSolverKDL",
                "robot_description": robot_description,
                "root": ROBOT_NAME + "_link0",
                "tip": ROBOT_NAME + "_link8",
                "gravity": "[0, 0, -9.81]",
            }.items(),
        )
    ]


def generate_launch_description():
    # Define arguments
    input_bag = DeclareLaunchArgument(
        "input_bag",
        default_value="panda_exciting_trajectory.db3",
        description="Path to the input rosbag file",
    )
    output_bag = DeclareLaunchArgument(
        "output_bag",
        default_value="panda_exciting_trajectory_torques",
        description="Path to the output rosbag file",
    )
    topic = DeclareLaunchArgument(
        "topic",
        default_value="/torques",
        description="The topic to write the output messages on",
    )

    # Declare arguments
    declared_arguments = []
    declared_arguments.append(input_bag)
    declared_arguments.append(output_bag)
    declared_arguments.append(topic)

    # Generate launch description
    return LaunchDescription(
        declared_arguments + [OpaqueFunction(function=launch_setup)]
    )
