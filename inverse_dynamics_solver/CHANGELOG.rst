^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package inverse_dynamics_solver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

6.0.4 (2026-06-19)
------------------
* Merge remote-tracking branch 'origin/main' into HEAD
* Merge pull request `#20 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/20>`_ from wentasah/argparse-dep
  Don't depend on Python 2 argparse
* [FIX] Fix deprecation warnings
* Don't depend Python 2 argparse
  It's rosdep entry is going to be removed.
  See https://github.com/ros/rosdistro/issues/51715.
  argparse is in Python 3 standard library so it doesn't need to be
  referenced explicitly.
* Contributors: Michal Sojka, Vincenzo Petrone

6.0.3 (2026-02-11)
------------------
* Merge branch 'main' into rolling
* Merge pull request `#15 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/15>`_ from unisa-acg/bugfix/realtime_safeness
  bugfix/realtime_safeness
* [MAK] Add trailing underscore to private member attributes
* [FIX] Deallocate variables
  - [REF] Use new instead of malloc
  - [ADD] Initialize pointers
  - [ADD] Measure performance in terms of computation time
* Merge branch 'main' into bugfix/realtime_safeness
* Contributors: Enrico Ferrentino, Vincenzo Petrone

6.0.2 (2026-01-09)
------------------
* Merge branch 'main' into bugfix/empty_tip_root
* Contributors: Vincenzo Petrone

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
