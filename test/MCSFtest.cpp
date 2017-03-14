/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MCSFtest.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 * @date Mar 10, 2017 - Added/expanded tests
 * @date Mar 13, 2017 - Added tests for Chassis movement classes
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
#include "../framework/Chassis.hpp"
#include "../framework/ChassisAcceleration.hpp"
#include "../framework/ChassisTurnRate.hpp"
#include "../framework/ChassisVelocity.hpp"
#include "../framework/DriveSystem.hpp"
#include "../framework/MotorAcceleration.hpp"
#include "../framework/MotorPosition.hpp"
#include "../framework/MotorVelocity.hpp"
#include "../framework/Path.hpp"
#include "../framework/PathPoint.hpp"
#include "../framework/Point.hpp"
#include "../framework/Trajectory.hpp"
#include "../framework/TrajectoryPoint.hpp"
#include "../framework/Route.hpp"
#include "../framework/TankDrive.hpp"
#include "../framework/WayPoint.hpp"

//*********************************************************
// Test initialization for the MotorPosition class
//*********************************************************
TEST(MotorPositionTest, testInitialization) {
  MotorPosition aMotorPosition;

  // Rotation count in the MotorPosition object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aMotorPosition.getRotations());
}

//*********************************************************
// Test accessor functions for the MotorPosition class
//*********************************************************
TEST(MotorPositionTest, testAccessorFunctions) {
  MotorPosition aMotorPosition;

  // Set and get values starting with zero
  double motorRotations = 0.0;
  aMotorPosition.setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition.getRotations());

  // Try a positive number
  motorRotations = 34.56;
  aMotorPosition.setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition.getRotations());

  // Try a negative number
  motorRotations = -34.56;
  aMotorPosition.setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition.getRotations());

  // Try a larger magnitude positive number
  motorRotations = 3123456.1234;
  aMotorPosition.setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition.getRotations());

  // Try a larger magnitude negative number
  motorRotations = -3123456.1234;
  aMotorPosition.setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition.getRotations());

  // Try a small magnitude positive number
  motorRotations = 0.000001;
  aMotorPosition.setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition.getRotations());

  // Try a small magnitude negative number
  motorRotations = 0.000001;
  aMotorPosition.setRotations(motorRotations);
  EXPECT_DOUBLE_EQ(motorRotations, aMotorPosition.getRotations());
}

//*********************************************************
// Test initialization for the MotorVelocity class
//*********************************************************
TEST(MotorVelocityTest, testInitialization) {
  MotorVelocity aMotorVelocity;

  // RPM in the MotorVelocity object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aMotorVelocity.getRotationsPerMinute());
}

//*********************************************************
// Test accessor functions for the MotorVelocity class
//*********************************************************
TEST(MotorVelocityTest, testAccessorFunctions) {
  MotorVelocity aMotorVelocity;

  // Set and get values starting with zero
  double motorRPM = 0.0;
  aMotorVelocity.setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity.getRotationsPerMinute());

  // Try a positive number
  motorRPM = 34.56;
  aMotorVelocity.setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity.getRotationsPerMinute());

  // Try a negative number
  motorRPM = -34.56;
  aMotorVelocity.setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity.getRotationsPerMinute());

  // Try a larger magnitude positive number
  motorRPM = 3123456.1234;
  aMotorVelocity.setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity.getRotationsPerMinute());

  // Try a larger magnitude negative number
  motorRPM = -3123456.1234;
  aMotorVelocity.setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity.getRotationsPerMinute());

  // Try a small magnitude positive number
  motorRPM = 0.000001;
  aMotorVelocity.setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity.getRotationsPerMinute());

  // Try a small magnitude negative number
  motorRPM = 0.000001;
  aMotorVelocity.setRotationsPerMinute(motorRPM);
  EXPECT_DOUBLE_EQ(motorRPM, aMotorVelocity.getRotationsPerMinute());
}

//*********************************************************
// Test initialization for the MotorAcceleration class
//*********************************************************
TEST(MotorAccelerationTest, testInitialization) {
  MotorAcceleration aMotorAcceleration;

  // Rotation count in the MotorAcceleration object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aMotorAcceleration.getRotationsPerMinutePerSecond());
}

