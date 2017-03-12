/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Point.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A base class to define common members of Point objects
 *
 * There are at least three types of Point objects - WayPoints,
 * PathPoints, and TrajectoryPoints.  All three have in common a
 * position with accessor methods to set and get the position.  This
 * base class is a generalization of those three types of points.
 *
 */
#include "Point.hpp"

Point::Point()
    : position() {
}

Point::~Point() {
  // TODO(Mark Jenkins): Auto-generated destructor stub
}

/**
 * @brief Set the position of a generic Point object
 * @param [in] MotorPosition pos is a point referenced by a motor position
 */
void Point::setPosition(const MotorPosition &pos) {
  position = pos;
  return;
}

/**
 * @brief Get the previously set position of a generic Point object
 * @return MotorPosition position
 */
MotorPosition Point::getPosition() {
  return position;
}

/**
 * @brief Show the point's position (in motor rotations)
 */
void Point::show() {
  std::cout << "Position: " << position.getRotations()
            << " motor rotations";
  return;
}
