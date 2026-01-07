cmake_minimum_required(VERSION 3.8)
project(pinocchio_inverse_dynamics_solver)

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
    inverse_dynamics_solver
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

add_library(pinocchio_inverse_dynamics_solver SHARED
            src/pinocchio_inverse_dynamics_solver.cpp
)
target_compile_features(
  pinocchio_inverse_dynamics_solver
  PUBLIC cxx_std_17
)
target_include_directories(
  pinocchio_inverse_dynamics_solver
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
target_link_libraries(
  pinocchio_inverse_dynamics_solver
  PUBLIC pinocchio::pinocchio
         pluginlib::pluginlib
         rclcpp::rclcpp
         urdfdom::urdf_parser
         inverse_dynamics_solver::inverse_dynamics_solver
)

pluginlib_export_plugin_description_file(
  inverse_dynamics_solver pinocchio_inverse_dynamics_solver.xml
)

if(BUILD_TESTING)
  # find dependencies
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ros_testing REQUIRED)
  find_package(rclcpp REQUIRED)

  # add test on 2R planar
  ament_add_gtest_executable(pinocchio_ids_on_2r_planar_test
                             test/test_pinocchio_ids_on_2r_planar.cpp
  )
  target_link_libraries(
    pinocchio_ids_on_2r_planar_test
    pluginlib::pluginlib
    rclcpp::rclcpp
    inverse_dynamics_solver::inverse_dynamics_solver
    pinocchio_inverse_dynamics_solver
  )
  add_ros_test(test/test_pinocchio_ids_on_2r_planar.py)

  # add test on 3R planar
  ament_add_gtest_executable(pinocchio_ids_on_3r_planar_test
                             test/test_pinocchio_ids_on_3r_planar.cpp
  )
  target_link_libraries(
    pinocchio_ids_on_3r_planar_test
    pluginlib::pluginlib
    rclcpp::rclcpp
    inverse_dynamics_solver::inverse_dynamics_solver
    pinocchio_inverse_dynamics_solver
  )
  add_ros_test(test/test_pinocchio_ids_on_3r_planar.py)

  # install tests
  install(TARGETS pinocchio_ids_on_2r_planar_test pinocchio_ids_on_3r_planar_test
          RUNTIME DESTINATION lib/pinocchio_inverse_dynamics_solver
  )
endif()

install(DIRECTORY bagfiles
        DESTINATION share/pinocchio_inverse_dynamics_solver
)

install(DIRECTORY launch
        DESTINATION share/pinocchio_inverse_dynamics_solver
)

install(DIRECTORY include/
        DESTINATION include
)
install(TARGETS pinocchio_inverse_dynamics_solver
        EXPORT export_pinocchio_inverse_dynamics_solver
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_pinocchio_inverse_dynamics_solver)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
