/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file TankDrive.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 13, 2017 - Creation
 *
 * @brief TankDrive is a kind of DriveSystem with two wheeled or tracked motivators, one per side
 *
 * There are different types of drive systems, one of which is the TankDrive.  The base class,
 * DriveSystem, defines all of the attributes and methods which the various specific drive systems
 * have in common.  TankDrive extends the definition of the DriveSystem base class to create a derived
 * class with attributes and methods specific to a TankDrive.  Note that the "move" method is a
 * virtual method that can be accessed from a variable of the DriveSystem base class to which a
 * specific derived class has been assigned.  The "move" method will be executed from the definition
 * contained in the derived class - in this case, the TankDrive.
 *
 */
#include "TankDrive.hpp"

TankDrive::TankDrive()
    : widthInFeet(0.0) {
}

TankDrive::~TankDrive() {
}

/**
 * @brief Set the distance between the two TankDrive motivators (left and right sides)
 * @param [in] double width as the distance between the two TankDrive motivators (left and right sides)
 */
void TankDrive::setWidthInFeet(double width) {
  widthInFeet = width;
  return;
}

/**
 * @brief Get the distance between the two TankDrive motivators (left and right sides)
 * @return double width as the distance between the two TankDrive motivators (left and right sides)
 */
double TankDrive::getWidthInFeet() {
  return widthInFeet;
}

