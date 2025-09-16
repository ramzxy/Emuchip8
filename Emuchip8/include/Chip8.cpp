#include <fstream>
#include "Chip8.h"
#include <vector>

const unsigned int START_ADDRESS = 0x200;

void Chip8::loadROM(char const* fileName) {
	// Open the file using ifstream, turn into binray and move file pointer to eof
	std::ifstream file(fileName, std::ios::binary);

	if (file.is_open()) {
		// Using a C++17+ approach to read the file stream into a char vector safe
		std::vector<char> buffer(std::istreambuf_iterator<char>(file), {});



	}
}