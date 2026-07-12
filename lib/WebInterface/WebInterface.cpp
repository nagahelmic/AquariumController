#include "WebInterface.h"

#include <LittleFS.h>

WebInterface::WebInterface()
    : server(80)
{
}

void WebInterface::begin()
{
    if (!LittleFS.begin(true))
    {
        Serial.println("LittleFS mount failed");
    }
    else
    {
        Serial.println("LittleFS mounted");
    }

    server.on("/api/status", HTTP_GET, [this](AsyncWebServerRequest* request)
    {
        request->send(200, "application/json", buildStatusJson());
    });

    server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

    server.onNotFound([](AsyncWebServerRequest* request)
    {
        request->send(404, "text/plain", "Not found");
    });

    server.begin();

    Serial.println("Web interface started");
}

void WebInterface::update(const WebData& data)
{
    portENTER_CRITICAL(&webDataMutex);
    webData = data;
    portEXIT_CRITICAL(&webDataMutex);
}

String WebInterface::buildStatusJson() const
{
    const WebData snapshot = getWebDataSnapshot();
    String json;

    json += "{";

    json += "\"waterTemperature\":{";
    json += "\"valueCelsius\":";
    json += (snapshot.waterTemperature.valid ? String(snapshot.waterTemperature.valueCelsius, 1) : "null");
    json += ",\"valid\":";
    json += (snapshot.waterTemperature.valid ? "true" : "false");
    json += "},";

    json += "\"roomTemperature\":{";
    json += "\"valueCelsius\":";
    json += (snapshot.roomTemperature.valid ? String(snapshot.roomTemperature.valueCelsius, 1) : "null");
    json += ",\"valid\":";
    json += (snapshot.roomTemperature.valid ? "true" : "false");
    json += "},";

    json += "\"wifiConnected\":";
    json += (snapshot.wifiConnected ? "true" : "false");
    json += ",";

    json += "\"uptimeSeconds\":";
    json += String(snapshot.uptimeSeconds);
    json += ",";

    json += "\"alarm\":{";

    json += "\"active\":";
    json += (snapshot.alarmState.active ? "true" : "false");
    json += ",";

    json += "\"waterTemperatureLow\":";
    json += snapshot.alarmState.waterTemperatureLow ? "true" : "false";
    json += ",";

    json += "\"waterTemperatureHigh\":";
    json += snapshot.alarmState.waterTemperatureHigh ? "true" : "false";
    json += ",";

    json += "\"waterTemperatureInvalid\":";
    json += snapshot.alarmState.waterTemperatureInvalid ? "true" : "false";
    json += ",";

    json += "\"roomTemperatureLow\":";
    json += snapshot.alarmState.roomTemperatureLow ? "true" : "false";
    json += ",";

    json += "\"roomTemperatureHigh\":";
    json += snapshot.alarmState.roomTemperatureHigh ? "true" : "false";
    json += ",";

    json += "\"roomTemperatureInvalid\":";
    json += snapshot.alarmState.roomTemperatureInvalid ? "true" : "false";

    json += "}";

    json += "}";

    return json;
}

WebData WebInterface::getWebDataSnapshot() const
{
    portENTER_CRITICAL(&webDataMutex);
    const WebData snapshot = webData;
    portEXIT_CRITICAL(&webDataMutex);

    return snapshot;
}
