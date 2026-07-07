#pragma once

#include "TemperatureReading.h"

struct DisplayData
{
    TemperatureReading waterTemperature1;
    TemperatureReading waterTemperature2;
    
    bool wifiConected = false;
    bool alarmActive = false;
};

