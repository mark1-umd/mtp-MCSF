/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MotorVelocity.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A class to define a strict type for motor velocities
 *
 * Motor velocities can be specified in a variety of ways; encoder ticks
 * per unit of time, or motor rotations per unit of time are two of these.
 * This class creates a strict type for motor velocities, and can provide
 * a variety of accessor functions to allow setting/getting the velocity
 * in different units.  The class stores the velocity internally as
 * "Rotations Per Minute" (RPM).
 *
 */
#include "MotorVelocity.hpp"

MotorVelocity::MotorVelocity()
    : velAsRotationsPerMinute(0.0) {
}

MotorVelocity::~MotorVelocity() {
}

/**
 * @brief Set motor velocity in units of Rotations per Minute
 * @param [in] double rate representing a motor velocity
 */
void MotorVelocity::setRotationsPerMinute(const double rate) {
  velAsRotationsPerMinute = rate;
  return;
}

/**
 * @brief Convert from a ChassVelocity to motor rotations by Rotations per Movement Foot
 * @param [in] ChassisVelocity chassisVelocity specifies a linear physical velocity
 * @param [in] double rotPerMovementFoot is the conversion factor from movement feet to rotations
 */
void MotorVelocity::setFromChassisVelocityByRotPerMovementFoot(
    ChassisVelocity chassisVelocity, double rotPerMovementFoot) {
  velAsRotationsPerMinute = chassisVelocity.getFeetPerSecond() * 60
      * rotPerMovementFoot;
  return;
}

/**
 * @brief Get motor velocity in units of Rotations per Minute
 * @return double representing a motor velocity
 */
double MotorVelocity::getRotationsPerMinute() {
  return velAsRotationsPerMinute;
}
