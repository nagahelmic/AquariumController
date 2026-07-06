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
    
}

void Application::update()
{
    const uint32_t now = millis();

    display.update();

    if (displayRefreshTimer.isReady(now, settings.display.refreshIntervalMs))
    {
        updateDisplayData();
        display.render(displaydata);
    }
}

 void Application::updateDisplayData()
 {
    displaydata.waterTemperature1 = 24.5f;
    displaydata.waterTemperature2 = 24.8f;
    displaydata.wifiConected = false;
    displaydata.alarmActive = false;
 }