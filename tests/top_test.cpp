#include <scheduler.hpp>

void build(TCG& G, const int& i) {
    G.v = 0;
    G.e = 0;
    G.edges.clear();
    switch (i) {
        case 0:
            G.v = 4;
            G.e = 4;
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(1, 2), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(2, 1), Edge(EdgeType::TYPE_3)));
            G.edges[std::make_pair(2, 1)].push_back(std::make_pair(std::make_pair(2, 2), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(2, 2)].push_back(std::make_pair(std::make_pair(1, 2), Edge(EdgeType::TYPE_3)));
            break;
        case 1:
            G.v = 5;
            G.e = 5;
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(1, 3), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(2, 1), Edge(EdgeType::TYPE_3)));
            G.edges[std::make_pair(2, 1)].push_back(std::make_pair(std::make_pair(2, 2), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(2, 2)].push_back(std::make_pair(std::make_pair(2, 3), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(2, 3)].push_back(std::make_pair(std::make_pair(1, 3), Edge(EdgeType::TYPE_3)));
            break;
        case 2:
            G.v = 6;
            G.e = 6;
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(1, 3), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(2, 1), Edge(EdgeType::TYPE_3)));
            G.edges[std::make_pair(2, 1)].push_back(std::make_pair(std::make_pair(2, 2), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(2, 2)].push_back(std::make_pair(std::make_pair(3, 2), Edge(EdgeType::TYPE_3)));
            G.edges[std::make_pair(3, 2)].push_back(std::make_pair(std::make_pair(3, 3), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(3, 3)].push_back(std::make_pair(std::make_pair(1, 3), Edge(EdgeType::TYPE_3)));
            break;
        case 3:
            G.v = 4;
            G.e = 4;
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(1, 2), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(2, 1), Edge(EdgeType::TYPE_3)));
            G.edges[std::make_pair(2, 1)].push_back(std::make_pair(std::make_pair(2, 2), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(1, 2)].push_back(std::make_pair(std::make_pair(2, 1), Edge(EdgeType::TYPE_3)));
            break;
        case 4:
            G.v = 5;
            G.e = 5;
            G.edges[std::make_pair(1, 1)].push_back(std::make_pair(std::make_pair(1, 3), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(2, 1)].push_back(std::make_pair(std::make_pair(1, 1), Edge(EdgeType::TYPE_3)));
            G.edges[std::make_pair(2, 1)].push_back(std::make_pair(std::make_pair(2, 2), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(2, 2)].push_back(std::make_pair(std::make_pair(2, 3), Edge(EdgeType::TYPE_1)));
            G.edges[std::make_pair(1, 3)].push_back(std::make_pair(std::make_pair(2, 3), Edge(EdgeType::TYPE_3)));
            break;
        default:
            std::cerr << "Only 5 testcases supported.\n";
    }
}

int main(int argc, char** argv) {
    TCG G;
    struct Config c = {.lambda = 0.2, .d = 6, .n = 4};

    Scheduler sched(c);

    int tc = 5;
    for (int i = 0; i < tc; i++) {
        std::cout << "Testcase #" << i + 1 << "\n";
        build(G, i);
        sched.init(G);
        sched.print_schedule();
        auto tv = sched.top_sort();
        for (auto x : tv) {
            std::cout << "(" << x.first << ", " << x.second << ") ";
        }
        std::cout << "\n";
    }

    return 0;
}