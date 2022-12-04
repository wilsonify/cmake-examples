cmake_minimum_required(VERSION 2.6)
project(library)

# should we use our own math functions?
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# The version number.
set(tutorial_VERSION_MAJOR 1)
set(tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
 "${PROJECT_SOURCE_DIR}/tutorialConfig.h.in"
 "${PROJECT_BINARY_DIR}/tutorialConfig.h"
 )

# add the binary tree to the search path for include files so that we will find tutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
 include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
 add_subdirectory(MathFunctions)
 set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# add the executable
add_executable (tutorial tutorial.cxx)
target_link_libraries (tutorial ${EXTRA_LIBS})

# add the install targets
install (TARGETS tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/tutorialConfig.h" DESTINATION include)

# Tests
 enable_testing ()

# does the application run
add_test (tutorialRuns tutorial 25)

# does the usage message work?
add_test (tutorialUsage tutorial)
set_tests_properties (tutorialUsage
PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .+ number")

# does it sqrt of 25
add_test (tutorialComp25 tutorial 25)
set_tests_properties (tutorialComp25
PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")

# does it handle negative numbers
add_test (tutorialNegative tutorial -25)
set_tests_properties (tutorialNegative
PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")

# does it handle small numbers
add_test (tutorialSmall tutorial 0.0001)
set_tests_properties (tutorialSmall
PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")

#define a macro to simplify adding tests, then use it
macro (do_test arg result)
 add_test (tutorialComp${arg} tutorial ${arg})
 set_tests_properties (tutorialComp${arg}
 PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# do a bunch of result based tests
do_test (25 "25 is 5")
do_test (-25 "-25 is 0")
do_test (100 "100 is 10")
do_test (44944 "44944 is 212")

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/license.txt")
set (CPACK_PACKAGE_NAME "tutorial")
set (CPACK_PACKAGE_VERSION_MAJOR "${tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${tutorial_VERSION_MINOR}")
set (CPACK_SOURCE_GENERATOR "TGZ")
include (CPack)

# enable dashboard scripting
include (CTest)
