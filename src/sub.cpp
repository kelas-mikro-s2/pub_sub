#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/string.hpp>



void sub_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "I heard: '%s'", msg->data.c_str());
}

int main(int argc, char * argv[])
{
    //init
    rclcpp::init(argc, argv);
    
    //create node
    auto node = rclcpp::Node::make_shared("sub_node");
    
    //create subscriber
    auto subscriber = node->create_subscription<std_msgs::msg::String>("topic", 10, sub_callback);
    
    //spin
    rclcpp::spin(node);
    
    //shutdown
    rclcpp::shutdown();
    
    return 0;
}