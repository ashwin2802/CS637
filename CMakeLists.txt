cmake_minimum_required(VERSION 2.8.3)
project(CS637)

add_definitions(-std=c++17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

include_directories(include)

add_library(traffic src/traffic.cpp)
add_library(rcg src/rcg.cpp)

add_executable(run_exp src/main.cpp)
target_link_libraries(run_exp traffic)

add_executable(rcg_test tests/rcg_test.cpp)
target_link_libraries(rcg_test rcg)