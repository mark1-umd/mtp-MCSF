/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file PathPoint.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A representation of a point along a path with maximum velocity
 * and maximum acceleration constraints
 *
 * A path to be used for motion profiling trajectories needs to include
 * velocity and acceleration constraints to be used in constructing
 * a motion profile that shapes the motion based on the maximum
 * velocities and accelerations to be used in achieving motion.
 *
 */
#ifndef PATHPOINT_HPP_
#define PATHPOINT_HPP_

#include "Point.hpp"
#include <iostream>

/** @brief <brief description>
 */

class PathPoint : public Point {
 public:
  PathPoint();
  virtual ~PathPoint();
  void setMaxVelocity(const MotorVelocity maxV);
  MotorVelocity getMaxVelocity();
  void setMaxAcceleration(const MotorAcceleration maxA);
  MotorAcceleration getMaxAcceleration();
  void show();

 private:
  MotorVelocity maxVelocity;
  MotorAcceleration maxAcceleration;
};

#endif /* PATHPOINT_HPP_ */
