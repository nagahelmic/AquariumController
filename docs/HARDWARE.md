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

## Temperature Sensors

2 × DS18B20

---

## Planned Hardware

- Relay module
- Water level sensor
- pH sensor
- Conductivity sensor
- Fan