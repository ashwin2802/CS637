cmake_minimum_required(VERSION 2.8.3)
project(CS637)

SET(GCC_COVERAGE_COMPILE_FLAGS "-g")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_definitions(-std=c++17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

include_directories(include)
include_directories($ENV{HOME}/sumo/src/)

add_library(traffic src/traffic.cpp)
add_library(rcg src/rcg.cpp)
add_library(tcg src/tcg.cpp)
add_library(intersection src/intersection.cpp)
add_library(petrinet src/petri_net.cpp)
add_library(traci src/TraCIAPI.cpp)
add_library(socket src/socket.cpp)
add_library(storage src/storage.cpp)

add_library(scheduler src/scheduler.cpp)
target_link_libraries(scheduler rcg tcg traffic intersection)

# add_executable(run_exp src/main.cpp)
# target_link_libraries(run_exp scheduler traffic intersection)

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

# add_executable(main src/main.cpp)
# target_link_libraries(main intersection traffic tcg petrinet rcg)

add_executable(test tests/test.cpp)
target_link_libraries(test intersection traffic tcg petrinet rcg traci socket storage)