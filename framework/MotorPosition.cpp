/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MotorPosition.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 *
 * @brief <brief description>
 *
 * <details>
 *
 */
#include "MotorPosition.hpp"

MotorPosition::MotorPosition()
    : rotationCount(0.0) {
}

MotorPosition::~MotorPosition() {
  // TODO Auto-generated destructor stub
}

/**
 * @brief Set the motor position using a floating point (double) rotation count
 * @param [in] a count value in a double
 */
void MotorPosition::setRotations(const double count) {
  rotationCount = count;
  return;
}

/**
 * @brief Return the motor position as a floating point (double) rotation count
 * @return the current position as a motor encoder rotation count
 */
double MotorPosition::getRotations() {
  return rotationCount;
}
