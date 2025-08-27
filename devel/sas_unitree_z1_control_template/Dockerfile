FROM murilomarinho/sas:jazzy
SHELL ["/bin/bash", "-c"]
ENV BASH_ENV="/etc/bash_env"


# Clone this rep
RUN mkdir -p ~/git/
RUN cd ~/git/ && git clone https://github.com/Adorno-Lab/sas_robot_driver_unitree_z1 --recursive

# Install the Z1 driver
RUN chmod +x ~/git/sas_robot_driver_unitree_z1/dependencies/install_z1_sas_drivers.sh
RUN bash -c '~/git/sas_robot_driver_unitree_z1/dependencies/install_z1_sas_drivers.sh' 

# Set the library path
RUN chmod +x ~/git/sas_robot_driver_unitree_z1/dependencies/set_z1_path.sh
RUN bash -c '~/git/sas_robot_driver_unitree_z1/dependencies/set_z1_path.sh' 

# Set the alias
RUN echo "alias launch_ROS2_Z1_drivers='cdros2 && source install/setup.bash && ros2 launch sas_robot_driver_unitree_z1 real_z1_robot_launch.py ' " >> /etc/bash_env


# Build the ROS2 packages
RUN bash -c "source /opt/ros/jazzy/setup.bash; cd ~/ros2_ws/; colcon build && source install/setup.bash" 


RUN echo "source /etc/bash_env" >> ~/.bashrc

