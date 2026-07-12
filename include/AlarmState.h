#pragma once

struct AlarmState
{
    bool active = false;

    bool waterTemperatureLow = false;
    bool waterTemperatureHigh = false;
    bool waterTemperatureInvalid = false;

    bool roomTemperatureLow = false;
    bool roomTemperatureHigh = false;
    bool roomTemperatureInvalid = false;
};
