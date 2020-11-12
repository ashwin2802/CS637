#include <petri_net.hpp>

PetriNet::PetriNet(TCG& graph) {
    for (auto edges:graph.edges) {
        if (edges.second[0].second.type != EdgeType::TYPE_1) continue;
        token initial = {{edges.first.first, edges.first.first}, {edges.first.second, graph.v}};
        token final = {{edges.first.first, edges.first.first}, {edges.second[0].first.second, graph.v}};

        // std::vector<token> initial_vec;
        std::unordered_set<token, hasher, comparator> initial_set;
        initial_set.insert(initial);
        // initial_vec.push_back(initial);

        // std::vector<token> final_vec;
        std::unordered_set<token, hasher, comparator> final_set;
        final_set.insert(final);
        // final_vec.push_back(final);

        transitions.push_back(transition(initial_set, final_set));
    }

    for (auto edges:graph.edges) {
        if (edges.second[0].second.type == EdgeType::TYPE_1 && edges.second.size() == 1) continue;

        token first_transition = {{edges.first.first, edges.first.first}, {edges.first.second, graph.v}};
        transition current;

        for (auto trans: transitions) {
            auto it = trans.first.find(first_transition);
            if (it != trans.first.end()) {
                current = trans;
                break;
            }
        }

        for (auto diff_edges:edges.second) {
            if (diff_edges.second.type == EdgeType::TYPE_1) continue;

            token second_transition = {{diff_edges.first.first, diff_edges.first.first}, {diff_edges.first.second, graph.v}};
                for (auto trans : transitions) {
                    auto it = trans.second.find(first_transition);
                    if (it != trans.second.end()) {
                        token to_insert = {{edges.first.first, diff_edges.first.first},{edges.first.second, graph.v}};
                        current.second.insert(to_insert);
                        trans.first.insert(to_insert);
                        break;
                    }
                }

        }
    }
}