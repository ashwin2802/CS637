#pragma once

#include <common.hpp>

// maybe implement a vehicle class instead?

struct compare_pair {
    bool operator()(const std::pair<int, int>& e1, const std::pair<int, int>& e2) const {
        return std::tie(e1.second, e1.first) < std::tie(e2.second, e2.first);
    }
};

class Traffic {
  private:
    void generate_lane_traffic(int);

    float lambda;  // Poisson distribution parameters
    long int arrival_time_max;

  public:
    Traffic(float, long int);

    std::map<std::pair<int, int>, int, compare_pair> traffic;  // Map(Pair(Source Lane, Arrival Time), Destination lane)
    int m;                                                     // number of vehicles
    std::vector<int> lane_nums;                                // number of vehicles on each source lane
    std::vector<std::vector<int>> enter_times;                 // entering times, source lane wise
};