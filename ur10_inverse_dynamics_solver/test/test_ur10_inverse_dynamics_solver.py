from launch import LaunchDescription
from launch_ros.actions import Node
from launch_testing import post_shutdown_test
from launch_testing.actions import ReadyToTest
from launch_testing.asserts import assertExitCodes
from launch_testing.util import KeepAliveProc

from ament_index_python.packages import get_package_share_path
import pytest
from unittest import TestCase


@pytest.mark.launch_test
def generate_test_description():
    # Bag file name to test
    bag_filename = (
        get_package_share_path("ur10_inverse_dynamics_solver")
        / "bagfiles"
        / "validation_trajectory.db3"
    )

    # Input arguments
    parameters = {
        "inverse_dynamics_solver_plugin_name": "ur10_inverse_dynamics_solver/InverseDynamicsSolverUR10",
        "bag_filename": str(bag_filename),
        "topic_name": "/joint_space_trajectory",
    }

    # The node to test
    test_ur10_inverse_dynamics_solver_node = Node(
        package="ur10_inverse_dynamics_solver",
        executable="ur10_inverse_dynamics_solver_test",
        name="test_ur10_inverse_dynamics_solver_node",
        parameters=[parameters],
        output="screen",
    )

    # Launch the processes and execute tests
    return (
        LaunchDescription(
            [
                test_ur10_inverse_dynamics_solver_node,
                KeepAliveProc(),
                ReadyToTest(),
            ]
        ),
        {
            "test_ur10_inverse_dynamics_solver_node": test_ur10_inverse_dynamics_solver_node
        },
    )


class TestTerminatingProcessStops(TestCase):
    def test_gtest_run_complete(
        self, proc_info, test_ur10_inverse_dynamics_solver_node
    ):
        proc_info.assertWaitForShutdown(
            process=test_ur10_inverse_dynamics_solver_node, timeout=4000.0
        )


@post_shutdown_test()
class TestOutcome(TestCase):
    def test_exit_codes(self, proc_info):
        assertExitCodes(proc_info)
