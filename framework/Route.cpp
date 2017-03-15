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

Route::Route()
    : route() {
}

Route::~Route() {
}

/**
 * @brief Add a way point to this route
 * @param [in] a WayPoint to be added to this route
 */
void Route::addWayPoint(const WayPoint &wayPoint) {
  route.push_back(wayPoint);
  return;
}

/**
 * @brief Plan a path based on this route's way points
 * @param maxVelocity
 * @param maxAcceleration
 * @return a Path object specifying the path points to traverse
 */
Path Route::planPath(const MotorVelocity &maxVelocity,
                     const MotorAcceleration &maxAcceleration) {
  Path path;
  for (auto wp : route) {
    PathPoint pathpoint;
    pathpoint.setPosition(wp.getPosition());
    pathpoint.setMaxVelocity(maxVelocity);
    pathpoint.setMaxAcceleration(maxAcceleration);
    path.addPathPoint(pathpoint);
  }
  return path;
}

/**
 * @brief Show the details of this route on the default output device
 */
void Route::show() {
  std::cout << "Route way points:" << std::endl;
  for (auto wayPoint : route) {
    wayPoint.show();
    std::cout << std::endl;
  }
  std::cout << "End of route" << std::endl;
  return;
}
