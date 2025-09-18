# Emuchip8 - CHIP-8 Emulator

A C++ implementation of the CHIP-8 virtual machine, designed to run classic CHIP-8 games and programs.

## Overview

CHIP-8 is an interpreted programming language that was first used on some microcomputers in the mid-1970s. It was made to allow video games to be more easily programmed for these computers. This emulator recreates the CHIP-8 system, allowing you to run original CHIP-8 programs on modern hardware.

## Features

- **Complete CHIP-8 Instruction Set**: Implements all 35 standard CHIP-8 opcodes
- **Memory Management**: 4KB RAM with proper memory mapping
- **Display System**: 64x32 pixel monochrome display
- **Input Handling**: 16-key hexadecimal keypad support
- **Timers**: Delay and sound timer implementation
- **Font System**: Built-in hexadecimal sprite font (0-F)
- **ROM Loading**: Support for loading CHIP-8 ROM files

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

## Instruction Set

The emulator supports all standard CHIP-8 instructions including:

- **System Operations**: Clear screen (CLS), Return from subroutine (RET)
- **Flow Control**: Jump (JP), Call subroutine (CALL), Skip instructions (SE, SNE)
- **Register Operations**: Load (LD), Add (ADD), Bitwise operations (OR, AND, XOR)
- **Memory Operations**: Load/Store register arrays, BCD conversion
- **Display**: Draw sprites with collision detection
- **Input**: Key press detection and waiting
- **Timers**: Timer manipulation and reading

## Building

This project uses CMake for building and requires C++20 support.

### Prerequisites

- CMake 3.8 or higher
- C++20 compatible compiler (Visual Studio 2019+, GCC 10+, Clang 10+)

### Build Instructions

1. Clone the repository:
```bash
git clone <repository-url>
cd Emuchip8
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Generate build files:
```bash
cmake ..
```

4. Build the project:
```bash
cmake --build .
```

## Usage

Currently, the emulator is in development. The main executable will be available after building:

```bash
./Emuchip8 [rom_file]
```

## Project Structure

```
Emuchip8/
├── CMakeLists.txt          # Root CMake configuration
├── CMakePresets.json       # Visual Studio CMake presets
├── README.md              # This file
├── Emuchip8/              # Source code directory
│   ├── CMakeLists.txt     # Executable CMake configuration
│   ├── main.cpp           # Main entry point
│   └── include/           # Header and implementation files
│       ├── Chip8.h        # CHIP-8 class declaration
│       └── Chip8.cpp      # CHIP-8 class implementation
└── out/                   # Build output directory
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

## Development Status

The emulator core is implemented with:

- ✅ Complete instruction set structure
- ✅ Memory management
- ✅ Register system
- ✅ Basic arithmetic and logic operations
- ✅ Display drawing with collision detection
- ✅ Font system
- ✅ ROM loading capability
- ⚠️ Input handling (partial implementation)
- ⚠️ Timer operations (partial implementation)
- ❌ Audio output
- ❌ User interface
- ❌ Configuration options

## Resources

- [CHIP-8 Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)
- [CHIP-8 Wikipedia](https://en.wikipedia.org/wiki/CHIP-8)
- [Awesome CHIP-8](https://github.com/tobiasvl/awesome-chip-8)

