/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MotorAcceleration.hpp
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
#ifndef MOTORACCELERATION_HPP_
#define MOTORACCELERATION_HPP_

#include "ChassisAcceleration.hpp"

/** @brief A class to provide a strict type for specifying motor acceleration
 */

class MotorAcceleration {
 public:
  MotorAcceleration();
  virtual ~MotorAcceleration();
  void setRotationsPerMinutePerSecond(const double rate);
  void setFromChassisAccelerationByRotPerMovementFoot(
      ChassisAcceleration chassisAcceleration, double rotPerMovementFoot);
  double getRotationsPerMinutePerSecond();

 private:
  double accelAsRotationsPerMinutePerSecond;
};

#endif /* MOTORACCELERATION_HPP_ */
