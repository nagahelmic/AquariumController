#include "Application.h"
#include <Arduino.h>
#include "Version.h"
#include "Pins.h"
#include "Secrets.h"

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
    wifi.begin(Secrets::WifiSsid, Secrets::WifiPassword);
    webInterface.begin();
    ota.begin(settings.ota.hostname, Secrets::OtaPassword);
    
}

void Application::update()
{
    const uint32_t now = millis();

    display.update();
    wifi.update(settings.wifi);
    ota.update(wifi.isConnected());

    if (temperatureMeasurementTimer.isReady(now, settings.temperature.measurementIntervalMs))
    {
        temperature.update(settings.temperature);

        alarm.update(settings.alarm, temperature.getWaterTemperature1(), temperature.getWaterTemperature2());
    }

    updateWebData();
    webInterface.update(webData);

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

    displayData.wifiConnected = wifi.isConnected();
    displayData.alarmActive = alarm.getState().active;
 }

 void Application::updateWebData()
{
    webData.waterTemperature1 = temperature.getWaterTemperature1();
    webData.waterTemperature2 = temperature.getWaterTemperature2();

    webData.wifiConnected = wifi.isConnected();
    webData.uptimeSeconds = millis() / 1000;

     webData.alarmState = alarm.getState();
}