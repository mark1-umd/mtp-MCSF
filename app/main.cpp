/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file main.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 10, 2017 - Creation
 *
 * @brief A main program to drive the MCSF system to verify its trajectory generation capabilities
 *
 * This main program uses the Motion Control System Framework to generate a motion profile
 * trajectory, then outputs the trajectory as a comma-separated value file in order to
 * permit close comparison between the output of the trajectory generator in the MCSF and the
 * model trajectory generator used to create the trajectory generation function in the MCSF.
 *
 */

#include <iostream>
#include "../framework/MotorPosition.hpp"
#include "../framework/MotorVelocity.hpp"
#include "../framework/MotorAcceleration.hpp"
#include "../framework/PathPoint.hpp"
#include "../framework/Trajectory.hpp"
#include "../framework/Path.hpp"
#include "../framework/Route.hpp"

int main() {
  std::cout
      << "Motion Control System Framework trajectory generation demonstration starting"
      << std::endl << std::endl;

  // Build a path with two path points
  Path aPath;

  // Create a path point, load it up and add it to the path
  PathPoint firstPathPoint;
  MotorPosition firstPosition;
  firstPosition.setRotations(0.0);
  firstPathPoint.setPosition(firstPosition);

  MotorVelocity firstMaxMotorVelocity;
  firstMaxMotorVelocity.setRotationsPerMinute(240);  // 4 RPS is 240 RPM
  firstPathPoint.setMaxVelocity(firstMaxMotorVelocity);

  MotorAcceleration firstMaxAcceleration;
  firstMaxAcceleration.setRotationsPerMinutePerSecond(600);  // 10 RPS/S is 600 RPM/S
  firstPathPoint.setMaxAcceleration(firstMaxAcceleration);

  aPath.addPathPoint(firstPathPoint);

  // Create another path point, load it up, and add it to the path
  PathPoint secondPathPoint;
  MotorPosition secondPosition;
  secondPosition.setRotations(5.0);
  secondPathPoint.setPosition(secondPosition);

  MotorVelocity secondMaxMotorVelocity;
  secondMaxMotorVelocity.setRotationsPerMinute(120);  // 2 RPS is 120 RPM
  secondPathPoint.setMaxVelocity(secondMaxMotorVelocity);

  MotorAcceleration secondMaxAcceleration;
  secondMaxAcceleration.setRotationsPerMinutePerSecond(300);  // 5 RPS/S is 300 RPM/S
  secondPathPoint.setMaxAcceleration(secondMaxAcceleration);

  aPath.addPathPoint(secondPathPoint);

  std::cout << "This is the path that will be used to generate the trajectory -"
            << std::endl << std::endl;
  aPath.show();
  std::cout << std::endl;

  // With two points on the path, generate a trajectory
  Trajectory aTrajectory;
  unsigned int iterationPeriod = 10;
  aTrajectory.generate(aPath, iterationPeriod);

  std::cout << "This is the trajectory that was generated -" << std::endl
            << std::endl;
  aTrajectory.show();
  std::cout << std::endl;

  std::cout << "Outputting trajectory to file \"trajectory.csv\" -" << std::cout
            << std::cout;
  aTrajectory.outputCSV("trajectory.csv");
  std::cout << "Output complete - exiting." << std::cout;

  return 0;
}