//*********************************************************
// Test accessor functions for the MotorAcceleration class
//*********************************************************
TEST(MotorAccelerationTest, testAccessorFunctions) {
  MotorAcceleration aMotorAcceleration;

  // Set and get values starting with zero
  double motorRPMperSecond = 0.0;
  aMotorAcceleration.setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration.getRotationsPerMinutePerSecond());

  // Try a positive number
  motorRPMperSecond = 34.56;
  aMotorAcceleration.setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration.getRotationsPerMinutePerSecond());

  // Try a negative number
  motorRPMperSecond = -34.56;
  aMotorAcceleration.setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration.getRotationsPerMinutePerSecond());

  // Try a larger magnitude positive number
  motorRPMperSecond = 3123456.1234;
  aMotorAcceleration.setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration.getRotationsPerMinutePerSecond());

  // Try a larger magnitude negative number
  motorRPMperSecond = -3123456.1234;
  aMotorAcceleration.setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration.getRotationsPerMinutePerSecond());

  // Try a small magnitude positive number
  motorRPMperSecond = 0.000001;
  aMotorAcceleration.setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration.getRotationsPerMinutePerSecond());

  // Try a small magnitude negative number
  motorRPMperSecond = 0.000001;
  aMotorAcceleration.setRotationsPerMinutePerSecond(motorRPMperSecond);
  EXPECT_DOUBLE_EQ(motorRPMperSecond,
                   aMotorAcceleration.getRotationsPerMinutePerSecond());
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
  MotorAcceleration acceleration = aTrajectoryPoint.getAcceleration();
  EXPECT_DOUBLE_EQ(0.0, acceleration.getRotationsPerMinutePerSecond());
  // The durationMS, step, timeS, filter1Sum, and filter2Sum variables
  // should be zero
  EXPECT_EQ(0, aTrajectoryPoint.getDurationMS());
  EXPECT_EQ(0, aTrajectoryPoint.getStep());
  EXPECT_DOUBLE_EQ(0.0, aTrajectoryPoint.getTimeS());
  EXPECT_DOUBLE_EQ(0.0, aTrajectoryPoint.getFilter1Sum());
  EXPECT_DOUBLE_EQ(0.0, aTrajectoryPoint.getFilter2Sum());
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

  // Define a MotorAcceleration, set it as the Accleration in a TrajectoryPoint,
  // and see if it comes back as the same value
  MotorAcceleration acceleration, returnedAcceleration;
  double accelerationInRPMperSecond = 1.2345;
  acceleration.setRotationsPerMinutePerSecond(accelerationInRPMperSecond);
  aTrajectoryPoint.setAcceleration(acceleration);
  returnedAcceleration = aTrajectoryPoint.getAcceleration();
  EXPECT_DOUBLE_EQ(accelerationInRPMperSecond,
                   returnedAcceleration.getRotationsPerMinutePerSecond());

  // Set a duration in milliseconds in a TrajectoryPoint,
  // and see if it comes back as the same value
  unsigned int duration = 12;
  aTrajectoryPoint.setDurationMS(duration);
  EXPECT_EQ(duration, aTrajectoryPoint.getDurationMS());

  // Set a step number and see if it comes back as the same value
  unsigned int aStep = 34;
  aTrajectoryPoint.setStep(aStep);
  EXPECT_EQ(aStep, aTrajectoryPoint.getStep());

  // Set a time in seconds in a TrajectoryPoint,
  // and see if it comes back as the same value
  double time = 1.001;
  aTrajectoryPoint.setTimeS(time);
  EXPECT_EQ(time, aTrajectoryPoint.getTimeS());

  // Set a filter 1 sum value and see if it comes back the same
  double filter1Sum = 36.90;
  aTrajectoryPoint.setFilter1Sum(filter1Sum);
  EXPECT_DOUBLE_EQ(filter1Sum, aTrajectoryPoint.getFilter1Sum());

  // Set a filter 2 sum value and see if it comes back the same
  double filter2Sum = .034989;
  aTrajectoryPoint.setFilter2Sum(filter2Sum);
  EXPECT_DOUBLE_EQ(filter2Sum, aTrajectoryPoint.getFilter2Sum());
}

//*********************************************************
// Test initialization for the Path class
//*********************************************************
TEST(PathTest, testInitilization) {
  Path aPath;

  // The path should be empty (size 0)
  unsigned int zero = 0;
  EXPECT_EQ(zero, aPath.size());
}

