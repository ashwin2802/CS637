#include <rcg.hpp>
#include <scheduler.hpp>

int main(int argc, char** argv) {
    // implement runtime logic here
    // need functions to benchmark times, save schedules --> utils.hpp
    int param_1, param_2;

    Traffic t(param_1);
    Intersection i(param_2);

    TCG G(t, i);
    SG scheduler(G);
    scheduler.run();

    return 0;
}