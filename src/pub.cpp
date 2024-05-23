#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

uint32_t count = 0;

int main(int argc, char * argv[])
{
    //init
    rclcpp::init(argc, argv);
    
    //create node
    auto node = rclcpp::Node::make_shared("pub_node");

    //create publisher
    auto publisher = node->create_publisher<std_msgs::msg::String>("topic", 10);
    
    //ros rate 1 Hz
    rclcpp::WallRate loop_rate(1);

    while (rclcpp::ok())
    {
        //create message
        auto message = std_msgs::msg::String();                

        //set message data
        message.data = "Mikro Publisher : "  + std::to_string(count++);

        //print message
        RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", message.data.c_str());

        //publish message
        publisher->publish(message);

        //spin
        rclcpp::spin_some(node);

        //delay
        loop_rate.sleep();

    }
    
    //shutdown
    rclcpp::shutdown();

    return 0;
}