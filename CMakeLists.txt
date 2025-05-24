cmake_minimum_required(VERSION 3.10)

project(csqc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c)

add_executable(csqc ${SOURCES})

set_target_properties(csqc PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)