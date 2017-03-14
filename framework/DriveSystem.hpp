/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file DriveSystem.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 13, 2017 - Creation
 *
 * @brief A base class for representing drive system objects
 *
 * There can be many kinds of drive systems.  Attributes and methods generalized from all types
 * are implemented in this base class.  The actual objects are intended to be instantiated from
 * class defintions derived from this base class.
 *
 */
#ifndef DRIVESYSTEM_HPP_
#define DRIVESYSTEM_HPP_

#include <string>
#include "MotorVelocity.hpp"
#include "MotorAcceleration.hpp"
#include "ChassisTurnRate.hpp"
#include "ChassisVelocity.hpp"
#include "ChassisAcceleration.hpp"

/** @brief Base class for representing drive system objects
 */

class DriveSystem {
 public:
  DriveSystem();
  virtual ~DriveSystem();
  void setChassisName(std::string name);
  std::string getChassisName();
  void setMaxVelocity(MotorVelocity velocity);
  MotorVelocity getMaxVelocity();
  void setMaxAcceleration(MotorAcceleration acceleration);
  MotorAcceleration getMaxAcceleration();
  void setMotorRotPerMovementFoot(double rotations);
  double getMotorRotPerMovementFoot();
  void setTrajectoryIterationPeriodMS(unsigned int period);
  unsigned int getTrajectoryIterationPeriodMS();
  virtual void move(double distanceFeet, ChassisTurnRate chassisTurnRate,
                    ChassisVelocity chassisVelocityRequested,
                    ChassisAcceleration chassisAccelerationRequested);

 protected:
  std::string chassisName;
  MotorVelocity maxVelocity;
  MotorAcceleration maxAcceleration;
  double motorRotPerMovementFoot;
  unsigned int trajectoryIterationPeriodMS;
};

#endif /* DRIVESYSTEM_HPP_ */
