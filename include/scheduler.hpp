#pragma once

#include <rcg.hpp>

class SG {
  private:
    void find_leaders();
    bool check_deadlock();
    void remove_edges();

  public:
    SG(TCG G);
    void run();

    int v, e;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> vertex_state;
    std::vector<int> edge_cost;
    std::vector<int> edge_state;
    std::vector<int> vertex_slack;
    std::vector<int> start_time();

    RCG G_R;
};