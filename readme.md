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

- The second phase will enhance the trajectory generator to handle
1-dimensional paths with 3+ points

- The third phase will enhance the trajectory generator to handle
2-dimensional paths

## Focus of work

The focus of this project is to perform this work using the software
engineering techniques being taught in a course entitled "Advanced Software Engineering for Robotics," so the results should not necessarily be relied upon as an "out-of-the-box" solution for motion control.  I am attempting to perform as much of the work as possible using my own original analysis, drawing on the reference material primarily to familiarize myself with the problem domain.  A secondary use of the reference material is to advance my understanding of how others have solved similar problems as I come to portions that I do not see a straightforward approach to solving.

## Technology

- Ubuntu Linux 14.04 as a VirtualBox guest O/S on a macOS 10.12 host O/S as the development platform
- git version control system with GitHub as a centralized repo host
- C++ language using the gcc compiler with C++11/14 syntax and extensions
- cmake build system
- googletest testing
- Travis Continual Integration
- Coveralls coverage monitoring (in development)

## Status

2017-03-04 Initial development work underway; no useful code at present

## Installation

- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/mark1-umd/mtp-MCSF.git
```

