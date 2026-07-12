#include "Alarm.h"

void Alarm::update(
    const Config::Alarm& config,
    const TemperatureReading& waterTemperature,
    const TemperatureReading& roomTemperature
)
{
    state = AlarmState{};

    if (!config.enabled)
    {
        return;
    }

    evaluateTemperature(
        waterTemperature,
        config.minTemperature,
        config.maxTemperature,
        state.waterTemperatureLow,
        state.waterTemperatureHigh,
        state.waterTemperatureInvalid
    );

    evaluateTemperature(
        roomTemperature,
        config.minTemperature,
        config.maxTemperature,
        state.roomTemperatureLow,
        state.roomTemperatureHigh,
        state.roomTemperatureInvalid
    );

    state.active =
        state.waterTemperatureLow ||
        state.waterTemperatureHigh ||
        state.waterTemperatureInvalid ||
        state.roomTemperatureLow ||
        state.roomTemperatureHigh ||
        state.roomTemperatureInvalid;
}

AlarmState Alarm::getState() const
{
    return state;
}

void Alarm::evaluateTemperature(
    const TemperatureReading& reading,
    float minTemperature,
    float maxTemperature,
    bool& low,
    bool& high,
    bool& invalid
) const
{
    if (!reading.valid)
    {
        invalid = true;
        return;
    }

    if (reading.valueCelsius < minTemperature)
    {
        low = true;
    }

    if (reading.valueCelsius > maxTemperature)
    {
        high = true;
    }
}
