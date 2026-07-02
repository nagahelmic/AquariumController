#pragma once 
#include <cstdint>

namespace Config {
    struct Temperature {
        float minTemperature = 22.0f;
        float maxTemperature = 27.0f;

        uint32_t measurementIntervalMs = 1000;
    };

    struct Display {
        uint8_t brightness = 255;
    };

    struct Alarm {
        bool enabled = true;
    };

    struct Settings {
        Temperature temperature;
        Display display;
        Alarm alarm;
    };
}