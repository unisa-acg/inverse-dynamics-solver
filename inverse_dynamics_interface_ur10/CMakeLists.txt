cmake_minimum_required(VERSION 3.8)
project(inverse_dynamics_interface_ur10)

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

# Code optimization flags are available here
# https://clang.llvm.org/docs/CommandGuide/clang.html#code-generation-options
set(CMAKE_CXX_FLAGS
    "-O3"
)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    pluginlib inverse_dynamics_interface
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

add_library(inverse_dynamics_interface_ur10 SHARED
            src/getCoriolisCurrents.cpp
            src/getCurrents.cpp
            src/getGravityCurrents.cpp
            src/getInertiaCurrents.cpp
            src/inverse_dynamics_interface_ur10.cpp
)
target_compile_features(
  inverse_dynamics_interface_ur10
  PUBLIC cxx_std_17
)
target_include_directories(
  inverse_dynamics_interface_ur10
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/inverse_dynamics_interface_ur10>
)
target_link_libraries(
  inverse_dynamics_interface_ur10
  PUBLIC pluginlib::pluginlib inverse_dynamics_interface::inverse_dynamics_interface
)

pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_ur10.xml
)

if(BUILD_TESTING)
  # find dependencies
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ros_testing REQUIRED)
  set(THIS_TEST_PACKAGE_INCLUDE_DEPENDS
      rclcpp
      rosbag2_cpp
      trajectory_msgs
  )
  foreach(dependency IN
          ITEMS ${THIS_TEST_PACKAGE_INCLUDE_DEPENDS}
  )
    find_package(${dependency} REQUIRED)
  endforeach()

  set(TEST_NAME
      inverse_dynamics_interface_ur10_test
  )
  ament_add_gtest_executable(${TEST_NAME} test/test_inverse_dynamics_interface_ur10.cpp)
  target_link_libraries(
    ${TEST_NAME}
    rclcpp::rclcpp
    rosbag2_cpp::rosbag2_cpp
    ${trajectory_msgs_TARGETS}
    inverse_dynamics_interface::inverse_dynamics_interface
    inverse_dynamics_interface_ur10
  )
  add_ros_test(test/test_inverse_dynamics_interface_ur10.py)

  install(DIRECTORY test/bagfiles
          DESTINATION share/inverse_dynamics_interface_ur10
  )
  install(TARGETS ${TEST_NAME}
          RUNTIME DESTINATION lib/inverse_dynamics_interface_ur10
  )
endif()

install(DIRECTORY bagfiles
        DESTINATION share/inverse_dynamics_interface_ur10
)

install(DIRECTORY launch
        DESTINATION share/inverse_dynamics_interface_ur10
)

install(DIRECTORY include/
        DESTINATION include
)
install(TARGETS inverse_dynamics_interface_ur10
        EXPORT export_inverse_dynamics_interface_ur10
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_inverse_dynamics_interface_ur10)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
