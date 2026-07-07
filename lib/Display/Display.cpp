#include "Display.h"
#include <Arduino.h>
#include <Wire.h>
#include "Pins.h"

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

void Display::render(const DisplayData& data) {
    
    oled.clearDisplay();

    oled.setTextSize(1);

    oled.setCursor(0, 0);
    oled.println("AquariumController");

    drawTemperatureLine(0, 16, "T1", data.waterTemperature1);
    drawTemperatureLine(0, 28, "T2", data.waterTemperature2);
    
    oled.setCursor(0, 44);
    oled.print("Wifi: ");
    oled.println(data.wifiConected ? "OK" : "OFF");

    oled.setCursor(0, 56);
    oled.print("Alarm: ");
    oled.println(data.alarmActive ? "YES" : "NO");

    oled.display();

}

void Display::drawTemperatureLine(
    int16_t x,
    int16_t y,
    const char* label,
    const TemperatureReading& reading
)
{
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
}