#pragma once

#include <cstdint>
#include <Wire.h>
#include <Adafruit_SH110X.h>

#include "DisplayData.h"
#include "TemperatureReading.h"

class Display
{
public:
    void begin();
    void update();
    void render(const DisplayData& data);

private:
    void drawTemperatureLine(
        int16_t x,
        int16_t y,
        const char* label,
        const TemperatureReading& reading,
        bool alarmActive
    );

    void drawTemperatureColumn(
    int16_t x,
    int16_t y,
    const char* label,
    const TemperatureReading& reading,
    bool alarmActive
    );
    
    bool initialized = false;
    void drawWifiIcon(int16_t x, int16_t y, bool connected);

    Adafruit_SH1106G oled = Adafruit_SH1106G(128, 64, &Wire, -1);
};