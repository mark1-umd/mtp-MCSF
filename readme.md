# ENPM808X MidTerm Project - Motion Control System Framework
[![Build Status](https://travis-ci.org/mark1-umd/mtp-MCSF.svg?branch=master)](https://travis-ci.org/mark1-umd/mtp-MCSF)
[![Coverage Status](https://coveralls.io/repos/github/mark1-umd/mtp-MCSF/badge.svg?branch=master)](https://coveralls.io/github/mark1-umd/mtp-MCSF?branch=master)
---

## Overview

C++ classes for a robotic motion control system framework:

- Path planner (stub now; future work to flesh out)
- Trajectory generation (focus of current development)
- Trajectory execution (stub now; future work to tie to hardware)

This work is inspired by work presented by FIRST mentors from Google
Robotics at the 2015 FIRST World Championships Conference in a session
entitled “Motion Planning and Control in FRC” available at
https://www.youtube.com/watch?v=8319J1BEHwM. I have used additional
background on motion profiling from Cross The Road (CTR) Electronics,
the makers of the Talon motor controller for FIRST Robotics Competition
(FRC) (documentation found here
https://www.ctr-electronics.com/talon-srx.html#product_tabs_technical_resources),
including the Talon SRX Motion Profile Reference Manual, and an Excel
model created by CTR Electronics to generator motion profiles compatible
with the Talon SRX motor controllers built-in motion profile execution
capability.

The motivation for this work is that smooth and well-controlled
operation of a robot’s drive system leads to highly repeatable
positioning and orientation of the robotics system in its operational
environment.  The use of motion profiling in the drive system maximizes
performance while still providing smooth, reliable, and predictable
movement and positioning of the robot chassis.

In order to demonstrate the effectiveness of my development capabilities,
I will deliver a Motion Control Subsystem Framework designed to accept a
“Route” containing a series of two or more Waypoints, and carry out the
motor control of the drive system necessary to travel that route after
performing path planning and generating a Trajectory based on the Path.
Only certain portions of the Motion Control Subsystem will be coded
completely in my initial delivery.

My initial development effort focuses on taking a planned path (to be
created by a path planning component to be developed later), and building
a trajectory based on motion profiling using trapezoidal motion profiles;
the trajectory will then be available to a motion execution routine (to
be developed later) that will control the physical drive system based on
the trajectory.  I am particularly interested in understanding how the
time-based sequencing of trajectory points interacts with a more simple
motor controller than the Talon SRX, especially at time granularities
more coarse than the capabilities offered by the Talon SRX, as I hope
to be able to use this work to coach student team members interested
in enhancing FIRST Technology Competition robot performance during the
autonomous period of competition match play.

My development is being conducted in phases:

- The first phase is to create a trajectory generator capable of taking a two-point, 1 dimensional path and creating a series of trajectory points that describe a trapezoidal motion profile consistent with specified
constraints (maximum velocity, maximum acceleration)
    - This phase is complete
- The second phase will use the trajectory generator to handle creating dual
trajectories for a "tank drive" system that turns through differential motor speeds
    - This phase is complete as of the end of the current design iteration
- The third phase will consider how to enhance the system to handle paths with
multiple segments (i.e., how to best merge motion profiles to avoid stopping/
restarting the robot at each change in direction and/or speed)
    - This is future work to be done


## Focus of work

The focus of this project is to perform this work using the software
engineering techniques being taught in a course entitled "Advanced Software Engineering for Robotics," so the results should not necessarily be relied upon as an "out-of-the-box" solution for motion control.  I am attempting to perform as much of the work as possible using my own original analysis, drawing on the reference material primarily to familiarize myself with the problem domain.  A secondary use of the reference material is to advance my understanding of how others have solved similar problems as I come to portions that I do not see a straightforward approach to solving.

## Current Results

As of 2017-03-14, the Motion Control System Framework consists of a series of classes that together enable two motion profile trajectory generation functions:

- The first, and simplest motion profile trajectory generation creates a motion profle trajectory from a 1-dimensional, 2 point path.  Each path point represents a position (specified in motor rotations) with an associated velocity and acceleration.  The generation function uses the velocity and acceleration from the first point, then generates a series of motion profile trajectory points to accelerate up to the velocity, cruise for as long as possible, then decelerate to arrive exactly at the target position.  Since this project is based on reference documentation from Cross The Road Electronics for their Talon SRX motor controller, the output is directly compatible with this motor controller.

- The second, and somewhat more interesting motion profile trajectory generation creates a 2 motion profile trajectories from a single move command.  The TankDrive class represents a robot mover with 2 sides, and it uses the simple 1D2P motion profile trajectory generator to create the two motion profile trajectories, intended for simultaneous use in driving the two sides of the robot.

## License
BSD 3-Clause License

Copyright (c) 2017, Mark Jenkins
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


## Technology

- Ubuntu Linux 14.04 as a VirtualBox guest O/S on a macOS 10.12 host O/S as the development platform
- git version control system with GitHub as a centralized repo host
- C++ language using the gcc compiler with C++11/14 syntax and extensions
- cmake build system
- googletest testing
- Travis Continual Integration
- Coveralls coverage monitoring (in development)

## Dependencies
The only dependencies are the technology elements listed under Technology, and not all of these are strictly required.  The Motion Control System Framework itself does not use any other libraries.

## Status
- See combined Work Log, Backlog, and Iteration planning at https://docs.google.com/spreadsheets/d/18VykVzmk6bcDeYrOBpadNUtSEcqD-ngulnOqJV_z5iA/edit?usp=sharing (Limited access, not public)

### Initial Development
- 2017-03-04 Initial MCSF development work underway; no useful code at present
- 2017-03-07 First set of three tests for basic accessor functions working
- 2017-03-08 Initial MCSF development complete, all basic tests working
    - See the design documents in the /UML/initial development folder
    
### Evolution 1 - Iteration20170308
- 2017-03-11 Evolution of the MCSF 1-dimensional 2-path trajectory generation complete
    - See the design documents in the /UML/iteration20170308 folder (Astah Community package and .png output)
    - See the results in the /Results folder (a 10ms iteration period motion profile that matches exactly with the Talon Motion Profile Excel model for possible use on an FRC robot with Talon SRX motor controllers, and a 25 ms iteration period motion profile showing the same profile at a coarser granularity, such as might be expected from an FTC Android-based robot with its 25 ms hardware update loop and no direct access to the motor controllers)
    
### Evolution 2 - Iteration20170312
- 2017-03-14 Evolution of the MCSF 2-dimensional 2-path trajectory generation complete
    - See the design documents in the /UML/Iteration20170312 folder (Astah Community package and .png output)
    - See the results in the /Results folder (two trajectory files, left side and right side, generated as the result of a single move command to the robot chassis) (PDF file containing Excel graph results showing simultaneous path relationship)
    - The file app/main-evo1 builds to the executable mcsf-demo-evo1 which demonstrates the first iteration's 1D2P trajectories
    - The file app/main-evo2 builds to the executable mcsf-demo-evo2 which demonstrates the second iteration's 2D2P trajectory generation
    - Further work needs to be done to refine the structure of the MCSF in order to make it as easy as possible to use, but for now follow the examples in the demo applications to see how to use the MCSF
    

## Review and usage of the MCSF

- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/mark1-umd/mtp-MCSF.git
```
- Examine the code, particularly the app/main-evo1.cpp and app/main-evo2.cpp that demonstrate how to use the Motion Control System Framework to generate trajectories
- Use/Extend the MCSF for your individual system

### Build
From the main directory, create a build subdirectory.  Change the working directory to the build subdirectory, type "cmake ..", then "make" to build the project.

### Demo
From the build subdirectory, type "./app/mcsf-demo-evo1" and "./app/mcsf-demo-evo2" to run the two demonstration programs.

### Testing
Execute the tests from the build directory with the command "./tests/MCSFtests".

### Documentation
From the main directory, use the "doxygen" command to generate documentation.  It will be placed in the docs subdirectory.
