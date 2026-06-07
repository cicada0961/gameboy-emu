//
// Created by Karim Makhlouf on 05/06/2026.
//

#include "cpu.h"
#include "memory.h"

LD_R_R(b_b, B, B);
LD_R_R(b_c, B, C);
LD_R_R(b_d, B, D);
LD_R_R(b_e, B, E);
LD_R_R(b_h, B, H);
LD_R_R(b_l, B, L);
LD_R_R(b_a, B, A);

LD_R_R(c_b, C, B);
LD_R_R(c_c, C, C);
LD_R_R(c_d, C, D);
LD_R_R(c_e, C, E);
LD_R_R(c_h, C, H);
LD_R_R(c_l, C, L);
LD_R_R(c_a, C, A);

LD_R_R(d_b, D, B);
LD_R_R(d_c, D, C);
LD_R_R(d_d, D, D);
LD_R_R(d_e, D, E);
LD_R_R(d_h, D, H);
LD_R_R(d_l, D, L);
LD_R_R(d_a, D, A);

LD_R_R(e_b, E, B);
LD_R_R(e_c, E, C);
LD_R_R(e_d, E, D);
LD_R_R(e_e, E, E);
LD_R_R(e_h, E, H);
LD_R_R(e_l, E, L);
LD_R_R(e_a, E, A);

LD_R_R(h_b, H, B);
LD_R_R(h_c, H, C);
LD_R_R(h_d, H, D);
LD_R_R(h_e, H, E);
LD_R_R(h_h, H, H);
LD_R_R(h_l, H, L);
LD_R_R(h_a, H, A);

LD_R_R(l_b, L, B);
LD_R_R(l_c, L, C);
LD_R_R(l_d, L, D);
LD_R_R(l_e, L, E);
LD_R_R(l_h, L, H);
LD_R_R(l_l, L, L);
LD_R_R(l_a, L, A);

LD_R_R(a_b, A, B);
LD_R_R(a_c, A, C);
LD_R_R(a_d, A, D);
LD_R_R(a_e, A, E);
LD_R_R(a_h, A, H);
LD_R_R(a_l, A, L);
LD_R_R(a_a, A, A);

LD_R_N(b, B);
LD_R_N(c, C);
LD_R_N(d, D);
LD_R_N(e, E);
LD_R_N(h, H);
LD_R_N(l, L);
LD_R_N(a, A);

ADD_A_R(a_b, B);
ADD_A_R(a_c, C);
ADD_A_R(a_d, D);
ADD_A_R(a_e, E);
ADD_A_R(a_h, H);
ADD_A_R(a_l, L);
ADD_A_R(a_a, A);

SUB_A_R(a_b, B);
SUB_A_R(a_c, C);
SUB_A_R(a_d, D);
SUB_A_R(a_e, E);
SUB_A_R(a_h, H);
SUB_A_R(a_l, L);
SUB_A_R(a_a, A);

AND_A_R(a_b, B);
AND_A_R(a_c, C);
AND_A_R(a_d, D);
AND_A_R(a_e, E);
AND_A_R(a_h, H);
AND_A_R(a_l, L);
AND_A_R(a_a, A);

OR_A_R(a_b, B);
OR_A_R(a_c, C);
OR_A_R(a_d, D);
OR_A_R(a_e, E);
OR_A_R(a_h, H);
OR_A_R(a_l, L);
OR_A_R(a_a, A);

XOR_A_R(a_b, B);
XOR_A_R(a_c, C);
XOR_A_R(a_d, D);
XOR_A_R(a_e, E);
XOR_A_R(a_h, H);
XOR_A_R(a_l, L);
XOR_A_R(a_a, A);

CP_A_R(a_b, B);
CP_A_R(a_c, C);
CP_A_R(a_d, D);
CP_A_R(a_e, E);
CP_A_R(a_h, H);
CP_A_R(a_l, L);
CP_A_R(a_a, A);

//INSTRUCTION PROCESSEURS --------------

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

void op_halted(CPU *cpu) {
    cpu->halted = 1;
}

void op_add_a_B(CPU *cpu) {
    uint16_t res = cpu->A + cpu->B;
    cpu->fH = ((cpu->A & 0xF) + (cpu->B & 0xF) > 0xF);
    cpu->fZ = (res == 0);
    cpu->fN = 0;
    cpu->fC = res > 0xFF;

    cpu->A = (uint8_t)res;
}

