#include "Temperature.h"

#include <Arduino.h>

#include "Pins.h"

namespace
{
    constexpr uint8_t SensorAddressLength = 8;
}

Temperature::Temperature()
    : oneWire(Pins::Temperature::OneWireBus),
      sensors(&oneWire)
{
}

void Temperature::begin()
{
    sensors.begin();
    sensors.setWaitForConversion(false);
    conversionWaitMs = sensors.millisToWaitForConversion();

    Serial.println("Temperature module initialized");
    Serial.print("DS18B20 sensors found: ");
    Serial.println(sensors.getDeviceCount());

    printSensorAddresses();
}

void Temperature::requestMeasurement(uint32_t now)
{
    if (conversionInProgress)
    {
        return;
    }

    sensors.requestTemperatures();
    conversionStartedMs = now;
    conversionInProgress = true;
}

bool Temperature::update(
    uint32_t now,
    const Config::Temperature& config
)
{
    if (!conversionInProgress ||
        now - conversionStartedMs < conversionWaitMs)
    {
        return false;
    }

    waterTemperature = readSensor(config.waterSensorAddress);
    roomTemperature = readSensor(config.roomSensorAddress);

    conversionInProgress = false;

    return true;
}

TemperatureReading Temperature::getWaterTemperature() const
{
    return waterTemperature;
}

TemperatureReading Temperature::getRoomTemperature() const
{
    return roomTemperature;
}

TemperatureReading Temperature::readSensor(const uint8_t* address)
{
    TemperatureReading reading;

    if (!sensors.isConnected(address))
    {
        return reading;
    }

    const float value = sensors.getTempC(address);

    if (value == DEVICE_DISCONNECTED_C)
    {
        return reading;
    }

    reading.valueCelsius = value;
    reading.valid = true;

    return reading;
}

void Temperature::printSensorAddresses()
{
    DeviceAddress address;

    for (uint8_t index = 0; index < sensors.getDeviceCount(); index++)
    {
        Serial.print("Sensor ");
        Serial.print(index);
        Serial.print(" address: ");

        if (sensors.getAddress(address, index))
        {
            printAddress(address);
            Serial.println();
        }
        else
        {
            Serial.println("ERROR");
        }
    }
}

void Temperature::printAddress(const uint8_t* address)
{
    for (uint8_t index = 0; index < SensorAddressLength; index++)
    {
        if (address[index] < 16)
        {
            Serial.print("0");
        }

        Serial.print(address[index], HEX);

        if (index < SensorAddressLength - 1)
        {
            Serial.print(" ");
        }
    }
}
