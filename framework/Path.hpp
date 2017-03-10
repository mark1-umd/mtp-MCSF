/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Path.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 * @date Mar 9, 2017 - Removed planTrajectory (moved to Trajectory object)
 * @date Mar 9, 2017 - Added getFirstPathPoint, getNextPathPoint, and
 * size methods to facilitate trajectory generation from Trajectory object
 *
 * @brief A motion path is a vector of Path Points
 *
 * A motion path represents a planned series of points through which
 * a motion will travel.  The path can be used to plan a motion profile
 * trajectory.
 *
 */
#ifndef PATH_HPP_
#define PATH_HPP_

#include <vector>
#include <iostream>
#include "PathPoint.hpp"

/** @brief A motion path is a series of path points between two Way Points
 */

class Path {
 public:
  Path();
  virtual ~Path();
  void addPathPoint(const PathPoint& pathPoint);
  bool getFirstPathPoint(PathPoint& pathPoint);
  bool getNextPathPoint(PathPoint& pathPoint);
  unsigned int size();
  void show();

 private:
  std::vector<PathPoint> path;
  std::vector<PathPoint>::size_type nextPathPoint;
};

#endif /* PATH_HPP_ */
