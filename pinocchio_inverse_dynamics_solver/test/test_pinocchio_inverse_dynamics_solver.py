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
    parameters = {
        "robot_description": robot_description,
        "inverse_dynamics_solver_plugin_name": "pinocchio_inverse_dynamics_solver/InverseDynamicsSolverPinocchio",
        "ids.root": "base_link",
        "ids.tip": "tool0",
        "ids.gravity": [0, 0, -9.81],
    }

    # The node to test
    test_pinocchio_inverse_dynamics_solver_node = Node(
        package="pinocchio_inverse_dynamics_solver",
        executable="pinocchio_inverse_dynamics_solver_test",
        name="test_pinocchio_inverse_dynamics_solver_node",
        parameters=[parameters],
        output="screen",
    )

    # Launch the processes and execute tests
    return (
        LaunchDescription(
            [
                test_pinocchio_inverse_dynamics_solver_node,
                KeepAliveProc(),
                ReadyToTest(),
            ]
        ),
        {
            "test_pinocchio_inverse_dynamics_solver_node": test_pinocchio_inverse_dynamics_solver_node
        },
    )


class TestTerminatingProcessStops(TestCase):
    def test_gtest_run_complete(
        self, proc_info, test_pinocchio_inverse_dynamics_solver_node
    ):
        proc_info.assertWaitForShutdown(
            process=test_pinocchio_inverse_dynamics_solver_node, timeout=4000.0
        )


@post_shutdown_test()
class TestOutcome(TestCase):
    def test_exit_codes(self, proc_info):
        assertExitCodes(proc_info)
