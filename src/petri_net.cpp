#include <petri_net.hpp>

void PetriNet::type_one_transitions (TCG& graph) {
    for (auto vertex:graph.vertices) {
        if (vertex.second.first_j) {
            
            token initial = {{vertex.first.first, vertex.first.first}, {0, graph.v}};
            token final = {{vertex.first.first, vertex.first.first}, {vertex.first.second, graph.v}};

            std::unordered_set<token, hasher, comparator> initial_set;
            initial_set.insert(initial);

            std::unordered_set<token, hasher, comparator> final_set;
            final_set.insert(final);

            transitions.push_back(transition(initial_set, final_set));

            std::pair<int, int> initial_cz = vertex.first;
            
            while (graph.edges.find(initial_cz) != graph.edges.end() && graph.edges[initial_cz][0].second.type == EdgeType::TYPE_1) {
                token initial = {{initial_cz.first, initial_cz.first}, {initial_cz.second, graph.v}};
                initial_cz =  std::pair<int, int>(graph.edges[initial_cz][0].first.first, graph.edges[initial_cz][0].first.second);

                token final = {{initial_cz.first, initial_cz.first}, {initial_cz.second, graph.v}};

                std::unordered_set<token, hasher, comparator> initial_set;
                initial_set.insert(initial);

                std::unordered_set<token, hasher, comparator> final_set;
                final_set.insert(final);

                transitions.push_back(transition(initial_set, final_set));
            }

            initial = {{initial_cz.first, initial_cz.first},{initial_cz.second, graph.v}};
            final = {{initial_cz.first, initial_cz.first},{-1, graph.v}};

            std::unordered_set<token, hasher, comparator> initial_set_two;
            initial_set_two.insert(initial);

            std::unordered_set<token, hasher, comparator> final_set_two;
            final_set_two.insert(final);

            transitions.push_back(transition(initial_set_two, final_set_two));
            // this->print();
        }
    }
}

void PetriNet::type_two_and_three(TCG& graph) {
    for (auto edges : graph.edges) {
        if (edges.second.size() == 1 && edges.second[0].second.type == EdgeType::TYPE_1)
            continue;

        token first_transition = {{edges.first.first, edges.first.first}, {edges.first.second, graph.v}};
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
            token second_transition = {{diff_edges.first.first, diff_edges.first.first}, {diff_edges.first.second, graph.v}};
            token to_insert = {{edges.first.first, diff_edges.first.first}, {edges.first.second, graph.v}};

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