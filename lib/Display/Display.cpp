#include "Display.h"
#include <Arduino.h>
#include <Wire.h>
#include "Pins.h"

namespace
{
    constexpr uint8_t OledAddress = 0x3C;

    constexpr int16_t WifiIconX = 120;
    constexpr int16_t WifiIconY = 56;

    constexpr int16_t AlarmIconX = 122;
    constexpr int16_t AlarmIconYOffset = 6;

    constexpr int16_t IconWidth = 8;
    constexpr int16_t IconHeight = 8;
}

static const uint8_t wifiIconConnected[] PROGMEM =
{
    0b00000000,
    0b01111110,
    0b10000001,
    0b00111100,
    0b01000010,
    0b00011000,
    0b00011000,
    0b00000000
};

static const uint8_t wifiIconDisconnected[] PROGMEM =
{
    0b10000001,
    0b01000010,
    0b00100100,
    0b00011000,
    0b00100100,
    0b01000010,
    0b10000001,
    0b00000000
};

void Display::begin()
{
    Wire.begin(Pins::Display::Sda, Pins::Display::Scl);

    if (!oled.begin(OledAddress, true))
    {
        Serial.println("OLED initialization failed");
        initialized = false;
        return;
    }

    initialized = true;

    oled.clearDisplay();
    oled.setTextColor(SH110X_WHITE);
    oled.setTextSize(1);

    Serial.println("Display module initialized");
}

void Display::update()
{
    // Display update logic will be added later.
}

void Display::render(const DisplayData& data)
{
    if (!initialized)
    {
        return;
    }

    oled.clearDisplay();

    drawTemperatureLine(
        0,
        0,
        "AKVA",
        data.waterTemperature,
        data.waterTemperatureAlarm
    );

    drawTemperatureLine(
        0,
        24,
        "MIST",
        data.roomTemperature,
        data.roomTemperatureAlarm
    );

    drawWifiIcon(WifiIconX, WifiIconY, data.wifiConnected);

    oled.display();
}

void Display::drawTemperatureLine(
    int16_t x,
    int16_t y,
    const char* label,
    const TemperatureReading& reading,
    bool alarmActive
)
{
    oled.setTextSize(2);
    oled.setCursor(x, y);

    oled.print(label);
    oled.print(" ");

    if (reading.valid)
    {
        oled.print(reading.valueCelsius, 1);
        oled.print("C");
    }
    else
    {
        oled.print("ERR");
    }

    if (alarmActive)
    {
        oled.setCursor(120, y);
        oled.print("!");
    }
}



void Display::drawWifiIcon(int16_t x, int16_t y, bool connected)
{
    oled.drawBitmap(
        x,
        y,
        connected ? wifiIconConnected : wifiIconDisconnected,
        IconWidth,
        IconHeight,
        SH110X_WHITE
    );
}
