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
    void generate_traffic();  // might not need
    void generate_lane_traffic(int);
    // void generate_lane_traffic(std::map<int, int>&, int);

    // LaneType return_enum(int);

    float lambda;  // Poisson distribution parameters
    long int arrival_time_max;

  public:
    Traffic(float, long int);

    // Map (Source Lane, Map (arrival time, Destination Lane))
    // std::map<int, std::map<int, int>> traffic;
    std::map<std::pair<int, int>, int, compare_pair> traffic; // Source Lane, arrival time, destination lane
    int m;                            // number of vehicles
    std::vector<int> lane_nums;       // number of vehicles on each source lane
    std::vector<std::vector<int>> enter_times;  // entering times, source lane wise
    std::vector<std::pair<int, int>> vehicles;  // source lane, arrival time
    static bool compare(std::pair<int, int> e1, std::pair<int, int> e2);
};