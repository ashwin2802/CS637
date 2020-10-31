#include <common.hpp>

// maybe implement a vehicle class instead?

class Traffic {
  private:
    void generate_traffic();  // might not need
                              // Poisson distribution parameters

  public:
    Traffic(int params);

    int m;                            // number of vehicles
    vector<int> lane_nums;            // number of vehicles on each source lane
    vector<vector<int>> enter_times;  // entering times, source lane wise
};