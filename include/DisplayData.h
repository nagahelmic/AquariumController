#pragma once

#include "TemperatureReading.h"

struct DisplayData
{
    TemperatureReading waterTemperature1;
    TemperatureReading waterTemperature2;
    
    bool wifiConnected = false;
    bool alarmActive = false;
};

