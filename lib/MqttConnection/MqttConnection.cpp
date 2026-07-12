#include "MqttConnection.h"

#include <Arduino.h>

namespace
{
    constexpr const char* AvailabilityTopic = "aquarium/status/availability";
    constexpr const char* WaterTemperatureTopic = "aquarium/temperature/water";
    constexpr const char* RoomTemperatureTopic = "aquarium/temperature/room";
    constexpr const char* AlarmTopic = "aquarium/status/alarm";

    constexpr const char* WaterTemperatureDiscoveryTopic =
        "homeassistant/sensor/aquarium_controller_water_temperature/config";
    constexpr const char* RoomTemperatureDiscoveryTopic =
        "homeassistant/sensor/aquarium_controller_room_temperature/config";
    constexpr const char* AlarmDiscoveryTopic =
        "homeassistant/binary_sensor/aquarium_controller_alarm/config";

    constexpr const char* WaterTemperatureDiscoveryPayload = R"json({
        "name":"Water temperature",
        "unique_id":"aquarium_controller_water_temperature",
        "default_entity_id":"sensor.aquarium_water_temperature",
        "state_topic":"aquarium/temperature/water",
        "availability_topic":"aquarium/status/availability",
        "payload_available":"online",
        "payload_not_available":"offline",
        "device_class":"temperature",
        "state_class":"measurement",
        "unit_of_measurement":"\u00b0C",
        "suggested_display_precision":1,
        "device":{
            "identifiers":["aquarium-controller"],
            "name":"AquariumController",
            "manufacturer":"DIY",
            "model":"ESP32 Aquarium Controller"
        },
        "origin":{
            "name":"AquariumController",
            "support_url":"https://github.com/nagahelmic/AquariumController"
        }
    })json";

    constexpr const char* RoomTemperatureDiscoveryPayload = R"json({
        "name":"Room temperature",
        "unique_id":"aquarium_controller_room_temperature",
        "default_entity_id":"sensor.aquarium_room_temperature",
        "state_topic":"aquarium/temperature/room",
        "availability_topic":"aquarium/status/availability",
        "payload_available":"online",
        "payload_not_available":"offline",
        "device_class":"temperature",
        "state_class":"measurement",
        "unit_of_measurement":"\u00b0C",
        "suggested_display_precision":1,
        "device":{
            "identifiers":["aquarium-controller"],
            "name":"AquariumController",
            "manufacturer":"DIY",
            "model":"ESP32 Aquarium Controller"
        },
        "origin":{
            "name":"AquariumController",
            "support_url":"https://github.com/nagahelmic/AquariumController"
        }
    })json";

    constexpr const char* AlarmDiscoveryPayload = R"json({
        "name":"Alarm",
        "unique_id":"aquarium_controller_alarm",
        "default_entity_id":"binary_sensor.aquarium_alarm",
        "state_topic":"aquarium/status/alarm",
        "availability_topic":"aquarium/status/availability",
        "payload_available":"online",
        "payload_not_available":"offline",
        "payload_on":"ON",
        "payload_off":"OFF",
        "device_class":"problem",
        "device":{
            "identifiers":["aquarium-controller"],
            "name":"AquariumController",
            "manufacturer":"DIY",
            "model":"ESP32 Aquarium Controller"
        },
        "origin":{
            "name":"AquariumController",
            "support_url":"https://github.com/nagahelmic/AquariumController"
        }
    })json";

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
        publishDiscovery();
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

bool MqttConnection::publishDiscovery()
{
    const bool waterPublished = client.publish(
        WaterTemperatureDiscoveryTopic,
        PublishQos,
        RetainMessages,
        WaterTemperatureDiscoveryPayload
    ) >= 0;

    const bool roomPublished = client.publish(
        RoomTemperatureDiscoveryTopic,
        PublishQos,
        RetainMessages,
        RoomTemperatureDiscoveryPayload
    ) >= 0;

    const bool alarmPublished = client.publish(
        AlarmDiscoveryTopic,
        PublishQos,
        RetainMessages,
        AlarmDiscoveryPayload
    ) >= 0;

    return waterPublished && roomPublished && alarmPublished;
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
