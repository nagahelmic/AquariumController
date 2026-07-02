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
    oled.setCursor(0, 0);
    oled.println("Display OK");
    oled.display();

    Serial.println("Display module initialized");
}

void Display::update()
{
    // Display update logic will be added later.
}

void Display::render() {
    
    oled.clearDisplay();

    oled.setTextSize(1);
    oled.setCursor(0, 0);
    oled.println("AquariumController");

    oled.setCursor(0, 16);
    oled.println("Display test");

    oled.setCursor(0, 32);
    oled.println("OLED SH1106 OK");

    oled.display();

    Serial.println("Display render called");
}