//*********************************************************
// Test accessor functions for the Path class
//*********************************************************
TEST(PathTest, testAccessorFunctions) {
  // Build a path with two path points
  Path aPath;

  // Create a path point, load it up and add it to the path
  PathPoint firstPathPoint;
  MotorPosition firstPosition;
  firstPosition.setRotations(0.0);
  firstPathPoint.setPosition(firstPosition);

  MotorVelocity firstMaxMotorVelocity;
  // 4 RPS is 240 RPM
  firstMaxMotorVelocity.setRotationsPerMinute(240);
  firstPathPoint.setMaxVelocity(firstMaxMotorVelocity);

  MotorAcceleration firstMaxAcceleration;
  // 10 RPS/S is 600 RPM/S
  firstMaxAcceleration.setRotationsPerMinutePerSecond(600);
  firstPathPoint.setMaxAcceleration(firstMaxAcceleration);

  aPath.addPathPoint(firstPathPoint);

  // Create another path point, load it up, and add it to the path
  PathPoint secondPathPoint;
  MotorPosition secondPosition;
  secondPosition.setRotations(5.0);
  secondPathPoint.setPosition(secondPosition);

  MotorVelocity secondMaxMotorVelocity;
  // 2 RPS is 120 RPM
  secondMaxMotorVelocity.setRotationsPerMinute(120);
  secondPathPoint.setMaxVelocity(secondMaxMotorVelocity);

  MotorAcceleration secondMaxAcceleration;
  // 5 RPS/S is 300 RPM/S
  secondMaxAcceleration.setRotationsPerMinutePerSecond(300);
  secondPathPoint.setMaxAcceleration(secondMaxAcceleration);

  aPath.addPathPoint(secondPathPoint);

  // Check the size of the path (should have two path points on it)
  unsigned int two = 2;
  EXPECT_EQ(two, aPath.size());

  // With two points on the path, test the accessor functions
  // No need to set values; just want test the points
  PathPoint firstReturnPathPoint, secondReturnPathPoint;

  // Test for a successful failure of getNextPathPoint with no
  // previous getFirstPathPoint
  EXPECT_FALSE(aPath.getNextPathPoint(firstReturnPathPoint));

  // Now test to see that we do get a first path point
  EXPECT_TRUE(aPath.getFirstPathPoint(firstReturnPathPoint));

  // Test the position setting
  MotorPosition firstReturnPosition = firstReturnPathPoint.getPosition();
  EXPECT_DOUBLE_EQ(0.0, firstReturnPosition.getRotations());

  // Test the max velocity
  MotorVelocity firstReturnMaxVelocity = firstReturnPathPoint.getMaxVelocity();
  EXPECT_DOUBLE_EQ(240, firstReturnMaxVelocity.getRotationsPerMinute());

  // Test the max acceleration
  MotorAcceleration firstReturnMaxAcceleration = firstReturnPathPoint
      .getMaxAcceleration();
  EXPECT_DOUBLE_EQ(600,
                   firstReturnMaxAcceleration.getRotationsPerMinutePerSecond());

  // Now test to see that we get a second path point
  EXPECT_TRUE(aPath.getNextPathPoint(secondReturnPathPoint));

  // Test the position setting
  MotorPosition secondReturnPosition = secondReturnPathPoint.getPosition();
  EXPECT_DOUBLE_EQ(5.0, secondReturnPosition.getRotations());

  // Test the max velocity
  MotorVelocity secondReturnMaxVelocity =
      secondReturnPathPoint.getMaxVelocity();
  EXPECT_DOUBLE_EQ(120, secondReturnMaxVelocity.getRotationsPerMinute());

  // Test the max acceleration
  MotorAcceleration secondReturnMaxAcceleration = secondReturnPathPoint
      .getMaxAcceleration();
  EXPECT_DOUBLE_EQ(
      300, secondReturnMaxAcceleration.getRotationsPerMinutePerSecond());

  // Test to see that another getNextPathPoint isn't successful
  EXPECT_FALSE(aPath.getNextPathPoint(secondReturnPathPoint));
}

