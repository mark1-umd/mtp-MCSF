/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file WayPoint.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A representation of a route-planning Way Point
 *
 * The Way Point object encodes a location that is to be used as part
 * of a route for path planning purposes.
 *
 */
#ifndef WAYPOINT_HPP_
#define WAYPOINT_HPP_

#include "Point.hpp"

/** @brief A representation of a route-planning Way Point
 */

class WayPoint : public Point {
 public:
  WayPoint();
  virtual ~WayPoint();
};

#endif /* WAYPOINT_HPP_ */
