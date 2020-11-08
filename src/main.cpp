#include <scheduler.hpp>
#include <intersection.hpp>

void print_enum (LaneType t) {
        switch (t) {
        case LaneType::NORTH:
            std::cout<<"NORTH";
            return;
        case LaneType::SOUTH:
            std::cout<<"SOUTH";
            return;
        case LaneType::EAST:
            std::cout<<"EAST";
            return;
        case LaneType::WEST:
            std::cout<<"WEST";
            return;
        default:
            std::invalid_argument e("Integer for enum LaneType not within bounds.");
            throw e;
    }
}

int main(int argc, char** argv) {
    // implement runtime logic here
    // need functions to benchmark times, save schedules --> utils.hpp
    // int param_1, param_2;
    
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
    // Intersection i(param_2);
    Intersection i(1);
    
    // TCG G(t, i);
    // SG scheduler(G);
    // scheduler.run();

    return 0;
}