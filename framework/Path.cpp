/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Path.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 * @date Mar 9, 2017 - Removed planTrajectory (moved to Trajectory object)
 * @date Mar 9, 2017 - Added getFirstPathPoint, getNextPathPoint, and
 * size methods to facilitate trajectory generation from Trajectory object
 *
 * * @brief A motion path is a vector of Path Points
 *
 * A motion path represents a planned series of points through which
 * a motion will travel.  The path can be used to plan a motion profile
 * trajectory.
 *
 */
#include "Path.hpp"

Path::Path()
    : path(),
      nextPathPoint(0) {
}

Path::~Path() {
  // TODO(Mark Jenkins): Auto-generated destructor stub
}

/**
 * @brief Add a path point onto this path
 * @param [in] a PathPoint pathPoint to add to the current path
 */
void Path::addPathPoint(const PathPoint &pathPoint) {
  path.push_back(pathPoint);
  return;
}

/**
 * @brief Return the first path point in the path
 * @param [out] PathPoint set equal to the value of the first path point on the path
 * @return bool indication of whether the requested point was on the path
 */
bool Path::getFirstPathPoint(PathPoint &pathPoint) {
  // Make sure the path has at least one point on it before accessing it
  if (!path.empty()) {
    pathPoint = path.front();
    nextPathPoint = 1;
    return true;
  }
  return false;
}

/**
 * @brief Return the next path point on the path
 * @param [out] PathPoint set equal to the value of the next path point on the path
 * @return bool indication of whether the requested point was on the path
 */
bool Path::getNextPathPoint(PathPoint &pathPoint) {
  // Make sure there is a "next" point on the path before trying to access it
  if (nextPathPoint != 0 && nextPathPoint < path.size()) {
    pathPoint = path.at(nextPathPoint);
    nextPathPoint++;
    return true;
  }
  return false;
}

/**
 * @brief Reports the number of path points in this path
 * @return int number of path points in path
 */
unsigned int Path::size() {
  return path.size();
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
