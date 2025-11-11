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
    # 3R kinematic description
    (a1, a2, a3) = (1.0, 0.8, 0.6)
    robot_description = Command(
        [
            FindExecutable(name="xacro"),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("planar_3r_description"),
                    "urdf",
                    "planar_3r.urdf.xacro",
                ]
            ),
            f" a1:={a1} a2:={a2} a3:={a3}",
        ]
    )

    # Input arguments
    parameters = {
        "robot_description": robot_description,
        "inverse_dynamics_solver_plugin_name": "kdl_inverse_dynamics_solver/InverseDynamicsSolverKDL",
        "link_lengths": [a1, a2, a3],
        "kdl.root": "base_link",
        "kdl.tip": "flange",
        "kdl.gravity": [0, 0, -9.81],
    }

    # The node to test
    test_kdl_ids_on_3r_planar_node = Node(
        package="kdl_inverse_dynamics_solver",
        executable="kdl_ids_on_3r_planar_test",
        name="test_kdl_ids_on_3r_planar_node",
        parameters=[parameters],
        output="screen",
    )

    # Launch the processes and execute tests
    return (
        LaunchDescription(
            [
                test_kdl_ids_on_3r_planar_node,
                KeepAliveProc(),
                ReadyToTest(),
            ]
        ),
        {"test_kdl_ids_on_3r_planar_node": test_kdl_ids_on_3r_planar_node},
    )


class TestTerminatingProcessStops(TestCase):
    def test_gtest_run_complete(self, proc_info, test_kdl_ids_on_3r_planar_node):
        proc_info.assertWaitForShutdown(
            process=test_kdl_ids_on_3r_planar_node, timeout=4000.0
        )


@post_shutdown_test()
class TestOutcome(TestCase):
    def test_exit_codes(self, proc_info):
        assertExitCodes(proc_info)
