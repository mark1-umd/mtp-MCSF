/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file TrajectoryPoint.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 * @date Mar 9, 2017 - Updates to support trajectory generation changes in Trajectory class
 * @date Mar 11, 2017 - Updates to track algorithm details for model comparison
 *
 * @brief A motion profile trajectory point - position, velocity, duration
 *
 * A motion profile consists of a set of trajectory points, each one of
 * which specifies a position and velocity to be achieved during the
 * execution of the point, and a duration in which to achieve the
 * velocity and position.  Additional attributes capture the generation
 * algorithm details such a filter values, acceleration and time points
 * calculated during trajectory generation so that the generated output can
 * be more closely compared with a spreadsheet model when verifying behavior.
 *
 */
#ifndef TRAJECTORYPOINT_HPP_
#define TRAJECTORYPOINT_HPP_

#include <fstream>
#include <iostream>
#include "MotorAcceleration.hpp"
#include "MotorPosition.hpp"
#include "MotorVelocity.hpp"
#include "Point.hpp"

/** @brief A trajectory point is a point with added velocity and duration
 */

class TrajectoryPoint : public Point {
 public:
  TrajectoryPoint();
  virtual ~TrajectoryPoint();
  void setPosition(const MotorPosition &pos);
  MotorPosition getPosition();
  void setVelocity(const MotorVelocity &vel);
  MotorVelocity getVelocity();
  void setAcceleration(const MotorAcceleration &accel);
  MotorAcceleration getAcceleration();
  void setDurationMS(const unsigned int duration);
  unsigned int getDurationMS();
  void setStep(const unsigned int stepCount);
  unsigned int getStep();
  void setTimeS(const double time);
  double getTimeS();
  void setFilter1Sum(const double sum);
  double getFilter1Sum();
  void setFilter2Sum(const double sum);
  double getFilter2Sum();
  void show();
  void outputCSV(std::ofstream& fileCSV);
  void outputCSVheader(std::ofstream& fileCSV);

 private:
  MotorPosition position;
  MotorVelocity velocity;
  MotorAcceleration acceleration;
  unsigned int durationMS;
  unsigned int step;
  double timeS;
  double filter1Sum;
  double filter2Sum;
};

#endif /* TRAJECTORYPOINT_HPP_ */
