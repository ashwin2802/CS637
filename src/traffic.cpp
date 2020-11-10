#include <traffic.hpp>

Traffic::Traffic(float lambda, long int arrival_time_max){
    this->lambda = lambda;
    this->arrival_time_max = arrival_time_max;
    lane_nums.resize(4);
    enter_times.resize(4);
    for (int i = 1; i <= 4; i++) generate_lane_traffic(i);
    m = traffic.size();
}

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

    lane_nums[source] = 0;

    for (long int time = distribution(generator); time < arrival_time_max; time += distribution(generator)) {
        auto z = traffic.insert({std::pair<int, int>(source, time), insert_direction[udistribution(generator)]});
        lane_nums[source]++;
        enter_times[source].push_back(time);
    }
}
