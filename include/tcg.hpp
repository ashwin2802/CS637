#pragma once

#include <intersection.hpp>
#include <traffic.hpp>

typedef struct Vertex {
    int slack;
    int pass_time;
    int start_time;
    VertexState state;
} Vertex;

typedef struct Edge {
    int cost;
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
    void create_type_1();
    void model_conflicts();

  public:
    TCG(){};  // for testing
    TCG(Traffic T, Intersection I);

    int v, e;
    int m, n;  // store from T and I
    std::map<std::pair<int, int>, std::vector<std::pair<std::pair<int, int>, Edge>>> edges;
    std::map<std::pair<int, int>, Vertex> vertices;
};