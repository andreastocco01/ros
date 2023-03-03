#include "ros/ros.h"
#include "std_msgs/String.h"
#include "service/upper_case.h"

int main (int argc, char** argv) {
    ros::init(argc, argv, "client");

    if(argc < 2) {
        ROS_INFO("At least one parameter");
        return 1;
    }
    ros::NodeHandle node;

    ros::ServiceClient service_client = node.serviceClient<service::upper_case>("upper_case");
    service::upper_case srv;
    for(int i = 1; i < argc; i++) {
        srv.request.input += argv[i];
        if (i != argc-1) //this check prevents adding a space after last argument.
            srv.request.input += " ";
    }

    if (service_client.call(srv)) {
        ROS_INFO("%s", srv.response.output.c_str());
    } else {
        ROS_ERROR("Failed to call the service");
        return 1;
    }
    return 0;
}