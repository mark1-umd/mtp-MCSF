/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file Trajectory.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Mar 6, 2017 - Creation
 * @date Mar 8, 2017 - Updates to attributes to support trajectory generation
 * @date Mar 9, 2017 - added "generate" method using Path input
 *
 * @brief A trajectory is a vector of motion profile trajectory points
 *
 * A motion profile trajectory is executed in order to induce carefully
 * controlled motion.  Each trajectory point represents a time-phased
 * position and velocity to be achieved by a motion mechanism.  A number
 * of algorithmic parameters that are artifacts of the generation
 * process are stored with the trajectory for information and/or
 * debugging purposes.
 *
 */
#include "Trajectory.hpp"

Trajectory::Trajectory()
    : maxVelocity(),
      maxAcceleration(),
      distance(),
      algoItPMS(0),
      algoT1MS(0),
      algoT2MS(0),
      algoT4MS(0),
      algoFL1count(0),
      algoFL2count(0),
      algoNcount(0),
      trajectory() {
}

Trajectory::~Trajectory() {
}

/**
 * @brief Get the maximum velocity for this trajectory
 * @return a MotorVelocity representing this trajectory's maximum velocity
 */
MotorVelocity Trajectory::getMaxVelocity() {
  return maxVelocity;
}

/**
 * @brief Get the maximum acceleration for this trajectory
 * @return a MotorAcceleration representing this trajectory's maximum acceleration
 */
MotorAcceleration Trajectory::getMaxAcceleration() {
  return maxAcceleration;
}

/**
 * @brief Get the distance covered by this trajectory (in MotorPosition units)
 * @return a MotorPosition representing this trajectory's distance covered
 */
MotorPosition Trajectory::getDistance() {
  return distance;
}

/**
 * @brief Get the iteration period for this trajectory in milliseconds
 * @return int iteration period in milliseconds
 */
unsigned int Trajectory::getAlgoItPMS() {
  return algoItPMS;
}

/**
 * @brief Get the algorithmic variable T1 for this trajectory in milliseconds
 * @return int algorithmic variable T1 for this trajectory in milliseconds
 */
unsigned int Trajectory::getAlgoT1MS() {
  return algoT1MS;
}

/**
 * @brief Get the algorithmic variable T2 for this trajectory in milliseconds
 * @return int algorithmic variable T2 for this trajectory in milliseconds
 */
unsigned int Trajectory::getAlgoT2MS() {
  return algoT2MS;
}

/**
 * @brief Get the algorithmic variable T4 for this trajectory in milliseconds
 * @return int algorithmic variable T4 for this trajectory in milliseconds
 */
unsigned int Trajectory::getAlgoT4MS() {
  return algoT4MS;
}

/**
 * @brief Get the algorithmic variable FL1 for this trajectory as a count
 * @return int algorithmic variable FL1 for this trajectory as a count
 */
unsigned int Trajectory::getAlgoFL1count() {
  return algoFL1count;
}

/**
 * @brief Get the algorithmic variable FL2 for this trajectory as a count
 * @return int algorithmic variable FL2 for this trajectory as a count
 */
unsigned int Trajectory::getAlgoFL2count() {
  return algoFL2count;
}

/**
 * @brief Get the algorithmic variable N for this trajectory as a count
 * @return int algorithmic variable N for this trajectory as a count
 */
unsigned int Trajectory::getAlgoNcount() {
  return algoNcount;
}

/**
 * @brief Private function to maintain a limited history of double values
 * @param [in/out] vector<double> history of values
 * @param [in] unsigned int maximum number of values to keep in the history list
 * @param [in] double value to add to the list
 */
void Trajectory::addToHistory(std::vector<double> &history,
                              const unsigned int max,
                              const double value) {
  // do some limited checking and correcting of the length of the list
  // assumes that max is the same for every invocation with the same list

  // So if max is more than 0 and the list is at least max in size
  if (max > 0 && history.size() >= max)
    // take a value off of the beginning of the list
    history.erase(history.begin());
  // add a value to the end of the list
  history.push_back(value);
  // return - the vector of doubles has already been updated in place
  return;
}

