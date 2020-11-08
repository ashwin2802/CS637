#include <intersection.hpp>

void Intersection::calculate_paths_one() {
    std::vector<int> single = {1};
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            if (i==j) continue;
            paths.insert({std::pair(i,j), single});
        }
    }
}

Intersection::Intersection(int num) : n(num){
    switch(n) {
        case 1:
            calculate_paths_one();
            break;
    }
}