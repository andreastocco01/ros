#include "ros/ros.h"
#include "std_msgs/String.h"

void callback (const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I receive [%s]", msg->data.c_str());
}

int main (int argc, char** argv) {
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle node;

    ros::Subscriber subscriber = node.subscribe("chat_topic", 100, callback);
    ros::spin(); // non so perche' vada messo
    return 0;
}