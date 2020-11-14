#pragma once

#include <common.hpp>

class Intersection {
  private:

    /*
        1
    */
    void calculate_paths_one();  // compute path map

    /*
        4   3
        1   2
    */
    void calculate_paths_four();  // compute path map

    /*
            15      14
        16  7   6   5   13
            8       4   
        9   1   2   3   12
            10      11
    */
    void calculate_paths_sixteen();  // compute path map


  public:
    Intersection(int num);
    int n;  // number of conflict zones

    std::map<std::pair<int, int>, std::vector<int>> paths;  // path followed by each vehicle through the intersection
};