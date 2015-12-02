cmake_minimum_required(VERSION 2.8.3)
project(webcam_kinematics)

find_package(catkin REQUIRED COMPONENTS
  kdl_parser
  roscpp
  std_msgs
  cmake_modules
)

add_library(${PROJECT_NAME} src/urdf_parser.cpp)

catkin_package(
  LIBRARIES ${PROJECT_NAME} ${KDL_LIBRARY}
  CATKIN_DEPENDS kdl_parser roscpp 
  DEPENDS orocos_kdl TinyXML
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(webcam_kinematics_node src/urdf_parser.cpp)

target_link_libraries(webcam_kinematics_node
  ${catkin_LIBRARIES}
)
