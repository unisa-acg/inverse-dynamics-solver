^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package kdl_inverse_dynamics_solver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

3.0.0 (2026-06-19)
------------------
* Merge pull request `#20 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/20>`_ from wentasah/argparse-dep
  Don't depend on Python 2 argparse
* [FIX] Fix deprecation warnings
* Merge pull request `#15 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/15>`_ from unisa-acg/bugfix/realtime_safeness
  bugfix/realtime_safeness
* [REF] Use mutable instead of pointers
* Merge branch 'main' into bugfix/realtime_safeness
* Merge pull request `#13 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/13>`_ from unisa-acg/bugfix/empty_tip_root
  bugfix/empty_tip_root
* [REF] Use param_namespace instead of ns in warning/error messages to print the namespace without a trailing dot
  - [DOC] Fix Doxygen and inline documentation to comply to the last implementation and fix typos
* [FIX] Deallocate variables
  - [REF] Use new instead of malloc
  - [ADD] Initialize pointers
  - [ADD] Measure performance in terms of computation time
* [REF] Manages missing/empty root/tip parameters with different logics
  - [TST] Add related tests
* [REF] Reorder dependencies alphabetically
* Merge branch 'main' into bugfix/realtime_safeness
* Merge branch 'main' into bugfix/empty_tip_root
* [FIX] Fix allocation of zero-vector
* [FIX] Avoid dynamic allocation when returning a zero-vector
* [FIX] Enforce real-time safeness by avoiding dynamic allocations of vectors
* [FIX] Handle empty root and tip parameters
  - [ADD] With empty root, defaults to chain root
  - [ADD] With empty tip, raises an exception
  - [TST] Add two test fixtures to test the two scenarios above
* Contributors: Enrico Ferrentino, Vincenzo Petrone

6.0.1 (2025-12-18)
------------------
* Merge pull request `#11 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/11>`_ from unisa-acg/feature/update_dependencies_exporting
  feature/update_dependencies_exporting
* [REF] Reduce direct dependencies when possible
  - [FIX] Add missing KDL dependencies
  - [DOC] Change citation in UR10 solver
* [FIX] Correct eigen name in package description
* Merge branch 'main' into feature/update_dependencies_exporting
* [REF] Solve compilation warnings about deprecation of "ament_target_dependencies" in favor of "target_link_libraries"
  - [REF] Add missing dependencies
* Merge pull request `#10 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/10>`_ from unisa-acg/feature/franka_description_removal
  feature/franka_description_removal
* [MAK] Update CMakeLists and package.xml to include new dependencies and refactor inverse dynamic solver target export
* [REF] Remove Franka's demos because Franka's description is not available in Jazzy
  - [DOC] Update documentation accordingly
* Merge pull request `#5 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/5>`_ from unisa-acg/humble
  1.0.1
* Contributors: Davide Risi, Enrico Ferrentino, Vincenzo Petrone

1.0.1 (2025-07-25)
------------------

1.0.0 (2025-04-13)
------------------
* [REF] Rename .h files to .hpp files
* Merge pull request `#2 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/2>`_ from unisa-acg/humble
  Set repo URL, rename test launch files, document CO reproducibility
* [REF] Rename launch file to change its extension and folder
* [MAK] Add repo URL
* Contributors: Enrico Ferrentino, Vincenzo Petrone

0.1.1 (2025-04-03)
------------------
* [MAK] Create CHANGELOG files
* [MAK] Commit for release
* Contributors: Vincenzo Petrone
