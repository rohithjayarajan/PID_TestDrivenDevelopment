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
#include <iostream>
#include "PIDController.hpp"

using std::cout;
using std::endl;
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
PIDController::~PIDController() {
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
double PIDController::computeVelocity(double targetSetPoint,
                                      double actualVelocity) {
  actualVelocity = (this->Kp) * (targetSetPoint - actualVelocity)
      + (this->Ki) * (targetSetPoint - actualVelocity) * (this->dt)
      + (this->Kd) * (targetSetPoint - actualVelocity) / (this->dt);
  return actualVelocity;
}
/**
 *   @brief Function to set PID gain Kp
 *
 *   @param double value of proportional gain
 *   @return nothing
 */
void PIDController::setGainKp(double Kp) {
  this->Kp = Kp;
}
/**
 *   @brief Function to set PID gain Ki
 *
 *   @param double value of integral gain
 *   @return nothing
 */
void PIDController::setGainKi(double Ki) {
  this->Ki = Ki;
}
/**
 *   @brief Function to set PID gains Kd
 *
 *   @param double value of differential gain
 *   @return nothing
 */
void PIDController::setGainKd(double Kd) {
  this->Kd = Kd;
}
/**
 *   @brief Function to set Time Step dt
 *
 *   @param double value of Time Step dt
 *   @return nothing
 */
void PIDController::setTimeStep(double dt) {
  this->dt = dt;
}
/**
 *   @brief Function to get present values of
 *          PID gain Kp
 *
 *   @param nothing
 *   @return double value of proportional gain
 */
double PIDController::getGainKp() {
  return this->Kp;
}
/**
 *   @brief Function to get present values of
 *          PID gain Ki
 *
 *   @param nothing
 *   @return double value of integral gain
 */
double PIDController::getGainKi() {
  return this->Ki;
}
/**
 *   @brief Function to get present values of
 *          PID gain Kd
 *
 *   @param nothing
 *   @return double value of differential gain
 */
double PIDController::getGainKd() {
  return this->Kd;
}
/**
 *   @brief Function to get Time Step dt
 *return this->dt;
 *   @param nothing
 *   @return double value of Time Step dt
 */
double PIDController::getTimeStep() {
  return this->dt;
}
