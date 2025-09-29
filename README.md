# Emuchip8 - CHIP-8 Emulator

A C++ implementation of the CHIP-8 virtual machine using SDL2, designed to run classic CHIP-8 games and programs.

## Overview

CHIP-8 is an interpreted programming language that was first used on some microcomputers in the mid-1970s. It was made to allow video games to be more easily programmed for these computers. This emulator recreates the CHIP-8 system, allowing you to run original CHIP-8 programs on modern hardware.

## Features

- **Complete CHIP-8 Instruction Set**: Implements all 35 standard CHIP-8 opcodes
- **SDL2 Graphics**: Hardware-accelerated rendering with configurable scaling
- **Memory Management**: 4KB RAM with proper memory mapping
- **Display System**: 64x32 pixel monochrome display with pixel-perfect scaling
- **Input Handling**: 16-key hexadecimal keypad mapped to keyboard
- **Timers**: 60Hz delay and sound timer implementation
- **Font System**: Built-in hexadecimal sprite font (0-F)
- **ROM Loading**: Support for loading CHIP-8 ROM files (.ch8)

## System Specifications

The emulator faithfully recreates the original CHIP-8 specifications:

- **Memory**: 4096 bytes (4KB)
- **Display**: 64x32 pixels, monochrome
- **Registers**: 16 8-bit general purpose registers (V0-VF)
- **Stack**: 16 levels for subroutine calls
- **Timers**: 60Hz delay and sound timers
- **Input**: 16-key hexadecimal keypad
- **Program Counter**: 16-bit
- **Index Register**: 16-bit (I register)

## Controls

The CHIP-8 keypad is mapped to your keyboard as follows:

```
CHIP-8 Keypad    Keyboard
1 2 3 C          1 2 3 4
4 5 6 D    =>    Q W E R
7 8 9 E          A S D F
A 0 B F          Z X C V
```

- **ESC**: Quit emulator

## Prerequisites

- **Windows**: Visual Studio 2019+ or equivalent C++20 compiler
- **Linux/macOS**: GCC 10+ or Clang 10+
- **CMake**: 3.8 or higher
- **SDL2**: Development libraries (automatically installed via scripts)

## Building

### Quick Setup (Windows)

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ramzxy/Emuchip8.git
   cd Emuchip8
   ```

2. **Install SDL2 (run as administrator):**
   ```powershell
   .\install_sdl2.ps1
   ```

3. **Build the project:**
   ```bash
   cmake -B out/build/x64-debug -S . -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE=C:/Users/[YourUsername]/vcpkg/scripts/buildsystems/vcpkg.cmake
   cmake --build out/build/x64-debug --config Debug
   ```

### Quick Setup (Linux/macOS)

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ramzxy/Emuchip8.git
   cd Emuchip8
   ```

2. **Install SDL2:**
   ```bash
   ./install_sdl2.sh
   ```

3. **Build the project:**
   ```bash
   cmake -B build -S .
   cmake --build build
   ```

## Usage

Run the emulator with the following command:

```bash
./Emuchip8.exe <Scale> <Delay> <ROM_file>
```

### Parameters

- **Scale**: Window scaling factor (recommended: 10-20)
  - `10` = 640x320 window
  - `15` = 960x480 window  
  - `20` = 1280x640 window
- **Delay**: Milliseconds between CPU cycles (recommended: 1-5)
- **ROM_file**: Path to your CHIP-8 game file (.ch8)

### Examples

```bash
# Play Tetris with 15x scaling and 2ms delay
./Emuchip8.exe 15 2 "Tetris.ch8"

# Play Space Intercept with 20x scaling and 1ms delay  
./Emuchip8.exe 20 1 "Space Intercept [Joseph Weisbecker, 1978].ch8"
```

## Project Structure

```
Emuchip8/
├── CMakeLists.txt              # Root CMake configuration
├── CMakePresets.json           # Visual Studio CMake presets
├── README.md                   # This file
├── Emuchip8.exe               # Built executable
├── install_sdl2.ps1           # Windows SDL2 installer
├── install_sdl2.sh            # Linux/macOS SDL2 installer
├── *.ch8                      # Sample CHIP-8 games
├── Emuchip8/                  # Source code directory
│   ├── CMakeLists.txt         # Executable CMake configuration
│   ├── main.cpp               # Main entry point and game loop
│   ├── Chip8.cpp              # CHIP-8 emulator implementation
│   └── include/               # Header files
│       ├── Chip8.h            # CHIP-8 class declaration
│       └── Platform.h         # SDL2 platform wrapper
└── out/                       # Build output directory
```

## Implementation Details

### Memory Layout

- `0x000-0x1FF`: Reserved for interpreter (font data stored at 0x50-0x9F)
- `0x200-0xFFF`: Program ROM and work RAM

### Registers

- **V0-VE**: General purpose 8-bit registers
- **VF**: Flag register (used for carry, borrow, and collision detection)
- **I**: 16-bit index register
- **PC**: Program counter
- **SP**: Stack pointer

### Display System

The display uses a 64x32 pixel array where each pixel can be on (white) or off (black). Sprites are drawn using XOR logic, enabling collision detection when pixels overlap.

## Sample Games Included

- **Tetris**: Classic falling blocks puzzle game
- **Space Intercept**: Shoot the UFOs before they land

## Development Status

✅ **Complete Features:**
- Complete CHIP-8 instruction set
- Memory management and ROM loading
- SDL2-based graphics with scaling
- Keyboard input handling
- Timer system implementation
- Font system and sprite rendering
- Collision detection

## Troubleshooting

### Common Issues

1. **"SDL2 not found"**: Run the appropriate install script for your platform
2. **Small window**: Increase the scale parameter (try 15-20)
3. **Game runs too fast/slow**: Adjust the delay parameter (1-10ms)
4. **Build errors**: Ensure you have C++20 support and correct CMake toolchain

### Getting CHIP-8 Games

You can find CHIP-8 games at:
- [CHIP-8 Archive](https://www.zophar.net/pdroms/chip8.html)
- [CHIP-8 Games Pack](https://github.com/kripod/chip8-roms)

## Resources

- [CHIP-8 Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)
- [CHIP-8 Wikipedia](https://en.wikipedia.org/wiki/CHIP-8)
- [Awesome CHIP-8](https://github.com/tobiasvl/awesome-chip-8)

## License

This project is open source. Feel free to use, modify, and distribute.