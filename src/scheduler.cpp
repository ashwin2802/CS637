#include <scheduler.hpp>

Scheduler::Scheduler(const struct Config& cfg)
    : T(cfg.lambda, cfg.d)
    , I(cfg.n) {
    max_leave_time = 0.0;
    params = cfg;
}

void Scheduler::init() {
    G = TCG(T, I);
    for (auto it = G.vertices.begin(); it != G.vertices.end(); it++) {
        it->second.state = VertexState::WHITE;
        it->second.slack = __DBL_MAX__;
    }

    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        for (auto& e : it->second) {
            if (e.second.type != EdgeType::TYPE_3) {
                e.second.state = EdgeState::ON;
            } else {
                e.second.state = EdgeState::UNDECIDED;
            }
        }
    }
}

void Scheduler::run() {
    update_times();
    remove_edges(0, T.m);
}

void Scheduler::update_times() {
    auto tv = top_sort();
    for (int i = 0; i < tv.size(); i++) {
        double start_time = 0;  // set arrival time of ith vehicle here
        for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
            for (auto& e : it->second) {
                if (e.second.state != EdgeState::ON) {
                    continue;
                }
                if (e.first == tv[i]) {
                    start_time = std::max(start_time, G.vertices[it->first].start_time + e.second.wait_time + G.vertices[it->first].pass_time);
                    if (G.edges.find(it->first) != G.edges.end()) {
                        for (auto& e1 : G.edges[it->first]) {
                            if (e1.first.first == it->first.first) {
                                start_time = std::max(start_time, G.vertices[it->first].start_time - e1.second.wait_time + e.second.wait_time);
                            }
                        }
                    }
                }
            }
        }
        G.vertices[tv[i]].start_time = start_time;
    }

    double max_leave_time = 0;
    for (auto it = G.vertices.begin(); it != G.vertices.end(); it++) {
        max_leave_time = std::max(max_leave_time, it->second.start_time + it->second.pass_time);
    }

    for (int i = tv.size() - 1; i >= 0; i--) {
        double slack = max_leave_time - G.vertices[tv[i]].start_time - G.vertices[tv[i]].pass_time;
        if (G.edges.find(tv[i]) != G.edges.end()) {
            for (auto& e : G.edges[tv[i]]) {
                if (e.second.state != EdgeState::ON) {
                    continue;
                }
                slack = std::min(slack, G.vertices[e.first].slack);
            }
        }
        G.vertices[tv[i]].slack = slack;
    }
}

std::vector<std::pair<int, int>> Scheduler::top_sort() {
    std::map<std::pair<int, int>, int> fin_times;
    std::vector<std::pair<int, int>> top_vertices;
    std::set<std::pair<int, int>> visited;
    int t = 0;
    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        if (visited.find(it->first) == visited.end()) {
            std::set<std::pair<int, int>> run_set;
            bool cyc = false;
            dfs_visit(it->first, run_set, visited, cyc, top_vertices);
            if (cyc) {
                std::cerr << "Graph has a cycle!";
                return std::vector<std::pair<int, int>>();
            }
        }
    }
    return top_vertices;
}

void Scheduler::dfs_visit(const std::pair<int, int>& v,
    std::set<std::pair<int, int>>& run_set,
    std::set<std::pair<int, int>>& visited,
    bool& f,
    std::vector<std::pair<int, int>>& top) {
    if (f == true) {
        return;
    }
    visited.insert(v);
    run_set.insert(v);
    if (G.edges.find(v) != G.edges.end()) {
        for (auto& e : G.edges[v]) {
            if (e.second.state != EdgeState::ON) {
                continue;
            } else if (run_set.find(e.first) != run_set.end()) {
                f = true;
                return;
            } else if (visited.find(e.first) == visited.end()) {
                dfs_visit(e.first, run_set, visited, f, top);
            }
        }
    }
    top.push_back(v);
}

