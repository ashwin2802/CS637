#include <rcg.hpp>

RCG::RCG(TCG G) {
    v = 0;
    e = 0;
    m = G.m;
    n = G.n;

    for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
        for (auto e : it->second) {
            if (e.second == EdgeType::TYPE_1) {
                v++;
                edges[make_pair(it->first, e.first.second)] = vector<pair<pair<int, int>, int>>();
            }
        }
    }
}