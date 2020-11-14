#include <tcg.hpp>

void TCG::vertices_and_type_1(Traffic& T, Intersection& I) {
    bool first_vehicle[] = {true, true, true, true};
    int i = 1;
    this->m = T.m;
    this->n = I.n;
    this->e = 0;

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
                (this->e)++;
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
    this->v = vertices.size();
}

void TCG::model_conflicts(Traffic& T, int conflict_zones) {
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            for (int k = 1; k <= conflict_zones; k++) {
                if (vertices.count(std::pair<int, int>(i, k)) && vertices.count(std::pair<int, int>(j, k))) {
                    auto vehicle_one = T.traffic.begin();
                    std::advance(vehicle_one, i - 1);

                    auto vehicle_two = T.traffic.begin();
                    std::advance(vehicle_two, j - 1);

                    if (vehicle_one->first.first == vehicle_two->first.first) {
                        Edge e(EdgeType::TYPE_2);
                        e.wait_time = 0.2;

                        std::pair<std::pair<int, int>, Edge> dest_v(std::pair<int, int>(j, k), e);

                        if (edges.count(std::pair<int, int>(i, k))) {
                            edges[std::pair<int, int>(i, k)].push_back(dest_v);
                        } else {
                            std::vector<std::pair<std::pair<int, int>, Edge>> dest = {dest_v};
                            edges.insert({std::pair<int, int>(i, k), dest});
                        }
                        (this->e)++;

                    } else {
                        Edge e(EdgeType::TYPE_3);
                        e.wait_time = 0.2;

                        std::pair<std::pair<int, int>, Edge> dest_v_one(std::pair<int, int>(j, k), e);
                        std::pair<std::pair<int, int>, Edge> dest_v_two(std::pair<int, int>(i, k), e);

                        if (edges.count(std::pair<int, int>(j, k))) {
                            edges[std::pair<int, int>(j, k)].push_back(dest_v_two);
                        } else {
                            std::vector<std::pair<std::pair<int, int>, Edge>> dest = {dest_v_two};
                            edges.insert({std::pair<int, int>(j, k), dest});
                        }

                        if (edges.count(std::pair<int, int>(i, k))) {
                            edges[std::pair<int, int>(i, k)].push_back(dest_v_one);
                        } else {
                            std::vector<std::pair<std::pair<int, int>, Edge>> dest = {dest_v_one};
                            edges.insert({std::pair<int, int>(i, k), dest});
                        }
                        (this->e) += 2;

                    }
                }
            }
        }
    }

}

TCG::TCG(Traffic T, Intersection I) {
    vertices_and_type_1(T, I);
    model_conflicts(T, I.n);
}