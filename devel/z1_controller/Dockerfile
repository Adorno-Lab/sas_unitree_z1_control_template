FROM murilomarinho/sas:jazzy
SHELL ["/bin/bash", "-c"]
ENV BASH_ENV="/etc/bash_env"

# Clone this rep
RUN mkdir -p ~/git/
RUN cd ~/git/ && git clone https://github.com/Adorno-Lab/sas_robot_driver_unitree_z1 --recursive 


# Install the Z1 driver
RUN chmod +x ~/git/sas_robot_driver_unitree_z1/dependencies/install_z1_controller.sh
RUN bash -c '~/git/sas_robot_driver_unitree_z1/dependencies/install_z1_controller.sh' 

ENTRYPOINT ["bash", "/root/git/sas_robot_driver_unitree_z1/dependencies/start_z1_controller.sh"]

