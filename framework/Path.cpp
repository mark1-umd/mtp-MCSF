/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Path.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 *
 * * @brief A motion path is a vector of Path Points
 *
 * A motion path represents a planned series of points through which
 * a motion will travel.  The path can be used to plan a motion profile
 * trajectory.
 *
 */
#include "Path.hpp"

Path::Path() {
}

Path::~Path() {
  // TODO Auto-generated destructor stub
}

/**
 * @brief Add a path point onto this path
 * @param [in] a PathPoint pathPoint to add to the current path
 */
void Path::addPathPoint(const PathPoint pathPoint) {
  path.push_back(pathPoint);
  return;
}
/**
 * @brief Using the current path, plan a motion profile trajectory
 * @return A motion profile trajectory
 */
Trajectory Path::planTrajectory() {
  Trajectory trajectory;
  return trajectory;
}

void Path::show() {
  std::cout << "Motion path:" << std::endl;
  for (auto pathPoint : path) {
    pathPoint.show();
    std::cout << std::endl;
  }
  std::cout << "End of motion path." << std::endl;
  return;
}
