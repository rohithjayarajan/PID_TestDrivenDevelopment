/**
 *  Copyright 2018 rohith jayarajan
 *  @file    test.cpp
 *  @author  rohithjayarajan (driver) and harshkakashaniya (navigator)
 *  @date    9/22/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 4, Test Driven Development
 *
 *  @section DESCRIPTION
 *
 *  Tests for the PID controller
 *
 */

#include <gtest/gtest.h>
#include <memory>
#include "PIDController.hpp"

std::shared_ptr<PIDController> testObject;

//  test to check the correctness of computeVelocity method
TEST(PIDController, velocityComputedCheck) {
  testObject = std::make_shared<PIDController>();
  EXPECT_EQ(-120.0, testObject->computeVelocity(10.0, 20.0));
}
//  test to ensure Kp is set
TEST(PIDController, isGainKpSet) {
  testObject = std::make_shared<PIDController>();
  testObject->setGainKp(12.56);
  EXPECT_EQ(12.56, testObject->getGainKp());
}
//  test to ensure Ki is set
TEST(PIDController, isGainKiSet) {
  testObject = std::make_shared<PIDController>();
  testObject->setGainKi(567.76);
  EXPECT_EQ(567.76, testObject->getGainKi());
}
//  test to ensure Kd is set
TEST(PIDController, isGainKdSet) {
  testObject = std::make_shared<PIDController>();
  testObject->setGainKd(23.23);
  EXPECT_EQ(23.23, testObject->getGainKd());
}
//  test to ensure dt is set
TEST(PIDController, isDtSet) {
  testObject = std::make_shared<PIDController>();
  testObject->setTimeStep(0.02);
  EXPECT_EQ(0.02, testObject->getTimeStep());
}
//  test to ensure time step is greater than zero
TEST(PIDController, dtGreaterThanZeroCheck) {
  testObject = std::make_shared<PIDController>();
  EXPECT_LT(0.0, testObject->getTimeStep());
}
