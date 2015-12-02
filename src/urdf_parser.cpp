#include <ros/ros.h>
#include <kdl_parser/kdl_parser.hpp>
#include <urdf/model.h>
#include <iostream>
 
#include <string>
#include <map>

int main(int argc, char *argv[]) 
{
	bool exit_value;
	KDL::Tree my_tree;
	urdf::Model my_model;
	

	if (argc ==2){
		if (!my_model.initFile(argv[1])){
			ROS_ERROR("Failed to parse urdf robot model");
			return false;
		}
		if (!kdl_parser::treeFromUrdfModel(my_model, my_tree)){
			ROS_ERROR("Failed to construct kdl tree");
			return false;
		}
		std::cout << "Number of links of the urdf:" << my_tree.getNrOfSegments() << std::endl;
		std::cout << "Number of Joints of the urdf:" << my_tree.getNrOfJoints() << std::endl;
	
	}else {
		ROS_ERROR("Failed to execute, use: rosrun {package} {executable} {path of urdf file}");
		return false;
	}
}
