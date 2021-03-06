/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MotorAcceleration.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A class for a strictly typed representation of motor acceleration
 *
 * Motor accelerations can be specified in a variety of ways;
 * a change in encoder tick rates per unit of time, or a change in
 * motor rotation rates per unit of time are two of these.
 * This class creates a strict type for motor accelerations, and can provide
 * a variety of accessor functions to allow setting/getting the velocity
 * in different units.  The class stores the acceleration internally as
 * "Rotations Per Minute per second" (RPM/s).
 *
 */
#include "MotorAcceleration.hpp"

MotorAcceleration::MotorAcceleration()
    : accelAsRotationsPerMinutePerSecond(0.0) {
}

MotorAcceleration::~MotorAcceleration() {
}

/**
 * @brief Set a motor acceleration value in Rotations per Minute per second
 * @param [in] double rate to set as the acceleration value
 */
void MotorAcceleration::setRotationsPerMinutePerSecond(const double rate) {
  accelAsRotationsPerMinutePerSecond = rate;
  return;
}

/**
 * @brief Set a motor acceleration value from a chassis acceleration object
 * @param [in] ChassisAcceleration chassisAcceleration object
 * @param [in] double rotPerMovementFoot specifying the rotations per movement foot
 */
void MotorAcceleration::setFromChassisAccelerationByRotPerMovementFoot(
    ChassisAcceleration chassisAcceleration, double rotPerMovementFoot) {
  accelAsRotationsPerMinutePerSecond = chassisAcceleration
      .getFeetPerSecondPerSecond() * 60 * rotPerMovementFoot;
  return;
}
/**
 * @brief Get a motor acceleration value in Rotations per Minute per second
 * @return a double representing the motor acceleration value
 */
double MotorAcceleration::getRotationsPerMinutePerSecond() {
  return accelAsRotationsPerMinutePerSecond;
}
