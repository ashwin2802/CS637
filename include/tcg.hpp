#pragma once

#include <intersection.hpp>
#include <traffic.hpp>

typedef struct Vertex {
    double slack;
    double pass_time;
    double start_time;
    bool first_j;  // zone j is the first conflict zone in the path
    bool first_i;  // vehicle i is the first in its source lane
    VertexState state;
} Vertex;

typedef struct Edge {
    double cost;
    double wait_time;
    EdgeType type;
    EdgeState state = EdgeState::ON;  // all edges on by default;

    Edge(){};
    Edge(const EdgeType& t) {
        type = t;
    }
} Edge;

class TCG {
  private:
    void vertices_and_type_1(Traffic& T, Intersection& I);
    void model_conflicts(Traffic& T, int conflict_zones);
    inline void print(const std::pair<int, int>& p) {
        std::cout << "(" << p.first << " " << p.second << ")";
    }

  public:
    TCG(){};  // for testing
    TCG(Traffic T, Intersection I);
    void print_graph();

    int v, e;
    int m, n;  // store from T and I
    std::map<std::pair<int, int>, std::vector<std::pair<std::pair<int, int>, Edge>>> edges;
    std::map<std::pair<int, int>, Vertex> vertices;
};