/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file TrajectoryPoint.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A motion profile trajectory point - position, velocity, duration
 *
 * A motion profile consists of a set of trajectory points, each one of
 * which specifies a position and velocity to be achieved during the
 * execution of the point, and a duration in which to achieve the
 * velocity and position.
 *
 */
#ifndef TRAJECTORYPOINT_HPP_
#define TRAJECTORYPOINT_HPP_

#include "Point.hpp"
#include <iostream>

/** @brief <brief description>
 */

class TrajectoryPoint : public Point {
 public:
  TrajectoryPoint();
  virtual ~TrajectoryPoint();
  void setVelocity(const MotorVelocity vel);
  MotorVelocity getVelocity();
  void setDurationMS(const int duration);
  int getDurationMS();
  void show();

 private:
  MotorVelocity velocity;
  int durationMS;
};

#endif /* TRAJECTORYPOINT_HPP_ */
