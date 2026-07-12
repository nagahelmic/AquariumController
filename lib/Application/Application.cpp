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
    mqtt.begin(
        settings.mqtt,
        Secrets::MqttUsername,
        Secrets::MqttPassword
    );
    wifi.begin(Secrets::WifiSsid, Secrets::WifiPassword);
    webInterface.begin();
    ota.begin(settings.ota.hostname, Secrets::OtaPassword);
}

void Application::update()
{
    const uint32_t now = millis();

    display.update();
    wifi.update(settings.wifi);
    mqtt.update(wifi.isConnected());
    ota.update(wifi.isConnected());

    if (temperatureMeasurementTimer.isReady(now, settings.temperature.measurementIntervalMs))
    {
        temperature.requestMeasurement(now);
    }

    if (temperature.update(now, settings.temperature))
    {
        alarm.update(
            settings.alarm,
            temperature.getWaterTemperature(),
            temperature.getRoomTemperature()
        );
    }

    updateWebData();
    webInterface.update(webData);

    if (mqttPublishTimer.isReady(now, settings.mqtt.publishIntervalMs))
    {
        mqtt.publish(
            temperature.getWaterTemperature(),
            temperature.getRoomTemperature(),
            alarm.getState()
        );
    }

    if (displayRefreshTimer.isReady(now, settings.display.refreshIntervalMs))
    {
        updateDisplayData();
        display.render(displayData);
    }
}

void Application::updateDisplayData()
{
    const AlarmState alarmState = alarm.getState();

    displayData.waterTemperature = temperature.getWaterTemperature();
    displayData.roomTemperature = temperature.getRoomTemperature();

    displayData.wifiConnected = wifi.isConnected();

    displayData.waterTemperatureAlarm =
        alarmState.waterTemperatureLow ||
        alarmState.waterTemperatureHigh ||
        alarmState.waterTemperatureInvalid;

    displayData.roomTemperatureAlarm =
        alarmState.roomTemperatureLow ||
        alarmState.roomTemperatureHigh ||
        alarmState.roomTemperatureInvalid;
}

void Application::updateWebData()
{
    webData.waterTemperature = temperature.getWaterTemperature();
    webData.roomTemperature = temperature.getRoomTemperature();

    webData.wifiConnected = wifi.isConnected();
    webData.uptimeSeconds = millis() / 1000;

    webData.alarmState = alarm.getState();
}
