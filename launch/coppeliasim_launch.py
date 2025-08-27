from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    joint_names = [
        "/UnitreeZ1/joint1",
        "/UnitreeZ1/joint2",
        "/UnitreeZ1/joint3",
        "/UnitreeZ1/joint4",
        "/UnitreeZ1/joint5",
        "/UnitreeZ1/joint6",
        "/UnitreeZ1/joint_gripper"
    ]

    coppeliasim_ip = LaunchConfiguration('coppeliasim_ip')
    coppeliasim_timeout = LaunchConfiguration('coppeliasim_timeout')

    return LaunchDescription([
        DeclareLaunchArgument(
            'coppeliasim_ip',
            default_value='localhost'
        ),
        DeclareLaunchArgument(
             'coppeliasim_timeout',
              default_value='2000'
        ),
        Node(
            package='sas_robot_driver_coppeliasim',
            executable='sas_robot_driver_coppeliasim_node',
            output='screen',
            emulate_tty=True,
            name='cs_sas_z1_1',
            parameters=[{
                "timeout": coppeliasim_timeout,
                "robot_joint_names": joint_names,
                "ip": coppeliasim_ip,
                "port": 23000,
                "joint_limits_min": [-360.0, -360.0, -360.0, -360.0, -360.0, -360],  
                "joint_limits_max": [360.0, 360.0, 360.0, 360.0, 360.0, 360],  
                "thread_sampling_time_sec": 0.001
            }]
        )

    ])