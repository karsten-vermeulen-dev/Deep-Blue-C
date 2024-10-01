cmake_minimum_required(VERSION 3.10)

project(DeepBlueC)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lesson_1 Lesson_1/Lesson_1.cpp)

add_executable(Calculator Projects/src/Calculator.cpp)
add_executable(Cinema Projects/src/Cinema.cpp)
add_executable(Algorithms Projects/src/Algorithms.cpp)

add_executable(Calendar 
Projects/Calendar/Date.h
Projects/Calendar/Date.cpp
Projects/Calendar/Main.cpp)
