cmake_minimum_required(VERSION 3.10)

project(csqlang)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.c")

add_executable(csqlang ${SOURCES})