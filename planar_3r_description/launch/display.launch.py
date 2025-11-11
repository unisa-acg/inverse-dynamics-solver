from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.launch_context import LaunchContext
from launch.substitutions import Command, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def launch_setup(context: LaunchContext, *args, **kwargs):
    # Launch-time configurable parameters
    a1 = LaunchConfiguration("a1").perform(context)
    a2 = LaunchConfiguration("a2").perform(context)
    a3 = LaunchConfiguration("a3").perform(context)

    # Robot description
    package_path = FindPackageShare("planar_3r_description")
    xacro_file = PathJoinSubstitution([package_path, "urdf", "planar_3r.urdf.xacro"])
    robot_description = Command(["xacro ", xacro_file, f" a1:={a1} a2:={a2} a3:={a3}"])

    return [
        Node(
            executable="robot_state_publisher",
            package="robot_state_publisher",
            parameters=[{"robot_description": robot_description}],
        ),
        Node(
            executable="joint_state_publisher_gui",
            package="joint_state_publisher_gui",
        ),
        Node(
            executable="rviz2",
            package="rviz2",
            name="rviz2",
            arguments=[
                "-d",
                PathJoinSubstitution([package_path, "config", "display.rviz"]),
            ],
            output="screen",
        ),
    ]


def generate_launch_description():

    a1 = DeclareLaunchArgument("a1", default_value="1.0", description="Link 1 length")
    a2 = DeclareLaunchArgument("a2", default_value="0.8", description="Link 2 length")
    a3 = DeclareLaunchArgument("a3", default_value="0.6", description="Link 3 length")

    return LaunchDescription([a1, a2, a3] + [OpaqueFunction(function=launch_setup)])
