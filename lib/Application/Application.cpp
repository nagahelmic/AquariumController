#include "Application.h"
#include <Arduino.h>
#include "Version.h"
#include "Pins.h"

void Application::begin()
{
    Serial.println();
    Serial.println("==============================");
    Serial.println(Version::Name);
    Serial.print("Version: ");
    Serial.println(Version::String);
    Serial.println("==============================");

    Serial.println("Application started");

    Serial.println("Pins:");
    Serial.print("OLED SDA: ");
    Serial.println(Pins::Display::Sda);

    Serial.print("OLED SCL: ");
    Serial.println(Pins::Display::Scl);

    Serial.print("OneWire bus: ");
    Serial.println(Pins::Temperature::OneWireBus);
}

void Application::update()
{
    delay(1000);
}