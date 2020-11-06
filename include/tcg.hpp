#pragma once

#include <intersection.hpp>
#include <traffic.hpp>

class TCG {
  private:
    void create_type_1();
    void model_conflicts();

  public:
    TCG(){};  // for testing
    TCG(Traffic T, Intersection I);

    int v, e;
    int m, n;  // store from T and I
    std::map<std::pair<int, int>, std::vector<std::pair<std::pair<int, int>, EdgeType>>> edges;
};