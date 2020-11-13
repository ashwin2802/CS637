#include <petri_net.hpp>

void PetriNet::type_one_transitions(TCG& graph) {
    this->v = graph.v;

    for (auto vertex : graph.vertices) {
        if (vertex.second.first_j) {
            token initial = {{vertex.first.first, vertex.first.first}, {0, v}};
            token final = {{vertex.first.first, vertex.first.first}, {vertex.first.second, v}};

            std::unordered_set<token, hasher, comparator> initial_set;
            initial_set.insert(initial);

            std::unordered_set<token, hasher, comparator> final_set;
            final_set.insert(final);

            transitions.push_back(transition(initial_set, final_set));

            std::pair<int, int> initial_cz = vertex.first;

            while (graph.edges.find(initial_cz) != graph.edges.end() && graph.edges[initial_cz][0].second.type == EdgeType::TYPE_1) {
                token initial = {{initial_cz.first, initial_cz.first}, {initial_cz.second, v}};
                initial_cz = std::pair<int, int>(graph.edges[initial_cz][0].first.first, graph.edges[initial_cz][0].first.second);

                token final = {{initial_cz.first, initial_cz.first}, {initial_cz.second, v}};

                std::unordered_set<token, hasher, comparator> initial_set;
                initial_set.insert(initial);

                std::unordered_set<token, hasher, comparator> final_set;
                final_set.insert(final);

                transitions.push_back(transition(initial_set, final_set));
            }

            initial = {{initial_cz.first, initial_cz.first}, {initial_cz.second, v}};
            final = {{initial_cz.first, initial_cz.first}, {-1, v}};

            std::unordered_set<token, hasher, comparator> initial_set_two;
            initial_set_two.insert(initial);

            std::unordered_set<token, hasher, comparator> final_set_two;
            final_set_two.insert(final);

            transitions.push_back(transition(initial_set_two, final_set_two));
        }
    }
}

void PetriNet::type_two_and_three(TCG& graph) {
    for (auto edges : graph.edges) {
        if (edges.second.size() == 1 && edges.second[0].second.type == EdgeType::TYPE_1)
            continue;

        token first_transition = {{edges.first.first, edges.first.first}, {edges.first.second, v}};
        std::list<transition>::iterator current;

        for (auto trans = transitions.begin(); trans != transitions.end(); trans++) {
            auto it = trans->first.find(first_transition);
            if (it != trans->first.end()) {
                current = trans;
                break;
            }
        }

        for (auto diff_edges : edges.second) {
            if (diff_edges.second.type == EdgeType::TYPE_1)
                continue;

            std::list<transition>::iterator next;
            token second_transition = {{diff_edges.first.first, diff_edges.first.first}, {diff_edges.first.second, v}};
            token to_insert = {{edges.first.first, diff_edges.first.first}, {edges.first.second, v}};

            for (auto trans = transitions.begin(); trans != transitions.end(); trans++) {
                auto it = trans->second.find(second_transition);
                if (it != trans->second.end()) {
                    next = trans;
                    break;
                }
            }
            current->second.insert(to_insert);
            next->first.insert(to_insert);
        }
    }
}

PetriNet::PetriNet(TCG& graph) {
    type_one_transitions(graph);
    type_two_and_three(graph);
}

bool PetriNet::simulate() {
    for (int i = 1; i <= v; i++) {
        active_tokens.insert({{i, i}, {0, v}});
    }

    auto it = transitions.begin();
    while (it != transitions.end()) {
        bool all_tokens_present = true;
        for (auto token_it : it->first) {
            if (active_tokens.find(token_it) == active_tokens.end()) {
                all_tokens_present = false;
                break;
            }
        }

        if (all_tokens_present) {
            for (auto token_it : it->first) {
                active_tokens.erase(token_it);
            }

            for (auto token_it : it->second) {
                active_tokens.insert(token_it);
            }

            auto copy = it;
            transitions.erase(copy);
            it = transitions.begin();
        } else {
            it++;
        }
    }

    if (transitions.size() == 0) {
        std::cout << "No deadlock!";
        return true;
    } else {
        std::cout << "Deadlock! Deadlocked transitions:" << std::endl;
        this->print();
        return false;
    }
}

void PetriNet::print() {
    for (auto trans : transitions) {
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
    std::cout << "------------------------------------------------------" << std::endl;
}

void PetriNet::print_transition(transition& trans) {
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

void PetriNet::print_token(token& left) {
    std::cout << left.first.first << ", " << left.first.second << ", " << left.second.first << std::endl;
}