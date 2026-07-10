#pragma once

#include "Config.h"
#include "Display.h"
#include "DisplayData.h"
#include "IntervalTimer.h"
#include "Temperature.h"
#include "WifiConnection.h"
#include "WebData.h"
#include "WebInterface.h"
#include "OtaUpdater.h"

class Application
{
public:
    void begin();
    void update();

private:
    void updateWebData();
    void updateDisplayData();

    Config::Settings settings;
    Display display;
    DisplayData displayData;
    WebData webData;

    IntervalTimer displayRefreshTimer;
    IntervalTimer temperatureMeasurementTimer;

    Temperature temperature;
    WifiConnection wifi;
    WebInterface webInterface;
    OtaUpdater ota;
};