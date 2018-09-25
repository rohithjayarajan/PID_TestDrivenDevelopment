/**
 *  Copyright 2018 rohith jayarajan
 *  @file    PIDController.hpp
 *  @author  rohithjayarajan (driver) and harshkakashaniya (navigator)
 *  @date    9/22/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 4, Test Driven Development
 *
 *  @section DESCRIPTION
 *
 *  Implementation to support PID control
 *
 */

#ifndef INCLUDE_PIDCONTROLLER_HPP_
#define INCLUDE_PIDCONTROLLER_HPP_

class PIDController {
 public:
  /**
   *   @brief Default constructor for PIDController
   *          with Kp, Ki and Kd initialized to
   *          random values
   *
   *   @param nothing
   *   @return nothing
   */
  PIDController();
  /**
   *   @brief Default destructor for PIDController
   *
   *   @param nothing
   *   @return nothing
   */
  virtual ~PIDController();
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
  double computeVelocity(double targetSetPoint, double actualVelocity);
  /**
   *   @brief Function to set PID gain Kp
   *
   *   @param double value of proportional gain
   *   @return nothing
   */
  void setGainKp(double Kp);
  /**
   *   @brief Function to set PID gain Ki
   *
   *   @param double value of integral gain
   *   @return nothing
   */
  void setGainKi(double Ki);
  /**
   *   @brief Function to set PID gains Kd
   *
   *   @param double value of differential gain
   *   @return nothing
   */
  void setGainKd(double Kd);
  /**
   *   @brief Function to set Time Step dt
   *
   *   @param double value of Time Step dt
   *   @return nothing
   */
  void setTimeStep(double dt);
  /**
   *   @brief Function to get present values of
   *          PID gain Kp
   *
   *   @param nothing
   *   @return double value of proportional gain
   */
  double getGainKp();
  /**
   *   @brief Function to get present values of
   *          PID gain Ki
   *
   *   @param nothing
   *   @return double value of integral gain
   */
  double getGainKi();
  /**
   *   @brief Function to get present values of
   *          PID gain Kd
   *
   *   @param nothing
   *   @return double value of differential gain
   */
  double getGainKd();
  /**
   *   @brief Function to get Time Step dt
   *
   *   @param nothing
   *   @return double value of Time Step dt
   */
  double getTimeStep();

 private:
  double Kp;  // declare proportional gain Kp
  double Ki;  // declare integral gain Ki
  double Kd;  // declare differential gain Kd
  double dt;  // time step
};

#endif  // INCLUDE_PIDCONTROLLER_HPP_
