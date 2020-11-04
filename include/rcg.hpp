#pragma once

#include <tcg.hpp>

class RCG {
  private:
    inline pair<pair<int, int>, int> make_triple(int a, int b, int c) {
        return make_pair(make_pair(a, b), c);
    }

  public:
    RCG(TCG G);
    bool check_cycle();

    int v, e;
    int m, n;
    map<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>> edges;
};