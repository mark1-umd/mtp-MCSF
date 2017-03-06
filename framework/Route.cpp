/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Route.cpp
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
#include "Route.hpp"

Route::Route() {
  // TODO Auto-generated constructor stub

}

Route::~Route() {
  // TODO Auto-generated destructor stub
}

/**
 * @brief Add a way point to this route
 * @param [in] a WayPoint to be added to this route
 */
void Route::addWayPoint(const WayPoint wayPoint) {
  Route::route.pushback(wayPoint);
  return;
}

/**
 * @brief Plan a path based on this route's way points
 * @param maxVelocity
 * @param maxAcceleration
 * @return a Path object specifying the path points to traverse
 */
Path Route::planPath(const MotorVelocity maxVelocity,
                     const MotorAcceleration maxAcceleration) {
  Path path = new Path;
  for (auto wp : Route::route)
    path.addPathPoint(wp.getPosition, maxVelocity, maxAcceleration);
  return path;
}

void Route::show() {
  std::cout << "Route way points:" << std::endl;
  for (auto wp : Route::route)
    std::cout << wp.show() << std::endl;
  std::cout << "End of route" << std::endl;
  return;
}
