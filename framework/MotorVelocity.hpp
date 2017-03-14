/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MotorVelocity.hpp
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
#ifndef MOTORVELOCITY_HPP_
#define MOTORVELOCITY_HPP_

/** @brief The MotorVelocity class is a strict type for motor velocities
 */

class MotorVelocity {
 public:
  MotorVelocity();
  virtual ~MotorVelocity();
  void setRotationsPerMinute(const double rate);
  void convertFromChassisVelocityByRotPerMovementFoot(
      ChassisVelocity chassisVelocity, double rotPerMovementFoot);
  double getRotationsPerMinute();

 private:
  double velAsRotationsPerMinute;
};

#endif /* MOTORVELOCITY_HPP_ */
