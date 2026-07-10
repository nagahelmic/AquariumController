# 🗺 AquariumController Roadmap

Project roadmap and development milestones.

---

# v0.1.0 - Project Initialization ✅

## Development Environment

- [x] VS Code
- [x] PlatformIO
- [x] GitHub
- [x] PlatformIO build successful

## Documentation

- [x] README
- [x] ROADMAP
- [x] REQUIREMENTS
- [x] ARCHITECTURE
- [x] HARDWARE
- [x] DECISIONS
- [x] CHANGELOG
- [x] IDEAS

Status: **Completed**

---

# v0.2.0 - Project Foundation

## Core

- [x] Create `Version.h`
- [x] Create `Config.h`
- [x] Create `Pins.h`

## Architecture

- [x] Create Application module
- [x] Prepare project skeleton

Status: **Completed**

---

# v0.3.0 - Display

## OLED

- [x] Create Display module
- [x] Display initialization
- [x] Display test

Status: **Completed**

---

# v0.4.0 - Temperature

## Temperature Sensors
- [x] Create `Temperature` module
- [x] Initialize OneWire bus
- [x] Initialize DallasTemperature library
- [x] Detect DS18B20 sensors
- [x] Print DS18B20 sensor addresses
- [x] Identify DS18B20 sensors by fixed hardware address
- [x] Read temperature values from configured sensor addresses
- [x] Store readings as `TemperatureReading`
- [x] Handle invalid or disconnected sensors
- [x] Add temperature measurement interval using `IntervalTimer`
- [x] Pass measured temperature data to `DisplayData`
- [x] Show real temperature values on OLED
- [x] Show `ERROR` when a sensor is disconnected

Status: **Completed**

---

# v0.5.0 - Display Integration

## Display Rendering
- [x] Display real temperature readings from `Temperature` module
- [x] Display invalid temperature readings as `ERROR`
- [x] Extract temperature line rendering into helper method
- [x] Improve main screen layout
- [x] Make temperature values the primary display content
- [x] Remove inactive Wi-Fi and alarm indicators from main screen

Status: **Completed**

---

# v0.6.0 - Wi-Fi

## Wi-Fi Connection
- [x] Add local `Secrets.h` for Wi-Fi credentials
- [x] Add `Secrets.example.h` template
- [x] Ignore `Secrets.h` in Git
- [x] Create `WifiConnection` module
- [x] Connect ESP32 to Wi-Fi
- [x] Print Wi-Fi connection status to Serial Monitor
- [x] Print ESP32 IP address
- [x] Add Wi-Fi configuration
- [x] Add non-blocking Wi-Fi update logic
- [x] Add non-blocking reconnect logic
- [x] Pass Wi-Fi connection state to `DisplayData`
- [x] Show Wi-Fi connection state on OLED using icon

Status: **Completed**

---

# v0.7.0 - Web Interface

## Web Dashboard
- [x] Add ESPAsyncWebServer support
- [x] Add AsyncTCP dependency
- [x] Add LittleFS filesystem support
- [x] Store frontend files in `data/`
- [x] Add `index.html`
- [x] Add `style.css`
- [x] Add `app.js`
- [x] Create `WebInterface` module
- [x] Create `WebData` structure
- [x] Serve local dashboard from ESP32
- [x] Add `/api/status` JSON endpoint
- [x] Show temperature values on web dashboard
- [x] Show sensor error state on web dashboard
- [x] Show Wi-Fi connection state on web dashboard
- [x] Show uptime on web dashboard

Status: **Completed**

---

# v0.8.0 - OTA Updates

## Over-The-Air Updates
- [x] Add OTA password to local `Secrets.h`
- [x] Add OTA password template to `Secrets.example.h`
- [x] Create `OtaUpdater` module
- [x] Initialize ArduinoOTA after Wi-Fi connection
- [x] Handle OTA updates in main update loop
- [x] Add PlatformIO OTA environment
- [x] Configure OTA upload over Wi-Fi
- [x] Test OTA firmware upload using IP address
- [x] Keep USB upload environment available as fallback

Status: **Completed**

---

# v0.9.0 - Alarm System

## Alarm Evaluation
- [x] Move temperature alarm thresholds to `Config::Alarm`
- [x] Create `AlarmState`
- [x] Create `Alarm` module
- [x] Evaluate low temperature state
- [x] Evaluate high temperature state
- [x] Evaluate invalid sensor state
- [x] Expose detailed alarm state through `/api/status`

## Display Integration
- [x] Add per-temperature alarm indicators to `DisplayData`
- [x] Show alarm indicator on OLED temperature lines

## Web Integration
- [x] Add alarm state to web dashboard
- [x] Show alarm banner when alarm is active
- [x] Show sensor error state on web dashboard
- [x] Show low/high temperature alarm text on web dashboard

Status: **Completed**

---

# v1.0.0 - First Stable Release

- [ ] Stable firmware
- [ ] Documentation complete
- [ ] Release on GitHub

Status: **Future**

---

# 🔮 Future

- [ ] MQTT
- [ ] Home Assistant
- [ ] Temperature history
- [ ] Graphs
- [ ] pH sensor
- [ ] Water level sensor
- [ ] Conductivity sensor
- [ ] Heater control
- [ ] Lighting control
- [ ] Mobile notifications