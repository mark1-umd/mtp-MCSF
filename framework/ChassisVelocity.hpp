/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file ChassisVelocity.hpp
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
#ifndef CHASSISVELOCITY_HPP_
#define CHASSISVELOCITY_HPP_

/** @brief A strictly defined type for chassis velocities
 */

class ChassisVelocity {
 public:
  ChassisVelocity();
  virtual ~ChassisVelocity();
  void setFeetPerSecond(double rate);
  double getFeetPerSecond();

 private:
  double velAsFeetPerSecond;
};

#endif /* CHASSISVELOCITY_HPP_ */
