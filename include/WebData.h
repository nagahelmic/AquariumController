#pragma once

#include <cstdint>

#include "AlarmState.h"
#include "TemperatureReading.h"

struct WebData
{
    TemperatureReading waterTemperature;
    TemperatureReading roomTemperature;

    bool wifiConnected = false;
    uint32_t uptimeSeconds = 0;

    AlarmState alarmState;
};
