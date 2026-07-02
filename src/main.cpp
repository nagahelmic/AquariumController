#include <Arduino.h>
#include <Version.h>
#include <Config.h>

Config::Settings settings;

void setup() {
    Serial.begin(115200);

    Serial.println();
    Serial.println("==============================");
    Serial.println(Version::Name);
    Serial.println("Version: ");
    Serial.println(Version::String);
    Serial.println("==============================");

    Serial.println("Config:");

    Serial.print("Min temperature: ");
    Serial.println(settings.temperature.minTemperature);

    Serial.print("Max temperature: ");
    Serial.println(settings.temperature.maxTemperature);

    Serial.print("Measurement interval: ");
    Serial.print(settings.temperature.measurementIntervalMs);
    Serial.println(" ms");

    Serial.print("Display brightness: ");
    Serial.println(settings.display.brightness);

    Serial.print("Alarm enabled: ");
    Serial.println(settings.alarm.enabled ? "yes" : "no");
}

void loop(){
    delay(1000);
}