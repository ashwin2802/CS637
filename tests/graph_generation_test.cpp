#include <traffic.hpp>
#include <intersection.hpp>
#include <tcg.hpp>
#include <iomanip>

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

int main() {
    Traffic T(0.1, 30);
    Intersection I(4);

    // T.traffic.clear();

    // T.traffic.insert({std::pair<int, int>(4, 8), 1});
    // T.traffic.insert({std::pair<int, int>(3, 11), 1});
    // T.traffic.insert({std::pair<int, int>(1, 14), 4});
    TCG G(T, I);

    std::cout << std::left << std::setw(10) << "Source" << std::setw(15) << "Destination" << "Time" << std::endl;
    for (auto it_ : T.traffic) {
    //     print_enum(it_.first.first);
    //     std::cout << std::endl;
    //     // for (auto sit_ : it_.second) {
    //         std::cout << sit_.first << " ";
    //         print_enum(sit_.second);
    //         std::cout << std::endl;
    //     // }
    //     std::cout << std::endl << std::endl;
        std::cout << std::left << std::setw(10) << print_enum(it_.first.first)  << std::setw(15) << print_enum(it_.second) << it_.first.second << std::endl;
        // std::cout << vit_ << ", ";
    }


    // for (auto it_:inter.paths) {
    //     std::cout << std::left << std::setw(10) << it_.first.first  << std::setw(15) << it_.first.second;
    //     for (auto vit_:it_.second) std::cout << vit_ << ", ";
    //     std::cout << std::endl;
    // }

    // for (auto it : T.vehicles) {
    //     std::cout << print_enum(it.first);
    //     std::cout << " " << it.second <<std::endl;
    // }

    std::cout << std::endl << std::endl;

    for (auto it : G.vertices) {
        std::cout << "i = " << it.first.first << "  ";
        std::cout << "j = " << it.first.second << "  ";
        std::cout << "arrival time = " << it.second.start_time << "  ";
        std::cout << "is it first vehicle: " << it.second.first_i << "  ";
        std::cout << "is it conflict zone: " << it.second.first_j << "  ";
        std::cout << std::endl << std::endl;
    }


    return 0;
}