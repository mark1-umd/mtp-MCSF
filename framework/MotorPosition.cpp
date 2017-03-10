/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MotorPosition.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 * @date Mar 9, 2017 - Added minus operator
 * *
 * @brief Creates a defined type for a position based on a motor encoder
 *
 * One type of position measurement is through the value of an absolute
 * motor encoder reading.  This class creates a strictly-typed value to
 * be used for such a position.
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
 * @brief Minus (-) operator to allow subtraction between MotorPositions
 * @param [in] MotorPosition mp - the right operand of the subtraction operator
 * @return MotorPosition representing the difference between the two operands
 */
MotorPosition MotorPosition::operator-(const MotorPosition& mp) {
  MotorPosition result;
  result.rotationCount = this->rotationCount - mp.rotationCount;
  return result;
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
