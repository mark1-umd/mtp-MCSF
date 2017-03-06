/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MCSFtest.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 *
 * @brief Test application for the Motion Control System Framework
 *
 * This is the Google Test-based test application for the Motion Control
 * System Framework.  It contains a series of tests, defined within
 * the Google Test framework, for verifying that the methods defined
 * within the Motion Control System Framework operate as expected.  Since
 * this code is being implemented using Test-Driven Development, the
 * tests in this application will generally be updated before the actual
 * code is written.  Old tests will be retained as new tests are added,
 * so that the test suite will serve as a regression test for old
 * functionality as well as the definition of the new functionality.
 *
 */
#include <gtest/gtest.h>
#include <memory>
#include "../framework/MotorPosition.hpp"
#include "../framework/MotorVelocity.hpp"
#include "../framework/MotorAcceleration.hpp"
#include "../framework/Point.hpp"
#include "../framework/WayPoint.hpp"
#include "../framework/PathPoint.hpp"
#include "../framework/TrajectoryPoint.hpp"
#include "../framework/Trajectory.hpp"
#include "../framework/Path.hpp"
#include "../framework/Route.hpp"

//*********************************************************
// Test accessor functions for the MotorPosition class
//*********************************************************
TEST(MotorPositionTest, testAccessorFunctions) {
  std::shared_ptr<MotorPosition> aMotorPosition =
      std::make_shared<MotorPosition>();

  // Set and get values starting with zero
  double motorRotations = 0.0;
  aMotorPosition->setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition->getRotations());

  // Try a positive number
  motorRotations = 34.56;
  aMotorPosition->setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition->getRotations());

  // Try a negative number
  motorRotations = -34.56;
  aMotorPosition->setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition->getRotations());

  // Try a larger magnitude positive number
  motorRotations = 3123456.1234;
  aMotorPosition->setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition->getRotations());

  // Try a larger magnitude negative number
  motorRotations = -3123456.1234;
  aMotorPosition->setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition->getRotations());

  // Try a small magnitude positive number
  motorRotations = 0.000001;
  aMotorPosition->setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition->getRotations());

  // Try a small magnitude negative number
  motorRotations = 0.000001;
  aMotorPosition->setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition->getRotations());
}

//*********************************************************
// Test accessor functions for the MotorVelocity class
//*********************************************************
TEST(MotorVelocityTest, testAccessorFunctions) {
  std::shared_ptr<MotorVelocity> aMotorVelocity =
      std::make_shared<MotorVelocity>();

  // Set and get values starting with zero
  double motorRPM = 0.0;
  aMotorVelocity->setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity->getRotationsPerMinute());

  // Try a positive number
  motorRPM = 34.56;
  aMotorVelocity->setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity->getRotationsPerMinute());

  // Try a negative number
  motorRPM = -34.56;
  aMotorVelocity->setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity->getRotationsPerMinute());

  // Try a larger magnitude positive number
  motorRPM = 3123456.1234;
  aMotorVelocity->setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity->getRotationsPerMinute());

  // Try a larger magnitude negative number
  motorRPM = -3123456.1234;
  aMotorVelocity->setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity->getRotationsPerMinute());

  // Try a small magnitude positive number
  motorRPM = 0.000001;
  aMotorVelocity->setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity->getRotationsPerMinute());

  // Try a small magnitude negative number
  motorRPM = 0.000001;
  aMotorVelocity->setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity->getRotationsPerMinute());
}

//*********************************************************
// Test accessor functions for the MotorAcceleration class
//*********************************************************
TEST(MotorAccelerationTest, testAccessorFunctions) {
  std::shared_ptr<MotorAcceleration> aMotorAcceleration = std::make_shared<
      MotorAcceleration>();

  // Set and get values starting with zero
  double motorRPMperSecond = 0.0;
  aMotorAcceleration->setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration->getRotationsPerMinutePerSecond());

  // Try a positive number
  motorRPMperSecond = 34.56;
  aMotorAcceleration->setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration->getRotationsPerMinutePerSecond());

  // Try a negative number
  motorRPMperSecond = -34.56;
  aMotorAcceleration->setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration->getRotationsPerMinutePerSecond());

  // Try a larger magnitude positive number
  motorRPMperSecond = 3123456.1234;
  aMotorAcceleration->setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration->getRotationsPerMinutePerSecond());

  // Try a larger magnitude negative number
  motorRPMperSecond = -3123456.1234;
  aMotorAcceleration->setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration->getRotationsPerMinutePerSecond());

  // Try a small magnitude positive number
  motorRPMperSecond = 0.000001;
  aMotorAcceleration->setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration->getRotationsPerMinutePerSecond());

  // Try a small magnitude negative number
  motorRPMperSecond = 0.000001;
  aMotorAcceleration->setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration->getRotationsPerMinutePerSecond());
}
