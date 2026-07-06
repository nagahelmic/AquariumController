![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino-green)
![IDE](https://img.shields.io/badge/IDE-PlatformIO-orange)
![Status](https://img.shields.io/badge/Status-In_Development-yellow)
![License](https://img.shields.io/badge/License-MIT-lightgrey)
# 🐠 AquariumController

> **A modular ESP32-based aquarium controller designed for long-term development.**

---

# 🚧 Project Status

**Current Version:** `v0.3.0`

**Development Progress**

```text
█░░░░░░░░░ 30%
```

Completed modules:

- ✅ Version
- ✅ Config
- ✅ Pins
- ✅ Application
- ✅ Display
- ✅ Timing

Next milestone:

**v0.4.0 – Temperature**

---

# 🎯 Project Vision

AquariumController is an open-source project focused on creating a **professional, modular and expandable aquarium controller** based on ESP32.

The goal is not only to build an aquarium thermometer, but a complete control system that can grow over time.

The project is designed to be:

- ✅ Modular
- ✅ Well documented
- ✅ Easy to maintain
- ✅ Easy to extend
- ✅ Open source

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

# 🗺 Current Roadmap

## Phase 0 – Development Environment

- ✅ VS Code
- ✅ PlatformIO
- ✅ Git
- ✅ GitHub
- ✅ Build successful

---

## Phase 1 – Project Foundation

- 🚧 Documentation
- ⬜ Basic architecture
- ⬜ Core configuration

---

## Next Milestone

🎯 **Create the project foundation**

- Config
- Version
- Pins
- Project architecture

---

# 🚀 Long-Term Vision

AquariumController should eventually become a complete aquarium automation platform supporting multiple sensors, automation, web management and smart-home integration.

The architecture is designed to allow adding new modules without changing existing code.

---

# 📄 License

MIT License