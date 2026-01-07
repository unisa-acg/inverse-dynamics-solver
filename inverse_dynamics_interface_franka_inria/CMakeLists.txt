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

set(THIS_PACKAGE_INCLUDE_DEPENDS
    pluginlib inverse_dynamics_interface
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

add_library(inverse_dynamics_interface_franka_inria SHARED
            src/get_CoriolisMatrix.cpp
            src/get_FrictionTorque.cpp
            src/get_GravityVector_eigen.cpp
            src/get_MassMatrix_parziale.cpp
            src/inverse_dynamics_interface_franka_inria.cpp
)
target_compile_features(
  inverse_dynamics_interface_franka_inria
  PUBLIC cxx_std_17
)
target_include_directories(
  inverse_dynamics_interface_franka_inria
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/inverse_dynamics_interface_franka_inria>
)
target_link_libraries(
  inverse_dynamics_interface_franka_inria
  PUBLIC pluginlib::pluginlib inverse_dynamics_interface::inverse_dynamics_interface
)

pluginlib_export_plugin_description_file(
  inverse_dynamics_interface inverse_dynamics_interface_franka_inria.xml
)

install(DIRECTORY bagfiles
        DESTINATION share/inverse_dynamics_interface_franka_inria
)

install(DIRECTORY launch
        DESTINATION share/inverse_dynamics_interface_franka_inria
)

install(DIRECTORY include/
        DESTINATION include
)
install(FILES inverse_dynamics_interface_franka_inria.xml
        DESTINATION share/inverse_dynamics_interface_franka_inria
)
install(TARGETS inverse_dynamics_interface_franka_inria
        EXPORT export_inverse_dynamics_interface_franka_inria
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_inverse_dynamics_interface_franka_inria)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
