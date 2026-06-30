# Architecture Decisions

This document records important technical decisions made during the project.

---

## ADR-001

### Decision

Use PlatformIO instead of Arduino IDE.

### Reason

- Better project structure
- Library management
- Git integration
- Professional development workflow

---

## ADR-002

### Decision

Use modular architecture.

### Reason

Each module has a single responsibility.

Examples:

- Temperature
- Display
- WiFi
- Web