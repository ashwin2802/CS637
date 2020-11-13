#include <petri_net.hpp>

int main() {
    Traffic T(0.1, 15);
    Intersection I(1);

    TCG G(T, I);
    G.edges.clear();

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    // e.type = EdgeType::TYPE_1;
    // v.push_back({{1, 2}, e});
    // e.type = EdgeType::TYPE_3;
    // v.push_back({{2, 1}, e});
    // G.edges.insert({{1, 1}, v});
    // v.clear();

    // e.type = EdgeType::TYPE_1;
    // v.push_back({{2, 2}, e});
    // G.edges.insert({{2, 1}, v});
    // v.clear();

    // e.type = EdgeType::TYPE_3;
    // v.push_back({{1, 2}, e});
    // G.edges.insert({{2, 2}, v});
    // v.clear();

    // G.vertices.clear();
    // Vertex k;
    // k.first_i = true;

    // k.first_j = true;
    // G.vertices.insert({{1, 1}, k});

    // k.first_j = false;
    // G.vertices.insert({{1, 2}, k});

    // k.first_j = true;
    // G.vertices.insert({{2, 1}, k});

    // k.first_j = false;
    // G.vertices.insert({{2, 2}, k});

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 2}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 2}, e});
    G.edges.insert({{1, 2}, v});
    v.clear();

    G.vertices.clear();
    Vertex k;
    k.first_i = true;

    k.first_j = true;
    G.vertices.insert({{1, 1}, k});

    k.first_j = false;
    G.vertices.insert({{1, 2}, k});

    k.first_j = true;
    G.vertices.insert({{2, 1}, k});

    k.first_j = false;
    G.vertices.insert({{2, 2}, k});

    G.v = 2;

    PetriNet P(G);
    P.print();
    P.simulate();

    return 0;
}