/**
 * @brief Generate a trajectory based on a provided 2-point path
 * @param [in] path A motion path consisting of a series of path points
 * @param [in] unsigned int iteration period in milliseconds (time slice for execution of each trajectory point)
 */
// Note that the path parameter cannot be set to a "const reference" without
// causing the path.size, pathGetFirstPathPoint, and pathGetNextPathPoint
// methods to no longer be recognized; fixing this is future work

void Trajectory::generate(Path &path,
                          const unsigned int iterationPeriodMS) {
  // This is the two-point path version of trajectory generation - only
  // paths where the counting of the path points is two, no more, and
  // no less, will result in the creation of an actual motion profile
  // trajectory within this trajectory object

  // Check the size of the path, bail if its not exactly two
  if (path.size() != (unsigned int) 2) {
    std::cout << "Can only generate trajectory for path with two points"
              << std::endl;
    return;
  }

  // *******************************************************************
  // Set up the parameters for the trajectory generation algorithm
  // *******************************************************************
  // The maximum velocity and acceleration information for the trajectory
  // between two points is determined by the settings for the first point
  PathPoint firstPathPoint;
  MotorPosition startPosition, endPosition;
  // Get the first path point
  if (path.getFirstPathPoint(firstPathPoint)) {
    // Set the starting position at the position of the first path point
    startPosition = firstPathPoint.getPosition();
    // Set the max velocity and acceleration for the trajectory
    maxVelocity = firstPathPoint.getMaxVelocity();
    maxAcceleration = firstPathPoint.getMaxAcceleration();
    // Get the next path point
    PathPoint nextPathPoint;
    if (path.getNextPathPoint(nextPathPoint))
      // Set the ending position at the position of the next path point
      endPosition = nextPathPoint.getPosition();
  }
  // The distance to be traveled is the difference between the two positions
  distance = endPosition - startPosition;
  // Algorithm distance is measured in motor rotations
  double algoDistRot = distance.getRotations();
  // Algorithm maximum velocity is in rotations per second
  double algoMaxVelRPS = maxVelocity.getRotationsPerMinute() / 60;
  // Algorithm maximum acceleration is in rotations per second per second
  double algoMaxAccelRPSpS = maxAcceleration.getRotationsPerMinutePerSecond()
      / 60;
  // Algorithm time factor T1 in milliseconds
  // - time to reach max vel at max accel
  algoT1MS = (algoMaxVelRPS / algoMaxAccelRPSpS) * 1000;
  // Algorithm time factor T2 in milliseconds - used to calculate lookback time
  // for the Filter 2 sum (manually adjustable in the Talon SRX model)
  // This implementation currently fixes it at half of T1; may need tuning later
  algoT2MS = algoT1MS / 2;
  // Algorithm Iteration Period in milliseconds
  // - the granularity of the trajectory points
  algoItPMS = iterationPeriodMS;
  // Algorithm time factor T4  in milliseconds
  // - the time to traverse the distance at max velocity
  algoT4MS = (algoDistRot / algoMaxVelRPS) * 1000;
  // Algorithm FL1 count - number of iteration periods in time T1
  algoFL1count = ceil(
      static_cast<double>(algoT1MS) / static_cast<double>(algoItPMS));
  double algoFL1recip = 1 / static_cast<double>(algoFL1count);
  // Algorithm FL2 count - number of iteration periods in time T2
  algoFL2count = ceil(
      static_cast<double>(algoT2MS) / static_cast<double>(algoItPMS));
  // Algorithm N count - number of iteration periods in time T4
  algoNcount = static_cast<double>(algoT4MS) / static_cast<double>(algoItPMS);

  // A vector to hold the history of Filter 1 sum values
  std::vector<double> algoFilter1SumHistory;

  // Ensure the trajectory is clear (in case this is a repeat invocation)
  trajectory.clear();

  // *******************************************************************
  // Generate the first trajectory point with manually-set zeroed values
  // *******************************************************************

  // Set the algorithm's calculated output variables to 0
  double tpPositionRot = 0.0;
  double tpVelocityRPS = 0.0;
  double tpVelocityRPSlastStep = 0.0;
  double tpAccelerationRPSpS = 0.0;
  double tpTimeS = 0.0;

  // Set the step counter, relative time, and Filter sum variables to 0
  unsigned int algoStep = 1;
  double algoFilter1Sum = 0.0;
  double algoFilter2Sum = 0.0;

  // Store this step's Filter1 sum in filter1SumHistory
  // with a limit of FL2 values
  addToHistory(algoFilter1SumHistory, algoFL2count, algoFilter1Sum);

  // Add first trajectory point to the trajectory

  // Get a variable for the trajectory point (we will re-use this in the
  // algorithm loop
  TrajectoryPoint tPoint;

  // Add a MotorPosition object with the current trajectory point rotations
  MotorPosition tpMotorPosition;
  tpMotorPosition.setRotations(tpPositionRot);
  tPoint.setPosition(tpMotorPosition);

  // Add a MotorVelocity object with the current trajectory point velocity
  MotorVelocity tpMotorVelocity;
  tpMotorVelocity.setRotationsPerMinute(tpVelocityRPS * 60);
  tPoint.setVelocity(tpMotorVelocity);

  // Add a MotorAcceleration object with the current
  // trajectory point acceleration
  MotorAcceleration tpMotorAcceleration;
  tpMotorAcceleration.setRotationsPerMinutePerSecond(tpAccelerationRPSpS * 60);
  tPoint.setAcceleration(tpMotorAcceleration);

  // Add in algorithmic details
  tPoint.setDurationMS(algoItPMS);
  tPoint.setStep(algoStep);
  tPoint.setTimeS(tpTimeS);
  tPoint.setFilter1Sum(algoFilter1Sum);
  tPoint.setFilter2Sum(algoFilter2Sum);

  // Stick the completed trajectory point onto the trajectory
  trajectory.push_back(tPoint);

  // *******************************************************************
  // Generate the rest of the trajectory points with algorithmically
  // calculated values
  // *******************************************************************

  // do the algorithm (while Filter1 sum or Filter2 sum is non-zero)
  do {
    // Increment the step that will calculate the next trajectory point
    algoStep++;

    // Increase or decrease Filter1 sum based on step
    // count (compared with N + 2)
    if (algoStep < (algoNcount + 2))
      // Increase filter1Sum, but don't go over 1.0
      algoFilter1Sum = std::min((algoFilter1Sum + algoFL1recip), 1.0);
    else
      // Decrease sumFilter1, but don't go under 0.0
      algoFilter1Sum = std::max((algoFilter1Sum - algoFL1recip), 0.0);

    // Store this step's Filter1 sum in filter1SumHistory
    // with a limit of FL2 values
    addToHistory(algoFilter1SumHistory, algoFL2count, algoFilter1Sum);

    // Calculate Filter2 sum as the sum of filter1Sum history
    algoFilter2Sum = accumulate(algoFilter1SumHistory.begin(),
                                algoFilter1SumHistory.end(), 0.0);

    // Calculate the trajectory point velocity
    tpVelocityRPS = ((algoFilter1Sum + algoFilter2Sum) / (1 + algoFL2count))
        * algoMaxVelRPS;

    // Calculate the trajectory point position in rotations as the
    // average of the velocities from this step and the last, times the
    // iteration period, added to the last position
    tpPositionRot +=
        ((((tpVelocityRPS + tpVelocityRPSlastStep) / 2) * algoItPMS) / 1000.0);

    // Calculate the trajectory point acceleration as the change in
    // velocity from the last step to this one, divided by the iteration
    // period
    tpAccelerationRPSpS = (tpVelocityRPS - tpVelocityRPSlastStep)
        / (algoItPMS / 1000.0);

    // Calculate the time of the trajectory point relative to the start
    // of the first trajectory point
    tpTimeS = ((static_cast<double>(algoStep) - 1.0)
        * static_cast<double>(algoItPMS)) / 1000.0;

    // Add this trajectory point to the trajectory

    // Add a MotorPosition object with the current trajectory point rotations
    tpMotorPosition.setRotations(tpPositionRot);
    tPoint.setPosition(tpMotorPosition);

    // Add a MotorVelocity object with the current trajectory point velocity
    tpMotorVelocity.setRotationsPerMinute(tpVelocityRPS * 60);
    tPoint.setVelocity(tpMotorVelocity);

    // Add a MotorAcceleration object with the current
    // trajectory point acceleration
    tpMotorAcceleration.setRotationsPerMinutePerSecond(
        tpAccelerationRPSpS * 60);
    tPoint.setAcceleration(tpMotorAcceleration);

    // Add the trajectory point duration (ms)
    tPoint.setDurationMS(algoItPMS);

    // Add in algorithmic details to the trajectory point
    tPoint.setStep(algoStep);
    tPoint.setTimeS(tpTimeS);
    tPoint.setFilter1Sum(algoFilter1Sum);
    tPoint.setFilter2Sum(algoFilter2Sum);

    // Stick the completed trajectory point onto the trajectory
    trajectory.push_back(tPoint);

    // Save current velocity for the next loop through the algorithm
    tpVelocityRPSlastStep = tpVelocityRPS;

    // Keep on keeping on until Filter1 sum and Filter2 sum are both zero
  } while (algoFilter1Sum != 0 || algoFilter2Sum != 0);

  // We have generated our trajectory; return to caller
  return;
}

