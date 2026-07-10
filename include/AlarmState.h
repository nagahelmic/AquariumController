#pragma once

struct AlarmState
{
    bool active = false;

    bool waterTemperature1Low = false;
    bool waterTemperature1High = false;
    bool waterTemperature1Invalid = false;

    bool waterTemperature2Low = false;
    bool waterTemperature2High = false;
    bool waterTemperature2Invalid = false;
};