#include "IntervalTimer.h"

bool IntervalTimer::isReady(uint32_t now, uint32_t intervalMs)
{
    if (firstRun)
    {
        firstRun = false;
        lastRunMs = now;
        return true;
    }

    if (now - lastRunMs < intervalMs)
    {
        return false;
    }

    lastRunMs = now;
    return true;
}

void IntervalTimer::reset()
{
    lastRunMs = 0;
    firstRun = true;
}