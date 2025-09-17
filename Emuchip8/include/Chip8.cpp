#include <fstream>
#include "Chip8.h"
#include <vector>

const unsigned int START_ADDRESS = 0x200;

const unsigned int FONTSET_SIZE = 80;
const unsigned int FONTSET_START_ADDRESS = 0x50;

uint8_t fontset[FONTSET_SIZE] =
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

Chip8::Chip8()
	: randGen(std::chrono::system_clock::now().time_since_epoch().count()),
		randByte(0, 255U)
{
	// Initialize program counter at start address of instructions
	pc = START_ADDRESS;

	// Load fontset on ROM
	for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
	{
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}
}

void Chip8::loadROM(char const* fileName) {
	// Open the file using ifstream, turn into binray and move file pointer to eof
	std::ifstream file(fileName, std::ios::binary);

	if (file.is_open()) {
		// read the file stream into a char vector safe
		std::vector<char> buffer(std::istreambuf_iterator<char>(file), {});
		int size = buffer.size();

		for (long i = 0; i < size; ++i) {
			memory[START_ADDRESS + i] = buffer[i];
		}

		//buffer is cleaned when out of scope
	}
}

void Chip8::OP_00E0()
{
}

void Chip8::OP_00EE()
{
}

void Chip8::OP_1nnn()
{
}

void Chip8::OP_2nnn()
{
}

void Chip8::OP_3xkk()
{
}

void Chip8::OP_4xkk()
{
}

void Chip8::OP_5xy0()
{
}

void Chip8::OP_6xkk()
{
}

void Chip8::OP_7xkk()
{
}

void Chip8::OP_8xy0()
{
}

void Chip8::OP_8xy1()
{
}

void Chip8::OP_8xy2()
{
}

void Chip8::OP_8xy3()
{
}

void Chip8::OP_8xy4()
{
}

void Chip8::OP_8xy6()
{
}

void Chip8::OP_8xy7()
{
}

void Chip8::OP_8xyE()
{
}

void Chip8::OP_9xy0()
{
}

void Chip8::OP_Annn()
{
}

void Chip8::OP_Bnnn()
{
}

void Chip8::OP_Cxkk()
{
}

void Chip8::OP_Dxyn()
{
}

void Chip8::OP_Ex9E()
{
}

void Chip8::OP_ExA1()
{
}

void Chip8::OP_Fx07()
{
}

void Chip8::OP_Fx0A()
{
}

void Chip8::OP_Fx15()
{
}

void Chip8::OP_Fx18()
{
}

void Chip8::OP_Fx1E()
{
}

void Chip8::OP_Fx29()
{
}

void Chip8::OP_Fx33()
{
}

void Chip8::OP_Fx55()
{
}

void Chip8::OP_Fx65()
{
}
