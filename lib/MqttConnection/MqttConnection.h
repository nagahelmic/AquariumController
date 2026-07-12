#pragma once

#include <PsychicMqttClient.h>

#include "AlarmState.h"
#include "Config.h"
#include "TemperatureReading.h"

class MqttConnection
{
public:
    void begin(
        const Config::Mqtt& config,
        const char* username,
        const char* password
    );

    void update(bool wifiConnected);

    bool publish(
        const TemperatureReading& waterTemperature,
        const TemperatureReading& roomTemperature,
        const AlarmState& alarmState
    );

    bool isConnected();

private:
    bool publishTemperature(
        const char* topic,
        const TemperatureReading& reading
    );

    PsychicMqttClient client;
    bool configured = false;
    bool started = false;
};
