/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file main.cpp
 *
 * @brief Test application for the Google Test Framework
 *
 * This is the Google Test-based test application
 *
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
