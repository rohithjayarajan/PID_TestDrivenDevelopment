/**
 *  Copyright 2018 rohith jayarajan
 *  @file    main.cpp
 *  @author  rohithjayarajan (driver) and harshkakashaniya (navigator)
 *  @date    9/22/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 4, Test Driven Development
 *
 *  @section DESCRIPTION
 *
 *  An implementation of a PID Controller for a new mobile
 *  robot product development at Acme Robotics
 *
 */

#include <PIDController.hpp>

int main() {
  PIDController PID;

  PID.setGainKp(0.4);
  PID.setGainKi(0.2);
  PID.setGainKd(0.01);
  PID.setTimeStep(0.01);
  double actualVelocity = 1.0;
  double setVelocity = 5.0;
  std::cout << "Initial velocity = " << actualVelocity << std::endl;
  std::cout << "Reference velocity = " << setVelocity << std::endl;

  actualVelocity = PID.computeVelocity(setVelocity, actualVelocity);
  std::cout << "Current velocity = " << actualVelocity << std::endl;

  std::cout << "Values of PID gains are as follows" << std::endl;
  std::cout << "Proportional gain: " << PID.getGainKp() << std::endl;
  std::cout << "Integral gain: " << PID.getGainKi() << std::endl;
  std::cout << "Differential gain: " << PID.getGainKd() << std::endl;
  return 0;
}
