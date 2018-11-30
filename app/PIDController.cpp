/**
 *  Copyright 2018 rohith jayarajan
 *  @file    PIDController.cpp
 *  @author  rohithjayarajan
 *  @date    11/29/2018
 *  @version 2.0
 *
 *  @brief UMD ENPM 808X, Week 4, Test Driven Development
 *
 *  @section DESCRIPTION
 *
 *  Class member functions for PIDController.hpp
 *
 */

#include "PIDController.hpp"
#include "ControlSystemHelper.hpp"

/**
 *   @brief Default constructor for PIDController
 *          with Kp, Ki and Kd initialized to
 *          random values
 *
 *   @param nothing
 *   @return nothing
 */
PIDController::PIDController() {
  Kp = 10.0;
  Ki = 100.0;
  Kd = 0.01;
  dt = 0.01;
}
/**
 *   @brief Default destructor for PIDController
 *
 *   @param nothing
 *   @return nothing
 */
PIDController::~PIDController() {}
/**
 *   @brief Function to compute Control Signal information given
 *          a known target setpoint and the
 *          actual velocity
 *
 *   @param targetSetpoint is a double value of the
 *          setpoint of the target
 *   @param initialVelocity is the actual velocity of
 *          the type double
 *   @return double value of the commandVelocity velocity
 */
double PIDController::computeControlSignalInfo(ControlSystemHelper &helper,
                                               double targetSetPoint,
                                               double initialVelocity) {
  double commandVelocity =
      helper.computeVelocity(targetSetPoint, initialVelocity, Kp, Ki, Kd, dt);
  // debug
  // std::cout << "$$$$$$$$$$$$$$$$$$$$$$$" << commandVelocity << std::endl;
  double error = helper.computeError(targetSetPoint);
  return commandVelocity;
}
/**
 *   @brief Function to set PID gain Kp
 *
 *   @param double value of proportional gain
 *   @return nothing
 */
void PIDController::setGainKp(double Kp) { this->Kp = Kp; }
/**
 *   @brief Function to set PID gain Ki
 *
 *   @param double value of integral gain
 *   @return nothing
 */
void PIDController::setGainKi(double Ki) { this->Ki = Ki; }
/**
 *   @brief Function to set PID gains Kd
 *
 *   @param double value of differential gain
 *   @return nothing
 */
void PIDController::setGainKd(double Kd) { this->Kd = Kd; }
/**
 *   @brief Function to set Time Step dt
 *
 *   @param double value of Time Step dt
 *   @return nothing
 */
void PIDController::setTimeStep(double dt) { this->dt = dt; }
/**
 *   @brief Function to get present values of
 *          PID gain Kp
 *
 *   @param nothing
 *   @return double value of proportional gain
 */
double PIDController::getGainKp() { return this->Kp; }
/**
 *   @brief Function to get present values of
 *          PID gain Ki
 *
 *   @param nothing
 *   @return double value of integral gain
 */
double PIDController::getGainKi() { return this->Ki; }
/**
 *   @brief Function to get present values of
 *          PID gain Kd
 *
 *   @param nothing
 *   @return double value of differential gain
 */
double PIDController::getGainKd() { return this->Kd; }
/**
 *   @brief Function to get Time Step dt
 *return this->dt;
 *   @param nothing
 *   @return double value of Time Step dt
 */
double PIDController::getTimeStep() { return this->dt; }
