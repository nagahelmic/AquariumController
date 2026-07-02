#pragma once

#include "Config.h"

class Application
{
public:
    void begin();
    void update();

private:
    Config::Settings settings;
};