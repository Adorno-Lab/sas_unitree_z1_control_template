#!/bin/bash



# Suggested instructions to sas_robot_driver_unitree_z1 and sas_robot_driver_unitree_b1
mkdir -p ~/ros2_ws/src

# Clone the sas_robot_driver_unitree_z1
cd ~/ros2_ws/src && git clone https://github.com/Adorno-Lab/sas_robot_driver_unitree_z1 --recursive

echo "source /opt/ros/jazzy/setup.bash" >> /etc/bash_env
echo "# Source the ROS2 overlay, as instructed in https://github.com/SmartArmStack/smart_arm_stack_ROS2" >> /etc/bash_env
echo "alias cdros2='cd ~/ros2_ws/' " >> /etc/bash_env
echo "alias buildros2='cdros2 && colcon build && source install/setup.bash' " >> /etc/bash_env

