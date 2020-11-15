#include <petri_net.hpp>
#include <rcg.hpp> 
TCG examplea() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

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
    v.push_back({{1, 2}, e});
    G.edges.insert({{2, 2}, v});
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

    G.m = 2;

    return G;
}

TCG exampleb() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 3}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 3}, e});
    G.edges.insert({{2, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{1, 3}, e});
    G.edges.insert({{2, 3}, v});
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
    G.vertices.insert({{2, 3}, k});

    G.m = 2;

    return G;
}

TCG examplec() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 3}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{3, 3}, e});
    G.edges.insert({{3, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{3, 2}, e});
    G.edges.insert({{2, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{1, 3}, e});
    G.edges.insert({{3, 3}, v});
    v.clear();

    G.vertices.clear();
    Vertex k;
    k.first_i = true;

    k.first_j = true;
    G.vertices.insert({{1, 1}, k});

    k.first_j = false;
    G.vertices.insert({{1, 3}, k});

    k.first_j = true;
    G.vertices.insert({{2, 1}, k});

    k.first_j = false;
    G.vertices.insert({{2, 2}, k});

    k.first_j = true;
    G.vertices.insert({{3, 2}, k});

    k.first_j = false;
    G.vertices.insert({{3, 3}, k});

    G.m = 3;

    return G;
}

TCG exampled() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

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

    G.m = 2;

    return G;
}

TCG examplee() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 3}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 3}, e});
    G.edges.insert({{2, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 3}, e});
    G.edges.insert({{1, 3}, v});
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
    G.vertices.insert({{2, 3}, k});

    G.m = 2;

    return G;
}

int main() {
    TCG G = exampleb();
    PetriNet P(G);
    P.print();
    P.simulate();

    std::cout << std::endl << "Deadlock check by RCG: ";

    RCG R(G);
    std::cout << R.check_cycle() << std::endl;
    R.print_graph();

    return 0;
}