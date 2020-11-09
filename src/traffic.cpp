#include <traffic.hpp>

Traffic::Traffic(float lambda, long int arrival_time_max){
    this->lambda = lambda;
    this->arrival_time_max = arrival_time_max;
    generate_traffic();
}

// void Traffic::generate_lane_traffic(std::map<int, int>& result, int source) {
void Traffic::generate_lane_traffic(int source) {
    std::poisson_distribution<int> distribution(1 / lambda);
    std::uniform_int_distribution<int> udistribution(0, 2);
    std::random_device rd;
    std::default_random_engine generator(rd());

    int insert_direction[3];

    int j = 0;
    for (int i = 1; i <= 4; i++) {
        if (source == i)
            continue;
        insert_direction[j] = i;
        j++;
    }

    for (long int time = distribution(generator); time < arrival_time_max; time += distribution(generator)) {
        // result.insert({time, insert_direction[udistribution(generator)]});
        traffic.insert({std::pair<int, int>(source, time), insert_direction[udistribution(generator)]});
        vehicles.push_back(std::pair<int, int>(source, time));
    }
}

bool Traffic::compare(std::pair<int, int> e1, std::pair<int, int> e2) {
    return e1.second < e2.second;
    // std::map<std::map<int, int>, int> trafficfefe();
}

void Traffic::generate_traffic() {
    traffic.clear();
    // std::map<int, int> arrival_times;

    for (int i = 1; i <= 4; i++) {
        // generate_lane_traffic(arrival_times, i);
        generate_lane_traffic(i);
        // traffic.insert({arrival_times, i});
        // arrival_times.clear();
    }

    sort(vehicles.begin(), vehicles.end(), Traffic::compare);
}