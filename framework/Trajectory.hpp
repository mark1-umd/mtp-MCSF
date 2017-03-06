/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Trajectory.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 *
 * @brief A trajectory is a vector of motion profile trajectory points
 *
 * A motion profile trajectory is executed in order to induce carefully
 * controlled motion.  Each trajectory point represents a time-phased
 * position and velocity to be achieved by a motion mechanism.
 *
 */
#ifndef TRAJECTORY_HPP_
#define TRAJECTORY_HPP_

#include <vector>
#include <iostream>

/** @brief A trajectory is a vector of motion prifle trajectory points
 */

class Trajectory {
 public:
  Trajectory();
  virtual ~Trajectory();
  void execute();
  void show();

 private:
  std::vector<TrajectoryPoint> trajectory;
};

#endif /* TRAJECTORY_HPP_ */
