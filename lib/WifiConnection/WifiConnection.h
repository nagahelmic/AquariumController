#pragma once

#include <cstdint>

#include "Config.h"

class WifiConnection
{
public:
    void begin(const char* ssid, const char* password);
    void update(const Config::Wifi& config);

    bool isConnected() const;

private:
    void startConnection();

    const char* ssid = nullptr;
    const char* password = nullptr;

    bool configured = false;
    bool lastConnectedState = false;

    uint32_t lastConnectionAttemptMs = 0;
};