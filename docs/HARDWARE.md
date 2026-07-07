# Hardware

## ESP32

Board:
ESP32 DevKitC 38 pin

---

## Display

1.3"
SH1106
I2C

#### Preferované piny
- I2C → GPIO21 (SDA), GPIO22 (SCL)
- OneWire → GPIO4 (pokud nebude důvod použít jiný)

#### Nepoužívat
- GPIO6–11 (Flash)
- GPIO1 a GPIO3 (UART)
- GPIO0 (BOOT), pokud to není nezbytné


## DS18B20 Temperature Sensors

Two waterproof DS18B20 temperature sensors are connected to one shared OneWire bus.

### Wiring

| DS18B20 | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| DATA | GPIO4 |

A 4.7 kΩ pull-up resistor is connected between DATA and 3V3.

### Sensor Addresses

| Sensor | Address |
|---|---|
| Water Sensor 1 | `28 44 9F E0 42 25 06 BB` |
| Water Sensor 2 | `28 8A 53 31 7B 24 0B D3` |

---

## Planned Hardware

- Relay module
- Water level sensor
- pH sensor
- Conductivity sensor
- Fan