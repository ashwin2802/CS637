#include <traffic.hpp>

void print_enum(LaneType t) {
    switch (t) {
        case LaneType::NORTH:
            std::cout << "NORTH";
            return;
        case LaneType::SOUTH:
            std::cout << "SOUTH";
            return;
        case LaneType::EAST:
            std::cout << "EAST";
            return;
        case LaneType::WEST:
            std::cout << "WEST";
            return;
        default:
            std::invalid_argument e("Integer for enum LaneType not within bounds.");
            throw e;
    }
}

int main(int argc, char** argv) {
    Traffic t(0.1, 30);

    for (auto it_ : t.traffic) {
        print_enum(it_.first);
        std::cout << std::endl;
        for (auto sit_ : it_.second) {
            std::cout << sit_.first << " ";
            print_enum(sit_.second);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}