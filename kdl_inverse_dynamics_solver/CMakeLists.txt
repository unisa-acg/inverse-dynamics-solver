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

# find dependencies
find_package(ament_cmake REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    kdl_parser
    pluginlib
    inverse_dynamics_solver
)

foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

# add library
add_library(kdl_inverse_dynamics_solver SHARED
            src/kdl_inverse_dynamics_solver.cpp
)
target_compile_features(
  kdl_inverse_dynamics_solver
  PUBLIC c_std_99 cxx_std_17
) # Require C99 and C++17
target_include_directories(
  kdl_inverse_dynamics_solver
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(kdl_inverse_dynamics_solver ${THIS_PACKAGE_INCLUDE_DEPENDS})

# create plugin
pluginlib_export_plugin_description_file(inverse_dynamics_solver kdl_inverse_dynamics_solver.xml)

# Causes the visibility macros to use dllexport rather than dllimport, which is appropriate when
# building the dll but not consuming it.
target_compile_definitions(
  kdl_inverse_dynamics_solver
  PRIVATE "KDL_INVERSE_DYNAMICS_SOLVER_BUILDING_LIBRARY"
)

# install library
install(DIRECTORY include/
        DESTINATION include
)
install(FILES kdl_inverse_dynamics_solver.xml
        DESTINATION share/kdl_inverse_dynamics_solver
)
install(TARGETS kdl_inverse_dynamics_solver
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
  ament_add_gtest_executable(${TEST_NAME} test/test_kdl_inverse_dynamics_solver.cpp)
  ament_target_dependencies(
    ${TEST_NAME}
    rclcpp
    pluginlib
    inverse_dynamics_solver
  )
  add_ros_test(test/test_kdl_inverse_dynamics_solver.py)

  target_link_libraries(${TEST_NAME} kdl_inverse_dynamics_solver)

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
