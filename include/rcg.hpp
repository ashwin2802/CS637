#include <tcg.hpp>

class RCG {
  private:
  public:
    RCG(TCG G);
    bool check_cycle();

    int v, e;
    vector<vector<int>> adj_list;
};