//*********************************************************
// Test initialization for the Trajectory class
//*********************************************************
TEST(TrajectoryTest, testInitialization) {
  Trajectory aTrajectory;

  // The maxVelocity, maxAcceleration, and distance should all
  // initialize to zeros
  MotorVelocity maxVelocity = aTrajectory.getMaxVelocity();
  EXPECT_DOUBLE_EQ(0.0, maxVelocity.getRotationsPerMinute());
  MotorAcceleration maxAcceleration = aTrajectory.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(0.0, maxAcceleration.getRotationsPerMinutePerSecond());
  MotorPosition distance = aTrajectory.getDistance();
  EXPECT_DOUBLE_EQ(0.0, distance.getRotations());

  // The algorithm variables should initialize to zeros
  unsigned int zero = 0;
  EXPECT_EQ(zero, aTrajectory.getAlgoItPMS());
  EXPECT_EQ(zero, aTrajectory.getAlgoT1MS());
  EXPECT_EQ(zero, aTrajectory.getAlgoT2MS());
  EXPECT_EQ(zero, aTrajectory.getAlgoT4MS());
  EXPECT_EQ(zero, aTrajectory.getAlgoFL1count());
  EXPECT_EQ(zero, aTrajectory.getAlgoFL2count());
  EXPECT_EQ(zero, aTrajectory.getAlgoNcount());

  // The initial size of the trajectory path itself should be zero
  EXPECT_EQ(zero, aTrajectory.size());
}

//*********************************************************
// Test generation & accessor functions for the Trajectory class
//*********************************************************
TEST(TrajectoryTest, testGenerationAndAccessorFunctions) {
  // Build a path with two path points
  Path aPath;

  // Create a path point, load it up and add it to the path
  PathPoint firstPathPoint;
  MotorPosition firstPosition;
  firstPosition.setRotations(0.0);
  firstPathPoint.setPosition(firstPosition);

  MotorVelocity firstMaxMotorVelocity;
  // 4 RPS is 240 RPM
  firstMaxMotorVelocity.setRotationsPerMinute(240);
  firstPathPoint.setMaxVelocity(firstMaxMotorVelocity);

  MotorAcceleration firstMaxAcceleration;
  // 10 RPS/S is 600 RPM/S
  firstMaxAcceleration.setRotationsPerMinutePerSecond(600);
  firstPathPoint.setMaxAcceleration(firstMaxAcceleration);

  aPath.addPathPoint(firstPathPoint);

  // Create another path point, load it up, and add it to the path
  PathPoint secondPathPoint;
  MotorPosition secondPosition;
  secondPosition.setRotations(5.0);
  secondPathPoint.setPosition(secondPosition);

  MotorVelocity secondMaxMotorVelocity;
  // 2 RPS is 120 RPM
  secondMaxMotorVelocity.setRotationsPerMinute(120);
  secondPathPoint.setMaxVelocity(secondMaxMotorVelocity);

  MotorAcceleration secondMaxAcceleration;
  // 5 RPS/S is 300 RPM/S
  secondMaxAcceleration.setRotationsPerMinutePerSecond(300);
  secondPathPoint.setMaxAcceleration(secondMaxAcceleration);

  aPath.addPathPoint(secondPathPoint);

  // Check the size of the path (should have two path points on it)
  unsigned int two = 2;
  EXPECT_EQ(two, aPath.size());

  // With two points on the path, generate a trajectory
  Trajectory aTrajectory;
  unsigned int iterationPeriod = 10;
  aTrajectory.generate(aPath, iterationPeriod);

  // Check the maxVelocity, maxAcceleration, and distance
  MotorVelocity returnMaxVelocity = aTrajectory.getMaxVelocity();
  EXPECT_DOUBLE_EQ(240, returnMaxVelocity.getRotationsPerMinute());
  MotorAcceleration returnMaxAcceleration = aTrajectory.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(600, returnMaxAcceleration.getRotationsPerMinutePerSecond());
  MotorPosition returnDistance = aTrajectory.getDistance();
  EXPECT_DOUBLE_EQ(5.0, returnDistance.getRotations());

  // Check the algorithm parameters
  EXPECT_EQ(iterationPeriod, aTrajectory.getAlgoItPMS());
  EXPECT_EQ(400, aTrajectory.getAlgoT1MS());
  EXPECT_EQ(200, aTrajectory.getAlgoT2MS());
  EXPECT_EQ(1250, aTrajectory.getAlgoT4MS());
  EXPECT_EQ(40, aTrajectory.getAlgoFL1count());
  EXPECT_EQ(20, aTrajectory.getAlgoFL2count());
  EXPECT_EQ(125, aTrajectory.getAlgoNcount());
}

//*********************************************************
// Test initialization for the ChassisTurnRate class
//*********************************************************
TEST(ChassisTurnRateTest, testInitialization) {
  ChassisTurnRate aChassisTurnRate;

  // Degrees per foot in the ChassisTurnRate object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aChassisTurnRate.getDegreesPerFoot());
}

