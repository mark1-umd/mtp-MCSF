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
  // TODO Auto-generated constructor stub

}

Path::~Path() {
  // TODO Auto-generated destructor stub
}

/**
 * @brief Using the current path, plan a motion profile trajectory
 * @return A motion profile trajectory
 */
Trajectory Path::planTrajectory() {
  Trajectory trajectory = new Trajectory;
  return trajectory;
}

void Path::show() {
  std::cout << "Motion path:" << std::endl;
  for (auto p : Path::path) {
    std::cout << p.show();
    std::cout << std::endl;
  }
  std::cout << "End of motion path." << std::endl;
  return;
}
