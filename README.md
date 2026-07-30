# Emuchip8

Emuchip8 is a CHIP-8 interpreter written in C++20 with SDL2 for display and keyboard input.

The implementation follows the classic 4 KiB, 64×32 CHIP-8 model and includes the 35 commonly documented opcodes.

## Implementation

- 4,096-byte memory with ROMs loaded at `0x200`
- 16 general-purpose registers, index register, program counter, and 16-level stack
- built-in hexadecimal font data at `0x50`
- table-driven opcode dispatch
- XOR sprite drawing with collision state stored in `VF`
- delay and sound timer registers
- SDL2-backed texture rendering and keypad input

The emulator state lives in `Chip8`. `Cycle()` fetches a two-byte opcode, advances the program counter, dispatches through the opcode tables, and updates the timers. `Platform` owns the SDL window, renderer, texture, and input mapping.

## Build

Requirements:

- CMake 3.8 or newer
- a C++20 compiler
- SDL2 with a CMake package configuration

The included setup scripts install SDL2 through the available system package manager or vcpkg:

```bash
./install_sdl2.sh        # Linux or macOS
```

```powershell
.\install_sdl2.ps1       # Windows
```

Configure and build:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

If CMake cannot locate SDL2, pass the vcpkg toolchain or an SDL2 installation prefix during configuration.

The executable is emitted in the repository root.

## Run

```bash
./Emuchip8 <scale> <cycle-delay-ms> <rom>
```

For example:

```bash
./Emuchip8 15 2 Tetris.ch8
./Emuchip8 20 1 "Space Intercept [Joseph Weisbecker, 1978].ch8"
```

`scale` controls the window size. `cycle-delay-ms` sets the minimum time between interpreter cycles.

## Key mapping

```text
CHIP-8          keyboard
1 2 3 C         1 2 3 4
4 5 6 D         Q W E R
7 8 9 E         A S D F
A 0 B F         Z X C V
```

Press `Escape` to exit.

## Source layout

```text
Emuchip8/
  Chip8.cpp          interpreter and opcode implementations
  include/Chip8.h    machine state and dispatch tables
  include/Platform.h SDL2 display and input wrapper
  main.cpp           timing and execution loop
```

## Current limitations

- timer registers are decremented once per interpreter cycle rather than by an independent 60 Hz clock
- the sound timer has no audio output
- CHIP-8 compatibility quirks are not configurable
- ROM size and malformed input are not validated
- there is no automated opcode or compatibility test suite