//*********************************************************
// Test accessor functions for the ChassisTurnRate class
//*********************************************************
TEST(ChassisTurnRateTest, testAccessorFunctions) {
  ChassisTurnRate aChassisTurnRate;

  // Set and get values starting with zero
  double degreesPerFoot = 0.0;
  aChassisTurnRate.setDegreesPerFoot(degreesPerFoot);
  EXPECT_DOUBLE_EQ(degreesPerFoot, aChassisTurnRate.getDegreesPerFoot());

  // Try a positive number
  degreesPerFoot = 34.56;
  aChassisTurnRate.setDegreesPerFoot(degreesPerFoot);
  EXPECT_DOUBLE_EQ(degreesPerFoot, aChassisTurnRate.getDegreesPerFoot());

  // Try a negative number
  degreesPerFoot = -34.56;
  aChassisTurnRate.setDegreesPerFoot(degreesPerFoot);
  EXPECT_DOUBLE_EQ(degreesPerFoot, aChassisTurnRate.getDegreesPerFoot());

  // Try a larger magnitude positive number
  degreesPerFoot = 3123456.1234;
  aChassisTurnRate.setDegreesPerFoot(degreesPerFoot);
  EXPECT_DOUBLE_EQ(degreesPerFoot, aChassisTurnRate.getDegreesPerFoot());

  // Try a larger magnitude negative number
  degreesPerFoot = -3123456.1234;
  aChassisTurnRate.setDegreesPerFoot(degreesPerFoot);
  EXPECT_DOUBLE_EQ(degreesPerFoot, aChassisTurnRate.getDegreesPerFoot());

  // Try a small magnitude positive number
  degreesPerFoot = 0.000001;
  aChassisTurnRate.setDegreesPerFoot(degreesPerFoot);
  EXPECT_DOUBLE_EQ(degreesPerFoot, aChassisTurnRate.getDegreesPerFoot());

  // Try a small magnitude negative number
  degreesPerFoot = 0.000001;
  aChassisTurnRate.setDegreesPerFoot(degreesPerFoot);
  EXPECT_DOUBLE_EQ(degreesPerFoot, aChassisTurnRate.getDegreesPerFoot());
}

//*********************************************************
// Test initialization for the ChassisVelocity class
//*********************************************************
TEST(ChassisVelocityTest, testInitialization) {
  ChassisVelocity aChassisVelocity;

  // RPM in the ChassisVelocity object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aChassisVelocity.getFeetPerSecond());
}

//*********************************************************
// Test accessor functions for the ChassisVelocity class
//*********************************************************
TEST(ChassisVelocityTest, testAccessorFunctions) {
  ChassisVelocity aChassisVelocity;

  // Set and get values starting with zero
  double velFPS = 0.0;
  aChassisVelocity.setFeetPerSecond(velFPS);
  EXPECT_DOUBLE_EQ(velFPS, aChassisVelocity.getFeetPerSecond());

  // Try a positive number
  velFPS = 34.56;
  aChassisVelocity.setFeetPerSecond(velFPS);
  EXPECT_DOUBLE_EQ(velFPS, aChassisVelocity.getFeetPerSecond());

  // Try a negative number
  velFPS = -34.56;
  aChassisVelocity.setFeetPerSecond(velFPS);
  EXPECT_DOUBLE_EQ(velFPS, aChassisVelocity.getFeetPerSecond());

  // Try a larger magnitude positive number
  velFPS = 3123456.1234;
  aChassisVelocity.setFeetPerSecond(velFPS);
  EXPECT_DOUBLE_EQ(velFPS, aChassisVelocity.getFeetPerSecond());

  // Try a larger magnitude negative number
  velFPS = -3123456.1234;
  aChassisVelocity.setFeetPerSecond(velFPS);
  EXPECT_DOUBLE_EQ(velFPS, aChassisVelocity.getFeetPerSecond());

  // Try a small magnitude positive number
  velFPS = 0.000001;
  aChassisVelocity.setFeetPerSecond(velFPS);
  EXPECT_DOUBLE_EQ(velFPS, aChassisVelocity.getFeetPerSecond());

  // Try a small magnitude negative number
  velFPS = 0.000001;
  aChassisVelocity.setFeetPerSecond(velFPS);
  EXPECT_DOUBLE_EQ(velFPS, aChassisVelocity.getFeetPerSecond());
}

//*********************************************************
// Test initialization for the ChassisAcceleration class
//*********************************************************
TEST(ChassisAccelerationTest, testInitialization) {
  ChassisAcceleration aChassisAcceleration;

  // Rotation count in the ChassisAcceleration object should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aChassisAcceleration.getFeetPerSecondPerSecond());
}

