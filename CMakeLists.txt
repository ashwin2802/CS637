cmake_minimum_required(VERSION 2.8.3)
project(CS637)

add_definitions(-std=c++17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

include_directories(include)

add_library(traffic src/traffic.cpp)
add_library(rcg src/rcg.cpp)
add_library(tcg src/tcg.cpp)
add_library(intersection src/intersection.cpp)
add_library(petrinet src/petri_net.cpp)

add_library(scheduler src/scheduler.cpp)
target_link_libraries(scheduler rcg tcg traffic intersection)

add_executable(run_exp src/main.cpp)
target_link_libraries(run_exp scheduler traffic intersection)

add_executable(rcg_test tests/rcg_test.cpp)
target_link_libraries(rcg_test rcg)

add_executable(traffic_test tests/traffic_test.cpp)
target_link_libraries(traffic_test traffic)

add_executable(intersection_test tests/intersection_test.cpp)
target_link_libraries(intersection_test intersection)

add_executable(graph_generation_test tests/graph_generation_test.cpp)
target_link_libraries(graph_generation_test intersection traffic tcg)

add_executable(deadlock_test tests/deadlock_test.cpp)
target_link_libraries(deadlock_test intersection traffic tcg petrinet rcg)

add_executable(top_test tests/top_test.cpp)
target_link_libraries(top_test scheduler)

add_executable(scheduler_test tests/scheduler_test.cpp)
target_link_libraries(scheduler_test scheduler)

add_executable(tcg_test tests/tcg_test.cpp)
target_link_libraries(tcg_test tcg traffic intersection)