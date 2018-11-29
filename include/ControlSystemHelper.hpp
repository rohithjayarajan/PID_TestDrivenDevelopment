/**
 *  Copyright 2018 rohith jayarajan
 *  @file    ControlSystemHelper.hpp
 *  @author  rohithjayarajan
 *  @date    11/29/2018
 *  @version 1.0
 *
 *  @brief Header file for the ControlSystemHelper class
 *
 *  @section DESCRIPTION
 *
 *  Class which includes helper functions for control system tools
 *
 */

#ifndef INCLUDE_CONTROLSYSTEMHELPER_HPP_
#define INCLUDE_CONTROLSYSTEMHELPER_HPP_

#include <iostream>

/**
 *  @brief Class ControlSystemHelper
 *  The ControlSystemHelper class contains helper functions for control system
 * tools
 */

class ControlSystemHelper {
 public:
  /**
   *   @brief Default constructor for ControlSystemHelper
   *
   *   @param nothing
   *   @return nothing
   */
  ControlSystemHelper();
  /**
   *   @brief Default destructor for ControlSystemHelper
   *
   *   @param nothing
   *   @return nothing
   */
  virtual ~ControlSystemHelper();
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
   *   @return double value of the computed velocity
   */
  virtual double computeVelocity(double targetSetPoint_,
                                 double initialVelocity_, double kp_,
                                 double ki_, double kd_, double dt_);
  /**
   *   @brief Function to compute error in tracking
   *
   *   @param targetSetpoint_ is a double value of the
   *          setpoint of the target
   *
   *   @return double value of the tracking error
   */
  virtual double computeError(double targetSetPoint_);

 private:
  double Kp;              // declare proportional gain Kp
  double Ki;              // declare integral gain Ki
  double Kd;              // declare differential gain Kd
  double dt;              // time step
  double outputVelocity;  // output velocity commanded by controller
};

#endif  // INCLUDE_CONTROLSYSTEMHELPER_HPP_