//*********************************************************
// Test accessor functions for the ChassisAcceleration class
//*********************************************************
TEST(ChassisAccelerationTest, testAccessorFunctions) {
  ChassisAcceleration aChassisAcceleration;

  // Set and get values starting with zero
  double velFPSperSecond = 0.0;
  aChassisAcceleration.setFeetPerSecondPerSecond(velFPSperSecond);
  EXPECT_DOUBLE_EQ(velFPSperSecond,
                   aChassisAcceleration.getFeetPerSecondPerSecond());

  // Try a positive number
  velFPSperSecond = 34.56;
  aChassisAcceleration.setFeetPerSecondPerSecond(velFPSperSecond);
  EXPECT_DOUBLE_EQ(velFPSperSecond,
                   aChassisAcceleration.getFeetPerSecondPerSecond());

  // Try a negative number
  velFPSperSecond = -34.56;
  aChassisAcceleration.setFeetPerSecondPerSecond(velFPSperSecond);
  EXPECT_DOUBLE_EQ(velFPSperSecond,
                   aChassisAcceleration.getFeetPerSecondPerSecond());

  // Try a larger magnitude positive number
  velFPSperSecond = 3123456.1234;
  aChassisAcceleration.setFeetPerSecondPerSecond(velFPSperSecond);
  EXPECT_DOUBLE_EQ(velFPSperSecond,
                   aChassisAcceleration.getFeetPerSecondPerSecond());

  // Try a larger magnitude negative number
  velFPSperSecond = -3123456.1234;
  aChassisAcceleration.setFeetPerSecondPerSecond(velFPSperSecond);
  EXPECT_DOUBLE_EQ(velFPSperSecond,
                   aChassisAcceleration.getFeetPerSecondPerSecond());

  // Try a small magnitude positive number
  velFPSperSecond = 0.000001;
  aChassisAcceleration.setFeetPerSecondPerSecond(velFPSperSecond);
  EXPECT_DOUBLE_EQ(velFPSperSecond,
                   aChassisAcceleration.getFeetPerSecondPerSecond());

  // Try a small magnitude negative number
  velFPSperSecond = 0.000001;
  aChassisAcceleration.setFeetPerSecondPerSecond(velFPSperSecond);
  EXPECT_DOUBLE_EQ(velFPSperSecond,
                   aChassisAcceleration.getFeetPerSecondPerSecond());
}

//*********************************************************
// Test initialization for the DriveSystem class
//*********************************************************
TEST(DriveSystemTest, testInitialization) {
  DriveSystem aDriveSystem;

  // chassisName in the DriveSystem object should initialize to ""
  EXPECT_EQ("", aDriveSystem.getChassisName());

  // maxVelocity should initialize to a MotorVelocity
  // with 0 rotations per minute
  MotorVelocity maxVelocity = aDriveSystem.getMaxVelocity();
  EXPECT_DOUBLE_EQ(0.0, maxVelocity.getRotationsPerMinute());

  // maxAccleration should initialize to a MotorAcceleration
  // with 0 rations per minute per second
  MotorAcceleration maxAcceleration = aDriveSystem.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(0.0, maxAcceleration.getRotationsPerMinutePerSecond());

  // motor rotations per (chassis) movement foot should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aDriveSystem.getMotorRotPerMovementFoot());

  // Trajectory Iteration Period (in milliseconds) should initialize to 0
  unsigned int zero = 0;
  EXPECT_EQ(zero, aDriveSystem.getTrajectoryIterationPeriodMS());
}

