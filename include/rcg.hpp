#pragma once

#include <set>
#include <stack>
#include <tcg.hpp>

class RCG {
  private:
    inline pair<pair<int, int>, int> make_triple(int a, int b, int c) {
        return make_pair(make_pair(a, b), c);
    }
    inline int get_hash(const pair<pair<int, int>, int> p) {
        return p.first.first + v * p.first.second + e * v * p.second;
    }
    inline pair<pair<int, int>, int> get_key(const int& hash) {
        return make_triple((hash % (e * v)) % v, (hash % (e * v)) / v, hash / (e * v));
    }

  public:
    RCG(TCG G);
    bool check_cycle();

    int v, e;
    int m, n;
    map<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>> edges;
};