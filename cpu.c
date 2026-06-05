//
// Created by Karim Makhlouf on 05/06/2026.
//

#include "cpu.h"
#include "memory.h"

void (*opcodes[256])(CPU *cpu);

void op_unknow(CPU *cpu) {
    printf("Opcode inconnu : 0x%02X à PC=0x%04X\n", read(cpu->PC), cpu->PC);
}

void op_nop(CPU *cpu) {
    //ne fait rien
}
void op_ld_bc_nn(CPU *cpu) {
    uint8_t lo = read(cpu->PC + 1);
    uint8_t hi = read(cpu->PC + 2);
    cpu->BC = lo | (hi << 8);
    cpu->PC += 2;
}
void op_jp_nn(CPU *cpu) {
    uint8_t lo = read(cpu->PC + 1);
    uint8_t hi = read(cpu->PC + 2);
    cpu->PC = lo | (hi << 8);
    cpu->PC--;
}

void cpu_init(CPU *cpu) {
    cpu->AF = 0x01B0;
    cpu->BC = 0x0013;
    cpu->DE = 0x00D8;
    cpu->HL = 0x014D;
    cpu->SP = 0xFFFE;
    cpu->PC = 0x0100;

    for (int i = 0; i < 256; i++) {
        opcodes[i] = op_unknow;
    }

    opcodes[0x00] = op_nop;
    opcodes[0x01] = op_ld_bc_nn;
    opcodes[0xC3] = op_jp_nn;
}

void cpu_step(CPU *cpu) {
    uint16_t pc = cpu->PC;
    uint8_t lecture_pc = read(pc);
    opcodes[lecture_pc](cpu);
    cpu->PC++;
}
