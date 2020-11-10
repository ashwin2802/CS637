#include <tcg.hpp>

TCG::TCG(Traffic T, Intersection I) {
    bool first_vehicle[] = {true, true, true, true};
    int i = 1;

    for (auto it : T.traffic) {
        bool first_cz = true;
        double start = it.first.second;

        for (auto czit : I.paths[std::pair<int, int>(it.first.first, it.second)]) {
            Vertex v = {.slack = INFINITY,
                .pass_time = 1,
                .start_time = start,
                .first_j = first_cz,
                .first_i = first_vehicle[it.first.first - 1],
                .state = VertexState::WHITE};
            vertices.insert({std::pair<int, int>(i, czit), v});
            first_cz = false;
        }

        first_vehicle[it.first.first - 1] = false;
        i++;
    }
}