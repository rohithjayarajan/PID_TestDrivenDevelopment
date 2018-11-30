/**
 *  Copyright 2018 rohith jayarajan
 *  @file    GmockTest.cpp
 *  @author  rohithjayarajan
 *  @date    11/29/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 4, Test Driven Development
 *
 *  @section DESCRIPTION
 *
 *  Gmock Tests for the mock class ControlSystemHelper
 *
 */

#include "ControlSystemHelper.hpp"
#include "PIDController.hpp"
#include "gmock/gmock.h"

using namespace std;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

class MockControlSystemHelper : public ControlSystemHelper {
 public:
  MockControlSystemHelper() : ControlSystemHelper(){};
  MOCK_CONST_METHOD6(computeVelocity,
                     double(double targetSetPoint_, double initialVelocity_,
                            double kp_, double ki_, double kd_, double dt_));
};

TEST(MockControlSystemHelperTests, CheckCompute) {
  MockControlSystemHelper mcsh;
  // GMock: specify a simple return value using Return(x)
  // Here, part of the test is that the Mock should be called once,
  // hence the 'WillOnce' call (more than one call would be an error).
  // If multiple calls should happen during the test,
  // use 'WillRepeatedly' instead.
  EXPECT_CALL(mcsh, computeVelocity(_, _, _, _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(1200.0));

  PIDController pid;
  double returnValue = pid.computeControlSignalInfo(mcsh, 100.0, 0.0);
  EXPECT_EQ(returnValue, 1200.0);
}