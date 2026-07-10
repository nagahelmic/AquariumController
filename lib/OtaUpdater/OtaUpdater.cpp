#include "OtaUpdater.h"

#include <Arduino.h>
#include <ArduinoOTA.h>

void OtaUpdater::begin(const char* hostname, const char* password)
{
    this->hostname = hostname;
    this->password = password;
    configured = true;
}

void OtaUpdater::update(bool wifiConnected)
{
    if (!configured)
    {
        return;
    }

    if (!wifiConnected)
    {
        return;
    }

    if (!started)
    {
        start();
    }

    ArduinoOTA.handle();
}

bool OtaUpdater::isStarted() const
{
    return started;
}

void OtaUpdater::start()
{
    ArduinoOTA.setHostname(hostname);
    ArduinoOTA.setPassword(password);

    ArduinoOTA.onStart([]()
    {
        Serial.println("OTA update started");
    });

    ArduinoOTA.onEnd([]()
    {
        Serial.println();
        Serial.println("OTA update finished");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
    {
        Serial.printf("OTA progress: %u%%\r", (progress * 100) / total);
    });

    ArduinoOTA.onError([](ota_error_t error)
    {
        Serial.printf("OTA error [%u]: ", error);

        if (error == OTA_AUTH_ERROR)
        {
            Serial.println("Auth failed");
        }
        else if (error == OTA_BEGIN_ERROR)
        {
            Serial.println("Begin failed");
        }
        else if (error == OTA_CONNECT_ERROR)
        {
            Serial.println("Connect failed");
        }
        else if (error == OTA_RECEIVE_ERROR)
        {
            Serial.println("Receive failed");
        }
        else if (error == OTA_END_ERROR)
        {
            Serial.println("End failed");
        }
    });

    ArduinoOTA.begin();

    started = true;

    Serial.print("OTA updater started: ");
    Serial.println(hostname);
}