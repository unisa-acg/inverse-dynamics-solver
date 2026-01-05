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
    DEFAULT_ROOT = "base_link"
    DEFAULT_TIP = "tool0"
    DEFAULT_GRAVITY = [0, 0, -9.81]
    parameters = {
        "robot_description": robot_description,
        "inverse_dynamics_solver_plugin_name": "kdl_inverse_dynamics_solver/InverseDynamicsSolverKDL",
        "kdl.root": DEFAULT_ROOT,
        "kdl.tip": DEFAULT_TIP,
        "kdl.gravity": DEFAULT_GRAVITY,
        "no_root.tip": DEFAULT_TIP,  # This setup shall log a warning
        "no_root.gravity": DEFAULT_GRAVITY,
        "empty_root.root": "",  # This setup shall raise an InvalidParameterValueException
        "empty_root.tip": DEFAULT_TIP,
        "empty_root.gravity": DEFAULT_GRAVITY,
        "no_tip.root": DEFAULT_ROOT,  # This setup shall raise a ParameterUninitializedException
        "no_tip.gravity": DEFAULT_GRAVITY,
        "empty_tip.tip": "",  # This setup shall raise an InvalidParameterValueException
        "empty_tip.gravity": DEFAULT_GRAVITY,
    }

    # The node to test
    test_kdl_inverse_dynamics_solver_node = Node(
        package="kdl_inverse_dynamics_solver",
        executable="kdl_inverse_dynamics_solver_test",
        name="test_kdl_inverse_dynamics_solver_node",
        parameters=[parameters],
        output="screen",
    )

    # Launch the processes and execute tests
    return (
        LaunchDescription(
            [
                test_kdl_inverse_dynamics_solver_node,
                KeepAliveProc(),
                ReadyToTest(),
            ]
        ),
        {
            "test_kdl_inverse_dynamics_solver_node": test_kdl_inverse_dynamics_solver_node
        },
    )


class TestTerminatingProcessStops(TestCase):
    def test_gtest_run_complete(self, proc_info, test_kdl_inverse_dynamics_solver_node):
        proc_info.assertWaitForShutdown(
            process=test_kdl_inverse_dynamics_solver_node, timeout=4000.0
        )


@post_shutdown_test()
class TestOutcome(TestCase):
    def test_exit_codes(self, proc_info):
        assertExitCodes(proc_info)
