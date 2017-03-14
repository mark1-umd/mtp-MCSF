/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file main-evo2.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 14, 2017 - Creation
 *
 * @brief A main program to drive the MCSF system to verify its trajectory generation capabilities
 *
 * This main program uses the Motion Control System Framework to generate a motion
 * profile trajectory for a Chassis with a TankDrive, then outputs the two trajectories
 * (one per side of the tank drive) in order to demonstrate the ability to generate
 * matched pairs of trajectories capable of moving a tank drive-based system in the
 * desired path using motion profiling.
 *
 */

#include <iostream>
#include "../framework/Chassis.hpp"
#include "../framework/ChassisAcceleration.hpp"
#include "../framework/ChassisTurnRate.hpp"
#include "../framework/ChassisVelocity.hpp"
#include "../framework/DriveSystem.hpp"
#include "../framework/MotorAcceleration.hpp"
#include "../framework/MotorVelocity.hpp"
#include "../framework/Path.hpp"
#include "../framework/PathPoint.hpp"
#include "../framework/Route.hpp"
#include "../framework/TankDrive.hpp"

int main() {
  std::cout
      << "Motion Control System Framework TankDrive trajectory generation -"
      << " demonstration starting" << std::endl << std::endl;

//********************************************************************
//     Create a robot
//********************************************************************
  // Create a chassis for this robot and give it a name
  Chassis aChassis;
  std::string robotName = "Johnny5";
  aChassis.setName(robotName);

  // Define the robot's drive system
  // This robot can move at 5 feet per second, accelerate at 6 fps/s
  // Its drive motors are moving at 4,250 RPM at 5 fps
  TankDrive aTankDrive;

  // Define a MotorVelocity, set it as the maxVelocity
  MotorVelocity maxVelocity;
  double velocityInRPM = 4250;  // 850 RPM per foot/second
  maxVelocity.setRotationsPerMinute(velocityInRPM);
  aTankDrive.setMaxVelocity(maxVelocity);

  // Define a MotorAcceleration, set it as the maxAccleration
  MotorAcceleration maxAcceleration;
  double accelerationInRPMperSecond = 5100;  // max velocity in 8.333 seconds
  maxAcceleration.setRotationsPerMinutePerSecond(accelerationInRPMperSecond);
  aTankDrive.setMaxAcceleration(maxAcceleration);

  // Set the motor rotations per movement foot in a TankDrive,
  double rotPerFoot = 850;
  aTankDrive.setMotorRotPerMovementFoot(rotPerFoot);

  // Set a trajectory iteration period in milliseconds in a TankDrive,
  unsigned int iterationPeriod = 10;
  aTankDrive.setTrajectoryIterationPeriodMS(iterationPeriod);

  // Set the drive system width (feet) in a TankDrive,
  double driveWidthFeet = 2.75;
  aTankDrive.setWidthInFeet(driveWidthFeet);

  // and set this this tank drive as the tank drive for the chassis
  aChassis.setDriveSystem(aTankDrive);

  //********************************************************************
  //     Give the robot something to do...
  //********************************************************************

  // In order to move, we have to know how to move
  ChassisTurnRate turnRate;
  turnRate.setDegreesPerFoot(5);
  ChassisVelocity velocity;
  velocity.setFeetPerSecond(3);
  ChassisAcceleration acceleration;
  acceleration.setFeetPerSecondPerSecond(2);

  // And head on out
  aChassis.move(45, turnRate, velocity, acceleration);

  // That's all for our demonstration... look for the trajectory files...
  std::cout << "Demonstration complete - look for trajectory files with"
            << std::endl << "the robot name " << robotName
            << " and left/right, ending in .CSV" << std::endl;
  std::cout << "These files can be graphed in a spreadsheet or graphing program"
            << std::endl << std::endl;
  return 0;
}
