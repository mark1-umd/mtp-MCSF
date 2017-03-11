/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file TrajectoryPoint.cpp
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
#include "TrajectoryPoint.hpp"

TrajectoryPoint::TrajectoryPoint()
    : position(),
      velocity(),
      acceleration(),
      durationMS(0),
      step(0),
      timeS(0.0),
      filter1Sum(0.0),
      filter2Sum(0.0) {
}

TrajectoryPoint::~TrajectoryPoint() {
  // TODO Auto-generated destructor stub
}

/**
 * @brief Set the position for this trajectory point
 * @param [in] a MotorPosition position setting
 */
void TrajectoryPoint::setPosition(const MotorPosition pos) {
  position = pos;
  return;
}

/**
 * @brief Get the position for this trajectory point
 * @return a MotorPosition representing this trajectory points position
 */
MotorPosition TrajectoryPoint::getPosition() {
  return position;
}

/**
 * @brief Set the velocity for this trajectory point
 * @param [in] a MotorVelocity velocity setting
 */
void TrajectoryPoint::setVelocity(const MotorVelocity vel) {
  velocity = vel;
  return;
}

/**
 * @brief Get the velocity for this trajectory point
 * @return a MotorVelocity representing this trajectory points velocity
 */
MotorVelocity TrajectoryPoint::getVelocity() {
  return velocity;
}

/**
 * @brief Set the acceleration for this trajectory point
 * @param [in] a MotorAcceleration acceleration setting
 */
void TrajectoryPoint::setAcceleration(const MotorAcceleration accel) {
  acceleration = accel;
  return;
}

/**
 * @brief Get the acceleration for this trajectory point
 * @return a MotorAcceleration representing this trajectory points acceleration
 */
MotorAcceleration TrajectoryPoint::getAcceleration() {
  return acceleration;
}

/**
 * @brief Set the duration for this trajectory point in milliseconds
 * @param [in] int duration in milliseconds
 */
void TrajectoryPoint::setDurationMS(const unsigned int duration) {
  durationMS = duration;
  return;
}

/**
 * @brief Get the duration for this trajectory point in milliseconds
 * @return int duration in milliseconds
 */
unsigned int TrajectoryPoint::getDurationMS() {
  return durationMS;
}

/**
 * @brief Set the step count for this trajectory point
 * @param [in] unsigned int step count
 */
void TrajectoryPoint::setStep(const unsigned int stepCount) {
  step = stepCount;
  return;
}

/**
 * @brief Get the step count for this trajectory point
 * @return unsigned int step count
 */
unsigned int TrajectoryPoint::getStep() {
  return step;
}

/**
 * @brief Set the relative time for this trajectory point in seconds
 * @param [in] double relative in seconds
 */
void TrajectoryPoint::setTimeS(const double time) {
  timeS = time;
  return;
}

/**
 * @brief Get the relative time for this trajectory point in seconds
 * @return double relative time in seconds
 */
double TrajectoryPoint::getTimeS() {
  return timeS;
}

/**
 * @brief Set the Filter 1 sum for this trajectory point
 * @param [in] double sum value for the Filter 1 sum
 */
void TrajectoryPoint::setFilter1Sum(const double sum) {
  filter1Sum = sum;
  return;
}

/**
 * @brief Get the Filter 1 sum for this trajectory point
 * @return double sum value for the Filter 1 sum
 */
double TrajectoryPoint::getFilter1Sum() {
  return filter1Sum;
}

/**
 * @brief Set the Filter 2 sum for this trajectory point
 * @param [in] double sum value for the Filter 2 sum
 */
void TrajectoryPoint::setFilter2Sum(const double sum) {
  filter2Sum = sum;
  return;
}

/**
 * @brief Get the Filter 2 sum for this trajectory point
 * @return double sum value for the Filter 2 sum
 */
double TrajectoryPoint::getFilter2Sum() {
  return filter2Sum;
}

/**
 * @brief Show the trajectory point on standard output
 */

void TrajectoryPoint::show() {
  std::cout << "Position: " << position.getRotations()
            << " rotations; " << "Velocity: "
            << velocity.getRotationsPerMinute() << " RPM; "
            << "Duration: " << durationMS << " ms";
  return;
}

/**
 * @brief Output the trajectory point header to a comma-separated value file
 */
void TrajectoryPoint::outputCSVheader(std::ofstream& fileCSV) {
  fileCSV << "Step" "," << "Time(s)" << "," << "Filter1 sum" << ","
          << "Filter2 sum" << "," << "Vel(RPS)" << "," << "Pos(R)" << ","
          << "Accel(RPS/S)" << "," << "Dur(ms)" << std::endl;
}

/**
 * @brief Output the trajectory point to a comma-separated value file
 */
void TrajectoryPoint::outputCSV(std::ofstream& fileCSV) {
  fileCSV << step << "," << timeS << "," << filter1Sum << "," << filter2Sum
          << "," << velocity.getRotationsPerMinute() / 60 << ","
          << position.getRotations() << ","
          << acceleration.getRotationsPerMinutePerSecond() / 60 << ","
          << durationMS
          << std::endl;
}
