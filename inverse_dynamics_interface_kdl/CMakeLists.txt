cmake_minimum_required(VERSION 3.8)
project(inverse_dynamics_interface_kdl)

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
    kdl_parser
    orocos_kdl
    pluginlib
    rclcpp
    urdf
    inverse_dynamics_interface
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

add_library(inverse_dynamics_interface_kdl SHARED
            src/inverse_dynamics_interface_kdl.cpp
)
target_compile_features(
  inverse_dynamics_interface_kdl
  PUBLIC cxx_std_17
)
target_include_directories(
  inverse_dynamics_interface_kdl
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/inverse_dynamics_interface_kdl>
)
target_link_libraries(
  inverse_dynamics_interface_kdl
  PUBLIC kdl_parser::kdl_parser
         pluginlib::pluginlib
         rclcpp::rclcpp
         urdf::urdf
         inverse_dynamics_interface::inverse_dynamics_interface
)

pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_kdl.xml
)

if(BUILD_TESTING)
  # find dependencies
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ros_testing REQUIRED)
  find_package(rclcpp REQUIRED)

  # add test on 2R planar
  ament_add_gtest_executable(kdl_interface_on_2r_planar_test
                             test/test_kdl_interface_on_2r_planar.cpp
  )
  target_link_libraries(
    kdl_interface_on_2r_planar_test
    rclcpp::rclcpp
    pluginlib::pluginlib
    inverse_dynamics_interface::inverse_dynamics_interface
    inverse_dynamics_interface_kdl
  )
  add_ros_test(test/test_kdl_interface_on_2r_planar.py)

  # add test on 3R planar
  ament_add_gtest_executable(kdl_interface_on_3r_planar_test
                             test/test_kdl_interface_on_3r_planar.cpp
  )
  target_link_libraries(
    kdl_interface_on_3r_planar_test
    rclcpp::rclcpp
    pluginlib::pluginlib
    inverse_dynamics_interface::inverse_dynamics_interface
    inverse_dynamics_interface_kdl
  )
  add_ros_test(test/test_kdl_interface_on_3r_planar.py)

  install(TARGETS kdl_interface_on_3r_planar_test kdl_interface_on_2r_planar_test
          RUNTIME DESTINATION lib/inverse_dynamics_interface_kdl
  )
endif()

install(DIRECTORY bagfiles
        DESTINATION share/inverse_dynamics_interface_kdl
)

install(DIRECTORY launch
        DESTINATION share/inverse_dynamics_interface_kdl
)

install(DIRECTORY include/
        DESTINATION include
)
install(TARGETS inverse_dynamics_interface_kdl
        EXPORT export_inverse_dynamics_interface_kdl
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_inverse_dynamics_interface_kdl)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
