/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Point.cpp
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
 #include "Point.hpp"


 Point::Point()
 {
 // TODO Auto-generated constructor stub

 }

 Point::~Point()
 {
 // TODO Auto-generated destructor stub
 }

/**
 * @brief Set the position of a generic Point object
 * @param [in] MotorPosition pos
 */
void setPosition(const MotorPosition pos) {
  Point::position = pos;
  return;
}

/**
 * @brief Get the previously set position of a generic Point object
 * @return MotorPosition position
 */
MotorPosition getPosition() {
  return Point::position;
}

/**
 * @brief Show the point's position (in motor rotations)
 */
void Point::show() {
  std::cout << "Position: " << Point::position.getRotations()
            << " motor rotations";
  return;
}
