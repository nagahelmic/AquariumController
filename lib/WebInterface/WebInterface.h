#pragma once

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

#include "WebData.h"

class WebInterface
{
public:
    WebInterface();

    void begin();
    void update(const WebData& data);

private:
    String buildStatusJson() const;
    WebData getWebDataSnapshot() const;

    AsyncWebServer server;
    WebData webData;
    mutable portMUX_TYPE webDataMutex = portMUX_INITIALIZER_UNLOCKED;
};
