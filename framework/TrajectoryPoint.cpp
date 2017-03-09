/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file TrajectoryPoint.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A motion profile trajectory point - position, velocity, duration
 *
 * A motion profile consists of a set of trajectory points, each one of
 * which specifies a position and velocity to be achieved during the
 * execution of the point, and a duration in which to achieve the
 * velocity and position.  In addition to these basic attributes, an
 * acceleration value indicating the current acceleration, and a time
 * value representing the relative time since the first trajectory point
 * in a series of trajectory points forming a motion profile trajectory,
 * are stored.
 *
 */
#include "TrajectoryPoint.hpp"

TrajectoryPoint::TrajectoryPoint()
    : position(),
      velocity(),
      acceleration(),
      durationMS(0),
      timeS(0.0) {
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
void TrajectoryPoint::setDurationMS(const int duration) {
  durationMS = duration;
  return;
}

/**
 * @brief Get the duration for this trajectory point in milliseconds
 * @return int duration in milliseconds
 */
int TrajectoryPoint::getDurationMS() {
  return durationMS;
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
 * @brief Output the trajectory point to a comma-separated value file
 * @return double relative time in seconds
 */

void TrajectoryPoint::outputCSV(std::ofstream& fileCSV) {
  fileCSV << timeS << "," << position.getRotations() << ","
      << velocity.getRotationsPerMinute() / 60 << ","
          << acceleration.getRotationsPerMinutePerSecond() / 60 << ","
          << durationMS
      << std::endl;

}
