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
        StorageOptions(uri=bag_file),
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
        "-d",
        "--output_dir",
        type=str,
        required=True,
        help="Output directory for plots.",
    )
    parser.add_argument(
        "-o",
        "--overlay",
        action="store_true",
        help="Plot measured torques from first bag and computed torques from all bags on the same axes.",
    )
    args = parser.parse_args()

    # Ensure output directory exists
    os.makedirs(args.output_dir, exist_ok=True)

    # Process each bag file
    topic = "/torques"
    mae_dict = {}  # {joint_name: {bag_name: mae_value}}
    mae_tables = []  # store all MAE tables entries
    headers = []  # store all MAE tables headers
    bag_names = []  # maintain bag order
    computed_data = []  # store computed signals for overlay
    first_measured = {}  # measured signals from first bag only

    for idx, bag_file in enumerate(args.bag_files):
        bag_name = os.path.basename(bag_file).split(".")[0]
        bag_names.append(bag_name)

        # Read messages
        input_msgs = read_ros2_bag(bag_file, topic + "_gt")
        output_msgs = read_ros2_bag(bag_file, topic)

        # Extract data
        input_timestamps, input_efforts_mat = extract_data(input_msgs)
        output_timestamps, output_efforts_mat = extract_data(output_msgs)

        n_joints = input_efforts_mat.shape[1]
        joint_names = input_msgs[0].name

        # Store the first bag's measured data if overlaying
        if args.overlay and idx == 0:
            first_measured["timestamps"] = input_timestamps
            first_measured["efforts"] = input_efforts_mat

        # Always store computed data
        if args.overlay:
            computed_data.append(
                {
                    "bag_name": bag_name,
                    "timestamps": output_timestamps,
                    "efforts": output_efforts_mat,
                }
            )

        # Compute MAE for the table
        mae_values = np.mean(np.abs(output_efforts_mat - input_efforts_mat), axis=0)
        for joint_name, mae_value in zip(joint_names, mae_values):
            if joint_name not in mae_dict:
                mae_dict[joint_name] = {}
            mae_dict[joint_name][bag_name] = mae_value

        # Plotting
        if not args.overlay:
            # Normal mode: separate figure for each bag
            fig, axes = plt.subplots(
                nrows=int(np.ceil(n_joints / 2)), ncols=2, figsize=(20, 12)
            )
            fig.set_tight_layout(True)
            fig.patch.set_alpha(0)
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
            fig.legend(["Computed", "Measured"], loc="lower right", fontsize=FS)

            # Save figure
            pdf_path = os.path.join(args.output_dir, f"{bag_name}.pdf")
            plt.savefig(pdf_path, format="pdf", bbox_inches="tight")
            plt.close(fig)
            print(f"Figure saved: {pdf_path}")

            # Compute table
            mae_tables.append(
                [
                    [joint, f"{error:.4f}"]
                    for joint, error in zip(joint_names, mae_values)
                ]
            )
            headers.append(["Joint", bag_name])

    # Overlay mode: plot one figure with all computed signals
    if args.overlay:
        n_joints = first_measured["efforts"].shape[1]

        fig, axes = plt.subplots(
            nrows=int(np.ceil(n_joints / 2)), ncols=2, figsize=(20, 12)
        )
        fig.set_tight_layout(True)
        fig.patch.set_alpha(0)
        axes = axes.flatten()

        # For each joint, overlay measured + all computed
        for jj in range(n_joints):
            ax = axes[jj]

            # Measured (from first bag)
            ax.plot(
                first_measured["timestamps"],
                first_measured["efforts"][:, jj],
                "k--",
                linewidth=LW,
                label="Measured",
            )

            # Computed signals from all bags
            for comp in computed_data:
                ax.plot(
                    comp["timestamps"],
                    comp["efforts"][:, jj],
                    linewidth=LW,
                    label=comp["bag_name"],
                )

            ax.set_xlabel("Time [s]", fontsize=FS)
            ax.set_ylabel(r"$\tau_{{{}}}$ [Nm]".format(jj + 1), fontsize=FS)
            ax.grid(True)
            ax.set_xlim([0, first_measured["timestamps"][-1]])
            ax.tick_params(axis="both", labelsize=FS)
        fig.legend(
            ["Measured"] + [comp["bag_name"] for comp in computed_data],
            loc="lower right",
            fontsize=FS,
        )

        # Save combined figure
        out_path = os.path.join(args.output_dir, "overlay_plot.pdf")
        plt.savefig(out_path, format="pdf", bbox_inches="tight")
        plt.close(fig)
        print(f"Overlay figure saved: {out_path}")

        # Compute MAE table
        mae_tables = [
            [
                [joint]
                + [f"{mae_dict[joint].get(b, float('nan')):.4f}" for b in bag_names]
                for joint in mae_dict
            ]
            + [
                ["Average"]
                + [
                    f"{np.mean([mae_dict[j][b] for j in joint_names if b in mae_dict[j]]):.4f}"
                    for b in bag_names
                ]
            ]
        ]
        headers = [["Joint"] + bag_names]

    # Display MAE
    print("\nMAE per Joint:")
    for mae_table, header in zip(mae_tables, headers):
        print(tabulate(mae_table, headers=header, tablefmt="grid"))


if __name__ == "__main__":
    main()
