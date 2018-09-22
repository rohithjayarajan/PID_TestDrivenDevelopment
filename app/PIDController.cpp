/**
 *  Copyright 2018 rohith jayarajan
 *  @file    PIDController.cpp
 *  @author  rohithjayarajan (driver) and harshkakashaniya (navigator)
 *  @date    9/22/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 4, Test Driven Development
 *
 *  @section DESCRIPTION
 *
 *  Class member functions for PIDController.hpp
 *
 */

#include "PIDController.hpp"

/**
 *   @brief Default constructor for PIDController
 *          with Kp, Ki and Kd initialized to
 *          random values
 *
 *   @param nothing
 *   @return nothing
 */

PIDController::PIDController() {
  // TODO(rohithjayarajan) Auto-generated constructor stub
  Kp = 10.0;
  Ki = 100.0;
  Kd = 1.0;
  dt = -0.01;
}

/**
 *   @brief Default destructor for PIDController
 *
 *   @param nothing
 *   @return nothing
 */

PIDController::~PIDController() {
  // TODO(rohithjayarajan) Auto-generated destructor stub
}

/**
 *   @brief Function to compute velocity given
 *          a known target setpoint and the
 *          actual velocity
 *
 *   @param targetSetpoint is a double value of the
 *          setpoint of the target
 *   @param actualVelocity is the actual velocity of
 *          the type double
 *   @return double value of the computed velocity
 */

double PIDController::computeVelocity(double targetSetpoint,
                                      double actualVelocity) {
  // TODO(rohithjayarajan) computeVelocity stub
  return 11.1;
}

/**
 *   @brief Function to set PID gains Kp, Ki and Kd
 *
 *   @param double value of proportional gain
 *   @param double value of integral gain
 *   @param double value of differential gain
 *   @return nothing
 */

void PIDController::setGains(double Kp, double Ki, double Kd) {
  // TODO(rohithjayarajan) setGains stub
}

/**
 *   @brief Function to display present values of
 *          PID gains Kp, Ki and Kd
 *
 *   @param nothing
 *   @return nothing
 */

void PIDController::displayGains() {
  // TODO(rohithjayarajan) displayGains stub
}
