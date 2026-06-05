//
// Created by Karim Makhlouf on 05/06/2026.
//

#include "cpu.h"


void cpu_init(CPU *cpu) {
    cpu->AF = 0x01B0;
    cpu->BC = 0x0013;
    cpu->DE = 0x00D8;
    cpu->HL = 0x014D;
    cpu->SP = 0xFFFE;
    cpu->PC = 0x0100;
}