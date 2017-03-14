/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file DriveSystem.cpp
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
#include "DriveSystem.hpp"

DriveSystem::DriveSystem()
    : chassisName(""),
      maxVelocity(),
      maxAcceleration(),
      motorRotPerMovementFoot(0.0),
      trajectoryIterationPeriodMS(0) {
}

DriveSystem::~DriveSystem() {
}

/**
 * @brief Set the chassis name to which this drive system belongs
 * @param [in] std::string name that matches the chassis name to which this drive system belongs
 */
void DriveSystem::setChassisName(std::string name) {
  chassisName = name;
  return;
}

/**
 * @brief Get the name for the chassis to which this drive system belongs
 * @return std::string chassisName of the chassis to which this drive system belongs
 */
std::string DriveSystem::getChassisName() {
  return chassisName;
}

/**
 * @brief Set the maximum velocity at which this drive system can operate effectively
 * @param [in] MotorVelocity velocity at which this drive system can operate effectively
 */
void DriveSystem::setMaxVelocity(MotorVelocity velocity) {
  maxVelocity = velocity;
  return;
}

/**
 * @brief Get the maximum velocity at which this drive system can operate effectively
 * @return MotorVelocity velocity at which this drive system can operate effectively
 */
MotorVelocity DriveSystem::getMaxVelocity() {
  return maxVelocity;
}

/**
 * @brief Set the maximum acceleration at which this drive system can operate effectively
 * @param [in] MotorAcceleration acceleration at which this drive system can operate effectively
 */
void DriveSystem::setMaxAcceleration(MotorAcceleration acceleration) {
  maxAcceleration = acceleration;
  return;
}

/**
 * @brief Get the maximum acceleration at which this drive system can operate effectively
 * @return MotorAcceleration acceleration at which this drive system can operate effectively
 */
MotorAcceleration DriveSystem::getMaxAcceleration() {
  return maxAcceleration;
}

/**
 * @brief Set the number of motor rotations required to move the drive system one foot
 * @param [in] double rotations of the motor per foot of movement
 */
void DriveSystem::setMotorRotPerMovementFoot(double rotations) {
  motorRotPerMovementFoot = rotations;
  return;
}

/**
 * @brief Get the number of motor rotations required to move the drive system one foot
 * @return double rotations of the motor per foot of movement
 */
double DriveSystem::getMotorRotPerMovementFoot() {
  return motorRotPerMovementFoot;
}

/**
 * @brief Set the iteration period (in milliseconds) to be used for each trajectory point
 * @param [in] unsigned int period for trajectory points in milliseconds
 */
void DriveSystem::setTrajectoryIterationPeriodMS(unsigned int period) {
  trajectoryIterationPeriodMS = period;
  return;
}

/**
 * @brief Get the iteration period (in milliseconds) to be used for each trajectory point
 * @return unsigned int period for trajectory points in milliseconds
 */
unsigned int DriveSystem::getTrajectoryIterationPeriodMS() {
  return trajectoryIterationPeriodMS;
}
/* this is now a virtual method MRJ 2017-03-12
void DriveSystem::move(double distanceFeet, ChassisTurnRate chassisTurnRate,
          ChassisVelocity chassisVelocityRequested,
          ChassisAcceleration chassisAccelerationRequested) {
  return;
}
 */
