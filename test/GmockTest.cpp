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

#include "PIDController.hpp"
#include "gmock/gmock.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

/**
 *  @brief Class MockControlSystemHelper
 *  The MockControlSystemHelper class helps to create a mock class object for
 * testing purposes in GMock tools
 */
class MockControlSystemHelper : public ControlSystemHelper {
 public:
  MOCK_METHOD1(computeError, double(double targetSetPoint_));
  MOCK_METHOD6(computeVelocity,
               double(double targetSetPoint_, double initialVelocity_,
                      double kp_, double ki_, double kd_, double dt_));
};

/**
 *  @brief Test the computeControlSignalInfo method in PIDController class using
 * object of mock class MockControlSystemHelper
 */
TEST(MockControlSystemHelperTests, CheckCompute) {
  MockControlSystemHelper mcsh;
  PIDController pid;
  // GMock: specify a simple return value using Return(x)
  // Here, part of the test is that the Mock should be called once,
  // hence the 'WillOnce' call (more than one call would be an error).
  // If multiple calls should happen during the test,
  // use 'WillRepeatedly' instead.
  EXPECT_CALL(mcsh, computeVelocity(_, _, _, _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(1200.0));

  // get a value from computeControlSignalInfo of PIDController object
  double returnValue = pid.computeControlSignalInfo(mcsh, 100.0, 0.0);
  // check if the returned value equality holds
  EXPECT_EQ(returnValue, 1200.0);
}

/**
 *  @brief Test the computeControlSignalInfo method in PIDController class using
 * object of mock class MockControlSystemHelper
 */
TEST(MockControlSystemHelperTests, CheckError) {
  MockControlSystemHelper mcsh;
  PIDController pid;
  // GMock: specify a simple return value using Return(x)
  // Here, part of the test is that the Mock should be called once,
  // hence the 'WillOnce' call (more than one call would be an error).
  // If multiple calls should happen during the test,
  // use 'WillRepeatedly' instead.
  EXPECT_CALL(mcsh, computeError(_)).Times(AtLeast(1)).WillOnce(Return(101.0));

  // get a value from computeControlSignalInfo of PIDController object
  double returnValue = pid.computeTrackingError(mcsh, 100.0);
  // check if the returned value equality holds
  EXPECT_EQ(returnValue, 101.0);
}
