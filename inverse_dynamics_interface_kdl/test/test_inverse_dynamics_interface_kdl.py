from launch import LaunchDescription
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_testing import post_shutdown_test
from launch_testing.actions import ReadyToTest
from launch_testing.asserts import assertExitCodes
from launch_testing.util import KeepAliveProc

import pytest
from unittest import TestCase


@pytest.mark.launch_test
def generate_test_description():
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

    # Input arguments
    DEFAULT_GRAVITY = [0, 0, -9.81]
    parameters = {
        "robot_description": robot_description,
        "inverse_dynamics_interface_plugin_name": "inverse_dynamics_interface_kdl/InverseDynamicsInterfaceKDL",
        "kdl.root": "base_link",
        "kdl.tip": "tool0",
        "kdl.gravity": DEFAULT_GRAVITY,
        "empty_root.root": "",
        "empty_root.tip": "tool0",
        "empty_root.gravity": DEFAULT_GRAVITY,
        "empty_tip.root": "",  # This setup shall raise a ParameterUninitializedException
        "empty_tip.tip": "",
        "empty_tip.gravity": DEFAULT_GRAVITY,
    }

    # The node to test
    inverse_dynamics_interface_kdl_test_node = Node(
        package="inverse_dynamics_interface_kdl",
        executable="inverse_dynamics_interface_kdl_test",
        name="inverse_dynamics_interface_kdl_test_node",
        parameters=[parameters],
        output="screen",
    )

    # Launch the processes and execute tests
    return (
        LaunchDescription(
            [
                inverse_dynamics_interface_kdl_test_node,
                KeepAliveProc(),
                ReadyToTest(),
            ]
        ),
        {
            "inverse_dynamics_interface_kdl_test_node": inverse_dynamics_interface_kdl_test_node
        },
    )


class TestTerminatingProcessStops(TestCase):
    def test_gtest_run_complete(
        self, proc_info, inverse_dynamics_interface_kdl_test_node
    ):
        proc_info.assertWaitForShutdown(
            process=inverse_dynamics_interface_kdl_test_node, timeout=4000.0
        )


@post_shutdown_test()
class TestOutcome(TestCase):
    def test_exit_codes(self, proc_info):
        assertExitCodes(proc_info)
