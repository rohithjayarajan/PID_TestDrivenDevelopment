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

// cpp header
#include "PIDController.hpp"
// GMock header
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
  /**
   *   @brief  Mock the computeError function for computing the tracking error
   *
   *   @param  double value of targetSetPoint velocity
   *   @return double
   */
  MOCK_METHOD1(computeError, double(double targetSetPoint_));
  /**
   *   @brief  Mock the computeVelocity function for computing the command
   * velocity given by PID controller
   *
   *   @param targetSetpoint_ is a double value of the
   *          setpoint_ of the target
   *   @param initialVelocity_ is the actual velocity of
   *          the type double
   *   @param kp_, the proportional gain
   *   @param ki_, the integral gain
   *   @param kd_, the differential gain
   *   @param dt_, the time step
   *   @return double value of the computed velocity
   */
  MOCK_METHOD6(computeVelocity,
               double(double targetSetPoint_, double initialVelocity_,
                      double kp_, double ki_, double kd_, double dt_));
};

/**
 *  @brief class MockControlSystemHelperTests
 * used for setup and teardown for all the tests
 */
class MockControlSystemHelperTests : public ::testing::Test {
 public:
  // initialize MockControlSystemHelper object
  MockControlSystemHelper mcsh;
  /**
   *   @brief Default constructor for MockControlSystemHelperTests
   *
   *   @param nothing
   *   @return nothing
   */
  MockControlSystemHelperTests() {}
  /**
   *   @brief Default destructor for MockControlSystemHelperTests
   *
   *   @param nothing
   *   @return nothing
   */
  ~MockControlSystemHelperTests() {}
  /**
   *   @brief setup up function to set up the tests with variables or objects
   *
   *   @param nothing
   *   @return nothing
   */
  void SetUp() {}
  /**
   *   @brief tear down function for the tests to clear up the used
   * variables or objects
   *
   *   @param nothing
   *   @return nothing
   */
  void TearDown() {}
};

/**
 *  @brief Test the computeControlSignalInfo method in PIDController class using
 * object of mock class MockControlSystemHelper
 *
 *  @param nothing
 *  @return nothing
 */
TEST_F(MockControlSystemHelperTests, CheckCompute) {
  PIDController pid;
  // GMock: specify a simple return value using Return(x)
  // Here, part of the test is that the Mock should be called once,
  // hence the 'WillOnce' call (more than one call would be an error).
  // If multiple calls should happen during the test,
  // use 'WillRepeatedly' instead.

  // Expect method computeVelocity of MockControlSystemHelperTests class to be
  // mocked
  EXPECT_CALL(mcsh, computeVelocity(_, _, _, _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(1200.0));

  // get a value from computeControlSignalInfo of PIDController object
  double returnValue = pid.computeControlSignalInfo(mcsh, 100.0, 0.0);
  // check if the returned value equals to value given by mocked class method
  EXPECT_EQ(returnValue, 1200.0);
}

/**
 *  @brief Test the computeControlSignalInfo method in PIDController class using
 * object of mock class MockControlSystemHelper
 *
 *  @param nothing
 *  @return nothing
 */
TEST_F(MockControlSystemHelperTests, CheckError) {
  PIDController pid;
  // GMock: specify a simple return value using Return(x)
  // Here, part of the test is that the Mock should be called once,
  // hence the 'WillOnce' call (more than one call would be an error).
  // If multiple calls should happen during the test,
  // use 'WillRepeatedly' instead.

  // Expect method computeError of MockControlSystemHelperTests class to be
  // mocked
  EXPECT_CALL(mcsh, computeError(_)).Times(AtLeast(1)).WillOnce(Return(101.0));

  // get a value from computeControlSignalInfo of PIDController object
  double returnValue = pid.computeTrackingError(mcsh, 100.0);
  // check if the returned value equals to value given by mocked class method
  EXPECT_EQ(returnValue, 101.0);
}
