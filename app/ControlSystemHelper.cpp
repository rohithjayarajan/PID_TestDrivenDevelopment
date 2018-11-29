/**
 *  Copyright 2018 rohith jayarajan
 *  @file    ControlSystemHelper.cpp
 *  @author  rohithjayarajan
 *  @date    11/29/2018
 *  @version 1.0
 *
 *  @brief Source file for the ControlSystemHelper class
 *
 *  @section DESCRIPTION
 *
 *  Definition of class which includes helper functions for control system tools
 *
 */

#include "ControlSystemHelper.hpp"

/**
 *   @brief Default constructor for PIDController
 *          with Kp, Ki and Kd initialized to
 *          random values
 *
 *   @param nothing
 *   @return nothing
 */
ControlSystemHelper::ControlSystemHelper() {
  Kp = 0.0;
  Ki = 0.0;
  Kd = 0.0;
  dt = 0.0;
}
/**
 *   @brief Default destructor for ControlSystemHelper
 *
 *   @param nothing
 *   @return nothing
 */
ControlSystemHelper::~ControlSystemHelper() {}
/**
 *   @brief Function to compute velocity given
 *          a known target setpoint and the
 *          actual velocity and controller gains
 *
 *   @param targetSetpoint_ is a double value of the
 *          setpoint_ of the target
 *   @param initialVelocity_ is the actual velocity of
 *          the type double
 *   @param kp_, the proportional gain
 *   @param ki_, the integral gain
 *   @param kd_, the differential gain
 *   @param dt_, the time step
 *   @return double value of the output velocity
 */
double ControlSystemHelper::computeVelocity(double targetSetPoint_,
                                            double initialVelocity_, double kp_,
                                            double ki_, double kd_,
                                            double dt_) {
  Kp = kp_;
  Ki = ki_;
  Kd = kd_;
  dt = dt_;
  outputVelocity = (Kp) * (targetSetPoint_ - initialVelocity_) +
                   (Ki) * (targetSetPoint_ - initialVelocity_) * (dt) +
                   (Kd) * (targetSetPoint_ - initialVelocity_) / (dt);
  return outputVelocity;
}
/**
 *   @brief Function to compute error in tracking
 *
 *   @param targetSetpoint_ is a double value of the
 *          setpoint of the target
 *
 *   @return double value of the tracking error
 */
double ControlSystemHelper::computeError(double targetSetPoint_) {
  return (targetSetPoint_ - outputVelocity);
}
