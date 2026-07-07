#pragma once

class WifiConnection
{
public:
    void begin(const char* ssid, const char* password);
    void update();

    bool isConnected() const;

private:
    bool connectionStarted = false;
    bool lastConnectedState = false;
};