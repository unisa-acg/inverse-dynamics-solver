cmake_minimum_required(VERSION 3.8)
project(inverse_dynamics_interface_pinocchio)

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
    pinocchio
    pluginlib
    rclcpp
    urdfdom
    inverse_dynamics_interface
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

add_library(inverse_dynamics_interface_pinocchio SHARED
            src/inverse_dynamics_interface_pinocchio.cpp
)
target_compile_features(
  inverse_dynamics_interface_pinocchio
  PUBLIC cxx_std_17
)
target_include_directories(
  inverse_dynamics_interface_pinocchio
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
target_link_libraries(
  inverse_dynamics_interface_pinocchio
  PUBLIC pinocchio::pinocchio
         pluginlib::pluginlib
         rclcpp::rclcpp
         urdfdom::urdf_parser
         inverse_dynamics_interface::inverse_dynamics_interface
)

pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_pinocchio.xml
)

if(BUILD_TESTING)
  # find dependencies
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ros_testing REQUIRED)
  find_package(rclcpp REQUIRED)

  # add test on 2R planar
  ament_add_gtest_executable(pinocchio_interface_on_2r_planar_test
                             test/test_pinocchio_interface_on_2r_planar.cpp
  )
  target_link_libraries(
    pinocchio_interface_on_2r_planar_test
    pluginlib::pluginlib
    rclcpp::rclcpp
    inverse_dynamics_interface::inverse_dynamics_interface
    inverse_dynamics_interface_pinocchio
  )
  add_ros_test(test/test_pinocchio_interface_on_2r_planar.py)

  # add test on 3R planar
  ament_add_gtest_executable(pinocchio_interface_on_3r_planar_test
                             test/test_pinocchio_interface_on_3r_planar.cpp
  )
  target_link_libraries(
    pinocchio_interface_on_3r_planar_test
    pluginlib::pluginlib
    rclcpp::rclcpp
    inverse_dynamics_interface::inverse_dynamics_interface
    inverse_dynamics_interface_pinocchio
  )
  add_ros_test(test/test_pinocchio_interface_on_3r_planar.py)

  install(TARGETS pinocchio_interface_on_2r_planar_test pinocchio_interface_on_3r_planar_test
          RUNTIME DESTINATION lib/inverse_dynamics_interface_pinocchio
  )
endif()

install(DIRECTORY bagfiles
        DESTINATION share/inverse_dynamics_interface_pinocchio
)

install(DIRECTORY launch
        DESTINATION share/inverse_dynamics_interface_pinocchio
)

install(DIRECTORY include/
        DESTINATION include
)
install(TARGETS inverse_dynamics_interface_pinocchio
        EXPORT export_inverse_dynamics_interface_pinocchio
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_inverse_dynamics_interface_pinocchio)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
