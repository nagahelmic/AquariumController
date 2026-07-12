#include "MqttConnection.h"

#include <Arduino.h>

namespace
{
    constexpr const char* AvailabilityTopic = "aquarium/status/availability";
    constexpr const char* WaterTemperatureTopic = "aquarium/temperature/water";
    constexpr const char* RoomTemperatureTopic = "aquarium/temperature/room";
    constexpr const char* AlarmTopic = "aquarium/status/alarm";

    constexpr uint8_t PublishQos = 1;
    constexpr bool RetainMessages = true;
}

void MqttConnection::begin(
    const Config::Mqtt& config,
    const char* username,
    const char* password
)
{
    client.setServer(config.brokerUri);
    client.setClientId(config.clientId);
    client.setCredentials(username, password);
    client.setAutoReconnect(true);
    client.setWill(
        AvailabilityTopic,
        PublishQos,
        RetainMessages,
        "offline"
    );

    client.onConnect([this](bool sessionPresent)
    {
        (void)sessionPresent;

        Serial.println("MQTT connected");
        client.publish(
            AvailabilityTopic,
            PublishQos,
            RetainMessages,
            "online"
        );
    });

    client.onDisconnect([](bool sessionPresent)
    {
        (void)sessionPresent;
        Serial.println("MQTT disconnected");
    });

    configured = true;
}

void MqttConnection::update(bool wifiConnected)
{
    if (!configured || started || !wifiConnected)
    {
        return;
    }

    Serial.println("MQTT connecting...");
    client.connect();
    started = true;
}

bool MqttConnection::publish(
    const TemperatureReading& waterTemperature,
    const TemperatureReading& roomTemperature,
    const AlarmState& alarmState
)
{
    if (!isConnected())
    {
        return false;
    }

    const bool waterPublished = publishTemperature(
        WaterTemperatureTopic,
        waterTemperature
    );

    const bool roomPublished = publishTemperature(
        RoomTemperatureTopic,
        roomTemperature
    );

    const bool alarmPublished = client.publish(
        AlarmTopic,
        PublishQos,
        RetainMessages,
        alarmState.active ? "ON" : "OFF"
    ) >= 0;

    return waterPublished && roomPublished && alarmPublished;
}

bool MqttConnection::isConnected()
{
    return client.connected();
}

bool MqttConnection::publishTemperature(
    const char* topic,
    const TemperatureReading& reading
)
{
    char payload[16];

    if (reading.valid)
    {
        snprintf(payload, sizeof(payload), "%.1f", reading.valueCelsius);
    }
    else
    {
        snprintf(payload, sizeof(payload), "unavailable");
    }

    return client.publish(
        topic,
        PublishQos,
        RetainMessages,
        payload
    ) >= 0;
}
