
cmake_minimum_required(VERSION 3.10)

project(csquared)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.c")

add_executable(csquared ${SOURCES})