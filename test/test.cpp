/**
 *  Copyright 2018 rohith jayarajan
 *  @file    test.cpp
 *  @author  rohithjayarajan
 *  @date    11/30/2018
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

//  test to ensure Kp is set
TEST(PIDController, isGainKpSet) {
  PIDController testObject2;
  testObject2.setGainKp(12.56);
  EXPECT_EQ(12.56, testObject2.getGainKp());
}
//  test to ensure Ki is set
TEST(PIDController, isGainKiSet) {
  PIDController testObject3;
  testObject3.setGainKi(567.76);
  EXPECT_EQ(567.76, testObject3.getGainKi());
}
//  test to ensure Kd is set
TEST(PIDController, isGainKdSet) {
  PIDController testObject4;
  testObject4.setGainKd(23.23);
  EXPECT_EQ(23.23, testObject4.getGainKd());
}
//  test to ensure dt is set
TEST(PIDController, isDtSet) {
  PIDController testObject5;
  testObject5.setTimeStep(0.02);
  EXPECT_EQ(0.02, testObject5.getTimeStep());
}
//  test to ensure time step is greater than zero
TEST(PIDController, dtGreaterThanZeroCheck) {
  PIDController testObject6;
  EXPECT_LT(0.0, testObject6.getTimeStep());
}
