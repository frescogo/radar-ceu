# Plan: Organize Repository

## Goal

Reorganize the repository with proper folder structure, meaningful
file names, and a README describing each file.

## File Analysis

| Current File | Purpose |
|---|---|
| `main.ceu` | Main app (Ceu): grid UI with logos, player names, icons |
| `main.mar` | Main app (Mar): same UI, partially commented out |
| `fp.ceu` | Functional utilities: map, concat, intercalate, etc. |
| `serial-01.ceu` | Basic serial test: reads raw chars from 2 ports |
| `serial-02.ceu` | Full radar protocol: parses 23-byte messages, displays speed/direction |
| `x-01.c` | C test: reads serial byte-by-byte (non-blocking) |
| `x-02.c` | C test: reads serial in bulk |
| `arduino-01/arduino-01.ino` | Arduino: sends sequential ASCII chars (echo test) |
| `arduino-02/arduino-02.ino` | Arduino: sends a fixed 23-byte radar message |
| `arduino-03/arduino-03.ino` | Arduino: sends random radar messages (simulator) |
| `tiny.ttf` | Font used by serial-radar.ceu for display |

## Proposed Structure

```
radar-ceu/
├── README.md
├── src/
│   ├── main.ceu
│   ├── main.mar
│   ├── fp.ceu
│   ├── serial-basic.ceu       (was serial-01.ceu)
│   └── serial-radar.ceu       (was serial-02.ceu)
├── arduino/
│   ├── echo-test/              (was arduino-01)
│   │   └── echo-test.ino
│   ├── radar-fixed/            (was arduino-02)
│   │   └── radar-fixed.ino
│   └── radar-random/           (was arduino-03)
│       └── radar-random.ino
├── tests/
│   ├── serial-read.c           (was x-01.c)
│   └── serial-bulk.c           (was x-02.c)
└── assets/
    └── tiny.ttf
```

## Renames

- `serial-01.ceu` -> `serial-basic.ceu`: reads/prints raw chars
- `serial-02.ceu` -> `serial-radar.ceu`: full radar protocol
- `arduino-01` -> `echo-test`: simple echo/serial test
- `arduino-02` -> `radar-fixed`: fixed radar message on loop
- `arduino-03` -> `radar-random`: randomized radar messages
- `x-01.c` -> `serial-read.c`: reads serial one byte at a time
- `x-02.c` -> `serial-bulk.c`: reads serial in bulk

## Status

- [x] Plan saved
- [x] Folder structure created
- [x] Files moved and renamed
- [x] README.md created
- [ ] Committed and pushed
