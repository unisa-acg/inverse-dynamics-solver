cmake_minimum_required(VERSION 3.8)
project(kdl_inverse_dynamics_solver)

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
    inverse_dynamics_solver
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

add_library(kdl_inverse_dynamics_solver SHARED
            src/kdl_inverse_dynamics_solver.cpp
)
target_compile_features(
  kdl_inverse_dynamics_solver
  PUBLIC cxx_std_17
)
target_include_directories(
  kdl_inverse_dynamics_solver
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/kdl_inverse_dynamics_solver>
)
target_link_libraries(
  kdl_inverse_dynamics_solver
  PUBLIC kdl_parser::kdl_parser
         pluginlib::pluginlib
         rclcpp::rclcpp
         urdf::urdf
         inverse_dynamics_solver::inverse_dynamics_solver
)

pluginlib_export_plugin_description_file(inverse_dynamics_solver kdl_inverse_dynamics_solver.xml)

if(BUILD_TESTING)
  # find dependencies
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ros_testing REQUIRED)
  find_package(rclcpp REQUIRED)

  # add test on 2R planar
  ament_add_gtest_executable(kdl_ids_on_2r_planar_test test/test_kdl_ids_on_2r_planar.cpp)
  target_link_libraries(
    kdl_ids_on_2r_planar_test
    pluginlib::pluginlib
    rclcpp::rclcpp
    inverse_dynamics_solver::inverse_dynamics_solver
    kdl_inverse_dynamics_solver
  )
  add_ros_test(test/test_kdl_ids_on_2r_planar.py)

  # add test on 3R planar
  ament_add_gtest_executable(kdl_ids_on_3r_planar_test test/test_kdl_ids_on_3r_planar.cpp)
  target_link_libraries(
    kdl_ids_on_3r_planar_test
    pluginlib::pluginlib
    rclcpp::rclcpp
    inverse_dynamics_solver::inverse_dynamics_solver
    kdl_inverse_dynamics_solver
  )
  add_ros_test(test/test_kdl_ids_on_3r_planar.py)

  # install tests
  install(TARGETS kdl_ids_on_3r_planar_test kdl_ids_on_2r_planar_test
          RUNTIME DESTINATION lib/kdl_inverse_dynamics_solver
  )
endif()

install(DIRECTORY bagfiles
        DESTINATION share/kdl_inverse_dynamics_solver
)

install(DIRECTORY launch
        DESTINATION share/kdl_inverse_dynamics_solver
)

install(DIRECTORY include/
        DESTINATION include
)
install(TARGETS kdl_inverse_dynamics_solver
        EXPORT export_kdl_inverse_dynamics_solver
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_kdl_inverse_dynamics_solver)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