/**
 * @brief Stub Execution of this trajectory's motion profile trajectory points
 */
void Trajectory::execute() {
  std::cout << "Executing motion profile trajectory: (one dot per point)"
            << std::endl;
  for (auto trajectoryPoint : trajectory)
    std::cout << ".";
  std::cout << std::endl;
  std::cout << "End of motion profile trajectory execution." << std::endl;
  return;
}

/**
 * @brief Returns the number of points in the motion profile trajectory
 * @return int motion profile trajectory size
 */
unsigned int Trajectory::size() {
return trajectory.size();
}

/**
 * @brief Show this motion profile trajectory as individual points
 */
void Trajectory::show() {
  std::cout << "Motion Profile trajectory:" << std::endl;
  for (auto trajectoryPoint : trajectory) {
    trajectoryPoint.show();
    std::cout << std::endl;
  }
  std::cout << "End of Motion Profile trajectory." << std::endl;
  return;
}

/**
 * @brief Output this motion profile trajectory as data to a CSV file
 */
void Trajectory::outputCSV(const std::string &trajectoryFileName) {
  // Open the trajectory file for output, wiping any current content
  std::ofstream tFile(trajectoryFileName,
                                 std::ios::out | std::ios::trunc);
  // Identify this file
  tFile << "\"Motion Profile Trajectory generated by MCSF\"" << std::endl;

  // Write out trajectory parameters
  tFile << "maxV(rps)," << maxVelocity.getRotationsPerMinute() / 60
        << std::endl;
  tFile << "maxA(rps/s),"
        << maxAcceleration.getRotationsPerMinutePerSecond() / 60 << std::endl;
  tFile << "dist(r)," << distance.getRotations() << std::endl;
  tFile << "ItP(ms)," << algoItPMS << std::endl;
  tFile << "T1(ms)," << algoT1MS << std::endl;
  tFile << "T2(ms)," << algoT2MS << std::endl;
  tFile << "T4(ms)," << algoT4MS << std::endl;
  tFile << "FL1," << algoFL1count << std::endl;
  tFile << "FL2," << algoFL2count << std::endl;
  tFile << "N," << algoNcount << std::endl;

  // Write out the trajectory points as tabular data
  bool headerNeeded = true;
  for (auto tp : trajectory) {
    if (headerNeeded) {
      tp.outputCSVheader(tFile);
      headerNeeded = false;
    }
    tp.outputCSV(tFile);
  }
  // Close out the trajectory file, and return from whence we were called
  tFile.close();
  return;
}
