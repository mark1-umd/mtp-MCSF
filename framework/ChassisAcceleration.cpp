/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file ChassisAcceleration.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 13, 2017 - Creation
 *
 * @brief A class to define a strict type for chassis accelerations
 *
 * Chassis accelerations can be specified in a variety of ways; the one chosen for initial
 * implementation is feet per second per second.  This class creates a strict type for chassis
 * accelerations, and can provide a variety of accessor functions to allow setting/getting the
 * acceleration in different units.  The class stores the acceleration internally as
 * "Feet Per Second Per Second" (fps/s).
 *
 */
#include "ChassisAcceleration.hpp"

ChassisAcceleration::ChassisAcceleration()
    : accelAsFeetPerSecondPerSecond(0.0) {
}

ChassisAcceleration::~ChassisAcceleration() {
}

/**
 * @brief Set the chassis acceleration in units of feet per second per second
 * @param [in] double rate of acceleration in units of feet per second per second
 */
void ChassisAcceleration::setFeetPerSecondPerSecond(double rate) {
  accelAsFeetPerSecondPerSecond = rate;
  return;
}

/**
 * @brief Get the chassis acceleration in units of feet per second per second
 * @return double rate of acceleration in units of feet per second per second
 */
double ChassisAcceleration::getFeetPerSecondPerSecond() {
  return accelAsFeetPerSecondPerSecond;
}
