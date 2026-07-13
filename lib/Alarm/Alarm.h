#pragma once

#include "AlarmState.h"
#include "Config.h"
#include "TemperatureReading.h"

class Alarm
{
public:
    void update(
        const Config::Alarm& config,
        const TemperatureReading& waterTemperature
    );

    AlarmState getState() const;

private:
    void evaluateTemperature(
        const TemperatureReading& reading,
        float minTemperature,
        float maxTemperature,
        bool& low,
        bool& high,
        bool& invalid
    ) const;

    AlarmState state;
};
