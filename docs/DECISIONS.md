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