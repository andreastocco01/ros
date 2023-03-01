#include "ros/ros.h"

int main(int argc, char** argv){
    ros::init(argc, argv, "node_name");
    ros::NodeHandle n;
    ROS_INFO_STREAM("ti prego funziona");
    ROS_ERROR_STREAM("messaggio di errore");
    return 0;
}