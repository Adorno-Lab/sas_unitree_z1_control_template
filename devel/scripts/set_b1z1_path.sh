echo "# Update the environment variable LD_LIBRARY_PATH as instructed in https://ros2-tutorial.readthedocs.io" >> /etc/bash_env
echo "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/ros2_ws/src/sas_robot_driver_unitree_z1/src/z1_sdk/lib/:~/ros2_ws/src/sas_robot_driver_unitree_b1/src/unitree_legged_sdk/lib/cpp/amd64/" >> /etc/bash_env

echo "# Update the environment variable LIBRARY_PATH as instructed in https://ros2-tutorial.readthedocs.io" >> /etc/bash_env
echo "export LIBRARY_PATH=$LIBRARY_PATH:~/ros2_ws/src/sas_robot_driver_unitree_z1/src/z1_sdk/lib/:~/ros2_ws/src/sas_robot_driver_unitree_b1/src/unitree_legged_sdk/lib/cpp/amd64/" >> /etc/bash_env


echo "alias launch_ROS2_B1Z1_drivers='cdros2 && source install/setup.bash && ros2 launch sas_robot_driver_unitree_b1 real_b1z1_robot_launch.py ' " >> /etc/bash_env