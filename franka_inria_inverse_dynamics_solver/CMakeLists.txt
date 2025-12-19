cmake_minimum_required(VERSION 3.8)
project(franka_inria_inverse_dynamics_solver)

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

add_library(franka_inria_inverse_dynamics_solver SHARED
            src/get_CoriolisMatrix.cpp
            src/get_FrictionTorque.cpp
            src/get_GravityVector_eigen.cpp
            src/get_MassMatrix_parziale.cpp
            src/franka_inria_inverse_dynamics_solver.cpp
)
target_compile_features(
  franka_inria_inverse_dynamics_solver
  PUBLIC cxx_std_17
)
target_include_directories(
  franka_inria_inverse_dynamics_solver
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/franka_inria_inverse_dynamics_solver>
)
target_link_libraries(
  franka_inria_inverse_dynamics_solver
  PUBLIC pluginlib::pluginlib inverse_dynamics_solver::inverse_dynamics_solver
)

pluginlib_export_plugin_description_file(
  inverse_dynamics_solver franka_inria_inverse_dynamics_solver.xml
)

install(DIRECTORY bagfiles
        DESTINATION share/franka_inria_inverse_dynamics_solver
)

install(DIRECTORY launch
        DESTINATION share/franka_inria_inverse_dynamics_solver
)

install(DIRECTORY include/
        DESTINATION include
)
install(FILES franka_inria_inverse_dynamics_solver.xml
        DESTINATION share/franka_inria_inverse_dynamics_solver
)
install(TARGETS franka_inria_inverse_dynamics_solver
        EXPORT export_franka_inria_inverse_dynamics_solver
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

ament_export_targets(export_franka_inria_inverse_dynamics_solver)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
