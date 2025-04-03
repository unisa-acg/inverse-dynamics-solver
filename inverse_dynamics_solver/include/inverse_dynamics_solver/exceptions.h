/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   exceptions.h
 * Author:  Vincenzo Petrone
 * Org.:    UNISA
 * Date:    May 2, 2024
 *
 * This library is a stub for plugging in domain specific exceptions.
 *
 * -------------------------------------------------------------------
 */

#pragma once

#include <rclcpp/exceptions/exceptions.hpp>

namespace inverse_dynamics_solver
{

typedef rclcpp::exceptions::InvalidParameterValueException InvalidParameterValueException;
typedef rclcpp::exceptions::ParameterUninitializedException ParameterUninitializedException;

class UninitializedException : public std::runtime_error
{
public:
  UninitializedException() : std::runtime_error("Solver is not initialized") {}
};
}  // namespace inverse_dynamics_solver
