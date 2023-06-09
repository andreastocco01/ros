#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <cstdlib>

int main (int argc, char** argv) {
    ros::init(argc, argv, "publisher");
    ros::NodeHandle node;

    ros::Rate rate(1);
    ros::Publisher publisher = node.advertise<std_msgs::String>("topic", 100);

    srand((unsigned) time(NULL));

    while (ros::ok()) {
        int random = std::rand() % 30;
        std_msgs::String message;

        std::stringstream ss;
        ss << random;
        message.data = ss.str();

        ROS_INFO("I send [%s]", message.data.c_str());

        publisher.publish(message);
        rate.sleep();
    }
    return 0;
}