//*********************************************************
// Test Accesor functions for the DriveSystem (Base) class
//*********************************************************
TEST(DriveSystemTest, testAccessorFunctions) {
  DriveSystem aDriveSystem;

  // Set a name and read it back
  std::string chassisName = "JohnnyFive";
  aDriveSystem.setChassisName(chassisName);
  EXPECT_EQ(chassisName, aDriveSystem.getChassisName());

  // Define a MotorVelocity, set it as the maxVelocity in a DriveSystem,
  // and see if it comes back as the same value
  MotorVelocity maxVelocity, returnedMaxVelocity;
  double velocityInRPM = 310.345;
  maxVelocity.setRotationsPerMinute(velocityInRPM);
  aDriveSystem.setMaxVelocity(maxVelocity);
  returnedMaxVelocity = aDriveSystem.getMaxVelocity();
  EXPECT_DOUBLE_EQ(velocityInRPM, returnedMaxVelocity.getRotationsPerMinute());

  // Define a MotorAcceleration, set it as the maxAccleration in a DriveSystem,
  // and see if it comes back as the same value
  MotorAcceleration maxAcceleration, returnedMaxAcceleration;
  double accelerationInRPMperSecond = 1.2345;
  maxAcceleration.setRotationsPerMinutePerSecond(accelerationInRPMperSecond);
  aDriveSystem.setMaxAcceleration(maxAcceleration);
  returnedMaxAcceleration = aDriveSystem.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(accelerationInRPMperSecond,
                   returnedMaxAcceleration.getRotationsPerMinutePerSecond());

  // Set the motor rotations per movement foot in a DriveSystem,
  // and see if it comes back as the same value
  double rotPerFoot = 101.56;
  aDriveSystem.setMotorRotPerMovementFoot(rotPerFoot);
  EXPECT_DOUBLE_EQ(rotPerFoot, aDriveSystem.getMotorRotPerMovementFoot());

  // Set a trajectory iteration period in milliseconds in a DriveSystem,
  // and see if it comes back as the same value
  unsigned int iterationPeriod = 12;
  aDriveSystem.setTrajectoryIterationPeriodMS(iterationPeriod);
  EXPECT_EQ(iterationPeriod, aDriveSystem.getTrajectoryIterationPeriodMS());
}

//*********************************************************
// Test initialization for the TankDrive class
//*********************************************************
TEST(TankDriveTest, testInitialization) {
  TankDrive aTankDrive;

  // chassisName in the TankDrive object should initialize to ""
  EXPECT_EQ("", aTankDrive.getChassisName());

  // maxVelocity should initialize to a MotorVelocity with
  // 0 rotations per minute
  MotorVelocity maxVelocity = aTankDrive.getMaxVelocity();
  EXPECT_DOUBLE_EQ(0.0, maxVelocity.getRotationsPerMinute());

  // maxAccleration should initialize to a MotorAcceleration with
  // 0 rations per minute per second
  MotorAcceleration maxAcceleration = aTankDrive.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(0.0, maxAcceleration.getRotationsPerMinutePerSecond());

  // motor rotations per (chassis) movement foot should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aTankDrive.getMotorRotPerMovementFoot());

  // Trajectory Iteration Period (in milliseconds) should initialize to 0
  unsigned int zero = 0;
  EXPECT_EQ(zero, aTankDrive.getTrajectoryIterationPeriodMS());

  // Drive system width (feet) should initialize to 0
  EXPECT_DOUBLE_EQ(0.0, aTankDrive.getWidthInFeet());
}

//*********************************************************
// Test Accesor functions for the TankDrive (Derived) class
//*********************************************************
TEST(TankDriveTest, testAccessorFunctions) {
  TankDrive aTankDrive;

  // Set a name and read it back
  std::string chassisName = "Johnny5";
  aTankDrive.setChassisName(chassisName);
  EXPECT_EQ(chassisName, aTankDrive.getChassisName());

  // Define a MotorVelocity, set it as the maxVelocity in a TankDrive,
  // and see if it comes back as the same value
  MotorVelocity maxVelocity, returnedMaxVelocity;
  double velocityInRPM = 310.345;
  maxVelocity.setRotationsPerMinute(velocityInRPM);
  aTankDrive.setMaxVelocity(maxVelocity);
  returnedMaxVelocity = aTankDrive.getMaxVelocity();
  EXPECT_DOUBLE_EQ(velocityInRPM, returnedMaxVelocity.getRotationsPerMinute());

  // Define a MotorAcceleration, set it as the maxAccleration in a TankDrive,
  // and see if it comes back as the same value
  MotorAcceleration maxAcceleration, returnedMaxAcceleration;
  double accelerationInRPMperSecond = 1.2345;
  maxAcceleration.setRotationsPerMinutePerSecond(accelerationInRPMperSecond);
  aTankDrive.setMaxAcceleration(maxAcceleration);
  returnedMaxAcceleration = aTankDrive.getMaxAcceleration();
  EXPECT_DOUBLE_EQ(accelerationInRPMperSecond,
                   returnedMaxAcceleration.getRotationsPerMinutePerSecond());

  // Set the motor rotations per movement foot in a TankDrive,
  // and see if it comes back as the same value
  double rotPerFoot = 101.56;
  aTankDrive.setMotorRotPerMovementFoot(rotPerFoot);
  EXPECT_DOUBLE_EQ(rotPerFoot, aTankDrive.getMotorRotPerMovementFoot());

  // Set a trajectory iteration period in milliseconds in a TankDrive,
  // and see if it comes back as the same value
  unsigned int iterationPeriod = 12;
  aTankDrive.setTrajectoryIterationPeriodMS(iterationPeriod);
  EXPECT_EQ(iterationPeriod, aTankDrive.getTrajectoryIterationPeriodMS());

  // Set the drive system width (feet) in a TankDrive,
  // and see if it comes back as the same value
  double driveWidthFeet = 3.333333;
  aTankDrive.setWidthInFeet(driveWidthFeet);
  EXPECT_DOUBLE_EQ(driveWidthFeet, aTankDrive.getWidthInFeet());
}

