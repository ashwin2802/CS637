#include <tcg.hpp>

TCG::TCG(Traffic T, Intersection I) {
    for (auto it : T.traffic) {
        bool first_v = true;
        // v.slack = INFINITY;

        for (auto vit : it.second) {
            bool first_cz = true;
            double start = vit.first;
            for (auto czit : I.paths[std::pair<int, int>(it.first, vit.second)]) {
                Vertex v = {.slack = INFINITY, .pass_time = 1, .start_time = start, .first_j = first_cz, .first_i = first_v, .state = VertexState::WHITE};
                
                int i = std::lower_bound(T.vehicles.begin(), T.vehicles.end(), std::pair<int, int>(it.first, vit.first)) - T.vehicles.begin() + 1;

                vertices.insert({std::pair<int, int>(i, czit), v});
                first_cz = false;
            }
            first_v = false;
        }

        // vertices.insert()
    }
}