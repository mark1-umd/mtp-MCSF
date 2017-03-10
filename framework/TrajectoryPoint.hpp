/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file TrajectoryPoint.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A motion profile trajectory point - position, velocity, duration
 *
 * A motion profile consists of a set of trajectory points, each one of
 * which specifies a position and velocity to be achieved during the
 * execution of the point, and a duration in which to achieve the
 * velocity and position.
 *
 */
#ifndef TRAJECTORYPOINT_HPP_
#define TRAJECTORYPOINT_HPP_

#include <iostream>
#include <fstream>
#include "Point.hpp"
#include "MotorPosition.hpp"
#include "MotorVelocity.hpp"
#include "MotorAcceleration.hpp"

/** @brief A trajectory point is a point with added velocity and duration
 */

class TrajectoryPoint : public Point {
 public:
  TrajectoryPoint();
  virtual ~TrajectoryPoint();
  void setPosition(const MotorPosition pos);
  MotorPosition getPosition();
  void setVelocity(const MotorVelocity vel);
  MotorVelocity getVelocity();
  void setAcceleration(const MotorAcceleration accel);
  MotorAcceleration getAcceleration();
  void setDurationMS(const int duration);
  int getDurationMS();
  void setTimeS(const double time);
  double getTimeS();
  void show();
  void outputCSV(std::ofstream& fileCSV);
  void outputCSVheader(std::ofstream& fileCSV);

 private:
  MotorPosition position;
  MotorVelocity velocity;
  MotorAcceleration acceleration;
  int durationMS;
  double timeS;
};

#endif /* TRAJECTORYPOINT_HPP_ */
