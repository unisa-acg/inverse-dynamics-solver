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

# find dependencies
find_package(ament_cmake REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    Eigen3
    pluginlib
    rclcpp
    inverse_dynamics_interface
)

foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

# add library
add_library(inverse_dynamics_interface_ur10 SHARED
            src/getCoriolisCurrents.cpp
            src/getCurrents.cpp
            src/getGravityCurrents.cpp
            src/getInertiaCurrents.cpp
            src/inverse_dynamics_interface_ur10.cpp
)
target_compile_features(
  inverse_dynamics_interface_ur10
  PUBLIC c_std_99 cxx_std_17
) # Require C99 and C++17
target_include_directories(
  inverse_dynamics_interface_ur10
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
target_link_libraries(
  inverse_dynamics_interface_ur10
  PUBLIC Eigen3::Eigen
         pluginlib::pluginlib
         rclcpp::rclcpp
         inverse_dynamics_interface::inverse_dynamics_interface_lib
)

# create plugin
pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_ur10.xml
)

# Causes the visibility macros to use dllexport rather than dllimport, which is appropriate when
# building the dll but not consuming it.
target_compile_definitions(
  inverse_dynamics_interface_ur10
  PRIVATE "INVERSE_DYNAMICS_INTERFACE_UR10_BUILDING_LIBRARY"
)

# install library
install(DIRECTORY include/
        DESTINATION include
)
install(FILES inverse_dynamics_interface_ur10.xml
        DESTINATION share/inverse_dynamics_interface_ur10
)
install(TARGETS inverse_dynamics_interface_ur10
        EXPORT export_${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

# tests
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

  # add gtests
  set(TEST_NAME
      ${PROJECT_NAME}_test
  )
  ament_add_gtest_executable(${TEST_NAME} test/test_inverse_dynamics_interface_ur10.cpp)
  target_link_libraries(
    ${TEST_NAME}
    rclcpp::rclcpp
    rosbag2_cpp::rosbag2_cpp
    ${trajectory_msgs_TARGETS}
    inverse_dynamics_interface::inverse_dynamics_interface_lib
    inverse_dynamics_interface_ur10
  )
  add_ros_test(test/test_inverse_dynamics_interface_ur10.py)

  target_link_libraries(${TEST_NAME})

  # install test files
  install(DIRECTORY test/bagfiles
          DESTINATION share/${PROJECT_NAME}
  )
  install(TARGETS ${TEST_NAME}
          RUNTIME DESTINATION lib/${PROJECT_NAME}
  )
endif()

# install bag files
install(DIRECTORY bagfiles
        DESTINATION share/${PROJECT_NAME}/
)

# install launch files
install(DIRECTORY launch
        DESTINATION share/${PROJECT_NAME}/
)

# compile the package
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_export_targets(export_${PROJECT_NAME})

ament_package()
