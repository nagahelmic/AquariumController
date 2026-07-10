#pragma once

#include <cstdint>

#include "AlarmState.h"
#include "TemperatureReading.h"

struct WebData
{
    TemperatureReading waterTemperature1;
    TemperatureReading waterTemperature2;

    bool wifiConnected = false;
    uint32_t uptimeSeconds = 0;

    AlarmState alarmState;
};