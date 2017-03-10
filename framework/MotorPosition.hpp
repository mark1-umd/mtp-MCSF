/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file MotorPosition.hpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 5, 2017 - Creation
 * @date Mar 9, 2017 - Added minus operator
 *
 * @brief Creates a defined type for a position based on a motor encoder
 *
 * One type of position measurement is through the value of an absolute
 * motor encoder reading.  This class creates a strictly-typed value to
 * be used for such a position.
 *
 */
#ifndef MOTORPOSITION_HPP_
#define MOTORPOSITION_HPP_

/** @brief Creates a defined type for a position based on a motor encoder
 */

class MotorPosition {
 public:
  MotorPosition();
  virtual ~MotorPosition();
  void setRotations(const double count);
  double getRotations();
  MotorPosition operator-(const MotorPosition& mp);

 private:
  double rotationCount;
};

#endif /* MOTORPOSITION_HPP_ */
