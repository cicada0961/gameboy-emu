//
// Created by Karim Makhlouf on 05/06/2026.
//

#include "memory.h"

uint8_t memory[0x10000];

uint8_t read(uint16_t address) {
    return memory[address];
}

void write(uint16_t address, uint8_t value) {
    memory[address] = value;
}