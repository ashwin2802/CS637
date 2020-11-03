#include <traffic.hpp>

Traffic::Traffic(float lamda, long int arrival_time_max) {
    this->lamda = lamda;
    this->arrival_time_max = arrival_time_max;
    generate_traffic();
}

LaneType Traffic::return_enum(int i) {
    switch (i) {
        case 0:
            return LaneType::NORTH;
        case 1:
            return LaneType::SOUTH;
        case 2:
            return LaneType::EAST;
        case 3:
            return LaneType::WEST;
        default:
            std::invalid_argument e("Integer for enum LaneType not within bounds.");
            throw e;
    }
}

void Traffic::generate_lane_traffic(std::map<int, LaneType>& result, LaneType source) {
    std::poisson_distribution<int> distribution(lamda);
    std::uniform_int_distribution<int> udistribution(0, 2);

    std::default_random_engine generator(time(0));

    LaneType insert_direction[3];

    int j = 0;
    for (int i = 0; i < 4; i++) {
        if (source == return_enum(i))
            continue;
        insert_direction[j] = return_enum(i);
        j++;
    }

    long int time = 0;

    while (time < arrival_time_max) {
        time += distribution(generator);
        result.insert({time, insert_direction[udistribution(generator)]});
    }
}

void Traffic::generate_traffic() {
    traffic.clear();
    std::map<int, LaneType> arrival_times;

    for (int i = 0; i < 4; i++) {
        generate_lane_traffic(arrival_times, return_enum(i));
        traffic.insert({return_enum(i), arrival_times});
        arrival_times.clear();
    }
}