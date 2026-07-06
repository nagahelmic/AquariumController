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
