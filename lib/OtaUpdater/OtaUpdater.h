#pragma once

class OtaUpdater
{
public:
    void begin(const char* hostname, const char* password);
    void update(bool wifiConnected);

    bool isStarted() const;

private:
    void start();

    const char* hostname = nullptr;
    const char* password = nullptr;

    bool configured = false;
    bool started = false;
};