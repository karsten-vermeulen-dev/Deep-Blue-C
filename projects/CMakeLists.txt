cmake_minimum_required(VERSION 3.10)

project(Calculator)
project(Cinema)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator src/Calculator.cpp)
add_executable(Cinema src/Cinema.cpp)
add_executable(Algorithms src/Algorithms.cpp)