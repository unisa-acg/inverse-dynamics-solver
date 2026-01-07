^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package ur10_inverse_dynamics_solver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

6.0.1 (2025-12-18)
------------------
* Merge pull request `#11 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/11>`_ from unisa-acg/feature/update_dependencies_exporting
  feature/update_dependencies_exporting
* [REF] Remove eigen dependency from package.xml
* [REF] Reduce direct dependencies when possible
  - [FIX] Add missing KDL dependencies
  - [DOC] Change citation in UR10 solver
* [FIX] Correct eigen name in package description
* Merge branch 'main' into feature/update_dependencies_exporting
* [REF] Solve compilation warnings about deprecation of "ament_target_dependencies" in favor of "target_link_libraries"
  - [REF] Add missing dependencies
* Merge pull request `#10 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/10>`_ from unisa-acg/feature/franka_description_removal
  feature/franka_description_removal
* [DOC] Remove superfluous instructions in documentation about ros bag files conversion
* Merge pull request `#5 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/5>`_ from unisa-acg/humble
  1.0.1
* Contributors: Enrico Ferrentino, Vincenzo Petrone

1.0.1 (2025-07-25)
------------------
* [REF] Remove unnecessary specification of rosbag2 reader plugin, uses default
* Contributors: Vincenzo Petrone

1.0.0 (2025-04-13)
------------------
* [REF] Rename .h files to .hpp files
* Merge pull request `#3 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/3>`_ from unisa-acg/humble
  Fix error in opening bag file due to unset storage options
* [FIX] Fix error in opening bag file due to unset storage options
* Merge pull request `#2 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/2>`_ from unisa-acg/humble
  Set repo URL, rename test launch files, document CO reproducibility
* [REF] Rename launch file to change its extension and folder
* [MAK] Add repo URL
* Merge pull request `#1 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/1>`_ from unisa-acg/humble
  [DOC] Add references for papers
* [DOC] Add references for paper in which the dynamic models have been identified
* Contributors: Enrico Ferrentino, Vincenzo Petrone

0.1.1 (2025-04-03)
------------------
* [MAK] Create CHANGELOG files
* [MAK] Commit for release
* Contributors: Vincenzo Petrone
