# Architecture Decisions

This document records important technical decisions made during the project.

---

# ADR-001

## Decision

Use PlatformIO instead of Arduino IDE.

## Reason

- Better project structure
- Built-in library management
- Excellent Git integration
- Professional development workflow
- Easier scalability for larger projects

---

# ADR-002

## Decision

Use a modular software architecture.

## Reason

Each module has a single responsibility.

Current planned modules:

- Core
- Display
- Temperature
- WiFi
- Web

Benefits:

- Easier maintenance
- Better readability
- Independent testing
- Future scalability

---

# ADR-003

## Decision

Use standard C++ headers whenever possible.

Example:

```cpp
#include <cstdint>
```

instead of:

```cpp
#include <Arduino.h>
```

## Reason

Keeping header files independent from the Arduino framework improves portability, reduces unnecessary dependencies and follows modern C++ practices.

---

# ADR-004

## Decision

Use fixed-width integer types from `<cstdint>`.

Preferred types:

| Type | Usage |
|------|-------|
| bool | Boolean values |
| uint8_t | Pins, version numbers, small counters |
| uint16_t | Medium-sized values |
| uint32_t | Timers, millis(), counters |
| float | Temperature and sensor values |
| int | Only when exact width is not important or signed values are required |

## Reason

Fixed-width integer types provide:

- predictable memory usage
- platform-independent behavior
- clearer intent
- better readability

Example:

```cpp
uint8_t oledSdaPin;
uint32_t lastUpdate;
```

instead of:

```cpp
int oledSdaPin;
long lastUpdate;
```

---

# ADR-005

## Decision

Prefer `constexpr` over `#define` for constants.

Example:

```cpp
constexpr uint8_t OledSdaPin = 21;
```

instead of:

```cpp
#define OLED_SDA_PIN 21
```

## Reason

`constexpr`:

- is type-safe
- is checked by the compiler
- is visible in the debugger
- belongs to the C++ language
- provides better readability

`#define` should only be used for:

- conditional compilation (`#ifdef`)
- build flags
- library configuration

---

# ADR-006

## Decision

Use `#pragma once` in every header file.

## Reason

It is simpler and more readable than traditional include guards.

Example:

```cpp
#pragma once
```

instead of:

```cpp
#ifndef VERSION_H
#define VERSION_H

...

#endif
```

Supported by all modern compilers used in this project.

---

# ADR-007

## Decision

Keep `main.cpp` as small as possible.

## Reason

Business logic should never be implemented directly inside `main.cpp`.

Target structure:

```cpp
void setup()
{
    app.begin();
}

void loop()
{
    app.update();
}
```

This improves readability, maintainability and testability.

# ADR-008

## Decision

Choose the C++ abstraction based on the responsibility of the component.

## Rules

- Use `namespace` for logical grouping of constants and utility functions.
- Use `struct` for simple data structures.
- Use `class` for objects with behavior, encapsulation and responsibility.

## Reason

Choosing the correct abstraction improves readability, maintainability and scalability.

The decision is based on the purpose of the component rather than implementation details.

Examples:

Version -> namespace

Pins -> namespace

Config -> struct

TemperatureReading -> struct

DisplayManager -> class

TemperatureManager -> class

# ADR-009

## Decision

Configuration is represented as a `struct`.

## Reason

Configuration values can change during runtime and may later be loaded from or saved to non-volatile memory.

Therefore configuration is data, not a collection of constants.

Examples:

- Temperature limits
- Wi-Fi credentials
- Display settings
- Measurement interval

# ADR-010

## Decision

Configuration is divided into smaller configuration structures.

## Reason

A single large configuration structure would become hard to read and maintain as the project grows.

Smaller configuration structures improve:

- readability
- maintainability
- module separation
- future web configuration
- future storage handling

Examples:

- TemperatureConfig
- DisplayConfig
- AlarmConfig
- WifiConfig

The main Config structure combines smaller configuration parts.

# ADR-011

## Decision

Use `Application` as the main firmware controller class.

## Reason

`Application` owns the main runtime structure of the firmware.

It is responsible for:

- holding global application settings
- initializing modules
- calling module update functions
- keeping `main.cpp` small

It must not contain hardware-specific logic directly.

Hardware features such as display, temperature, Wi-Fi and web server will be implemented in separate modules.

# ADR-012: Use Display as a dedicated display module

## Decision

The OLED display is controlled by a dedicated `Display` class.

The `Display` module is responsible for:

- initializing the OLED display,
- owning the display driver/library object,
- rendering data to the screen.

Display rendering data is passed through a dedicated `DisplayData` structure:

`include/DisplayData.h`

The `Display` module receives this data through:

`render(const DisplayData& data)`

## Reason

The display is a separate hardware component with its own initialization and rendering logic.

Keeping this logic inside a dedicated `Display` class keeps `Application` simple and prevents display-specific code from spreading across the project.

`DisplayData` acts as a clear contract between `Application` and `Display`.

The `Display` module should not read sensors, Wi-Fi state or alarm state directly.  
Those values are collected by `Application` and passed to `Display` as rendering data.

This keeps modules loosely coupled and easier to change later.

# ADR-013: Use non-blocking interval timing

## Decision

Periodic tasks will use non-blocking timing based on `millis()`.

A reusable `IntervalTimer` class is used to decide whether a task should run.

Example:

```cpp
if (displayRefreshTimer.isReady(now, settings.display.refreshIntervalMs))
{
    updateDisplayData();
    display.render(displayData);
}