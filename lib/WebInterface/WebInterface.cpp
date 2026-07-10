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
    webData = data;
}

String WebInterface::buildStatusJson() const
{
    String json;

    json += "{";

    json += "\"waterTemperature1\":{";
    json += "\"valueCelsius\":";
    json += webData.waterTemperature1.valid ? String(webData.waterTemperature1.valueCelsius, 1) : "null";
    json += ",\"valid\":";
    json += webData.waterTemperature1.valid ? "true" : "false";
    json += "},";

    json += "\"waterTemperature2\":{";
    json += "\"valueCelsius\":";
    json += webData.waterTemperature2.valid ? String(webData.waterTemperature2.valueCelsius, 1) : "null";
    json += ",\"valid\":";
    json += webData.waterTemperature2.valid ? "true" : "false";
    json += "},";

    json += "\"wifiConnected\":";
    json += webData.wifiConnected ? "true" : "false";
    json += ",";

    json += "\"uptimeSeconds\":";
    json += String(webData.uptimeSeconds);

    json += "}";

    return json;
}