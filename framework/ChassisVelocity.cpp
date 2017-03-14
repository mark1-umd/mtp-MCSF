/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file ChassisVelocity.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 13, 2017 - Creation
 *
 * @brief A class to define a strict type for chassis velocities
 *
 * Chassis velocities can be specified in a variety of ways; the one chosen for initial
 * implementation is feet per second.  This class creates a strict type for chassis velocities,
 * and can provide a variety of accessor functions to allow setting/getting the velocity
 * in different units.  The class stores the velocity internally as "Feet Per Second" (fps).
 *
 */
#include "ChassisVelocity.hpp"

ChassisVelocity::ChassisVelocity()
    : velAsFeetPerSecond(0.0) {
}

ChassisVelocity::~ChassisVelocity() {
}

/**
 * @brief Set the chassis velocity in units of feet per second
 * @param [in] double velocity (in units of feet per second)
 */
void ChassisVelocity::setFeetPerSecond(double rate) {
  velAsFeetPerSecond = rate;
  return;
}

/**
 * @brief Get the chassis velocity in units of feet per second
 * @return double velocity in units of feet per second
 */
double ChassisVelocity::getFeetPerSecond() {
  return velAsFeetPerSecond;
}
