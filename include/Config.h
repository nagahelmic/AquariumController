#pragma once

#include <cstdint>

namespace Config
{
    struct Ota
    {
        const char* hostname = "aquarium-controller";
    };

    struct Temperature
    {
        uint32_t measurementIntervalMs = 1000;

        uint8_t waterSensorAddress[8] = {
            0x28, 0x44, 0x9F, 0xE0, 0x42, 0x25, 0x06, 0xBB
        };

        uint8_t roomSensorAddress[8] = {
            0x28, 0x8A, 0x53, 0x31, 0x7B, 0x24, 0x0B, 0xD3
        };
    };

    struct Display
    {
        uint8_t brightness = 255;
        uint32_t refreshIntervalMs = 1000;
    };

    struct Alarm
    {
        bool enabled = true;

        float minTemperature = 22.0f;
        float maxTemperature = 27.0f;
    };

    struct Wifi
    {
        uint32_t reconnectIntervalMs = 10000;
    };

    struct Mqtt
    {
        const char* brokerUri = "mqtt://192.168.0.140:1883";
        const char* clientId = "aquarium-controller";
        uint32_t publishIntervalMs = 60000;
    };

    struct Settings
    {
        Temperature temperature;
        Display display;
        Wifi wifi;
        Mqtt mqtt;
        Ota ota;
        Alarm alarm;
    };
}
