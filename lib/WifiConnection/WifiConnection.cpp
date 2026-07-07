#include "WifiConnection.h"

#include <Arduino.h>
#include <WiFi.h>

void WifiConnection::begin(const char* ssid, const char* password)
{
    this->ssid = ssid;
    this->password = password;
    configured = true;

    startConnection();
}

void WifiConnection::update(const Config::Wifi& config)
{
    if (!configured)
    {
        return;
    }

    const bool connected = isConnected();

    if (connected != lastConnectedState)
    {
        lastConnectedState = connected;

        if (connected)
        {
            Serial.println("WiFi connected");
            Serial.print("IP address: ");
            Serial.println(WiFi.localIP());
        }
        else
        {
            Serial.println("WiFi disconnected");
        }
    }

    if (!connected && millis() - lastConnectionAttemptMs >= config.reconnectIntervalMs)
    {
        startConnection();
    }
}

bool WifiConnection::isConnected() const
{
    return WiFi.status() == WL_CONNECTED;
}

void WifiConnection::startConnection()
{
    lastConnectionAttemptMs = millis();

    Serial.println("WiFi connecting...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
}