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

# find dependencies
find_package(ament_cmake REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    Eigen3
    rclcpp
    urdfdom
    pluginlib
    pinocchio
    inverse_dynamics_interface
)

foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

# add library
add_library(inverse_dynamics_interface_pinocchio SHARED
            src/inverse_dynamics_interface_pinocchio.cpp
)
target_compile_features(
  inverse_dynamics_interface_pinocchio
  PUBLIC c_std_99 cxx_std_17
) # Require C99 and C++17
target_include_directories(
  inverse_dynamics_interface_pinocchio
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
target_link_libraries(
  inverse_dynamics_interface_pinocchio
  PUBLIC Eigen3::Eigen
         rclcpp::rclcpp
         urdfdom::urdf_parser
         pluginlib::pluginlib
         pinocchio::pinocchio
         inverse_dynamics_interface::inverse_dynamics_interface_lib
)

# create plugin
pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_pinocchio.xml
)

# Causes the visibility macros to use dllexport rather than dllimport, which is appropriate when
# building the dll but not consuming it.
target_compile_definitions(
  inverse_dynamics_interface_pinocchio
  PRIVATE "INVERSE_DYNAMICS_INTERFACE_PINOCCHIO_BUILDING_LIBRARY"
)

# install library
install(DIRECTORY include/
        DESTINATION include
)
install(FILES inverse_dynamics_interface_pinocchio.xml
        DESTINATION share/inverse_dynamics_interface_pinocchio
)
install(TARGETS inverse_dynamics_interface_pinocchio
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
  find_package(rclcpp REQUIRED)

  # add test on 2R planar
  ament_add_gtest_executable(pinocchio_interface_on_2r_planar_test
                             test/test_pinocchio_interface_on_2r_planar.cpp
  )
  target_link_libraries(
    pinocchio_interface_on_2r_planar_test
    rclcpp::rclcpp
    pluginlib::pluginlib
    inverse_dynamics_interface::inverse_dynamics_interface_lib
    inverse_dynamics_interface_pinocchio
  )
  add_ros_test(test/test_pinocchio_interface_on_2r_planar.py)

  # add test on 3R planar
  ament_add_gtest_executable(pinocchio_interface_on_3r_planar_test
                             test/test_pinocchio_interface_on_3r_planar.cpp
  )
  target_link_libraries(
    pinocchio_interface_on_3r_planar_test
    rclcpp::rclcpp
    pluginlib::pluginlib
    inverse_dynamics_solver::inverse_dynamics_solver_lib
    pinocchio_inverse_dynamics_solver
  )
  add_ros_test(test/test_pinocchio_interface_on_3r_planar.py)

  install(TARGETS pinocchio_interface_on_2r_planar_test pinocchio_interface_on_3r_planar_test
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
