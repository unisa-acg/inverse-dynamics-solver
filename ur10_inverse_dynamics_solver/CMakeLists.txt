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

# find dependencies
find_package(ament_cmake REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    inverse_dynamics_solver pluginlib
)

foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

# add library
add_library(ur10_inverse_dynamics_solver SHARED
            src/getCoriolisCurrents.cpp
            src/getCurrents.cpp
            src/getGravityCurrents.cpp
            src/getInertiaCurrents.cpp
            src/ur10_inverse_dynamics_solver.cpp
)
target_compile_features(
  ur10_inverse_dynamics_solver
  PUBLIC c_std_99 cxx_std_17
) # Require C99 and C++17
target_include_directories(
  ur10_inverse_dynamics_solver
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(ur10_inverse_dynamics_solver ${THIS_PACKAGE_INCLUDE_DEPENDS})

# create plugin
pluginlib_export_plugin_description_file(inverse_dynamics_solver ur10_inverse_dynamics_solver.xml)

# Causes the visibility macros to use dllexport rather than dllimport, which is appropriate when
# building the dll but not consuming it.
target_compile_definitions(
  ur10_inverse_dynamics_solver
  PRIVATE "UR10_INVERSE_DYNAMICS_SOLVER_BUILDING_LIBRARY"
)

# install library
install(DIRECTORY include/
        DESTINATION include
)
install(FILES ur10_inverse_dynamics_solver.xml
        DESTINATION share/ur10_inverse_dynamics_solver
)
install(TARGETS ur10_inverse_dynamics_solver
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
  ament_add_gtest_executable(${TEST_NAME} test/test_ur10_inverse_dynamics_solver.cpp)
  ament_target_dependencies(
    ${TEST_NAME}
    ${THIS_TEST_PACKAGE_INCLUDE_DEPENDS}
    inverse_dynamics_solver
  )
  add_ros_test(test/test_ur10_inverse_dynamics_solver.py)

  target_link_libraries(${TEST_NAME} ur10_inverse_dynamics_solver)

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
