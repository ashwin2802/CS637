#pragma once

#include <common.hpp>

class Intersection {
  private:
    void calculate_paths_one();  // compute path map
    void calculate_paths_four();  // compute path map

  public:
    Intersection(int num);
    int n;  // number of conflict zones

    std::map<std::pair<int, int>, std::vector<int>> paths;  // path followed by each vehicle through the intersection
};