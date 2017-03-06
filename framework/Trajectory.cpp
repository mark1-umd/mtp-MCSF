/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Trajectory.cpp
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
#include "Trajectory.hpp"

Trajectory::Trajectory() {
  // TODO Auto-generated constructor stub
}

Trajectory::~Trajectory() {
  // TODO Auto-generated destructor stub
}

/**
 * @brief Stub Execution of this trajectory's motion profile trajectory points
 */
void Trajectory::execute() {
  std::cout << "Executing motion profile trajectory: (one dot per point)"
            << std::endl;
  for (auto tp : Trajectory::trajectory)
    std::cout << ".";
  std::cout << std::endl;
  std::cout << "End of motion profile trajectory execution." << std::endl;
  return;
}

/**
 * @brief Show this motion profile trajectory as individual points
 */
void Trajectory::show() {
  std::cout << "Motion Profile trajectory:" << std::endl;
  for (auto tp : Trajectory::trajectory) {
    tp.show();
    std::cout << std::endl;
  }
  std::cout << "End of Motion Profile trajectory." << std::endl;
  return;
}
