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


def launch_setup(_: LaunchContext, *args, **kwargs):
    # UR10 kinematic description
    ROBOT_NAME = "ur10"
    robot_description = Command(
        [
            FindExecutable(name="xacro"),
            " ",
            PathJoinSubstitution(
                [FindPackageShare("ur_description"), "urdf", "ur.urdf.xacro"]
            ),
            " ",
            "name:=",
            ROBOT_NAME,
            " ",
            "ur_type:=",
            ROBOT_NAME,
        ]
    )

    # Launch configuration variables for command-line arguments
    input_bag = LaunchConfiguration("input_bag")
    output_bag = LaunchConfiguration("output_bag")
    topic = LaunchConfiguration("topic")

    # Get path of input bag file
    input_bag = PathJoinSubstitution(
        [FindPackageShare("ur10_inverse_dynamics_solver"), "bagfiles", input_bag]
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
                "plugin_name": "ur10_inverse_dynamics_solver/InverseDynamicsSolverUR10",
                "robot_description": robot_description,
            }.items(),
        )
    ]


def generate_launch_description():
    # Define arguments
    input_bag = DeclareLaunchArgument(
        "input_bag",
        default_value="ur10_exciting_trajectory.db3",
        description="Path to the input rosbag file",
    )
    output_bag = DeclareLaunchArgument(
        "output_bag",
        default_value="ur10_exciting_trajectory_real_torques",
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
