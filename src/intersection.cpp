#include <intersection.hpp>

void Intersection::calculate_paths_one() {
    std::vector<int> single = {1};
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (i == j)
                continue;
            paths.insert({std::pair<int, int>(i, j), single});
        }
    }
}

void Intersection::calculate_paths_four() {
    paths.insert({std::pair<int, int>(1, 2), std::vector<int>({4, 1})});
    paths.insert({std::pair<int, int>(1, 3), std::vector<int>({4, 1, 2})});
    paths.insert({std::pair<int, int>(1, 4), std::vector<int>({4})});

    paths.insert({std::pair<int, int>(2, 1), std::vector<int>({2, 3})});
    paths.insert({std::pair<int, int>(2, 3), std::vector<int>({2})});
    paths.insert({std::pair<int, int>(2, 4), std::vector<int>({2, 3, 4})});

    paths.insert({std::pair<int, int>(3, 1), std::vector<int>({3})});
    paths.insert({std::pair<int, int>(3, 2), std::vector<int>({3, 4, 1})});
    paths.insert({std::pair<int, int>(3, 4), std::vector<int>({3, 4})});

    paths.insert({std::pair<int, int>(4, 1), std::vector<int>({1, 2, 3})});
    paths.insert({std::pair<int, int>(4, 2), std::vector<int>({1})});
    paths.insert({std::pair<int, int>(4, 3), std::vector<int>({1, 2})});
}

void Intersection::calculate_paths_sixteen() {
    paths.insert({std::pair<int, int>(1, 2), std::vector<int>({15, 7, 8, 1, 10})});
    paths.insert({std::pair<int, int>(1, 3), std::vector<int>({15, 7, 8, 2, 3, 12})});
    paths.insert({std::pair<int, int>(1, 4), std::vector<int>({15, 16})});

    paths.insert({std::pair<int, int>(2, 1), std::vector<int>({11, 3, 4, 5, 14})});
    paths.insert({std::pair<int, int>(2, 3), std::vector<int>({11, 12})});
    paths.insert({std::pair<int, int>(2, 4), std::vector<int>({11, 3, 4, 6, 7, 16})});

    paths.insert({std::pair<int, int>(3, 1), std::vector<int>({13, 14})});
    paths.insert({std::pair<int, int>(3, 2), std::vector<int>({13, 5, 6, 8, 1, 10})});
    paths.insert({std::pair<int, int>(3, 4), std::vector<int>({13, 5, 6, 7, 16})});

    paths.insert({std::pair<int, int>(4, 1), std::vector<int>({9, 1, 2, 4, 5, 14})});
    paths.insert({std::pair<int, int>(4, 2), std::vector<int>({9, 10})});
    paths.insert({std::pair<int, int>(4, 3), std::vector<int>({9, 1, 2, 3, 12})});
}

Intersection::Intersection(int num)
    : n(num) {
    switch (n) {
        case 1:
            calculate_paths_one();
            break;
        case 4:
            calculate_paths_four();
            break;
    }
}