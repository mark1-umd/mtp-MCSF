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
 * velocity and position.
 *
 */
#include "TrajectoryPoint.hpp"

TrajectoryPoint::TrajectoryPoint()
    : velocity(),
      durationMS(0) {
}

TrajectoryPoint::~TrajectoryPoint() {
  // TODO Auto-generated destructor stub
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

void TrajectoryPoint::show() {
  std::cout << "Position: " << position.getRotations()
            << " rotations; " << "Velocity: "
            << velocity.getRotationsPerMinute() << " RPM; "
            << "Duration: " << durationMS << " ms";
  return;
}
