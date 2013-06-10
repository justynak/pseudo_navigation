#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char** argv){
	ros::init(argc, argv, "navigation");
	ros::NodeHandle n;
	ros::Publisher publisher = n.advertise<std_msgs::String>("robot", 1000);
        ros::Rate loop_rate(1);

	std::stringstream ss;
	std::string str;
		


	while(ros::ok()){
                ss<<"Navigation\n";
		str = "Navigation\n";
		std_msgs::String msg;
		msg.data=str;	
		ROS_INFO("%s", msg.data.c_str());

		publisher.publish(msg);
                ss.flush();


		ros::spinOnce();
		
		loop_rate.sleep();

	}

	return 0;
} 
