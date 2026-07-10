![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino-green)
![IDE](https://img.shields.io/badge/IDE-PlatformIO-orange)
![Status](https://img.shields.io/badge/Status-In_Development-yellow)
![License](https://img.shields.io/badge/License-MIT-lightgrey)
# 🐠 AquariumController

> **A modular ESP32-based aquarium controller designed for long-term development.**

---

# 🚧 Project Status

## Current Status

Current project version:

**v0.8.0 – OTA Updates**

Completed modules:

- ✅ Version
- ✅ Config
- ✅ Pins
- ✅ Application
- ✅ Display
- ✅ Timing
- ✅ Temperature
- ✅ Wi-Fi
- ✅ Web Interface
- ✅ OTA Updates

Next milestone:

**v0.9.0 – Alarm System**


---
## OTA Upload

OTA upload is available through the `esp32dev_ota` PlatformIO environment.

The current OTA upload target uses the ESP32 IP address:

```ini
upload_port = your_assigned_ip_addres
```
If the router assigns a different IP address, upload_port must be updated.

For stable OTA uploads, it is recommended to configure DHCP reservation for the ESP32 in the router.

---
# ✨ Planned Features

## Core

- 🌡 Water temperature monitoring
- 📺 OLED display
- 📶 Wi-Fi connectivity
- 🌐 Embedded web interface

## Monitoring

- 📈 Temperature history
- 📊 Graphs
- 📝 Logging

## Control

- 🔥 Heater control
- 💡 Lighting control
- 🌬 Cooling fan
- 🚨 Temperature alarms

## Integration

- ☁ OTA firmware updates
- 📡 MQTT
- 🏠 Home Assistant

---

# 🔧 Current Hardware

| Component | Status |
|-----------|:------:|
| ESP32 DevKitC (38 pin) | ✅ |
| 2 × DS18B20 | ✅ |
| 1.3" OLED SH1106 (I2C) | ✅ |

---

# 🛠 Technologies

| Technology | Purpose |
|------------|---------|
| ESP32 | Main controller |
| Arduino Framework | Firmware |
| PlatformIO | Build system |
| Visual Studio Code | IDE |
| Git | Version control |
| GitHub | Repository |
| Markdown | Documentation |

---

# 📂 Project Structure

```
AquariumController
│
├── docs
├── include
├── lib
├── src
├── test
└── data
```

---

# 📚 Documentation

| Document | Description |
|----------|-------------|
| ROADMAP.md | Project roadmap |
| REQUIREMENTS.md | Functional requirements |
| ARCHITECTURE.md | Software architecture |
| HARDWARE.md | Hardware overview |
| DECISIONS.md | Architecture Decision Records |
| CHANGELOG.md | Project history |
| IDEAS.md | Future ideas |

---

# 🏗 Development Workflow

```
Requirements
      ↓
Architecture
      ↓
Implementation
      ↓
Testing
      ↓
Commit
      ↓
Documentation
```

---

# 📌 Project Principles

This project follows several simple rules:

- 🎯 Design before implementation
- 📦 One module = one responsibility
- 🧪 Test every module independently
- 🔄 Small incremental changes
- 📚 Keep documentation up to date
- 🚫 No "magic numbers"
- ⚙ Configuration stored in one place
- 🧹 Keep `main.cpp` as small as possible

---


# 📄 License

MIT License