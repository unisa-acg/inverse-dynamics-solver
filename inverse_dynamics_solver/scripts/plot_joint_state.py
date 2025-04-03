#!/usr/bin/env python3
"""
----------------------------------------------------------------------

This module has been developed by the Automatic Control Group of the
University of Salerno, Italy.

Title:    plot_joint_state.py
Author:   Vincenzo Petrone
Org.:     UNISA
Date:     Feb 2, 2025

This script reads a bag file containing a sequence of joint state
messages from two topics, which include ground truth and computed
torques. The former are measured from the robot, while the latter are
estimated by the inverse dynamics solver.

----------------------------------------------------------------------
"""

import os
import argparse
import numpy as np
import matplotlib.pyplot as plt
from rosbag2_py import SequentialReader, StorageOptions, ConverterOptions
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import JointState
from tabulate import tabulate

# Plot configuration
FS = 20
LW = 3


def read_ros2_bag(bag_file, topic):
    """Reads messages from a ROS 2 bag file."""
    reader = SequentialReader()
    reader.open(
        StorageOptions(uri=bag_file, storage_id="sqlite3"),
        ConverterOptions(
            input_serialization_format="cdr",
            output_serialization_format="cdr",
        ),
    )

    messages = []
    while reader.has_next():
        (topic_name, data, t) = reader.read_next()
        if topic_name == topic:
            msg = deserialize_message(data, JointState)
            messages.append(msg)
    return messages


def extract_data(messages):
    """Extract timestamps and torques from ROS 2 messages."""
    timestamps = np.array(
        [msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9 for msg in messages]
    )
    timestamps -= timestamps[0]  # Normalize time
    efforts = np.array([msg.effort for msg in messages])
    return timestamps, efforts


def main():
    parser = argparse.ArgumentParser(
        description="Plot joint state torques from ROS2 bag files."
    )
    parser.add_argument(
        "-b", "--bag_files", nargs="+", required=True, help="List of ROS2 bag files."
    )
    parser.add_argument(
        "-o",
        "--output_dir",
        type=str,
        required=True,
        help="Output directory for plots.",
    )
    args = parser.parse_args()

    # Ensure output directory exists
    os.makedirs(args.output_dir, exist_ok=True)

    # Process each bag file
    topic = "/torques"
    for bag_file in args.bag_files:
        # Read messages
        input_msgs = read_ros2_bag(bag_file, topic + "_gt")
        output_msgs = read_ros2_bag(bag_file, topic)

        # Extract timestamps and torques
        input_timestamps, input_efforts_mat = extract_data(input_msgs)
        output_timestamps, output_efforts_mat = extract_data(output_msgs)

        # Number of joints
        n_joints = input_efforts_mat.shape[1]

        # Plot results
        name = os.path.basename(bag_file).split(".")[0]
        fig, axes = plt.subplots(
            nrows=int(np.ceil(n_joints / 2)), ncols=2, figsize=(20, 12)
        )
        fig.set_tight_layout(True)
        fig.patch.set_alpha(0)  # Transparent background
        axes = axes.flatten()

        for jj in range(n_joints):
            ax = axes[jj]
            ax.plot(
                output_timestamps,
                output_efforts_mat[:, jj],
                "r",
                linewidth=LW,
                label="Computed",
            )
            ax.plot(
                input_timestamps,
                input_efforts_mat[:, jj],
                "k--",
                linewidth=LW,
                label="Measured",
            )
            ax.set_xlabel("Time [s]", fontsize=FS)
            ax.set_ylabel(r"$\tau_{{{}}}$ [Nm]".format(jj + 1), fontsize=FS)
            ax.grid(True)
            ax.set_xlim([0, input_timestamps[-1]])
            ax.tick_params(axis="both", labelsize=FS)

        # Save figure as PDF
        pdf_path = os.path.join(args.output_dir, f"{name}.pdf")
        plt.savefig(pdf_path, format="pdf", bbox_inches="tight")
        plt.close(fig)  # Close figure to avoid displaying
        print(f"Figure saved: {pdf_path}")

        # Compute and display MAE
        mae = np.mean(np.abs(output_efforts_mat - input_efforts_mat), axis=0)
        joint_names = input_msgs[0].name
        mae_table = [[joint, f"{error:.4f}"] for joint, error in zip(joint_names, mae)]
        print("\nMAE per Joint:")
        print(tabulate(mae_table, headers=["Joint", "MAE [Nm]"], tablefmt="grid"))


if __name__ == "__main__":
    main()
