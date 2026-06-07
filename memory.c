//
// Created by Karim Makhlouf on 05/06/2026.
//

#include "memory.h"
#include <stdio.h>

uint8_t memory[0x10000];

uint8_t read(uint16_t address) {
    return memory[address];
}

void write(uint16_t address, uint8_t value) {
    if (address == 0xFF02 && value == 0x81) {
        printf("%c", memory[0xFF01]);
        fflush(stdout);
    }
    memory[address] = value;
}