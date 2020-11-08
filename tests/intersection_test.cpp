#include <intersection.hpp>
#include <iomanip>

void print(int i) {
    Intersection inter(i);
    for (auto it_:inter.paths) {
            std::cout << std::setw(3) << "Source" << std::setw(3) << "Destination" << std::cout << "Conflict Zones" << std::endl;
    }
}

int main() {
    
    print(1);    
    return 0;
}