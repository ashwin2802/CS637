#include <intersection.hpp>
#include <traffic.hpp>

class TCG {
  private:
    void create_type_1();
    void model_conflicts();

  public:
    TCG(Traffic T, Intersection I);

    vector<int> wait_time;  // based on edge types
    int pass_time;
    int v, e;
    vector<vector<int>> adj_list;

    // store pointer to arrival times?
};