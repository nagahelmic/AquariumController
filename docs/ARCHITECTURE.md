# AquariumController Architecture

## Goal

Create a modular, maintainable and extensible aquarium controller based on ESP32.

The application should be easy to understand, test and extend.

---

# High Level Architecture

Application
│
├── Temperature
├── Display
├── WiFi
├── Web
├── Storage
├── Logger
└── Alarm

Each module has only one responsibility.

---

# Project Structure

AquariumController

├── docs
├── include
├── lib
├── src
└── test

---

# Modules

## Temperature

Responsibilities

- Read DS18B20 sensors
- Detect disconnected sensors
- Store current values

Does NOT

- Draw display
- Handle WiFi
- Handle Web

---

## Display

Responsibilities

- OLED initialization
- Draw information
- Screen refresh

Does NOT

- Read sensors
- Handle WiFi

---

## WiFi

Responsibilities

- Connect to WiFi
- Reconnect
- Provide network status

---

## Web

Responsibilities

- HTTP server
- Web pages
- JSON API

---

## Storage

Responsibilities

- Save configuration
- Load configuration

---

## Alarm

Responsibilities

- Temperature limits
- Notifications
- Buzzer
