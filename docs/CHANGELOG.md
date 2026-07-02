# Changelog

All notable changes to this project will be documented here.

---

## v0.1.0 - Project initialization

### Added

- VS Code project
- PlatformIO
- ESP32 configuration
- Library configuration
- Initial roadmap
- github 

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