/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Chassis.cpp
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
#include "Chassis.hpp"

Chassis::Chassis()
    : myName(""),
      myDriveSystem() {
}

Chassis::~Chassis() {
}

/**
 * @brief Set the chassis name
 * @param [in] string name of the chassis
 */
void Chassis::setMyName(std::string name) {
  myName = name;
  myDriveSystem.setChassisName(myName);
  return;
}

/**
 * @brief Get the chassis name
 * @return string name of the chassis
 */
std::string Chassis::getMyName() {
  return myName;
}

/**
 * @brief Sets the chassis's drive system to the specified object of a class derived from DriveSystem
 * @param [in] DriveSystem driveSystem derived class object (e.g., a TankDrive object)
 */
void Chassis::setMyDriveSystem(const DriveSystem &driveSystem) {
  myDriveSystem = driveSystem;
  myDriveSystem.setChassisName(myName);
  return;
}

/**
 * @brief Gets the chassis' drive system (an object of a class derived from the DriveSystem base class)
 * @return DriveSystem myDriveSystem - an object of a class derived from the DriveSystem base class
 */
DriveSystem Chassis::getMyDriveSystem() {
  return myDriveSystem;
}

/**
 * @brief Use the DriveSystem to move the chassis
 * @param [in] double distanceFeet to move the chassis
 * @param [in] ChassisTurnrate chassisTurnRate (0 for straight, < 0 for left turn, > 0 for right turn)
 * @param [in] ChassisVelocity chassisVelocityRequested (actual movement constrained by drive system)
 * @param [in] ChassisAcceleration chassisAccelerationRequested (actual movement constrained by drive system)
 */
void Chassis::move(double distanceFeet, ChassisTurnRate chassisTurnRate,
                   ChassisVelocity chassisVelocityRequested,
                   ChassisAcceleration chassisAccelerationRequested) {
  // Pass this on to the drive system
  myDriveSystem.move(distanceFeet, chassisTurnRate, chassisVelocityRequested,
                     chassisAccelerationRequested);
  return;
}
