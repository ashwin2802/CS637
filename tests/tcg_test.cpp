#include <tcg.hpp>

void print_enum(int t) {
    switch (t) {
        case 1:
            std::cout << "NORTH";
            return;
        case 2:
            std::cout << "SOUTH";
            return;
        case 3:
            std::cout << "EAST";
            return;
        case 4:
            std::cout << "WEST";
            return;
        default:
            std::invalid_argument e("Integer for enum LaneType not within bounds.");
            throw e;
    }
}

int main(int argc, char** argv) {
    double lambda = 0.1;
    int d = 12;
    int n = 4;

    int tc = 3;
    for (int i = 0; i < tc; i++) {
        Traffic T(lambda, d);
        TCG G(T, Intersection(n));
        for (auto it_ : T.traffic) {
            print_enum(it_.first.first);
            std::cout << " " << it_.first.second << " ";
            print_enum(it_.second);
            std::cout << std::endl;
        }
        G.print_graph();
        std::cout << std::endl;
    }
    return 0;
}