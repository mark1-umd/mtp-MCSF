/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Path.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
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
#include "Trajectory.hpp"

/** @brief A motion path is a vector of Path Points
 */

class Path {
 public:
  Path();
  virtual ~Path();
  void addPathPoint(const PathPoint pathPoint);
  Trajectory planTrajectory();
  void show();

 private:
  std::vector<PathPoint> path;
};

#endif /* PATH_HPP_ */
