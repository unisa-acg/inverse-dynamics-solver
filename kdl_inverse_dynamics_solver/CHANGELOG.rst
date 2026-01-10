^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package kdl_inverse_dynamics_solver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2.0.2 (2026-01-10)
------------------

2.0.1 (2026-01-09)
------------------
* Merge branch 'main' into jazzy
* Merge branch 'jazzy' of github.com:unisa-acg/inverse-dynamics-solver into jazzy
* Merge pull request `#13 <https://github.com/unisa-acg/inverse-dynamics-solver/issues/13>`_ from unisa-acg/bugfix/empty_tip_root
  bugfix/empty_tip_root
* [REF] Use param_namespace instead of ns in warning/error messages to print the namespace without a trailing dot
  - [DOC] Fix Doxygen and inline documentation to comply to the last implementation and fix typos
* [REF] Manages missing/empty root/tip parameters with different logics
  - [TST] Add related tests
* [REF] Reorder dependencies alphabetically
* Merge branch 'main' into bugfix/empty_tip_root
* [FIX] Handle empty root and tip parameters
  - [ADD] With empty root, defaults to chain root
  - [ADD] With empty tip, raises an exception
  - [TST] Add two test fixtures to test the two scenarios above
* 2.0.0
* [MAK] Update changelog
* [DOC] Update links to match Jazzy distro
* Contributors: Enrico Ferrentino, Vincenzo Petrone

2.0.0 (2025-09-16)
------------------
* [DOC] Update links to match Jazzy distro
* [REF] Remove Franka's demos because Franka's description is not available in Jazzy
  - [DOC] Update documentation accordingly
* Contributors: Enrico Ferrentino, Vincenzo Petrone

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
