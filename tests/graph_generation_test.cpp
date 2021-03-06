#include <intersection.hpp>
#include <iomanip>
#include <tcg.hpp>
#include <traffic.hpp>

std::string print_enum(int t) {
    switch (t) {
        case 1:
            return "NORTH";
        case 2:
            return "SOUTH";
        case 3:
            return "EAST";
        case 4:
            return "WEST";
        default:
            std::invalid_argument e("Integer for enum LaneType not within bounds.");
            throw e;
    }
}

std::string print_enum(EdgeType type) {
    switch (type) {
        case EdgeType::TYPE_1:
            return "Type 1";

        case EdgeType::TYPE_2:
            return "Type 2";

        case EdgeType::TYPE_3:
            return "Type 3";
    }
}

int main() {
    Traffic T(0.1, 15);
    Intersection I(4);

    TCG G(T, I);

    std::cout << std::left << std::setw(10) << "Source" << std::setw(15) << "Destination"
              << "Time" << std::endl;
    for (auto it_ : T.traffic) {
        std::cout << std::left << std::setw(10) << print_enum(it_.first.first) << std::setw(15) << print_enum(it_.second) << it_.first.second << std::endl;
    }

    std::cout << std::endl << std::endl;

    for (auto it : G.vertices) {
        std::cout << "i = " << it.first.first << "  ";
        std::cout << "j = " << it.first.second << "  ";
        std::cout << "arrival time = " << it.second.start_time << "  ";
        std::cout << "is it first vehicle: " << it.second.first_i << "  ";
        std::cout << "is it conflict zone: " << it.second.first_j << "  ";
        std::cout << std::endl << std::endl;
    }

    for (auto it : G.edges) {
        for (auto vit : it.second) {
            std::cout << it.first.first << ", " << it.first.second << "   ";
            std::cout << vit.first.first << ", " << vit.first.second << "   ";
            std::cout << print_enum(vit.second.type) << std::endl;
        }
    }

    return 0;
}