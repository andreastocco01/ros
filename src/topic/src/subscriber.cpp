#include "ros/ros.h"
#include "std_msgs/String.h"

void callback (const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I receive [%s]", msg->data.c_str());
}

int main (int argc, char** argv) {
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle node;

    ros::Subscriber subscriber = node.subscribe("chat_topic", 1, callback);

    // ros::spin();

    // essendo la coda lunga 1 e la velocita' di esecuzione del ciclo DOPPIA rispetto a quella del publisher
    // il subscriber sara' in grado di ricevere effettivamente solo messaggi alterni! 
    ros::Rate rate(0.5);
    while (ros::ok()) {
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}