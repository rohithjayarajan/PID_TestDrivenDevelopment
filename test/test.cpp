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


TEST(PIDController, velocityComputedCheck) {
  testObject = std::make_shared<PIDController>();
  ASSERT_EQ(2100.0, testObject->computeVelocity(10.0, 20.0));
}

TEST(PIDController, dtGreaterThanZeroCheck) {
  testObject = std::make_shared<PIDController>();
  ASSERT_LT(0.0, testObject->dt);
}
