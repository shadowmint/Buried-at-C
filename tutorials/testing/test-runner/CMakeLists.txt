CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(TEST_RUNNER)

# Debug mode?
SET(DEBUG 1)
IF(DEBUG)
  SET(CMAKE_BUILD_TYPE Debug)
  SET(CMAKE_C_FLAGS "-Wall -pedantic -Wimplicit-function-declaration -Wreturn-type -Wextra -g")
ENDIF(DEBUG)

# Code type
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# Includes
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

# test-runner
FILE(GLOB_RECURSE SOURCES src/*.c)
ADD_EXECUTABLE(test-runner ${SOURCES})
