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
This generates the Timing Conflict Graph of the random traffic. Output is fairly self-explanatory (it prints the vehicles, then the vertices and finally the edges). Run the `graph_generation_test` executable in the bin folder.
Its parameters (which can be changed in lines 36-37 of `tests/graph_generation_test.cpp`) are:
- Traffic parameters (As mentioned in previous section)
- Number of conflict zones in the Intersection I (supports 1, 4, 16 conflict zones). To see the geometry of these intersection, please see the file `include/intersection.hpp`
Alternately, you can also run `tcg_test`. Change its parameters via `tcg_Test.cpp`. `lambda` is self explanatory, d is the earliest arrival time of the last vehicle, n is the number of conflict zones in the intersection, and tc is the number of test cases.

### Petri-net and RCG verifier
This checks for deadlock in the given schedules. Since the scheduler isn't bug free, the examples from the paper itself are given for testing. To run a particular example from the figure 5 of the paper, just change the line 252 in `tests/deadlock_test.cpp` to whichever example you want to run (for example, if you want to run example c, change that line to `TCG G = examplec();`). Then, build and run the `deadlock_test` executable in the bin folder.
The program first outputs the constructed petri-net. If there is a deadlock, it will then print the deadlocked transitions. If there is no deadlock, it will print "No-deadlock". The next part shows the same result with the use of the RCG. If there is a deadlock, Deadlock check by RCG will be 1, otherwise 0. It also prints the constructed RCG graph, along with the number of verticies and edges. Also, the RCG for all 5 examples can be seen at once by running `rcg_test`

### Intersection test
This just shows the conflict zones that a vehicle passes through for passing from one source lane to another. The print statement on line 17 can take arguments 1,4 and 16. The codes are 1 --> NORTH, 2 --> SOUTH, 3 --> EAST, 4 --> WEST.

If there are any issues in running the code, please leave an issue on the issue tracker.
