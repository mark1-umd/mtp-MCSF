/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Route.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A Route represents a series of Way Points to be traveled to
 *
 * Routes are planned as a series of Way Points indicating positions
 * to be traveled to.
 *
 */
#ifndef ROUTE_HPP_
#define ROUTE_HPP_

#include <iostream>
#include <vector>
#include "Path.hpp"
#include "WayPoint.hpp"

/** @brief A Route represents a series of Way Points to be traveled to
 */

class Route {
 public:
  Route();
  virtual ~Route();
  void addWayPoint(const WayPoint &wayPoint);
  Path planPath(const MotorVelocity &maxVelocity,
                const MotorAcceleration &maxAcceleration);
  void show();

 private:
  std::vector<WayPoint> route;
};

#endif /* ROUTE_HPP_ */
