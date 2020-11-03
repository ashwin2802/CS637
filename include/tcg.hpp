#include <intersection.hpp>
#include <traffic.hpp>

class TCG {
  private:
    void create_type_1();
    void model_conflicts();

  public:
    TCG(Traffic T, Intersection I);

    int v, e;
    int m, n;  // store from T and I
    // vertex v_ij is indexed by i+m*j. map stores edge types as an adjacency list
    map<pair<int, int>, vector<pair<pair<int, int>, EdgeType>>> edges;
};