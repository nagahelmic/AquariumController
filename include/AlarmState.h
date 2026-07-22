#pragma once

struct AlarmState
{
    bool active = false;

    bool waterTemperatureLow = false;
    bool waterTemperatureHigh = false;
    bool waterTemperatureInvalid = false;
    bool roomTemperatureInvalid = false;
};
