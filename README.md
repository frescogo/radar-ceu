# FrescoGO Radar

Speed radar application for sports, built with
[Ceu](https://github.com/fsantanna/ceu).

## Directory Structure

```
radar-ceu/
├── src/            Ceu/Mar source files
├── arduino/        Arduino sketches for radar hardware
├── tests/          C test programs for serial communication
└── assets/         Fonts and other resources
```

## Source Files (`src/`)

| File | Description |
|---|---|
| `main.ceu` | Main application in Ceu. Grid-based UI layout (1280x720) with logos, player names, and icons. |
| `main.mar` | Main application in Mar (alternative version, partially disabled). |
| `fp.ceu` | Functional programming utilities: `map`, `concat`, `intercalate`, `drop-first`, `drop-last`, `take-first`. |
| `serial-basic.ceu` | Basic serial reader. Opens two serial ports (`/dev/ttyACM0`, `/dev/ttyACM1`), reads raw characters, and broadcasts them. |
| `serial-radar.ceu` | Full radar protocol. Parses 23-byte radar frames (sync byte `0x88`, direction, speed), displays live speed and direction arrows on screen. |

## Arduino Sketches (`arduino/`)

| Sketch | Description |
|---|---|
| `echo-test/` | Sends sequential ASCII characters over serial at 9600 baud. Simple connectivity test. |
| `radar-fixed/` | Sends a fixed 23-byte radar message in a loop. Useful for testing the parser with known data. |
| `radar-random/` | Sends randomized radar messages (random direction and speed). Simulates a real radar sensor. |

## Test Programs (`tests/`)

| File | Description |
|---|---|
| `serial-read.c` | Reads serial data byte-by-byte from `/dev/ttyACM0` in non-blocking mode. Prints each character as received. |
| `serial-bulk.c` | Reads serial data in bulk from `/dev/ttyACM0`. Prints received buffers. |

## Assets (`assets/`)

| File | Description |
|---|---|
| `tiny.ttf` | Font used by `serial-radar.ceu` for on-screen display of speed and direction. |
