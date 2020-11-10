#include <tcg.hpp>

TCG::TCG(Traffic T, Intersection I) {
    bool first_vehicle[] = {true, true, true, true};
    int i = 1;

    for (auto it : T.traffic) {
        bool isfirst_cz = true;
        double start = it.first.second;

        int first_cz = I.paths[std::pair<int, int>(it.first.first, it.second)][0];

        for (auto czit : I.paths[std::pair<int, int>(it.first.first, it.second)]) {
            if (first_cz != czit) {
                Edge e(EdgeType::TYPE_1);
                e.wait_time = 0.1;

                std::pair<std::pair<int, int>, Edge> dest_v(std::pair<int, int>(i, czit), e);
                std::vector<std::pair<std::pair<int, int>, Edge>> dest = {dest_v};
                edges.insert({std::pair<int, int>(i, first_cz), dest});
                first_cz = czit;
            }

            Vertex v = {.slack = INFINITY,
                .pass_time = 1,
                .start_time = start,
                .first_j = isfirst_cz,
                .first_i = first_vehicle[it.first.first - 1],
                .state = VertexState::WHITE};
            vertices.insert({std::pair<int, int>(i, czit), v});
            isfirst_cz = false;
        }

        first_vehicle[it.first.first - 1] = false;
        i++;
    }
}