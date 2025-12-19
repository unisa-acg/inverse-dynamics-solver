cmake_minimum_required(VERSION 3.8)
project(ur10_inverse_dynamics_solver)

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
    pluginlib inverse_dynamics_solver
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

add_library(ur10_inverse_dynamics_solver SHARED
            src/getCoriolisCurrents.cpp
            src/getCurrents.cpp
            src/getGravityCurrents.cpp
            src/getInertiaCurrents.cpp
            src/ur10_inverse_dynamics_solver.cpp
)
target_compile_features(
  ur10_inverse_dynamics_solver
  PUBLIC cxx_std_17
)
target_include_directories(
  ur10_inverse_dynamics_solver
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/ur10_inverse_dynamics_solver>
)
target_link_libraries(
  ur10_inverse_dynamics_solver
  PUBLIC pluginlib::pluginlib inverse_dynamics_solver::inverse_dynamics_solver
)

pluginlib_export_plugin_description_file(inverse_dynamics_solver ur10_inverse_dynamics_solver.xml)

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
      ur10_inverse_dynamics_solver_test
  )
  ament_add_gtest_executable(${TEST_NAME} test/test_ur10_inverse_dynamics_solver.cpp)
  target_link_libraries(
    ${TEST_NAME}
    rclcpp::rclcpp
    rosbag2_cpp::rosbag2_cpp
    ${trajectory_msgs_TARGETS}
    inverse_dynamics_solver::inverse_dynamics_solver
    ur10_inverse_dynamics_solver
  )
  add_ros_test(test/test_ur10_inverse_dynamics_solver.py)

  install(DIRECTORY test/bagfiles
          DESTINATION share/ur10_inverse_dynamics_solver
  )
  install(TARGETS ${TEST_NAME}
          RUNTIME DESTINATION lib/ur10_inverse_dynamics_solver
  )
endif()

install(DIRECTORY bagfiles
        DESTINATION share/ur10_inverse_dynamics_solver
)

install(DIRECTORY launch
        DESTINATION share/ur10_inverse_dynamics_solver
)

install(DIRECTORY include/
        DESTINATION include
)
install(TARGETS ur10_inverse_dynamics_solver
        EXPORT export_ur10_inverse_dynamics_solver
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_ur10_inverse_dynamics_solver)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
