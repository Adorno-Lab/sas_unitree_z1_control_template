![GitHub License](https://img.shields.io/github/license/Adorno-Lab/sas_robot_driver_unitree_z1)![Static Badge](https://img.shields.io/badge/ROS2-Jazzy-blue)![Static Badge](https://img.shields.io/badge/powered_by-DQ_Robotics-red)![Static Badge](https://img.shields.io/badge/SmartArmStack-green)![Static Badge](https://img.shields.io/badge/Ubuntu-24.04_LTS-orange)

# sas_unitree_z1_control_template

> [!TIP]
> SmartArmStack powers this template.
> More information about SmartArmStack is available at https://smartarmstack.github.io/.

## Clone this repository

```shell
mkdir -p ~/git
cd ~/git && git clone https://github.com/Adorno-Lab/sas_unitree_z1_control_template.git --recursive
```

This is a control template for Unitree Z1 robotic manipulators. It relies on [sas_robot_driver_unitree_z1](https://github.com/Adorno-Lab/sas_robot_driver_unitree_z1).

### Real Platform

> [!CAUTION]
> For using the real robot, you **must** have the risk assessments in place. 
> This guide is meant to be helpful, but holds absolutely no liability whatsoever. More details are available in the software license.

> [!WARNING]
> This code will move the robot. Ensure that the workspace is clear and safe for operation.

> [!CAUTION]
> Be ready to perform an emergency stop! 




https://github.com/user-attachments/assets/eb8c6c1e-ea05-46ca-8bcf-b488a4fe1f3b


1. Set up your Unitree Z1 arm

2. Run this in your terminal


```shell
cd ~/git/sas_unitree_z1_control_template/devel/robot_demo
xhost +local:root
docker compose up
```

### Simulation 

<img width="1000" alt="Screenshot from 2025-08-27 17-50-42" src="https://github.com/user-attachments/assets/ae205645-95c9-413d-81ef-e2ee3b33acb4" />

#### Ubuntu amd64

```shell
cd ~/git/sas_unitree_z1_control_template/devel/coppeliasim_demo
xhost +local:root
docker compose up
```

#### Apple Silicon

```shell
cd ~/git/sas_unitree_z1_control_template/devel/coppeliasim_demo_macos
open -a XQuartz
xhost + 127.0.0.1
docker compose up
```
