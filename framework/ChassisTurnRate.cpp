/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file ChassisTurnRate.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 13, 2017 - Creation
 *
 * @brief ChassisTurnRate is a strictly defined type for specifying the turn rate of a moving chassis
 *
 * Chassis turn rates may be specified in a variety of ways; the one implemented here is as a
 * degree of turn per foot of movement.  This class creates a strict type for chassis turn rates,
 * and can provide a variety of accessor functiont so allow setting/getting the turn rate in
 * different units.  The class stores the turn rate internaly as "Degrees per Foot of movement".
 * Note that a zero turn rate indicates movement straight ahead, a negative turn rate indicates a
 * deviation (turn) to the left, and a positive turn rate indicates a deviation (turn) to the right.
 *
 */
#include "ChassisTurnRate.hpp"

ChassisTurnRate::ChassisTurnRate()
    : degreesPerFoot(0.0) {
}

ChassisTurnRate::~ChassisTurnRate() {
}

/**
 * @brief Set the turn rate in degrees per foot of movement (0 no turn, < 0 left turn, > 0 right turn)
 * @param [in] double degrees - the change in heading in degrees per foot of movement
 */
void ChassisTurnRate::setDegreesPerFoot(double degrees) {
  degreesPerFoot = degrees;
  return;
}

/**
 * @brief Return the turn rate in degrees per foot of movement (0 no turn, < 0 left turn, > 0 right turn)
 * @return double degrees per foot of movement
 */
double ChassisTurnRate::getDegreesPerFoot() {
  return degreesPerFoot;
}
