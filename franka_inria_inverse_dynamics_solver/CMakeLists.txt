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

# find dependencies
find_package(ament_cmake REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    Eigen3
    pluginlib
    inverse_dynamics_solver
)

foreach(dependency IN
        ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
  find_package(${dependency} REQUIRED)
endforeach()

# add library
add_library(franka_inria_inverse_dynamics_solver SHARED
            src/get_CoriolisMatrix.cpp
            src/get_FrictionTorque.cpp
            src/get_GravityVector_eigen.cpp
            src/get_MassMatrix_parziale.cpp
            src/franka_inria_inverse_dynamics_solver.cpp
)
target_compile_features(
  franka_inria_inverse_dynamics_solver
  PUBLIC c_std_99 cxx_std_17
) # Require C99 and C++17
target_include_directories(
  franka_inria_inverse_dynamics_solver
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(franka_inria_inverse_dynamics_solver ${THIS_PACKAGE_INCLUDE_DEPENDS})

# create plugin
pluginlib_export_plugin_description_file(
  inverse_dynamics_solver franka_inria_inverse_dynamics_solver.xml
)

# Causes the visibility macros to use dllexport rather than dllimport, which is appropriate when
# building the dll but not consuming it.
target_compile_definitions(
  franka_inria_inverse_dynamics_solver
  PRIVATE "FRANKA_INRIA_INVERSE_DYNAMICS_SOLVER_BUILDING_LIBRARY"
)

# install library
install(DIRECTORY include/
        DESTINATION include
)
install(FILES franka_inria_inverse_dynamics_solver.xml
        DESTINATION share/franka_inria_inverse_dynamics_solver
)
install(TARGETS franka_inria_inverse_dynamics_solver
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
