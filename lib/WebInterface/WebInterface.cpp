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

    json += "\"waterTemperature1\":{";
    json += "\"valueCelsius\":";
    json += (snapshot.waterTemperature1.valid ? String(snapshot.waterTemperature1.valueCelsius, 1) : "null");
    json += ",\"valid\":";
    json += (snapshot.waterTemperature1.valid ? "true" : "false");
    json += "},";

    json += "\"waterTemperature2\":{";
    json += "\"valueCelsius\":";
    json += (snapshot.waterTemperature2.valid ? String(snapshot.waterTemperature2.valueCelsius, 1) : "null");
    json += ",\"valid\":";
    json += (snapshot.waterTemperature2.valid ? "true" : "false");
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

    json += "\"waterTemperature1Low\":";
    json += snapshot.alarmState.waterTemperature1Low ? "true" : "false";
    json += ",";

    json += "\"waterTemperature1High\":";
    json += snapshot.alarmState.waterTemperature1High ? "true" : "false";
    json += ",";

    json += "\"waterTemperature1Invalid\":";
    json += snapshot.alarmState.waterTemperature1Invalid ? "true" : "false";
    json += ",";

    json += "\"waterTemperature2Low\":";
    json += snapshot.alarmState.waterTemperature2Low ? "true" : "false";
    json += ",";

    json += "\"waterTemperature2High\":";
    json += snapshot.alarmState.waterTemperature2High ? "true" : "false";
    json += ",";

    json += "\"waterTemperature2Invalid\":";
    json += snapshot.alarmState.waterTemperature2Invalid ? "true" : "false";

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
