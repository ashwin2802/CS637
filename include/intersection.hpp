#include <common.hpp>

class Intersection {
  private:
    void calculate_paths();  // compute path map

  public:
    Intersection(int num);
    int n;  // number of conflict zones

    unordered_map<pair<int, int>, vector<int>> paths;  // path followed by each vehicle through the intersection
};