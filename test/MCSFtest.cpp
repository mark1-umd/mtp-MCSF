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
#include "../framework/TrajectoryPoint.hpp"
#include "../framework/TrajectoryPoint.hpp"
#include "../framework/Trajectory.hpp"
#include "../framework/Path.hpp"
#include "../framework/Route.hpp"

//*********************************************************
// Test initialization for the MotorPosition class
//*********************************************************
TEST(MotorPositionTest, testInitialization) {
  std::shared_ptr<MotorPosition> aMotorPosition =
      std::make_shared<MotorPosition>();

  // Rotation count in the MotorPosition object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aMotorPosition->getRotations());
}

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
// Test initialization for the MotorVelocity class
//*********************************************************
TEST(MotorVelocityTest, testInitialization) {
  std::shared_ptr<MotorVelocity> aMotorVelocity =
      std::make_shared<MotorVelocity>();

  // RPM in the MotorVelocity object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aMotorVelocity->getRotationsPerMinute());
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
// Test initialization for the MotorAcceleration class
//*********************************************************
TEST(MotorAccelerationTest, testInitialization) {
  std::shared_ptr<MotorAcceleration> aMotorAcceleration = std::make_shared<
      MotorAcceleration>();

  // Rotation count in the MotorAcceleration object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aMotorAcceleration->getRotationsPerMinutePerSecond());
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

//*********************************************************
// Test initialization for the Point class
//*********************************************************
TEST(PointTest, testInitialization) {
  Point aPoint;

  // Rotation count in the returned MotorPosition object should initialize to 0
  MotorPosition aMotorPosition = aPoint.getPosition();
  EXPECT_DOUBLE_EQ(0.0, aMotorPosition.getRotations());
}

//*********************************************************
// Test accessor functions for the Point class
//*********************************************************
TEST(PointTest, testAccessorFunctions) {
  Point aPoint;
  double motorRotations;
  MotorPosition aMotorPosition, bMotorPosition;

  // Define a MotorPosition, set it as a position in a point, and
  // see if it comes back as the same value
  motorRotations = 390.093;
  aMotorPosition.setRotations(motorRotations);
  aPoint.setPosition(aMotorPosition);
  bMotorPosition = aPoint.getPosition();
  EXPECT_DOUBLE_EQ(motorRotations, bMotorPosition.getRotations());
}

//*********************************************************
// Test initialization for the WayPoint class
//*********************************************************
TEST(WayPointTest, testInitialization) {
  WayPoint aWayPoint;

  // Rotation count in the returned MotorPosition object should initialize to 0
  MotorPosition aMotorPosition = aWayPoint.getPosition();
  EXPECT_DOUBLE_EQ(0.0, aMotorPosition.getRotations());
}

//*********************************************************
// Test accessor functions for the WayPoint class
//*********************************************************
TEST(WayPointTest, testAccessorFunctions) {
  Point aWayPoint;
  double motorRotations;
  MotorPosition aMotorPosition, bMotorPosition;

  // Define a MotorPosition, set it as a position in a waypoint, and
  // see if it comes back as the same value
  motorRotations = 390.093;
  aMotorPosition.setRotations(motorRotations);
  aWayPoint.setPosition(aMotorPosition);
  bMotorPosition = aWayPoint.getPosition();
  EXPECT_DOUBLE_EQ(motorRotations, bMotorPosition.getRotations());
}

//*********************************************************
// Test initialization for the PathPoint class
//*********************************************************
TEST(PathPointTest, testInitialization) {
  PathPoint aPathPoint;

  // The MotorPosition, MaxVelocity, and MaxAcceleration should all
  // initialize to zeros
  MotorPosition aMotorPosition = aPathPoint.getPosition();
  EXPECT_DOUBLE_EQ(0.0, aMotorPosition.getRotations());
  MotorVelocity maxVelocity = aPathPoint.getMaxVelocity();
  EXPECT_DOUBLE_EQ(0.0, maxVelocity.getRotationsPerMinute());
  MotorAcceleration maxAcceleration = aPathPoint.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(0.0, maxAcceleration.getRotationsPerMinutePerSecond());
}

//*********************************************************
// Test accessor functions for the PathPoint class
//*********************************************************
TEST(PathPointTest, testAccessorFunctions) {
  PathPoint aPathPoint;

  // Define a MotorPosition, set it as a position in a PathPoint, and
  // see if it comes back as the same value
  double motorRotations = 432.045;
  MotorPosition aMotorPosition, bMotorPosition;
  aMotorPosition.setRotations(motorRotations);
  aPathPoint.setPosition(aMotorPosition);
  bMotorPosition = aPathPoint.getPosition();
  EXPECT_DOUBLE_EQ(motorRotations, bMotorPosition.getRotations());

  // Define a MotorVelocity, set it as the MaxVelocity in a PathPoint,
  // and see if it comes back as the same value
  MotorVelocity maxVelocity, returnedMaxVelocity;
  double velocityInRPM = 310.345;
  maxVelocity.setRotationsPerMinute(velocityInRPM);
  aPathPoint.setMaxVelocity(maxVelocity);
  returnedMaxVelocity = aPathPoint.getMaxVelocity();
  EXPECT_DOUBLE_EQ(velocityInRPM, returnedMaxVelocity.getRotationsPerMinute());

  // Define a MotorAcceleration, set it as the MaxAccleration in a PathPoint,
  // and see if it comes back as the same value
  MotorAcceleration maxAcceleration, returnedMaxAcceleration;
  double accelerationInRPMperSecond = 34.98;
  maxAcceleration.setRotationsPerMinutePerSecond(accelerationInRPMperSecond);
  aPathPoint.setMaxAcceleration(maxAcceleration);
  returnedMaxAcceleration = aPathPoint.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(accelerationInRPMperSecond,
                   returnedMaxAcceleration.getRotationsPerMinutePerSecond());
}


//*********************************************************
// Test initialization for the TrajectoryPoint class
//*********************************************************
TEST(TrajectoryPointTest, testInitialization) {
  TrajectoryPoint aTrajectoryPoint;

  // The MotorPosition, MaxVelocity, and MaxAcceleration should all
  // initialize to zeros
  MotorPosition aMotorPosition = aTrajectoryPoint.getPosition();
  EXPECT_DOUBLE_EQ(0.0, aMotorPosition.getRotations());
  MotorVelocity velocity = aTrajectoryPoint.getVelocity();
  EXPECT_DOUBLE_EQ(0.0, velocity.getRotationsPerMinute());
  EXPECT_EQ(0, aTrajectoryPoint.getDurationMS());
}

 //*********************************************************
// Test accessor functions for the TrajectoryPoint class
 //*********************************************************
TEST(TrajectoryPointTest, testAccessorFunctions) {
  TrajectoryPoint aTrajectoryPoint;

  // Define a MotorPosition, set it as a position in a TrajectoryPoint, and
  // see if it comes back as the same value
  double motorRotations = 432.045;
  MotorPosition aMotorPosition, bMotorPosition;
  aMotorPosition.setRotations(motorRotations);
  aTrajectoryPoint.setPosition(aMotorPosition);
  bMotorPosition = aTrajectoryPoint.getPosition();
  EXPECT_DOUBLE_EQ(motorRotations, bMotorPosition.getRotations());

  // Define a MotorVelocity, set it as the Velocity in a TrajectoryPoint,
  // and see if it comes back as the same value
  MotorVelocity velocity, returnedVelocity;
  double velocityInRPM = 310.345;
  velocity.setRotationsPerMinute(velocityInRPM);
  aTrajectoryPoint.setVelocity(velocity);
  returnedVelocity = aTrajectoryPoint.getVelocity();
  EXPECT_DOUBLE_EQ(velocityInRPM, returnedVelocity.getRotationsPerMinute());

  // Set a duration in milliseconds in a TrajectoryPoint,
  // and see if it comes back as the same value
  int duration = 12;
  aTrajectoryPoint.setDurationMS(duration);
  EXPECT_EQ(duration, aTrajectoryPoint.getDurationMS());
}
