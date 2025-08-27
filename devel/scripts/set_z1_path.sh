echo "# Update the environment variable LD_LIBRARY_PATH as instructed in https://ros2-tutorial.readthedocs.io" >> /etc/bash_env
echo "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/ros2_ws/src/sas_robot_driver_unitree_z1/src/z1_sdk/lib/" >> /etc/bash_env

echo "# Update the environment variable LIBRARY_PATH as instructed in https://ros2-tutorial.readthedocs.io" >> /etc/bash_env
echo "export LIBRARY_PATH=$LIBRARY_PATH:~/ros2_ws/src/sas_robot_driver_unitree_z1/src/z1_sdk/lib/" >> /etc/bash_env

