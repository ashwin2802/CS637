#pragma once

#include <common.hpp>

// maybe implement a vehicle class instead?

class Traffic {
  private:
    void generate_traffic();  // might not need
    void generate_lane_traffic(std::map<int, LaneType>&, LaneType);

    LaneType return_enum(int);

    float lamda;  // Poisson distribution parameters
    long int arrival_time_max;

  public:
    Traffic(float, long int);

    std::map<LaneType, std::map<int, LaneType>> traffic;
    int m;                            // number of vehicles
    std::vector<int> lane_nums;       // number of vehicles on each source lane
    std::vector<std::vector<int>> enter_times;  // entering times, source lane wise
};