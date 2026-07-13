#pragma once

#include "TemperatureReading.h"

struct DisplayData
{
    TemperatureReading waterTemperature;
    TemperatureReading roomTemperature;
    
    bool wifiConnected = false;

    bool waterTemperatureAlarm = false;
};

