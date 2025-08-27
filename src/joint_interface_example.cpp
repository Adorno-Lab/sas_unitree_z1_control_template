#include <rclcpp/rclcpp.hpp>
#include <sas_core/sas_clock.hpp>
#include <sas_robot_driver/sas_robot_driver_client.hpp>
#include <dqrobotics/utils/DQ_Math.h>
#include <sas_common/sas_common.hpp>
#include <sas_core/eigen3_std_conversions.hpp>

using namespace DQ_robotics;

#include<signal.h>
static std::atomic_bool kill_this_process(false);
void sig_int_handler(int)
{
    kill_this_process = true;
}

int main(int argc, char** argv)
{
    if(signal(SIGINT, sig_int_handler) == SIG_ERR)
        throw std::runtime_error("::Error setting the signal int handler.");
    

    rclcpp::init(argc,argv,rclcpp::InitOptions(),rclcpp::SignalHandlerOptions::None);
    auto node = std::make_shared<rclcpp::Node>("sas_unitree_z1_control_template_joint_interface_example");

    try
    {
        RCLCPP_INFO_STREAM_ONCE(node->get_logger(), "::Loading parameters from parameter server.");

        double thread_sampling_time_sec;
        sas::get_ros_parameter(node,"thread_sampling_time_sec", thread_sampling_time_sec);

        std::string topic_namespace;
        sas::get_ros_parameter(node,"topic_namespace", topic_namespace);

        bool move_robot_to_initial_configuration;
        sas::get_ros_parameter(node,"move_robot_to_initial_configuration", move_robot_to_initial_configuration);

        std::vector<double> initial_configuration_vec;
        sas::get_ros_parameter(node,"initial_configuration", initial_configuration_vec);
        VectorXd initial_configuration = deg2rad(sas::std_vector_double_to_vectorxd(initial_configuration_vec));
  

        sas::Clock clock{thread_sampling_time_sec};
        clock.init();

        // Initialize the RobotDriverClient
        sas::RobotDriverClient rdi(node, topic_namespace);

        // Wait for RobotDriverClient to be enabled
        while(!rdi.is_enabled() && !kill_this_process)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            rclcpp::spin_some(node);
        }

        // Do not use move_robot_to_initial_configuration = true when using the real robot!!!
        if (move_robot_to_initial_configuration)
        {
            for(auto i=0;i<2000;++i)
            {
                RCLCPP_INFO_STREAM_ONCE(node->get_logger(), "::Setting initial configuration.");
                clock.update_and_sleep();
                rdi.send_target_joint_positions(initial_configuration);
                rdi.send_target_joint_velocities(VectorXd::Ones(rdi.get_joint_positions().size())*0.01);
                rclcpp::spin_some(node);
            }
        }

        // Get topic information
        RCLCPP_INFO_STREAM(node->get_logger(),"topic_prefix = " << rdi.get_topic_prefix());

        // Read the values sent by the RobotDriverServer
        auto joint_positions = rdi.get_joint_positions();
        RCLCPP_INFO_STREAM(node->get_logger(),"joint positions = " << joint_positions);

        VectorXd target_velocities =  VectorXd::Zero(joint_positions.size());
        double gain = 0.2;

        // For some iterations. Note that this can be stopped with CTRL+C.
        for(auto i=0;i<10000;++i)
        {
            clock.update_and_sleep();

            //Move the joints
            VectorXd target_joint_positions = joint_positions + VectorXd::Ones(joint_positions.size())*deg2rad(10.0 * sin(i / (100.0 * pi)));
            target_joint_positions(target_joint_positions.size()-1) = 0;
            std::cout<<target_joint_positions.transpose()<<std::endl;
            rdi.send_target_joint_positions(target_joint_positions);
            rdi.send_target_joint_velocities(gain*(target_joint_positions-rdi.get_joint_positions()));

            rclcpp::spin_some(node);
        }

        // Statistics
        RCLCPP_INFO_STREAM(node->get_logger(),"Statistics for the entire loop");

        RCLCPP_INFO_STREAM(node->get_logger(),"  Mean computation time: " << clock.get_statistics(
                                                sas::Statistics::Mean, sas::Clock::TimeType::Computational));
        RCLCPP_INFO_STREAM(node->get_logger(),"  Mean idle time: " << clock.get_statistics(
                                                sas::Statistics::Mean, sas::Clock::TimeType::Idle));
        RCLCPP_INFO_STREAM(node->get_logger(),"  Mean effective thread sampling time: " << clock.get_statistics(
                                                sas::Statistics::Mean, sas::Clock::TimeType::EffectiveSampling));

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
