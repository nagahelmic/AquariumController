#include "Application.h"

#include <Arduino.h>

#include "Secrets.h"
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

        alarm.update(
            settings.alarm,
            temperature.getWaterTemperature1(),
            temperature.getWaterTemperature2()
        );
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
    const AlarmState alarmState = alarm.getState();

    displayData.waterTemperature1 = temperature.getWaterTemperature1();
    displayData.waterTemperature2 = temperature.getWaterTemperature2();

    displayData.wifiConnected = wifi.isConnected();

    displayData.waterTemperature1Alarm =
        alarmState.waterTemperature1Low ||
        alarmState.waterTemperature1High ||
        alarmState.waterTemperature1Invalid;

    displayData.waterTemperature2Alarm =
        alarmState.waterTemperature2Low ||
        alarmState.waterTemperature2High ||
        alarmState.waterTemperature2Invalid;
}

void Application::updateWebData()
{
    webData.waterTemperature1 = temperature.getWaterTemperature1();
    webData.waterTemperature2 = temperature.getWaterTemperature2();

    webData.wifiConnected = wifi.isConnected();
    webData.uptimeSeconds = millis() / 1000;

    webData.alarmState = alarm.getState();
}