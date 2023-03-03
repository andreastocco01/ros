#include "ros/ros.h"
#include "std_msgs/String.h"
#include "service/upper_case.h"

#include <ctype.h>
#include <string>

bool to_upper_case(service::upper_case::Request& req, service::upper_case::Response& res) {
    res.output = "";
    for(int i = 0; i < req.input.length(); i++) {
        res.output += toupper(req.input[i]);
    } 

    ROS_INFO("Request: %s -> Response: %s", req.input.c_str(), res.output.c_str());
    return true;
}

int main (int argc, char** argv) {
    ros::init(argc, argv, "server");
    ros::NodeHandle node;

    ros::ServiceServer service_server = node.advertiseService("upper_case", to_upper_case);
    ROS_INFO("Ready");
    ros::spin();
    return 0;
}