void cpu_init(CPU *cpu) {
    cpu->AF = 0x01B0;
    cpu->BC = 0x0013;
    cpu->DE = 0x00D8;
    cpu->HL = 0x014D;
    cpu->SP = 0xFFFE;
    cpu->PC = 0x0100;
    cpu->halted = 0;

    for (int i = 0; i < 256; i++) {
        opcodes[i] = op_unknow;
    }

    opcodes[0x00] = op_nop;
    opcodes[0x01] = op_ld_bc_nn;
    opcodes[0xC3] = op_jp_nn;
    opcodes[0x76] = op_halted;

    opcodes[0x40] = op_ld_b_b;
    opcodes[0x41] = op_ld_b_c;
    opcodes[0x42] = op_ld_b_d;
    opcodes[0x43] = op_ld_b_e;
    opcodes[0x44] = op_ld_b_h;
    opcodes[0x45] = op_ld_b_l;
    opcodes[0x47] = op_ld_b_a;

    opcodes[0x48] = op_ld_c_b;
    opcodes[0x49] = op_ld_c_c;
    opcodes[0x4A] = op_ld_c_d;
    opcodes[0x4B] = op_ld_c_e;
    opcodes[0x4C] = op_ld_c_h;
    opcodes[0x4D] = op_ld_c_l;
    opcodes[0x4F] = op_ld_c_a;

    opcodes[0x50] = op_ld_d_b;
    opcodes[0x51] = op_ld_d_c;
    opcodes[0x52] = op_ld_d_d;
    opcodes[0x53] = op_ld_d_e;
    opcodes[0x54] = op_ld_d_h;
    opcodes[0x55] = op_ld_d_l;
    opcodes[0x57] = op_ld_d_a;

    opcodes[0x58] = op_ld_e_b;
    opcodes[0x59] = op_ld_e_c;
    opcodes[0x5A] = op_ld_e_d;
    opcodes[0x5B] = op_ld_e_e;
    opcodes[0x5C] = op_ld_e_h;
    opcodes[0x5D] = op_ld_e_l;
    opcodes[0x5F] = op_ld_e_a;

    opcodes[0x60] = op_ld_h_b;
    opcodes[0x61] = op_ld_h_c;
    opcodes[0x62] = op_ld_h_d;
    opcodes[0x63] = op_ld_h_e;
    opcodes[0x64] = op_ld_h_h;
    opcodes[0x65] = op_ld_h_l;
    opcodes[0x67] = op_ld_h_a;

    opcodes[0x68] = op_ld_l_b;
    opcodes[0x69] = op_ld_l_c;
    opcodes[0x6A] = op_ld_l_d;
    opcodes[0x6B] = op_ld_l_e;
    opcodes[0x6C] = op_ld_l_h;
    opcodes[0x6D] = op_ld_l_l;
    opcodes[0x6F] = op_ld_l_a;

    opcodes[0x78] = op_ld_a_b;
    opcodes[0x79] = op_ld_a_c;
    opcodes[0x7A] = op_ld_a_d;
    opcodes[0x7B] = op_ld_a_e;
    opcodes[0x7C] = op_ld_a_h;
    opcodes[0x7D] = op_ld_a_l;
    opcodes[0x7F] = op_ld_a_a;

    opcodes[0x06] = op_ld_b_n;
    opcodes[0x0E] = op_ld_c_n;
    opcodes[0x16] = op_ld_d_n;
    opcodes[0x1E] = op_ld_e_n;
    opcodes[0x26] = op_ld_h_n;
    opcodes[0x2E] = op_ld_l_n;
    opcodes[0x3E] = op_ld_a_n;

    opcodes[0x80] = op_add_a_b;
    opcodes[0x81] = op_add_a_c;
    opcodes[0x82] = op_add_a_d;
    opcodes[0x83] = op_add_a_e;
    opcodes[0x84] = op_add_a_h;
    opcodes[0x85] = op_add_a_l;
    opcodes[0x87] = op_add_a_a;

    opcodes[0x91] = op_sub_a_b;
    opcodes[0x91] = op_sub_a_c;
    opcodes[0x92] = op_sub_a_d;
    opcodes[0x93] = op_sub_a_e;
    opcodes[0x94] = op_sub_a_h;
    opcodes[0x95] = op_sub_a_l;
    opcodes[0x97] = op_sub_a_a;

    opcodes[0xA0] = op_and_a_b;
    opcodes[0xA1] = op_and_a_c;
    opcodes[0xA2] = op_and_a_d;
    opcodes[0xA3] = op_and_a_e;
    opcodes[0xA4] = op_and_a_h;
    opcodes[0xA5] = op_and_a_l;
    opcodes[0xA7] = op_and_a_a;

    opcodes[0xB0] = op_or_a_b;
    opcodes[0xB1] = op_or_a_c;
    opcodes[0xB2] = op_or_a_d;
    opcodes[0xB3] = op_or_a_e;
    opcodes[0xB4] = op_or_a_h;
    opcodes[0xB5] = op_or_a_l;
    opcodes[0xB7] = op_or_a_a;

    opcodes[0xA8] = op_xor_a_b;
    opcodes[0xA9] = op_xor_a_c;
    opcodes[0xAA] = op_xor_a_d;
    opcodes[0xAB] = op_xor_a_e;
    opcodes[0xAC] = op_xor_a_h;
    opcodes[0xAD] = op_xor_a_l;
    opcodes[0xAF] = op_xor_a_a;

    opcodes[0xB8] = op_cp_a_b;
    opcodes[0xB9] = op_cp_a_c;
    opcodes[0xBA] = op_cp_a_d;
    opcodes[0xBB] = op_cp_a_e;
    opcodes[0xBC] = op_cp_a_h;
    opcodes[0xBD] = op_cp_a_l;
    opcodes[0xBF] = op_cp_a_a;
}

void cpu_step(CPU *cpu) {
    if (cpu->halted == 1) return;
    uint16_t pc = cpu->PC;
    uint8_t lecture_pc = read(pc);
    opcodes[lecture_pc](cpu);
    cpu->PC++;
}

// -------------------