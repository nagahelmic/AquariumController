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
    temperature.begin();
    
}

void Application::update()
{
    const uint32_t now = millis();

    display.update();

    if (temperatureMeasurementTimer.isReady(now, settings.temperature.measurementIntervalMs))
    {
        temperature.update(settings.temperature);
    }

    if (displayRefreshTimer.isReady(now, settings.display.refreshIntervalMs))
    {
        updateDisplayData();
        display.render(displayData);
    }
}

 void Application::updateDisplayData()
 {
    //Temperature Senzor 1
    displayData.waterTemperature1 = temperature.getWaterTemperature1();
    //Temperature Senzor 2
    displayData.waterTemperature2 = temperature.getWaterTemperature2();

    displayData.wifiConected = false;
    displayData.alarmActive = false;
 }