cmake_minimum_required(VERSION 3.8)
project(inverse_dynamics_solver)

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

# Include directories (ensure header-only library is found)
include_directories(include)

# Export include directories
ament_export_include_directories(include)

# Export dependencies
ament_export_dependencies(rclcpp Eigen3)

# Define executable
add_executable(evaluate_solver
               demo/evaluate_solver.cpp
)

# Link against necessary libraries (no linking required for header-only libraries)
ament_target_dependencies(evaluate_solver ${THIS_PACKAGE_INCLUDE_DEPENDS})

# Install the library
install(DIRECTORY include/
        DESTINATION include
)

# Install the executable
install(TARGETS evaluate_solver
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