void TankDrive::move(double distanceFeet, ChassisTurnRate chassisTurnRate,
                     ChassisVelocity chassisVelocityRequested,
                     ChassisAcceleration chassisAccelerationRequested) {
  // Calculate chassis max velocity from drive system's maximum motor velocity and motor Rotations
  // per movement foot
  double chassisMaxVelocityFPS = maxVelocity.getRotationsPerMinute() / 60
      * motorRotPerMovementFoot;

  // Calculate chassis max acceleration from drive system's maximum motor acceleration and motor
  // rotations per movement foot
  double chassisMaxAccelerationFPSS = maxAcceleration
      .getRotationsPerMinutePerSecond() / 60 * motorRotPerMovementFoot;

  // Create the variables to contain the parameters for the paths used for trajectory generation
  double leftPathDistanceFeet, rightPathDistanceFeet;
  ChassisVelocity leftPathVelocity, rightPathVelocity;
  ChassisAcceleration leftPathAcceleration, rightPathAcceleration;

  // Is this movement straight?
  if (chassisTurnRate.getDegreesPerFoot() == 0) {

    // Set left and right path distances in feet to the move distance in feet
    leftPathDistanceFeet = distanceFeet;
    rightPathDistanceFeet = distanceFeet;

    // Set left and right path velocities to the lesser of the requested velocity and
    // the maximum chassis velocity
    leftPathVelocity.setFeetPerSecond(
        std::min(chassisVelocityRequested.getFeetPerSecond(),
                 chassisMaxVelocityFPS));
    rightPathVelocity = leftPathVelocity;

    // Set left and right path accelerations to the lesser of the requested acceleration and
    // the maximum chassis acceleration
    leftPathAcceleration.setFeetPerSecondPerSecond(
        std::min(chassisAccelerationRequested.getFeetPerSecondPerSecond(),
                 chassisMaxAccelerationFPSS));
    rightPathAcceleration = leftPathAcceleration;
  } else {
    // movement is circular, not straight, and the path variables will be smaller
    // for the inside of the turn, and bigger for the outside of the turn

    // ****** First determine path distances based on move distance and
    // ****** drive geometry (the distance beween the left and right motivators)

    // Calculate center turn circle circumference in feet, then radius in feet
    const double centerTurnCircleCircumferenceFeet = (360
        / chassisTurnRate.getDegreesPerFoot());
    const double pi = 4 * atan(double(1.0));
    const double centerTurnCircleRadiusFeet = centerTurnCircleCircumferenceFeet
        / (2 * pi);

    // Calculate circumference to distance scaling factor for all paths
    const double circumferenceToDistanceScaleFactor = distanceFeet
        / centerTurnCircleCircumferenceFeet;

    // Calculate inner distance in feet as the scaled inner turning circle circumference (which
    // is itself calculated as the circle with radius 1/2 half of the drive width less than the
    // radius of the center turning circle)
    const double innerPathDistanceFeet = circumferenceToDistanceScaleFactor * 2
        * pi * (centerTurnCircleRadiusFeet - (0.5 * widthInFeet));

    // Calculate outer distance in feet as the scaled outer turning circle circumference
    // (which is itself calculated as the circle with radius 1/2 of the drive width greater
    // than the radius of the center turning circle)
    const double outerPathDistanceFeet = circumferenceToDistanceScaleFactor * 2
        * pi * (centerTurnCircleRadiusFeet - (0.5 * widthInFeet));

    // ****** Next determine path velocities and accelerations adjusted to that
    // ****** the inner and outer path motions take the same amount of time

    // Calculate the center to outer path motion scaling factor
    const double centerToOuterPathMotionScaleFactor = outerPathDistanceFeet
        / distanceFeet;

    // Scale up the center path velocity to get the outer path velocity, being careful
    // not to exceed the maximum chassis velocity
    const double outerPathVelocityFPS = std::min(
        (chassisVelocityRequested.getFeetPerSecond()
            * centerToOuterPathMotionScaleFactor),
        chassisMaxVelocityFPS);

    // Scale up the center acceleration to get the outer path acceleration, being
    // careful not to exceed the maximum chassis acceleration
    const double outerPathAccelerationFPSS = std::min(
        (chassisAccelerationRequested.getFeetPerSecondPerSecond()
            * centerToOuterPathMotionScaleFactor),
        chassisMaxAccelerationFPSS);

    // Calculate the outer to inner path motion scaling factor
    const double outerToInnerPathMotionScaleFactor = innerPathDistanceFeet
        / outerPathDistanceFeet;

    // Scale down the outer path velocity to get the inner path velocity
    const double innerPathVelocityFPS = outerPathVelocityFPS
        * outerToInnerPathMotionScaleFactor;

    // Scale down the outer path acceleration to get the inner path acceleration
    const double innerPathAccelerationFPSS = outerPathAccelerationFPSS
        * outerToInnerPathMotionScaleFactor;

    // ****** Finally, set the left and right path motion variables from the
    // ****** inner and outer path motion variables based on sign of turn rate
    if (chassisTurnRate.getDegreesPerFoot() < 0) {
      // negative turn rate is a deviation (turn) to the left
      // so the left path is the inner path
      leftPathDistanceFeet = innerPathDistanceFeet;
      leftPathVelocity.setFeetPerSecond(innerPathVelocityFPS);
      leftPathAcceleration.setFeetPerSecondPerSecond(innerPathAccelerationFPSS);
      // and the right path is the outer path
      rightPathDistanceFeet = outerPathDistanceFeet;
      rightPathVelocity.setFeetPerSecond(outerPathVelocityFPS);
      rightPathAcceleration.setFeetPerSecondPerSecond(
          outerPathAccelerationFPSS);
    } else {
      // positive turn rate is deviation (turn) to the right
      // so the right path is the inner path
      rightPathDistanceFeet = innerPathDistanceFeet;
      rightPathVelocity.setFeetPerSecond(innerPathVelocityFPS);
      rightPathAcceleration.setFeetPerSecondPerSecond(
          innerPathAccelerationFPSS);
      // and the left path is the outer path
      leftPathDistanceFeet = outerPathDistanceFeet;
      leftPathVelocity.setFeetPerSecond(outerPathVelocityFPS);
      leftPathAcceleration.setFeetPerSecondPerSecond(outerPathAccelerationFPSS);
    }
    // This is the end of "Straight?" or turning movement decision
  }
  // Convert the chassis distances, velocities, and accelerations for each side's
  // path to motor distances (positions), velocities, and accelerations to that
  // we can build the motion paths for this movement

  // Left path beginning and ending position, velocity, and acceleration
  MotorPosition beginLeftPathMotorPosition, endLeftPathMotorPosition;
  beginLeftPathMotorPosition.setRotations(0.0);
  endLeftPathMotorPosition.convertFromDistanceFeetByRotPerMovementFoot(
      leftPathDistanceFeet, motorRotPerMovementFoot);
  MotorVelocity beginLeftPathMotorVelocity, endLeftPathMotorVelocity;
  beginLeftPathMotorVelocity.convertFromChassisVelocityByRotPerMovementFoot(
      leftPathVelocity, motorRotPerMovementFoot);
  endLeftPathMotorVelocity.setRotationsPerMinute(0.0);
  MotorAcceleration beginLeftPathMotorAcceleration,
      endLeftPathMotorAcceleration;
  beginLeftPathMotorAcceleration
      .convertFromChassisAccelerationByRotPerMovementFoot(
      leftPathAcceleration, motorRotPerMovementFoot);

  // Create the left path with two points
  Path leftPath;
  PathPoint beginLeftPathPoint, endLeftPathPoint;
  beginLeftPathPoint.setPosition(beginLeftPathMotorPosition);
  beginLeftPathPoint.setMaxVelocity(beginLeftPathMotorVelocity);
  beginLeftPathPoint.setMaxAcceleration(beginLeftPathMotorAcceleration);
  leftPath.addPathPoint(beginLeftPathPoint);
  endLeftPathPoint.setPosition(endLeftPathMotorPosition);
  endLeftPathPoint.setMaxVelocity(endLeftPathMotorVelocity);
  endLeftPathPoint.setMaxAcceleration(endLeftPathMotorAcceleration);
  leftPath.addPathPoint(endLeftPathPoint);

  // Right path beginning and ending position, velocity, and acceleration
  MotorPosition beginRightPathMotorPosition, endRightPathMotorPosition;
  beginRightPathMotorPosition.setRotations(0.0);
  endRightPathMotorPosition.convertFromDistanceFeetByRotPerMovementFoot(
      rightPathDistanceFeet, motorRotPerMovementFoot);
  MotorVelocity beginRightPathMotorVelocity, endRightPathMotorVelocity;
  beginRightPathMotorVelocity.convertFromChassisVelocityByRotPerMovementFoot(
      rightPathVelocity, motorRotPerMovementFoot);
  endRightPathMotorVelocity.setRotationsPerMinute(0.0);
  MotorAcceleration beginRightPathMotorAcceleration,
      endRightPathMotorAcceleration;
  beginRightPathMotorAcceleration
      .convertFromChassisAccelerationByRotPerMovementFoot(
      rightPathAcceleration, motorRotPerMovementFoot);

  // Create the right path with two points
  Path rightPath;
  PathPoint beginRightPathPoint, endRightPathPoint;
  beginRightPathPoint.setPosition(beginRightPathMotorPosition);
  beginRightPathPoint.setMaxVelocity(beginRightPathMotorVelocity);
  beginRightPathPoint.setMaxAcceleration(beginRightPathMotorAcceleration);
  rightPath.addPathPoint(beginRightPathPoint);
  endRightPathPoint.setPosition(endRightPathMotorPosition);
  endRightPathPoint.setMaxVelocity(endRightPathMotorVelocity);
  endRightPathPoint.setMaxAcceleration(endRightPathMotorAcceleration);
  rightPath.addPathPoint(endRightPathPoint);

  // Create the left and right motion profile trajectories, and generate using paths
  Trajectory leftTrajectory;
  leftTrajectory.generate(leftPath, trajectoryIterationPeriodMS);
  Trajectory rightTrajectory;
  rightTrajectory.generate(rightPath, trajectoryIterationPeriodMS);

  /* When trajectory.execute has been implemented for a real drive system:
   *    leftTrajectory.execute();
   *    rightTrajectory.execute();
   * would simultaneously run the left and right trajectories, and the drive system
   * would move.
   */

  // For demonstration purposes, create meaningful CSV file names
  std::string leftTrajectoryFileName = chassisName + "-left.CSV";
  std::string rightTrajectoryFileName = chassisName + "-right.CSV";

  // Output CSV files for the two trajectories
  leftTrajectory.outputCSV(leftTrajectoryFileName);
  rightTrajectory.outputCSV(rightTrajectoryFileName);

  return;
}
