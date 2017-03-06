/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Point.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A superclass to define Point objects; subclasses will inherit
 *
 * There are at least three types of Point objects - WayPoints,
 * PathPoints, and TrajectoryPoints.  All three have in common a
 * position with accessor methods to set and get the position.  This
 * superclass is a generalization of those three types of points.
 *
 */
#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>

/** @brief A point is position reference for a motor
 */

class Point {
 public:
  Point();
  virtual ~Point();
  void setPosition(const MotorPosition pos);
  MotorPosition getPosition();
  void show();

 private:
  MotorPosition position;
};


#endif /* POINT_HPP_ */
