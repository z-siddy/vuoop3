#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include "main.h"

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    void startClock();
    void endClock(string opName);
};

#endif