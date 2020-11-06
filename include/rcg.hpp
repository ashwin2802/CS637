#pragma once

#include <iostream>
#include <set>
#include <stack>
#include <tcg.hpp>

class RCG {
  private:
    inline std::pair<std::pair<int, int>, int> make_triple(int a, int b, int c) {
        return std::make_pair(std::make_pair(a, b), c);
    }
    inline int get_hash(const std::pair<std::pair<int, int>, int> p) {
        return (p.first.first - 1) + v * (p.first.second - 1) + e * v * (p.second - 1);
    }
    inline std::pair<std::pair<int, int>, int> get_key(const int& hash) {
        return make_triple((hash % (e * v)) % v + 1, (hash % (e * v)) / v + 1, hash / (e * v) + 1);
    }
    inline void print(const std::pair<std::pair<int, int>, int> p) {
        std::cout << "(" << p.first.first << " " << p.first.second << " " << p.second << ")";
    }

  public:
    RCG(const TCG& G);
    bool check_cycle();
    void print_graph();

    int v, e;
    int m, n;
    std::map<std::pair<std::pair<int, int>, int>, std::vector<std::pair<std::pair<int, int>, int>>> edges;
};