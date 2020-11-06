#include <rcg.hpp>

RCG::RCG(const TCG& G) {
    v = 0;
    e = 0;
    m = G.m;
    n = G.n;
    edges.clear();

    // std::cout << "G: " << G.v << " " << G.e << "\n";

    // for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
    //     std::cout << it->first.first << " " << it->first.second;
    //     for (auto& e : it->second) {
    //         std::cout << " -> ";
    //         std::cout << e.first.first << " " << e.first.second << " " << (int) e.second;
    //     }
    //     std::cout << "\n";
    // }

    // create RCG vertices - Rule 1
    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        auto [i1, j1] = it->first;
        for (auto& e : it->second) {
            auto [i2, j2] = e.first;
            if (i1 == i2 && e.second == EdgeType::TYPE_1) {
                v++;
                edges.insert(std::make_pair(make_triple(i1, j1, j2), std::vector<std::pair<std::pair<int, int>, int>>()));
            }
        }
    }

    // Rule 2-6
    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        auto [i1, j1] = it->first;
        for (auto& e1 : it->second) {
            auto [i2, j2] = e1.first;
            // Rule 2
            if (i1 == i2 && j1 != j2 && G.edges.find(std::make_pair(i2, j2)) != G.edges.end()) {
                for (auto& e2 : G.edges.at(std::make_pair(i2, j2))) {
                    auto [i3, j3] = e2.first;
                    if (i2 == i3 && j2 != j3) {
                        e++;
                        edges[make_triple(i1, j1, j2)].push_back(make_triple(i1, j2, j3));
                    }
                }
            }

            if (i1 != i2 && j1 == j2) {
                for (auto& e2 : G.edges.at(std::make_pair(i1, j1))) {
                    auto [i3, j3] = e2.first;
                    if (i1 == i3 && j1 != j3) {
                        // Rule 3
                        if (G.edges.find(std::make_pair(i2, j2)) != G.edges.end()) {
                            for (auto& e3 : G.edges.at(std::make_pair(i2, j2))) {
                                auto [i4, j4] = e3.first;
                                if (i2 == i4 && j2 != j4) {
                                    e++;
                                    edges[make_triple(i1, j1, j3)].push_back(make_triple(i2, j2, j4));
                                }
                            }
                        }

                        // Rule 5
                        for (auto it2 = G.edges.begin(); it2 != G.edges.end(); it2++) {
                            auto [i4, j4] = it2->first;
                            if (i2 == i4 && j2 != j4) {
                                for (auto& e3 : it2->second) {
                                    auto [i5, j5] = e3.first;
                                    if (i2 == i5 && j2 == j5) {
                                        e++;
                                        edges[make_triple(i1, j2, j3)].push_back(make_triple(i2, j4, j5));
                                    }
                                }
                            }
                        }
                    }
                }

                for (auto it2 = G.edges.begin(); it2 != G.edges.end(); it2++) {
                    auto [i3, j3] = it2->first;
                    if (i1 == i3 && j1 != j3 && G.edges.find(std::make_pair(i3, j3)) != G.edges.end()) {
                        for (auto& e2 : G.edges.at(std::make_pair(i3, j3))) {
                            auto [i4, j4] = e2.first;
                            if (i4 == i1 && j4 == j1) {
                                // Rule 6
                                if (G.edges.find(std::make_pair(i2, j2)) != G.edges.end()) {
                                    for (auto& e3 : G.edges.at(std::make_pair(i2, j2))) {
                                        auto [i5, j5] = e3.first;
                                        if (i5 == i2 && j2 != j5) {
                                            e++;
                                            edges[make_triple(i1, j3, j2)].push_back(make_triple(i2, j2, j5));
                                        }
                                    }
                                }

                                // Rule 4
                                for (auto it2 = G.edges.begin(); it2 != G.edges.end(); it2++) {
                                    auto [i5, j5] = it2->first;
                                    if (i5 == i2 && j5 != j2) {
                                        for (auto& e3 : it2->second) {
                                            auto [i6, j6] = e3.first;
                                            if (i5 == i6 && j6 == j2) {
                                                e++;
                                                edges[make_triple(i1, j3, j1)].push_back(make_triple(i2, j5, j1));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->second.size() == 0) {
            edges.erase(it);
        }
    }
}

bool RCG::check_cycle() {
    std::set<int> visited;
    std::stack<int> dfs_stack;
    for (auto it = edges.begin(); it != edges.end(); it++) {
        int hash = get_hash(it->first);
        if (visited.find(hash) == visited.end()) {
            dfs_stack.push(hash);
            std::set<int> cycle_set;
            while (!dfs_stack.empty()) {
                int u = dfs_stack.top();
                visited.insert(u);
                cycle_set.insert(u);
                dfs_stack.pop();
                for (auto& e : edges[get_key(u)]) {
                    int h = get_hash(e);
                    if (cycle_set.find(h) != cycle_set.end()) {
                        return true;
                    }
                    if (visited.find(h) == visited.end()) {
                        dfs_stack.push(h);
                    }
                }
            }
        }
    }
    return false;
}

void RCG::print_graph() {
    std::cout << "Number of vertices: " << v << "\n";
    std::cout << "Number of edges: " << e << "\n";

    for (auto it = edges.begin(); it != edges.end(); it++) {
        print(it->first);
        for (auto e : it->second) {
            std::cout << " -> ";
            print(e);
        }
        std::cout << "\n";
    }
}