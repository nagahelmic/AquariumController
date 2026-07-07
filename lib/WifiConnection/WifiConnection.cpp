#include "WifiConnection.h"

#include <Arduino.h>
#include <WiFi.h>

void WifiConnection::begin(const char* ssid, const char* password)
{
    Serial.println("WiFi connecting...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    connectionStarted = true;
}

void WifiConnection::update()
{
    if (!connectionStarted)
    {
        return;
    }

    const bool connected = isConnected();

    if (connected == lastConnectedState)
    {
        return;
    }

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

bool WifiConnection::isConnected() const
{
    return WiFi.status() == WL_CONNECTED;
}