#include "Application.h"
#include <Arduino.h>
#include "Version.h"

void Application::begin()
{
    Serial.println();
    Serial.println("==============================");
    Serial.println(Version::Name);
    Serial.print("Version: ");
    Serial.println(Version::String);
    Serial.println("==============================");

    Serial.println("Application started");
}

void Application::update()
{
    delay(1000);
}