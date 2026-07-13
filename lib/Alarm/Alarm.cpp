#include "Alarm.h"

void Alarm::update(
    const Config::Alarm& config,
    const TemperatureReading& waterTemperature
)
{
    state = AlarmState{};

    if (!config.enabled)
    {
        return;
    }

    evaluateTemperature(
        waterTemperature,
        config.minWaterTemperature,
        config.maxWaterTemperature,
        state.waterTemperatureLow,
        state.waterTemperatureHigh,
        state.waterTemperatureInvalid
    );

    state.active =
        state.waterTemperatureLow ||
        state.waterTemperatureHigh ||
        state.waterTemperatureInvalid;
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
