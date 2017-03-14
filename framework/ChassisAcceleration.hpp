/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file ChassisAcceleration.hpp
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
#ifndef CHASSISACCELERATION_HPP_
#define CHASSISACCELERATION_HPP_

/** @brief Defines a strict type for chassis accelerations
 */

class ChassisAcceleration {
 public:
  ChassisAcceleration();
  virtual ~ChassisAcceleration();
  void setFeetPerSecondPerSecond(double rate);
  double getFeetPerSecondPerSecond();

 private:
  double accelAsFeetPerSecondPerSecond;
};

#endif /* CHASSISACCELERATION_HPP_ */
