#include <cstdint>
#include <chrono>
#include <random>

class Chip8 {
public:
	uint8_t registers[16]{};
	uint8_t memory[4096]{};
	uint16_t index{};
	uint16_t pc{};
	uint16_t stack[16]{};
	uint8_t sp{};
	uint8_t delayTimer{};
	uint8_t soundTimer{};
	uint8_t keypad[16]{};
	uint32_t video[64 * 32]{};
	uint16_t opcode;



	// General methods
	Chip8();
	void loadROM(char const*);

	// Commands

	// 00E0: CLS
	void OP_00E0();

	// 00EE: RET
	void OP_00EE();

	// 1nnn: JP addr
	void OP_1nnn();

	// 2nnn - CALL addr
	void OP_2nnn();

	// 3xkk - SE Vx, byte
	void OP_3xkk();

	// 4xkk - SNE Vx, byte
	void OP_4xkk();

	//5xy0 - SE Vx, Vy
	void OP_5xy0();

	// 6xkk - LD Vx, byte
	void OP_6xkk();

	// 7xkk - ADD Vx, byte
	void OP_7xkk();

	// 8xy0 - LD Vx, Vy
	void OP_8xy0();

	// 8xy1 - OR Vx, Vy
	void OP_8xy1();

	// 8xy2 - AND Vx, Vy
	void OP_8xy2();

	// 8xy3 - XOR Vx, Vy
	void OP_8xy3();

	// 8xy4 - ADD Vx, Vy
	void OP_8xy4();

	// 8xy5 - SUB Vx, Vy
	void OP_8xy4();

	// 8xy6 - SHR Vx
	void OP_8xy6();

	// 8xy7 - SUBN Vx, Vy
	void OP_8xy7();

	// 8xyE - SHL Vx {, Vy}
	void OP_8xyE();

	// 9xy0 - SNE Vx, Vy
	void OP_9xy0();

	// Annn - LD I, addr
	void OP_Annn();

	// Bnnn - JP V0, addr
	void OP_Bnnn();

	// Cxkk - RND Vx, byte
	void OP_Cxkk();

	// Dxyn - DRW Vx, Vy, nibble
	void OP_Dxyn();

	// Ex9E - SKP Vx
	void OP_Ex9E();

	// ExA1 - SKNP Vx
	void OP_ExA1();

	// Fx07 - LD Vx, DT
	void OP_Fx07();

	// Fx0A - LD Vx, K
	void OP_Fx0A();

	// Fx15 - LD DT, Vx
	void OP_Fx15();

	// Fx18 - LD ST, Vx
	void OP_Fx18();

	// Fx1E - ADD I, Vx
	void OP_Fx1E();

	// Fx29 - LD F, Vx
	void OP_Fx29();

	// Fx33 - LD B, Vx
	void OP_Fx33();

	// Fx55 - LD [I], Vx
	void OP_Fx55();

	// Fx65 - LD Vx, [I]
	void OP_Fx65();

private:
	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;
};