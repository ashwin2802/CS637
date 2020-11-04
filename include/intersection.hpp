#pragma once

#include <common.hpp>

class Intersection {
  private:
    void calculate_paths();  // compute path map

  public:
    Intersection(int num);
    int n;  // number of conflict zones

    unordered_map<pair<LaneType, LaneType>, vector<int>> paths;  // path followed by each vehicle through the intersection
};