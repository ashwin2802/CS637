# CS637
Course Project repository.

## Build Instructions

Requires a working version of CMake. (Min version: 2.8.3)

To compile, run the following commands on a terminal, in the repository directory:

```
rm -rf build
mkdir build && cd build
cmake ..
make
```

Executables are stored in the `bin` directory post build.

## Testing the code

Currently, the code can successfully generate random traffic, the timing conflict graph, petri-net verifier and resource conflict graph verifier. It also has models for intersections having 1, 4, 16 conflict zones.

### Random Traffic Generator
To generate and test random traffic run the `traffic_test` executable in the bin folder. Each time you run it, you will get a different traffic distribution. The output is of the form <SOURCE_LANE> <ARRIVAL_TIME> <DESTINATION_LANE>.
To change the frequency of traffic and the last arrival times, just change the parameters in line 24 of `tests/traffic_test.cpp`, rebuild and rerun.
- The first parameter is the parameter lamda of the poisson distribution of the traffic. The reciprocal of lamda represents the average time in between different vehicles, so increasing it will lead to denser traffic.
- The second parameter is the earliest arrival time of the last vehicle. Increasing this number means that more and more vehicles are in the range of the intersection manager, and hence more vehicles will be spawned on each lane.


### Graph Generation Test
This generates the Timing Conflict Graph of the random traffic. Output is fairly self-explanatory (it prints the vehicles, then the vertices and finally the edges).
Its parameters (which can be changed in lines 36-37 of `tests/graph_generation_test.cpp`) are:
- Traffic parameters (As mentioned in previous section)
- Number of conflict zones in the Intersection I (supports 1, 4, 16 conflict zones).
