/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file TankDrive.hpp
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
#ifndef TANKDRIVE_HPP_
#define TANKDRIVE_HPP_

#include <algorithm>
#include <cmath>
#include <string>
#include "ChassisAcceleration.hpp"
#include "ChassisTurnRate.hpp"
#include "ChassisVelocity.hpp"
#include "DriveSystem.hpp"
#include "MotorAcceleration.hpp"
#include "MotorPosition.hpp"
#include "MotorVelocity.hpp"
#include "Path.hpp"
#include "PathPoint.hpp"
#include "Trajectory.hpp"


/** @brief TankDrive is derived from the base class DriveSystem
 */

class TankDrive : public DriveSystem {
 public:
  TankDrive();
  virtual ~TankDrive();
  void setWidthInFeet(double width);
  double getWidthInFeet();
  void move(double distanceFeet, ChassisTurnRate chassisTurnRate,
            ChassisVelocity chassisVelocityRequested,
            ChassisAcceleration chassisAccelelerationRequested);

 private:
  double widthInFeet;  // the distance between the left and right side
                       // motivators of the tank drive
};

#endif /* TANKDRIVE_HPP_ */
