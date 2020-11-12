#include <petri_net.hpp>

int main() {
    Traffic T(0.1, 15);
    Intersection I(1);

    TCG G(T, I);
    G.edges.clear();

    std::vector<std::pair<std::pair<int, int>, Edge>> v1, v2, v3, v4;
    Edge e1, e2, e3, e4;

    e1.type = EdgeType::TYPE_1;
    v1.push_back({{1, 2}, e1});
    e2.type = EdgeType::TYPE_3;
    v1.push_back({{2, 1}, e2});
    G.edges.insert({{1, 1}, v1});
    // v.clear();

    e3.type = EdgeType::TYPE_1;
    v2.push_back({{2, 2}, e3});
    G.edges.insert({{2, 1}, v2});
    // v.clear();

    e4.type = EdgeType::TYPE_3;
    v3.push_back({{1, 2}, e4});
    G.edges.insert({{2, 2}, v3});
    // v.clear();

    PetriNet P(G);

    for (auto trans : P.transitions) {
        std::cout << "LEFT:" << std::endl;
        for (auto left : trans.first) {
            std::cout << left.first.first << ", " << left.first.second << ", " << left.second.first << std::endl;
        }

        std::cout << "RIGHT:" << std::endl;
        for (auto right : trans.second) {
            std::cout << right.first.first << ", " << right.first.second << ", " << right.second.first << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}