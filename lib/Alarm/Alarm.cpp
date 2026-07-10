#include "Alarm.h"

void Alarm::update(
    const Config::Alarm& config,
    const TemperatureReading& waterTemperature1,
    const TemperatureReading& waterTemperature2
)
{
    state = AlarmState{};

    if (!config.enabled)
    {
        return;
    }

    evaluateTemperature(
        waterTemperature1,
        config.minTemperature,
        config.maxTemperature,
        state.waterTemperature1Low,
        state.waterTemperature1High,
        state.waterTemperature1Invalid
    );

    evaluateTemperature(
        waterTemperature2,
        config.minTemperature,
        config.maxTemperature,
        state.waterTemperature2Low,
        state.waterTemperature2High,
        state.waterTemperature2Invalid
    );

    state.active =
        state.waterTemperature1Low ||
        state.waterTemperature1High ||
        state.waterTemperature1Invalid ||
        state.waterTemperature2Low ||
        state.waterTemperature2High ||
        state.waterTemperature2Invalid;
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