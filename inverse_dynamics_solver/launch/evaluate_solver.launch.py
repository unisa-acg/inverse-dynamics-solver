from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.launch_context import LaunchContext
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ast import literal_eval


def launch_setup(context: LaunchContext, *args, **kwargs):
    # Launch configuration variables to pass to the launch file
    input_bag = LaunchConfiguration("input_bag")
    output_bag = LaunchConfiguration("output_bag")
    topic = LaunchConfiguration("topic")
    plugin_name = LaunchConfiguration("plugin_name")
    robot_description = LaunchConfiguration("robot_description")
    root = LaunchConfiguration("root")
    tip = LaunchConfiguration("tip")
    gravity = LaunchConfiguration("gravity")

    return [
        LaunchDescription(
            [
                Node(
                    package="inverse_dynamics_solver",
                    executable="evaluate_solver",
                    name="inverse_dynamics_bag_processor",
                    parameters=[
                        {
                            "input_bag": input_bag,
                            "output_bag": output_bag,
                            "topic": topic,
                            "plugin_name": plugin_name,
                            "robot_description": robot_description,
                            "ids.root": root,
                            "ids.tip": tip,
                            "ids.gravity": literal_eval(gravity.perform(context)),
                        }
                    ],
                ),
            ]
        )
    ]


def generate_launch_description():
    # Define arguments
    input_bag = DeclareLaunchArgument(
        "input_bag", description="Path to the input rosbag file"
    )
    output_bag = DeclareLaunchArgument(
        "output_bag", description="Path to the output rosbag file"
    )
    topic = DeclareLaunchArgument(
        "topic",
        default_value="/torques",
        description="The topic to write the output messages on",
    )
    plugin_name = DeclareLaunchArgument(
        "plugin_name", description="The name of the IDS plugin to use"
    )
    robot_description = DeclareLaunchArgument(
        "robot_description", description="The robot description in URDF"
    )
    root = DeclareLaunchArgument(
        "root", default_value="", description="The kinematic chain root"
    )
    tip = DeclareLaunchArgument(
        "tip", default_value="", description="The kinematic chain tip"
    )
    gravity = DeclareLaunchArgument(
        "gravity",
        default_value="[0, 0, -9.81]",
        description="The gravity vector in root frame",
    )

    # Declare arguments
    declared_arguments = []
    declared_arguments.append(input_bag)
    declared_arguments.append(output_bag)
    declared_arguments.append(topic)
    declared_arguments.append(plugin_name)
    declared_arguments.append(robot_description)
    declared_arguments.append(root)
    declared_arguments.append(tip)
    declared_arguments.append(gravity)

    # Generate launch description
    return LaunchDescription(
        declared_arguments + [OpaqueFunction(function=launch_setup)]
    )
