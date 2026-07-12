#pragma once

#include <cstdint>

#include <DallasTemperature.h>
#include <OneWire.h>

#include "Config.h"
#include "TemperatureReading.h"

class Temperature
{
public:
    Temperature();

    void begin();
    void requestMeasurement(uint32_t now);
    bool update(uint32_t now, const Config::Temperature& config);

    TemperatureReading getWaterTemperature1() const;
    TemperatureReading getWaterTemperature2() const;

private:
    TemperatureReading readSensor(const uint8_t* address);

    void printSensorAddresses();
    void printAddress(const uint8_t* address);

    OneWire oneWire;
    DallasTemperature sensors;

    TemperatureReading waterTemperature1;
    TemperatureReading waterTemperature2;

    uint32_t conversionStartedMs = 0;
    uint16_t conversionWaitMs = 0;
    bool conversionInProgress = false;
};
