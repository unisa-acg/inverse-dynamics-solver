cmake_minimum_required(VERSION 3.8)
project(inverse_dynamics_interface_franka_inria)

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

# Code optimization flags are available here
# https://clang.llvm.org/docs/CommandGuide/clang.html#code-generation-options
set(CMAKE_CXX_FLAGS
    "-O3"
)

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
add_library(inverse_dynamics_interface_franka_inria SHARED
            src/get_CoriolisMatrix.cpp
            src/get_FrictionTorque.cpp
            src/get_GravityVector_eigen.cpp
            src/get_MassMatrix_parziale.cpp
            src/inverse_dynamics_interface_franka_inria.cpp
)
target_compile_features(
  inverse_dynamics_interface_franka_inria
  PUBLIC c_std_99 cxx_std_17
) # Require C99 and C++17
target_include_directories(
  inverse_dynamics_interface_franka_inria
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
target_link_libraries(
  inverse_dynamics_interface_franka_inria
  PUBLIC Eigen3::Eigen
         pluginlib::pluginlib
         rclcpp::rclcpp
         inverse_dynamics_interface::inverse_dynamics_interface_lib
)

# create plugin
pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_franka_inria.xml
)

# Causes the visibility macros to use dllexport rather than dllimport, which is appropriate when
# building the dll but not consuming it.
target_compile_definitions(
  inverse_dynamics_interface_franka_inria
  PRIVATE "INVERSE_DYNAMICS_INTERFACE_FRANKA_INRIA_BUILDING_LIBRARY"
)

# install library
install(DIRECTORY include/
        DESTINATION include
)
install(FILES inverse_dynamics_interface_franka_inria.xml
        DESTINATION share/inverse_dynamics_interface_franka_inria
)
install(TARGETS inverse_dynamics_interface_franka_inria
        EXPORT export_${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

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
