cmake_minimum_required(VERSION 3.16)
project(inverse_dynamics_interface
        LANGUAGES CXX
)

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

set(THIS_PACKAGE_INCLUDE_DEPENDS
    pluginlib
    rclcpp
    rosbag2_cpp
    sensor_msgs
    urdf
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()
find_package(Eigen3
             REQUIRED
             NO_MODULE
)

# header-only libraries must be represented as interface targets to correctly export their
# dependencies for dependents
add_library(inverse_dynamics_interface INTERFACE)
target_compile_features(
  inverse_dynamics_interface
  INTERFACE cxx_std_17
)
target_include_directories(
  inverse_dynamics_interface
  INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include/inverse_dynamics_interface>
)
target_link_libraries(
  inverse_dynamics_interface
  INTERFACE Eigen3::Eigen rclcpp::rclcpp
)

add_executable(evaluate_dynamics
               demo/evaluate_dynamics.cpp
)
target_include_directories(
  evaluate_dynamics
  PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
          $<INSTALL_INTERFACE:include/inverse_dynamics_interface>
)
target_link_libraries(
  evaluate_dynamics
  PUBLIC rclcpp::rclcpp
         rosbag2_cpp::rosbag2_cpp
         ${sensor_msgs_TARGETS}
         urdf::urdf
)
install(TARGETS evaluate_dynamics
        DESTINATION lib/inverse_dynamics_interface
)

install(PROGRAMS scripts/plot_joint_state.py
        DESTINATION lib/inverse_dynamics_interface
)

install(DIRECTORY launch
        DESTINATION share/inverse_dynamics_interface
)

install(DIRECTORY include/
        DESTINATION include
)
install(TARGETS inverse_dynamics_interface
        EXPORT export_inverse_dynamics_interface
        INCLUDES
        DESTINATION include
)

ament_export_targets(export_inverse_dynamics_interface HAS_LIBRARY_TARGET)
ament_export_include_directories(include)
ament_export_dependencies(rclcpp Eigen3)
ament_package()
