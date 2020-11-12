#include <petri_net.hpp>

PetriNet::PetriNet(TCG& graph) {    
    for (auto edges:graph.edges) {
        if (edges.second[0].second.type != EdgeType::TYPE_1) continue;
        token initial = {{edges.first.first, edges.first.first}, {edges.first.second, graph.v}};
        token final = {{edges.first.first, edges.first.first}, {edges.second[0].first.second, graph.v}};

        std::unordered_set<token, hasher, comparator> initial_set;
        initial_set.insert(initial);

        std::unordered_set<token, hasher, comparator> final_set;
        final_set.insert(final);

        transitions.push_back(transition(initial_set, final_set));

        if (graph.vertices[edges.first].first_j) {
            token initial = {{edges.first.first, edges.first.first}, {0, graph.v}};
            token final = {{edges.first.first, edges.first.first}, {edges.first.second, graph.v}};

            std::unordered_set<token, hasher, comparator> initial_set;
            initial_set.insert(initial);

            std::unordered_set<token, hasher, comparator> final_set;
            final_set.insert(final);

            transitions.push_back(transition(initial_set, final_set));
        }
    }

    for (auto edges:graph.edges) {
        if (edges.second[0].second.type == EdgeType::TYPE_1 && edges.second.size() == 1) continue;
        // std::cout << "Type 2 and Type 3" << std::endl;
        token first_transition = {{edges.first.first, edges.first.first}, {edges.first.second, graph.v}};
        transition current;

        for (auto trans: transitions) {
            
            auto it = trans.first.find(first_transition);
            if (it != trans.first.end()) {
                // this->print_transition(trans);
                current = trans;
                break;
            }
        }

        if (current.first.size() == 0 && current.second.size() == 0) return;
        std::cout << "Source:" << std::endl;
        this->print_transition(current);    

        for (auto diff_edges:edges.second) {
            if (diff_edges.second.type == EdgeType::TYPE_1) continue;

            token second_transition = {{diff_edges.first.first, diff_edges.first.first}, {diff_edges.first.second, graph.v}};

            // this->print_token(second_transition);
            for (auto trans : transitions) {
                auto it = trans.first.find(second_transition);
                if (it != trans.first.end()) {
                    // std::cout << "Is this even running" << std::endl;
                    std::cout << "Destination:" << std::endl;
                    this->print_transition(trans);
                    token to_insert = {{edges.first.first, diff_edges.first.first},{edges.first.second, graph.v}};
                    // std::cout << to_insert.first.first << " " << to_insert.first.second << " " << to_insert.second.first << " " << to_insert.second.second << std::endl;
                    auto k = current.second.insert(to_insert);
                    this->print_transition(current);
                    // std::cout << k.second << std::endl;
                    // std::cout << current.second.size() << std::endl;
                    trans.first.insert(to_insert);
                    this->print_transition(trans);
                    break;
                }
            }
            // this->print();
        }
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
    // for (auto left: t) {
    std::cout << left.first.first << ", " << left.first.second << ", " << left.second.first << std::endl;
    // }
}