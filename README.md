# 🐠 AquariumController

![Version](https://img.shields.io/badge/Version-1.0.0-blue)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino-green)
![Status](https://img.shields.io/badge/Status-Stable-brightgreen)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

A modular ESP32-based aquarium monitoring controller.

AquariumController monitors two water temperatures, displays the current
state on an OLED screen and provides a local web dashboard.

## Features

- Two DS18B20 temperature sensors
- SH1106 OLED display
- Wi-Fi with automatic reconnection
- Responsive local web dashboard
- JSON status API
- Low, high and invalid-sensor alarms
- OTA firmware updates
- Non-blocking modular firmware

## Hardware

- ESP32 DevKitC, 38-pin
- 2× waterproof DS18B20
- 1.3-inch SH1106 I2C OLED
- 4.7 kΩ pull-up resistor

See [HARDWARE.md](docs/HARDWARE.md) for wiring and sensor configuration.

## Getting started

1. Copy `include/Secrets.example.h` to `include/Secrets.h`.
2. Enter the Wi-Fi credentials and OTA password.
3. Update the DS18B20 addresses in `include/Config.h` if necessary.
4. Upload the firmware:

```bash
pio run --environment esp32dev --target upload
```

5. Upload the web interface to LittleFS:

```bash
pio run --environment esp32dev --target uploadfs
```

The assigned IP address is printed to the serial monitor. Open it in a browser
to access the dashboard.

## OTA updates

Set the ESP32 IP address in the `esp32dev_ota` environment in `platformio.ini`
and provide the OTA password:

```powershell
$env:AQUARIUM_OTA_PASSWORD = "YOUR_OTA_PASSWORD"
pio run --environment esp32dev_ota --target upload
```

A DHCP reservation is recommended so the device keeps the same IP address.

## Version 1.0.0

The first stable release includes temperature monitoring, OLED and web
output, Wi-Fi reconnection, alarms and OTA updates.

Equipment control, historical data, MQTT and Home Assistant integration are
planned for future versions.

## Documentation

- [Roadmap](docs/ROADMAP.md)
- [Requirements](docs/REQUIREMENTS.md)
- [Architecture](docs/ARCHITECTURE.md)
- [Hardware](docs/HARDWARE.md)
- [Architecture decisions](docs/DECISIONS.md)
- [Changelog](docs/CHANGELOG.md)

## License

MIT License