void Scheduler::remove_edges(const int& i_start, const int& i_end) {
    bool fail = false;
    for (auto it = G.vertices.begin(); it != G.vertices.end(); it++) {
        if (it->first.first >= i_start) {
            it->second.state = VertexState::WHITE;
        }
    }

    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        auto [i1, j1] = it->first;
        for (auto& e : it->second) {
            if (e.second.type == EdgeType::TYPE_3) {
                auto [i2, j2] = e.first;
                if (i1 >= i_end && i2 >= i_end) {
                    e.second.state = EdgeState::DONTCARE;
                } else if (i1 >= i_start && i2 < i_end) {
                    e.second.state = EdgeState::UNDECIDED;
                } else if (i1 >= i_start && i2 >= i_end && i1 < i_end) {
                    e.second.state = EdgeState::ON;
                } else if (i2 >= i_start && i2 < i_end && i1 >= i_end) {
                    e.second.state = EdgeState::OFF;
                }
            }
        }
    }

    std::vector<std::pair<int, int>> leaders;
    find_leaders(leaders);
    while (!leaders.empty()) {
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> candidates;
        find_candidates(candidates, leaders);

        std::pair<std::pair<int, int>, std::pair<int, int>> e_max;
        double max_cost = __DBL_MIN__;
        for (auto& e : candidates) {
            for (auto& e1 : G.edges[e.first]) {
                if (e1.first == e.second) {
                    e1.second.cost = G.vertices[e.first].start_time + G.vertices[e.first].pass_time + e1.second.wait_time - G.vertices[e.second].start_time -
                                     G.vertices[e.second].slack;
                    if (e1.second.cost > max_cost) {
                        e_max = e;
                        max_cost = e1.second.cost;
                    }
                }
            }
        }

        for (auto& e : G.edges[e_max.first]) {
            if (e.first == e_max.second) {
                e.second.state = EdgeState::OFF;
            }
        }
        for (auto& e : G.edges[e_max.second]) {
            if (e.first == e_max.first) {
                e.second.state = EdgeState::ON;
            }
        }

        if (!check_deadlock()) {
            for (auto& e : G.edges[e_max.first]) {
                if (e.first == e_max.second) {
                    e.second.state = EdgeState::ON;
                }
            }
            for (auto& e : G.edges[e_max.second]) {
                if (e.first == e_max.first) {
                    e.second.state = EdgeState::OFF;
                }
            }
            if (!check_deadlock()) {
                fail = true;
                break;
            }
        }

        update_leaders(leaders);
        update_times();
    }

    if (fail) {
        int i_mid = (i_start + i_end) / 2;
        remove_edges(i_start, i_mid);
        remove_edges(i_mid, i_end);
    }
}

bool Scheduler::check_deadlock() {
    RCG R(G);
    return R.check_cycle();
}

void Scheduler::find_leaders(std::vector<std::pair<int, int>>& leaders) {
    for (auto it = G.vertices.begin(); it != G.vertices.end(); it++) {
        if (it->second.first_j && it->second.first_i) {
            leaders.push_back(it->first);
        }
    }
}

void Scheduler::update_leaders(std::vector<std::pair<int, int>>& leaders) {
    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        bool black_from = true;
        for (auto& e : it->second) {
            if (e.second.state != EdgeState::ON && e.second.state != EdgeState::OFF) {
                black_from = false;
                break;
            }
        }

        bool black_to = true;
        for (auto it2 = G.edges.begin(); it2 != G.edges.end(); it2++) {
            if (it == it2)
                continue;
            for (auto& e : it2->second) {
                if (e.first == it->first) {
                    if (e.second.state != EdgeState::ON && e.second.state != EdgeState::OFF) {
                        black_to = false;
                        break;
                    }
                }
            }
            if (!black_to)
                break;
        }

        if (black_from || black_to) {
            G.vertices[it->first].state = VertexState::BLACK;
        }
    }

    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        bool gray = true;
        for (auto it2 = G.edges.begin(); it2 != G.edges.end(); it2++) {
            if (it == it2)
                continue;
            for (auto& e : it2->second) {
                if (e.first == it->first) {
                    if (G.vertices[it2->first].state != VertexState::BLACK) {
                        gray = false;
                        break;
                    }
                }
            }
            if (!gray) {
                break;
            }
        }

        if (gray) {
            G.vertices[it->first].state == VertexState::GRAY;
            leaders.push_back(it->first);
        }
    }
}

void Scheduler::find_candidates(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& edges, std::vector<std::pair<int, int>>& leaders) {
    for (auto& v : leaders) {
        for (auto& e : G.edges[v]) {
            if (e.second.type == EdgeType::TYPE_3 && e.second.state == EdgeState::UNDECIDED) {
                edges.push_back(std::make_pair(v, e.first));
            }
        }
        for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
            for (auto& e : it->second) {
                if (e.first == v && e.second.type == EdgeType::TYPE_3 && e.second.state == EdgeState::UNDECIDED) {
                    edges.push_back(std::make_pair(it->first, e.first));
                }
            }
        }
    }
}

void Scheduler::print_schedule() {
    std::cout << "Number of vertices: " << G.v << "\n";
    std::cout << "Number of edges: " << G.e << "\n";

    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        for (auto e : it->second) {
            if (e.second.state == EdgeState::ON) {
                print(it->first);
                std::cout << " -> ";
                print(e.first);
            }
        }
        std::cout << "\n";
    }
}