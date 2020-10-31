cmake_minimum_required(VERSION 2.8.3)
project(CS637)

add_definitions(-std=c++17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(run_exp src/main.cpp)
