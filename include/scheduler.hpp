#pragma once

#include <rcg.hpp>

struct Config {
    double lambda = 0.1;                     // Poisson distribution parameter
    int d = 30;                              // Earliest arrival time of last vehicle
    int n = 4;                               // Number of conflict zones
    double wait_times[3] = {0.1, 0.2, 0.2};  // Wait time for each edge, typewise
    double pass_time = 1;                    // time for vehicle to pass through a conflict zone in seconds
};

class Scheduler {
  private:
    void find_leaders(std::vector<std::pair<int, int>>& leaders);
    void update_leaders(std::vector<std::pair<int, int>>& leaders);
    void find_candidates(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& edges);
    bool check_deadlock();
    void remove_edges(const int& i_start, const int& i_end);
    void update_times();
    std::vector<std::pair<int, int>> top_sort();
    void dfs_visit(const std::pair<int, int>& v,
        std::set<std::pair<int, int>>& run_set,
        std::set<std::pair<int, int>>& visited,
        bool& f,
        std::vector<std::pair<int, int>>& top);

  public:
    Scheduler(const struct Config& cfg);
    void init();
    void run();

    Traffic T;
    Intersection I;
    TCG G;

    double max_leave_time;
    struct Config params;
};