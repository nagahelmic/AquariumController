#pragma once

#include <cstdint>

class IntervalTimer
{
public:
    bool isReady(uint32_t now, uint32_t intervalMs);
    void reset();

private:
    uint32_t lastRunMs = 0;
    bool firstRun = true;
};