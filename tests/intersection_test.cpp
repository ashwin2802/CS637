#include <intersection.hpp>
#include <iomanip>

void print(int i) {
    Intersection inter(i);
    std::cout << std::left << std::setw(10) << "Source" << std::setw(15) << "Destination" << "Conflict Zones" << std::endl;

    for (auto it_:inter.paths) {
        std::cout << std::left << std::setw(10) << it_.first.first  << std::setw(15) << it_.first.second;
        for (auto vit_:it_.second) std::cout << vit_ << ", ";
        std::cout << std::endl;
    }
}

int main() {
    
    print(4);    
    return 0;
}