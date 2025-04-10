/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   getCurrents.h
 * Author:  Antonio Annunziata, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Jul 14, 2023
 *
 * This is a function returning the joint currents according to the
 * UR10's dynamic model, given the joint positions, velocities and
 * accelerations. The function is automatically generated by MATLAB
 * (see details below) based on the UR10's dynamic model's regressive
 * form.
 * Note: the dynamic model considered by this function only takes into
 * account linear contributions, hence friction effects are discarded.
 *
 * -------------------------------------------------------------------
 */

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: getCurrents.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 14-Jul-2023 17:08:21
//

#pragma once

// Include Files
// #include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ur10_inverse_dynamics_solver
{
extern void getCurrents(const double joint_positions[6], const double joint_velocities[6], const double joint_accelerations[6], double currents[6]);

}

//
// File trailer for getCurrents.h
//
// [EOF]
//
