#include <rcg.hpp>

RCG::RCG(TCG G) {
    v = 0;
    e = 0;
    m = G.m;
    n = G.n;

    // create RCG vertices - Rule 1
    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        auto [i1, j1] = it->first;
        for (auto& e : it->second) {
            auto [i2, j2] = e.first;
            if (i1 == i2 && e.second == EdgeType::TYPE_1) {
                v++;
                edges[make_triple(i1, j1, j2)] = vector<pair<pair<int, int>, int>>();
            }
        }
    }

    // Rule 2-6
    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        auto [i1, j1] = it->first;
        for (auto& e1 : it->second) {
            auto [i2, j2] = e1.first;

            // Rule 2
            if (i1 == i2 && j1 != j2) {
                for (auto& e2 : G.edges[make_pair(i2, j2)]) {
                    auto [i3, j3] = e2.first;
                    if (i2 == i3 && j2 != j3) {
                        e++;
                        edges[make_triple(i1, j1, j2)].push_back(make_triple(i1, j2, j3));
                    }
                }
            }

            if (i1 != i2 && j1 == j2) {
                for (auto& e2 : G.edges[make_pair(i1, j1)]) {
                    auto [i3, j3] = e2.first;
                    if (i1 == i3 && j1 != j3) {
                        // Rule 3
                        for (auto& e3 : G.edges[make_pair(i2, j2)]) {
                            auto [i4, j4] = e3.first;
                            if (i2 == i4 && j2 != j4) {
                                e++;
                                edges[make_triple(i1, j1, j3)].push_back(make_triple(i2, j2, j4));
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
                    if (i1 == i3 && j1 != j3) {
                        for (auto& e2 : G.edges[make_pair(i3, j3)]) {
                            auto [i4, j4] = e2.first;
                            if (i4 == i1 && j4 == j1) {
                                // Rule 6
                                for (auto& e3 : G.edges[make_pair(i2, j2)]) {
                                    auto [i5, j5] = e3.first;
                                    if (i5 == i2 && j2 != j5) {
                                        e++;
                                        edges[make_triple(i1, j3, j2)].push_back(make_triple(i2, j2, j5));
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
}

bool RCG::check_cycle() {
}