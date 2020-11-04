#pragma once

#include <tcg.hpp>

class RCG {
  private:
  public:
    RCG(TCG G);
    bool check_cycle();

    int v, e;
    int m, n;
    // vertex u_ijk is indexed by i+m*j+n*m*k
    map<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>> edges;
};