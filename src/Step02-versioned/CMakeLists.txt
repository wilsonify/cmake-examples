
cmake_minimum_required(VERSION 2.6)
project(versioned)

# The version number.
set (tutorial_VERSION_MAJOR 1)
set (tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
 "${PROJECT_SOURCE_DIR}/tutorialConfig.h.in"
 "${PROJECT_BINARY_DIR}/tutorialConfig.h"
 )

# add the binary tree to the search path for include files so that we will find tutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
add_executable(tutorial tutorial.cxx)
