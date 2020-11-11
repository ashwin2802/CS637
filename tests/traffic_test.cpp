#include <traffic.hpp>

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
    Traffic t(0.1, 30);

    for (auto it_ : t.traffic) {
        print_enum(it_.first);
        std::cout << std::endl;
        for (auto sit_ : it_.second) {
            std::cout << sit_.first << " ";
            print_enum(sit_.second);
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    for (auto it_:t.vehicles) {
        std::cout << it_.first << " " << it_.second << std::endl;
    }
}