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

#include <iostream>
#include <memory>
#include <PIDController.hpp>

using std::shared_ptr;
using std::cout;
using std::endl;
using std::make_shared;

int main() {
  // Created an object of class PIDController.
  shared_ptr<PIDController> PID;
  PID = make_shared<PIDController>();
  // Calling the setGains function to set the values of gains Kp, Ki, and Kd.
  double actualVelocity = 1.0;
  double setVelocity = 5.0;
  cout << "Initial velocity = " << actualVelocity << endl;
  cout << "Reference velocity = " << setVelocity << endl;
  // Calling the computeVelocity function by setting the targetSetpoint
  // and actualVelocity.
  actualVelocity = PID->computeVelocity(setVelocity, actualVelocity);
  cout << "Current velocity = " << actualVelocity << endl;
  // Calling the displayGains function to display gains.
  return 0;
}
