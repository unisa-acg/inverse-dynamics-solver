^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package inverse_dynamics_solver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

6.0.1 (2025-12-18)
------------------
* Merge pull request `#11 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/11>`_ from unisa-acg/feature/update_dependencies_exporting
  feature/update_dependencies_exporting
* [REF] Avoid using variable for consistency
* [REF] Reduce direct dependencies when possible
  - [FIX] Add missing KDL dependencies
  - [DOC] Change citation in UR10 solver
* Merge branch 'main' into feature/update_dependencies_exporting
* [REF] Solve compilation warnings about deprecation of "ament_target_dependencies" in favor of "target_link_libraries"
  - [REF] Add missing dependencies
* Merge pull request `#10 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/10>`_ from unisa-acg/feature/franka_description_removal
  feature/franka_description_removal
* [MAK] Update CMakeLists and package.xml to include new dependencies and refactor inverse dynamic solver target export
* [REF] Remove Franka's demos because Franka's description is not available in Jazzy
  - [DOC] Update documentation accordingly
* [REF] Make robot description empty by default
* Merge pull request `#5 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/5>`_ from unisa-acg/humble
  1.0.1
* Contributors: Davide Risi, Enrico Ferrentino, Vincenzo Petrone

1.0.1 (2025-07-25)
------------------
* [REF] Remove unnecessary specification of rosbag2 reader plugin, uses default
* Contributors: Vincenzo Petrone

1.0.0 (2025-04-13)
------------------
* [FIX] Update missing dependencies in demo to include plugins to read bag files with sqlite3
* [REF] Rename .h files to .hpp files
* Merge pull request `#2 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/2>`_ from unisa-acg/humble
  Set repo URL, rename test launch files, document CO reproducibility
* [MAK] Add repo URL
* Contributors: Enrico Ferrentino, Vincenzo Petrone

0.1.1 (2025-04-03)
------------------
* [MAK] Create CHANGELOG files
* [MAK] Commit for release
* Contributors: Vincenzo Petrone
