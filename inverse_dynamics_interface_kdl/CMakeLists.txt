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

# find dependencies
find_package(ament_cmake REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    Eigen3
    rclcpp
    urdf
    kdl_parser
    pluginlib
    inverse_dynamics_interface
)

foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

# add library
add_library(inverse_dynamics_interface_kdl SHARED
            src/inverse_dynamics_interface_kdl.cpp
)
target_compile_features(
  inverse_dynamics_interface_kdl
  PUBLIC c_std_99 cxx_std_17
) # Require C99 and C++17
target_include_directories(
  inverse_dynamics_interface_kdl
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
target_link_libraries(
  inverse_dynamics_interface_kdl
  PUBLIC Eigen3::Eigen
         rclcpp::rclcpp
         urdf::urdf
         kdl_parser::kdl_parser
         pluginlib::pluginlib
         inverse_dynamics_interface::inverse_dynamics_interface_lib
)

# create plugin
pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_kdl.xml
)

# Causes the visibility macros to use dllexport rather than dllimport, which is appropriate when
# building the dll but not consuming it.
target_compile_definitions(
  inverse_dynamics_interface_kdl
  PRIVATE "INVERSE_DYNAMICS_SOLVER_KDL_BUILDING_LIBRARY"
)

# install library
install(DIRECTORY include/
        DESTINATION include
)
install(FILES inverse_dynamics_interface_kdl.xml
        DESTINATION share/inverse_dynamics_interface_kdl
)
install(TARGETS inverse_dynamics_interface_kdl
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

  # add tests
  set(TEST_NAME
      ${PROJECT_NAME}_test
  )
  ament_add_gtest_executable(${TEST_NAME} test/test_inverse_dynamics_interface_kdl.cpp)
  target_link_libraries(
    ${TEST_NAME}
    rclcpp::rclcpp
    pluginlib::pluginlib
    inverse_dynamics_interface::inverse_dynamics_interface_lib
    inverse_dynamics_interface_kdl
  )
  add_ros_test(test/test_inverse_dynamics_interface_kdl.py)

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
