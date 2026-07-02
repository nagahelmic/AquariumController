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

    display.begin();
    display.render();
}

void Application::update()
{
    display.update();
    delay(1000);
}