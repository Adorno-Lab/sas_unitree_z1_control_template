![GitHub License](https://img.shields.io/github/license/Adorno-Lab/sas_robot_driver_unitree_z1)![Static Badge](https://img.shields.io/badge/ROS2-Jazzy-blue)![Static Badge](https://img.shields.io/badge/powered_by-DQ_Robotics-red)![Static Badge](https://img.shields.io/badge/SmartArmStack-green)![Static Badge](https://img.shields.io/badge/Ubuntu-24.04_LTS-orange)

# sas_unitree_z1_control_template


### Real Platform

> [!CAUTION]
> For using the real robot, you **must** have the risk assessments in place. 
> This guide is meant to be helpful, but holds absolutely no liability whatsoever. More details are available in the software license.

> [!WARNING]
> This code will move the robot. Ensure that the workspace is clear and safe for operation.




https://github.com/user-attachments/assets/eb8c6c1e-ea05-46ca-8bcf-b488a4fe1f3b







1. Set up your Unitree Z1 arm

2. Run this in your terminal


```shell
mkdir -p ~/git
cd ~/git && git clone https://github.com/Adorno-Lab/sas_unitree_z1_control_template.git --recursive
cd ~/git/sas_unitree_z1_control_template/devel/robot_demo
xhost +local:root
docker compose up
```

### Simulation 

```shell
mkdir -p ~/git
cd ~/git && git clone https://github.com/Adorno-Lab/sas_unitree_z1_control_template.git --recursive
cd ~/git/sas_unitree_z1_control_template/devel/coppeliasim_demo
xhost +local:root
docker compose up
```
