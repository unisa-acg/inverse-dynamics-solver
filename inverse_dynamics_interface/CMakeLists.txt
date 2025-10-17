cmake_minimum_required(VERSION 3.8)
project(inverse_dynamics_interface)

if(CMAKE_COMPILER_IS_GNUCXX
   OR CMAKE_CXX_COMPILER_ID
      MATCHES
      "Clang"
)
  add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
  )
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    Eigen3
    pluginlib
    rclcpp
    rosbag2_cpp
    sensor_msgs
    urdf
)

foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

# Header-only libraries must be represented as interface targets to correctly export their
# dependencies for dependents
add_library(${PROJECT_NAME}_lib INTERFACE)
target_link_libraries(
  ${PROJECT_NAME}_lib
  INTERFACE rclcpp::rclcpp Eigen3::Eigen
)
target_include_directories(
  ${PROJECT_NAME}_lib
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)

# Install the library
install(DIRECTORY include/
        DESTINATION include
)

install(TARGETS ${PROJECT_NAME}_lib
        EXPORT export_${PROJECT_NAME}_lib
        INCLUDES
        DESTINATION include
)

# Export targets
ament_export_targets(export_${PROJECT_NAME}_lib HAS_LIBRARY_TARGET)

# Export include directories
ament_export_include_directories(include)

# Export dependencies
ament_export_dependencies(rclcpp Eigen3)

# Define executable
add_executable(evaluate_dynamics
               demo/evaluate_dynamics.cpp
)

# Link against necessary libraries
target_link_libraries(
  evaluate_dynamics
  PUBLIC rclcpp::rclcpp
         rosbag2_cpp::rosbag2_cpp
         ${sensor_msgs_TARGETS}
         urdf::urdf
)
target_include_directories(
  evaluate_dynamics
  PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)

# Install the executable
install(TARGETS evaluate_dynamics
        DESTINATION lib/${PROJECT_NAME}
)

# Install Python scripts
install(PROGRAMS scripts/plot_joint_state.py
        DESTINATION lib/${PROJECT_NAME}
)

# install launch files
install(DIRECTORY launch
        DESTINATION share/${PROJECT_NAME}/
)

ament_package()
