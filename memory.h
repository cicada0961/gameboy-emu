//
// Created by Karim Makhlouf on 05/06/2026.
//

#include <stdint.h>

#ifndef GAMEBOY_MEMORY_H
#define GAMEBOY_MEMORY_H

extern uint8_t memory[0x10000];

uint8_t read(uint16_t address);
void write(uint16_t address, uint8_t value);

#endif //GAMEBOY_MEMORY_H
