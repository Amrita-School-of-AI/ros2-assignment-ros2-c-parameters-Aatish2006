#include "rclcpp/rclcpp.hpp"

class ParametersNode : public rclcpp::Node
{
public:
  ParametersNode() : Node("parameters_node")
  {
    // Declare parameters with default values
    this->declare_parameter<std::string>("name", "Aatish");
    this->declare_parameter<int>("age", 20);
    this->declare_parameter<double>("height", 5.8);

    // Get parameters
    std::string name;
    int age;
    double height;

    this->get_parameter("name", name);
    this->get_parameter("age", age);
    this->get_parameter("height", height);

    // Print values
    RCLCPP_INFO(this->get_logger(), "Name: %s", name.c_str());
    RCLCPP_INFO(this->get_logger(), "Age: %d", age);
    RCLCPP_INFO(this->get_logger(), "Height: %.2f", height);
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParametersNode>());
  rclcpp::shutdown();
  return 0;
}

