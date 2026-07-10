#include "Display.h"
#include <Arduino.h>
#include <Wire.h>
#include "Pins.h"

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

    if (!oled.begin(0x3C, true)) {
        Serial.println("OLED initialization failed");
        return;
    }

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
    oled.clearDisplay();

    drawTemperatureLine(
        0,
        0,
        "T1",
        data.waterTemperature1,
        data.waterTemperature1Alarm
    );

    drawTemperatureLine(
        0,
        24,
        "T2",
        data.waterTemperature2,
        data.waterTemperature2Alarm
    );

    drawWifiIcon(120, 56, data.wifiConnected);

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
    oled.print(": ");

    if (reading.valid)
    {
        oled.print(reading.valueCelsius, 1);
        oled.println(" C");
    }
    else
    {
        oled.println("ERROR");
    }

    if (alarmActive)
    {
        oled.setTextSize(1);
        oled.setCursor(122, y + 6);
        oled.print("!");
    }
}

void Display::drawWifiIcon(int16_t x, int16_t y, bool connected)
{
    oled.drawBitmap(
        x,
        y,
        connected ? wifiIconConnected : wifiIconDisconnected,
        8,
        8,
        SH110X_WHITE
    );
}