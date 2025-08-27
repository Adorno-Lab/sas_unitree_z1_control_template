import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():

    real_robot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('sas_unitree_z1_control_template'), 'launch'),
            '/real_z1_robot_launch.py'])
    )

    return LaunchDescription([
        real_robot_launch,
        Node(
            package='sas_unitree_z1_control_template',
            executable='joint_interface_example_cpp',
            output='screen',
            emulate_tty=True,
            name='sas_unitree_z1_control_template_joint_interface_example_cpp',
            parameters=[{
                "thread_sampling_time_sec": 0.002, 
                "topic_namespace": "/sas_z1/z1_1",
                "move_robot_to_initial_configuration": False, # Do not use 'move_robot_to_initial_configuration = True' when using the real robot!!!
                "initial_configuration": [0.0, 90.0,-60.0,-30.0, 0.0, -90.0, 0]
            }]
        )
    ])