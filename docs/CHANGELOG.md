# Changelog

All notable changes to this project will be documented here.

## v0.7.0 - Web Interface

### Added

#### Web Interface
- Added `WebInterface` module.
- Added ESPAsyncWebServer support.
- Added AsyncTCP dependency.
- Added LittleFS filesystem support.
- Added static frontend files in `data/`.
- Added local read-only dashboard.
- Added `/api/status` JSON endpoint.
- Added `WebData` structure for web output data.

#### Frontend
- Added `index.html`.
- Added `style.css`.
- Added `app.js`.
- Added automatic status refresh using JavaScript `fetch()`.

#### API
- Added JSON output for water temperature readings.
- Added JSON output for sensor validity state.
- Added JSON output for Wi-Fi connection state.
- Added JSON output for uptime.

### Changed

#### Application
- Integrated `WebInterface` module.
- Added `updateWebData()` helper method.
- Added `WebData` update flow from `Application`.

### Documentation
- Added ADR-017 for local read-only Web Interface.

### Tested
- Successfully built firmware with ESPAsyncWebServer.
- Successfully uploaded firmware to ESP32.
- Successfully uploaded LittleFS filesystem image.
- Successfully loaded web dashboard from ESP32.
- Successfully tested `/api/status` JSON endpoint.
- Successfully verified valid temperature display on web dashboard.
- Successfully verified sensor error display on web dashboard.

## v0.6.0 - Wi-Fi

### Added

#### Wi-Fi
- Added `WifiConnection` module.
- Added Wi-Fi connection initialization.
- Added non-blocking Wi-Fi update logic.
- Added Wi-Fi connection state tracking.
- Added non-blocking reconnect support.
- Added Wi-Fi reconnect interval configuration.
- Added IP address output to Serial Monitor.

#### Secrets
- Added `Secrets.example.h` template.
- Added local `Secrets.h` support for Wi-Fi credentials.
- Added Git ignore rule for `Secrets.h`.

#### Display Integration
- Added Wi-Fi connection state to `DisplayData`.
- Added Wi-Fi status icon on OLED.
- Added connected and disconnected icon states.

### Changed

#### Application
- Integrated `WifiConnection` module.
- Updated `updateDisplayData()` to use real Wi-Fi connection state.
- Added `wifi.update(settings.wifi)` to the main update loop.

### Tested
- Successfully connected ESP32 to Wi-Fi.
- Successfully printed IP address to Serial Monitor.
- Successfully tested failed connection attempts with invalid credentials.
- Successfully tested non-blocking reconnect behavior.
- Successfully verified Wi-Fi status icon on OLED.

## v0.5.0 - Display Integration

### Changed

#### Display
- Improved main screen layout.
- Made temperature readings the primary content on the OLED display.
- Removed inactive Wi-Fi and alarm indicators from the main screen.
- Extracted temperature line rendering into a dedicated helper method.

#### Display Integration
- Display now focuses only on currently implemented functionality.
- Invalid temperature readings continue to be displayed as `ERROR`.

### Tested
- Successfully tested improved OLED layout.
- Successfully verified valid temperature rendering.
- Successfully verified invalid temperature rendering.
- Successfully tested layout on real SH1106 OLED hardware.

---
## v0.4.0 - Temperature

### Added

#### Temperature
- Added dedicated `Temperature` module.
- Added OneWire bus initialization.
- Added DallasTemperature library integration.
- Added DS18B20 sensor detection.
- Added DS18B20 sensor address scanning.
- Added fixed-address DS18B20 sensor reading.
- Added support for two configured water temperature sensors.
- Added `TemperatureReading` structure with value and validity state.
- Added invalid sensor handling.
- Added temperature measurement timer using `IntervalTimer`.

#### Display Integration
- Updated `DisplayData` to use `TemperatureReading`.
- Display now shows real measured temperature values.
- Display now shows `ERROR` when a temperature reading is invalid.

#### Configuration
- Added DS18B20 sensor addresses to temperature configuration.
- Reused existing temperature measurement interval configuration.

### Changed

#### Application
- Added `Temperature` module integration.
- Added `temperatureMeasurementTimer`.
- Updated `updateDisplayData()` to use measured temperature readings instead of test values.

### Documentation
- Added ADR-014 for keeping the `Temperature` module focused on measurement only.
- Added ADR-015 for representing temperature readings with validity state.
- Added ADR-016 for identifying DS18B20 sensors by address.

### Tested
- Successfully detected two DS18B20 sensors.
- Successfully read temperature values from both sensors.
- Successfully displayed real temperature values on OLED.
- Successfully tested one disconnected sensor state.
- Successfully tested both disconnected sensors state.
- Successfully verified recovery after reconnecting sensors.

---


## v0.3.0 - Display

### Added

#### Display
- Added dedicated `Display` module.
- Added SH1106 OLED support.
- Added OLED initialization.
- Added first OLED rendering output.
- Added `DisplayData` structure for display rendering.
- Added `render(const DisplayData& data)` API.
- Added display refresh interval configuration.

#### Timing
- Added reusable `IntervalTimer` class.
- Added non-blocking timing based on `millis()`.

### Changed

#### Application
- Moved display rendering from `Application::begin()` to `Application::update()`.
- Added `updateDisplayData()` helper method.
- Replaced blocking `delay()` with non-blocking interval timing.

#### Display
- Removed repeated Serial logging from `Display::render()`.
- Display now renders data received from `Application` instead of using hardcoded values only.

### Documentation
- Updated ADR-012 with display ownership and `DisplayData` rendering contract.
- Added ADR-013 for non-blocking interval timing.

---

## v0.2.0 - Project Foundation (In Progress)

### Added

#### Core

- Added `Version` module.
- Added `Config` module.
- Added `Application` module.

#### Architecture

- Introduced modular configuration design.
- Introduced `Config` namespace.
- Added `Settings` structure.
- Split configuration into:
  - `Temperature`
  - `Display`
  - `Alarm`
- Introduced `Application` as the main firmware controller.

#### Documentation

- Added Architecture Decision Records (ADR-008 to ADR-011).

#### Testing

- Successfully built firmware.
- Successfully tested on real ESP32 hardware.

---

## v0.1.0 - Project initialization

### Added

- VS Code project
- PlatformIO
- ESP32 configuration
- Library configuration
- Initial roadmap
- github 
