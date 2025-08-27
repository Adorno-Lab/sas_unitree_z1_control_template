FROM murilomarinho/sas:jazzy
SHELL ["/bin/bash", "-c"]
ENV BASH_ENV="/etc/bash_env"


RUN mkdir -p ~/ros2_ws/src

# Clone this rep
RUN cd ~/ros2_ws/src && git clone https://github.com/Adorno-Lab/sas_unitree_z1_control_template.git --recursive

# Install the Z1 driver
RUN chmod +x ~/ros2_ws/src/sas_unitree_z1_control_template/devel/scripts/install_z1_sas_drivers.sh
RUN bash -c '~/ros2_ws/src/sas_unitree_z1_control_template/devel/scripts/install_z1_sas_drivers.sh' 

# Set the library path
RUN chmod +x ~/ros2_ws/src/sas_unitree_z1_control_template/devel/scripts/set_z1_path.sh
RUN bash -c '~/ros2_ws/src/sas_unitree_z1_control_template/devel/scripts/set_z1_path.sh' 

# Set the alias
# RUN echo "alias launch_ROS2_Z1_drivers='cdros2 && source install/setup.bash && ros2 launch sas_robot_driver_unitree_z1 real_z1_robot_launch.py ' " >> /etc/bash_env



# Build the ROS2 packages
RUN bash -c "source /opt/ros/jazzy/setup.bash; cd ~/ros2_ws/; colcon build && source install/setup.bash" 


RUN echo "source /etc/bash_env" >> ~/.bashrc

