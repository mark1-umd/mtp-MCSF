/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Trajectory.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 * @date Mar 8, 2017 - Updates to attributes to support trajectory generation
 * @date Mar 9, 2017 - added "generate" method using Path input
 *
 * @brief A trajectory is a vector of motion profile trajectory points
 *
 * A motion profile trajectory is executed in order to induce carefully
 * controlled motion.  Each trajectory point represents a time-phased
 * position and velocity to be achieved by a motion mechanism.  A number
 * of algorithmic parameters that are artifacts of the generation
 * process are stored with the trajectory for information and/or
 * debugging purposes.
 *
 */
#ifndef TRAJECTORY_HPP_
#define TRAJECTORY_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "MotorPosition.hpp"
#include "MotorVelocity.hpp"
#include "MotorAcceleration.hpp"
#include "TrajectoryPoint.hpp"
#include "Path.hpp"
#include "PathPoint.hpp"

/** @brief A trajectory is a vector of motion profile trajectory points
 */

class Trajectory {
 public:
  Trajectory();
  virtual ~Trajectory();
  MotorVelocity getMaxVelocity();
  MotorAcceleration getMaxAcceleration();
  MotorPosition getDistance();
  unsigned int getAlgoItPMS();
  unsigned int getAlgoT1MS();
  unsigned int getAlgoT2MS();
  unsigned int getAlgoT4MS();
  unsigned int getAlgoFL1count();
  unsigned int getAlgoFL2count();
  unsigned int getAlgoNcount();
  void generate(Path& path, const unsigned int iterationPeriodMS);
  void execute();
  unsigned int size();
  void show();
  void outputCSV(const std::string trajectoryFileName);

 private:
  void addToHistory(std::vector<double> &history, const unsigned int max,
                    const double value);
  MotorVelocity maxVelocity;          // maximum velocity for this trajectory
  MotorAcceleration maxAcceleration;  // maximum acceleration for this trajectory
  MotorPosition distance;             // total distance for this trajectory
  unsigned int algoItPMS;             // iteration period for each point
  unsigned int algoT1MS;              // algorithm T1 variable, in milliseconds
  unsigned int algoT2MS;              // algorithm T2 variable, in milliseconds
  unsigned int algoT4MS;              // algorithm T4 variable, in milliseconds
  unsigned int algoFL1count;          // algorithm FL1 count
  unsigned int algoFL2count;          // algorithm FL2 count
  unsigned int algoNcount;            // algorithm N count
  std::vector<TrajectoryPoint> trajectory;  // the series of trajectory points
};

#endif /* TRAJECTORY_HPP_ */
