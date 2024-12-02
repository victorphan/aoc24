cmake_minimum_required(VERSION 3.31)
project(template)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(day1 day1/day1.cpp)
add_executable(day2 day2/day2.cpp)
add_executable(day3 day3/day3.cpp)
