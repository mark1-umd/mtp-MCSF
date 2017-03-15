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
      myDrive() {
}

Chassis::~Chassis() {
}

/**
 * @brief Set the chassis name
 * @param [in] string name of the chassis
 */
void Chassis::setName(std::string name) {
  myName = name;
//  if (myDrive)
//    myDrive->setChassisName(myName); // Not working - 2017-03-14
  myDrive.setChassisName(myName);
  return;
}

/**
 * @brief Get the chassis name
 * @return string name of the chassis
 */
std::string Chassis::getName() {
  return myName;
}

// The assignable Drive System function is not working - MRJ 2017-03-14
///**
// * @brief Sets the chassis's drive system to the specified object of a class derived from DriveSystem
// * @param [in] DriveSystem driveSystem derived class object (e.g., a TankDrive object)
// */
// void Chassis::setDriveSystem(std::shared_ptr<DriveSystem> driveSystem) {
//  myDrive = driveSystem;
//  myDrive->setChassisName(myName);
//  return;
//}

///**
// * @brief Gets the chassis' drive system (an object of a class derived from the DriveSystem base class)
// * @return DriveSystem myDriveSystem - an object of a class derived from the DriveSystem base class
// */
// std::shared_ptr<DriveSystem> Chassis::getDriveSystem() {
//  std::shared_ptr<DriveSystem> theDrive = myDrive;
//  return theDrive;
//}

void Chassis::setDriveSystem(const TankDrive &driveSystem) {
  myDrive = driveSystem;
  myDrive.setChassisName(myName);
  return;
}

TankDrive Chassis::getDriveSystem() {
  return myDrive;
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
//  myDrive->move(distanceFeet, chassisTurnRate, chassisVelocityRequested,
//                     chassisAccelerationRequested);  // Not working 2017-03-14
  myDrive.move(distanceFeet, chassisTurnRate, chassisVelocityRequested,
                     chassisAccelerationRequested);

  return;
}
