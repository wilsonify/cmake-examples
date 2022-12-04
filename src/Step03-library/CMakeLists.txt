cmake_minimum_required(VERSION 2.6)
project(library)

# should we use our own math functions?
option(USE_MYMATH "Use tutorial provided math implementation" ON)

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

# add the MathFunctions library?
if (USE_MYMATH)
 include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
 add_subdirectory (MathFunctions)
 set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)
# add the executable
add_executable (tutorial tutorial.cxx)
target_link_libraries (tutorial ${EXTRA_LIBS})
