/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file ChassisTurnRate.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 13, 2017 - Creation
 *
 * @brief ChassisTurnRate is a strictly defined type for specifying the turn rate of a moving chassis
 *
 * Chassis turn rates may be specified in a variety of ways; the one implemented here is as a
 * degree of turn per foot of movement.  This class creates a strict type for chassis turn rates,
 * and can provide a variety of accessor functiont so allow setting/getting the turn rate in
 * different units.  The class stores the turn rate internaly as "Degrees per Foot of movement".
 * Note that a zero turn rate indicates movement straight ahead, a negative turn rate indicates a
 * deviation (turn) to the left, and a positive turn rate indicates a deviation (turn) to the right.
 *
 */
#ifndef CHASSISTURNRATE_HPP_
#define CHASSISTURNRATE_HPP_

/** @brief ChassisTurnRate objects are used to specify a change in direction while a chassis is moving.
 */

class ChassisTurnRate {
 public:
  ChassisTurnRate();
  virtual ~ChassisTurnRate();
  void setDegreesPerFoot(double degrees);
  double getDegreesPerFoot();

 private:
  double degreesPerFoot;  // 0 indicates straight movement, negative indicates left turn
                          // positive indicates right turn
};

#endif /* CHASSISTURNRATE_HPP_ */
