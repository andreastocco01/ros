#include "ros/ros.h"

int main(int argc, char** argv){
    ros::init(argc, argv, "node");
    ros::NodeHandle n;
    ROS_INFO_STREAM("funzia");
    ROS_ERROR_STREAM("messaggio di errore");
    int freq = 10; // 10 Hz
    ros::Rate rate(10);
    while (ros::ok()) {
        ROS_WARN_STREAM("scrivo questo messaggio 10 volte al secondo");
        rate.sleep();
    }
    return 0;
}