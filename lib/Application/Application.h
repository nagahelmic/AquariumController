#pragma once

#include "Config.h"
#include "Display.h"
#include "DisplayData.h"
#include "IntervalTimer.h"

class Application
{
public:
    void begin();
    void update();

private:
    void updateDisplayData();

    Config::Settings settings;
    Display display;
    DisplayData displaydata;

    IntervalTimer displayRefreshTimer;
};