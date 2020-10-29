#include <rcg.hpp>

class SG {
  private:
    void find_leaders();
    bool check_deadlock();
    void remove_edges();

  public:
    SC(TCG G);
    void run();

    int v, e;
    vector<vector<int>> adj_list;
    vector<int> vertex_state;
    vector<int> edge_cost;
    vector<int> edge_state;
    vector<int> vertex_slack;
    vector<int> start_time();

    RCG G_R;
};