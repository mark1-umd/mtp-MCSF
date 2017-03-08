set(GTEST_SHUFFLE 1)

add_executable(
    MCSFtest
    main.cpp
    MCSFtest.cpp
    ../framework/MotorAcceleration.cpp
    ../framework/MotorPosition.cpp
    ../framework/MotorVelocity.cpp
    ../framework/Path.cpp
    ../framework/PathPoint.cpp
    ../framework/Point.cpp
    ../framework/Route.cpp
    ../framework/Trajectory.cpp
    ../framework/TrajectoryPoint.cpp
    ../framework/WayPoint.cpp
)
include_directories(
    ${CMAKE_SOURCE_DIR}/framework)
target_include_directories(MCSFtest PUBLIC ../vendor/googletest/googletest/include)
target_link_libraries(MCSFtest PUBLIC gtest)
