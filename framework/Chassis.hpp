/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Chassis.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 14, 2017 - Creation
 *
 * @brief A Chassis has a DriveSystem and a name, and can move using the Motion Control System Framework
 *
 * The Chassis class represents a robot chassis.  The chassis has a DriveSystem, which can be
 * of different types (only a TankDrive is derived from the DriveSystem class at this time).  Once
 * the DriveSystem has been configured and set in the chassis, the chassis can be commanded to
 * move with a distance, a turn rate (0 for straight, < 0 for left turns, > 0 for right turns),
 * a velocity, and an acceleration.  While operating within the constraints of the drive system
 * (which has maximum velocity and acceleration constraints), the drive system will create a path
 * for the motion, generate trajectories, and either execute (after customizing the execution
 * method for a particular hardware implementation) or demonstrate the trajectories (by outputting
 * comma-separated value files for the trajectories, named with the chassis name as the leading
 * element of the CSV file name.
 *
 */
#ifndef CHASSIS_HPP_
#define CHASSIS_HPP_

#include <memory>
#include <string>
#include "ChassisAcceleration.hpp"
#include "ChassisTurnRate.hpp"
#include "ChassisVelocity.hpp"
#include "DriveSystem.hpp"
#include "TankDrive.hpp"

/** @brief A Chassis has a DriveSystem and a name, and can move using the Motion Control System Framework
 */

class Chassis {
 public:
  Chassis();
  virtual ~Chassis();
  void setName(std::string myName);
  std::string getName();
  void setDriveSystem(std::shared_ptr<DriveSystem> driveSystem);
  std::shared_ptr<DriveSystem> getDriveSystem();
  void move(double distanceFeet, ChassisTurnRate chassisTurnRate,
            ChassisVelocity chassisVelocityRequested,
            ChassisAcceleration chassisAccelerationRequested);

 private:
  std::string myName;
  std::shared_ptr<DriveSystem> myDrive;
};

#endif /* CHASSIS_HPP_ */
