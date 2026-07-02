#pragma once

#include "Config.h"
#include "Display.h"

class Application
{
public:
    void begin();
    void update();

private:
    Config::Settings settings;
    Display display;
};