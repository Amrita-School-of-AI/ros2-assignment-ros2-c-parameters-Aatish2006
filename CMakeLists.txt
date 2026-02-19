cmake_minimum_required(VERSION 3.8)
project(ros2_parameters)

# Enable compiler warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find required packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Create executable
add_executable(parameters_node src/parameters_node.cpp)

# Link dependencies
ament_target_dependencies(
  parameters_node
  rclcpp
)

# Install executable
install(
  TARGETS parameters_node
  DESTINATION lib/${PROJECT_NAME}
)

# Required for all ROS 2 packages
ament_package()

