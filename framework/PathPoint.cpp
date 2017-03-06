/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file PathPoint.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief A representation of a point along a path with maximum velocity
 * and maximum acceleration constraints
 *
 * A path to be used for motion profiling trajectories needs to include
 * velocity and acceleration constraints to be used in constructing
 * a motion profile that shapes the motion based on the maximum
 * velocities and accelerations to be used in achieving motion.
 *
 */
#include "PathPoint.hpp"

PathPoint::PathPoint() {
  // TODO Auto-generated constructor stub

}

PathPoint::~PathPoint() {
  // TODO Auto-generated destructor stub
}

/**
 * @brief Set the maximum allowable velocity for this path point
 * @param [in] a MotorVelocity maximum velocity
 */
void PathPoint::setMaxVelocity(const MotorVelocity maxV) {
  PathPoint::maxVelocity = maxV;
  return;
}

/**
 * @brief Get the maximum allowable velocity for this path point
 * @return a MotorVelocity value representing the maximum allowable velocity
 */
MotorVelocity PathPoint::getMaxVelocity() {
  return PathPoint::maxVelocity;
}

/**
 * @brief Set the maximum allowable acceleration for this path point
 * @param [in] a MotorAcceleration maximum allowable acceleration
 */
void PathPoint::setMaxAcceleration(const MotorAcceleration maxA) {
  PathPoint::maxAcceleration = maxA;
  return;
}

/**
 * @brief Get the maximum allowable acceleration for this path point
 * @return a MotorAcceleration value representing the maximum allowable acceleration
 */
MotorAcceleration PathPoint::getMaxAcceleration() {
  return PathPoint::maxAcceleration;
}

/**
 * @brief Show the details of the current path point
 */
void PathPoint::show() {
  std::cout << "Position: " << PathPoint::position.getRotations()
            << " rotations; " << "Max Vel: "
            << PathPoint::maxVelocity.getRotationsPerMinute() << " RPM; "
            << "Max Accel: "
            << PathPoint::maxAcceleration.getRotationsPerMinutePerSecond
            << " RPM/s ";
  return;
}