//*********************************************************
// Test initialization for the Chassis class
//*********************************************************
TEST(ChassisTest, testInitialization) {
  Chassis aChassis;

  // Chassis name should initialize to ""
  EXPECT_EQ("", aChassis.getName());
}

//*********************************************************
// Test accessor functions for the Chassis class
//*********************************************************
TEST(ChassisTest, testAccessorFunctions) {
  Chassis aChassis;

  // Chassis name
  std::string chassisName = "JohnnyFive";
  aChassis.setName(chassisName);
  EXPECT_EQ(chassisName, aChassis.getName());

  // Drive system...

  // Create a drive system so that we can set it in the chassis...
//  std::unique_ptr<TankDrive> aTankDrive; // Not working 2017-03-14

  TankDrive aTankDrive;

  // Define a MotorVelocity, set it as the maxVelocity
  MotorVelocity maxVelocity;
  double velocityInRPM = 310.345;
  maxVelocity.setRotationsPerMinute(velocityInRPM);
  aTankDrive.setMaxVelocity(maxVelocity);

  // Define a MotorAcceleration, set it as the maxAccleration
  MotorAcceleration maxAcceleration;
  double accelerationInRPMperSecond = 1.2345;
  maxAcceleration.setRotationsPerMinutePerSecond(accelerationInRPMperSecond);
  aTankDrive.setMaxAcceleration(maxAcceleration);

  // Set the motor rotations per movement foot in a TankDrive,
  double rotPerFoot = 101.56;
  aTankDrive.setMotorRotPerMovementFoot(rotPerFoot);

  // Set a trajectory iteration period in milliseconds in a TankDrive,
  unsigned int iterationPeriod = 12;
  aTankDrive.setTrajectoryIterationPeriodMS(iterationPeriod);

  // Set the drive system width (feet) in a TankDrive,
  double driveWidthFeet = 3.333333;
  aTankDrive.setWidthInFeet(driveWidthFeet);

  // and set this this tank drive as the tank drive for the chassis
//  std::shared_ptr<DriveSystem> theDrive = std::move(aTankDrive);
//  aChassis.setDriveSystem(theDrive); // Not working 2017-03-14
  aChassis.setDriveSystem(aTankDrive);

  // Now get the drive system back, and check all of the
  // bits to see if they are the same as were set above
//  std::shared_ptr<DriveSystem> returnedTankDrive = aChassis.getDriveSystem();
  TankDrive returnedTankDrive = aChassis.getDriveSystem();

  // The Drive System chassis name should match the name set
  // in the Chassis (above)
  EXPECT_EQ(chassisName, returnedTankDrive.getChassisName());

  // Pull out the max velocity and see if it matches what was set
  MotorVelocity returnedMaxVelocity = returnedTankDrive.getMaxVelocity();
  EXPECT_DOUBLE_EQ(velocityInRPM, returnedMaxVelocity.getRotationsPerMinute());

  // Pull out the max acceleration and see if it matches what was set
  MotorAcceleration returnedMaxAcceleration = returnedTankDrive
      .getMaxAcceleration();
  EXPECT_DOUBLE_EQ(accelerationInRPMperSecond,
                   returnedMaxAcceleration.getRotationsPerMinutePerSecond());

  // Check the rest of the attributes
  EXPECT_DOUBLE_EQ(rotPerFoot, returnedTankDrive.getMotorRotPerMovementFoot());
  EXPECT_EQ(iterationPeriod,
            returnedTankDrive.getTrajectoryIterationPeriodMS());
  EXPECT_DOUBLE_EQ(driveWidthFeet, returnedTankDrive.getWidthInFeet());

}

