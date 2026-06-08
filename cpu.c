//
// Created by Karim Makhlouf on 05/06/2026.
//

#include "cpu.h"

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

INC_R(b, B);
INC_R(c, C);
INC_R(d, D);
INC_R(e, E);
INC_R(h, H);
INC_R(l, L);
INC_R(a, A);

DEC_R(b, B);
DEC_R(c, C);
DEC_R(d, D);
DEC_R(e, E);
DEC_R(h, H);
DEC_R(l, L);
DEC_R(a, A);

PUSH_R_R(bc, BC);
PUSH_R_R(de, DE);
PUSH_R_R(hl, HL);
PUSH_R_R(af, AF);

POP_R_R(bc, BC);
POP_R_R(de, DE);
POP_R_R(hl, HL);
POP_R_R(af, AF);

LD_HL_R(b, B);
LD_HL_R(c, C);
LD_HL_R(d, D);
LD_HL_R(e, E);
LD_HL_R(h, H);
LD_HL_R(l, L);
LD_HL_R(a, A);

LD_R_HL(b, B);
LD_R_HL(c, C);
LD_R_HL(d, D);
LD_R_HL(e, E);
LD_R_HL(h, H);
LD_R_HL(l, L);
LD_R_HL(a, A);

INC_RR(bc, BC);
INC_RR(de, DE);
INC_RR(hl, HL);
INC_RR(sp, SP);

RLC_R(b, B);
RLC_R(c, C);
RLC_R(d, D);
RLC_R(e, E);
RLC_R(h, H);
RLC_R(l, L);
RLC_R(a, A);

RRC_R(b, B);
RRC_R(c, C);
RRC_R(d, D);
RRC_R(e, E);
RRC_R(h, H);
RRC_R(l, L);
RRC_R(a, A);

RL_R(b, B);
RL_R(c, C);
RL_R(d, D);
RL_R(e, E);
RL_R(h, H);
RL_R(l, L);
RL_R(a, A);

RR_R(b, B);
RR_R(c, C);
RR_R(d, D);
RR_R(e, E);
RR_R(h, H);
RR_R(l, L);
RR_R(a, A);

SLA_R(b, B);
SLA_R(c, C);
SLA_R(d, D);
SLA_R(e, E);
SLA_R(h, H);
SLA_R(l, L);
SLA_R(a, A);

SRA_R(b, B);
SRA_R(c, C);
SRA_R(d, D);
SRA_R(e, E);
SRA_R(h, H);
SRA_R(l, L);
SRA_R(a, A);

SRL_R(b, B);
SRL_R(c, C);
SRL_R(d, D);
SRL_R(e, E);
SRL_R(h, H);
SRL_R(l, L);
SRL_R(a, A);

SWAP_R(b, B);
SWAP_R(c, C);
SWAP_R(d, D);
SWAP_R(e, E);
SWAP_R(h, H);
SWAP_R(l, L);
SWAP_R(a, A);

BIT_N_R(0, b, B);
BIT_N_R(0, c, C);
BIT_N_R(0, d, D);
BIT_N_R(0, e, E);
BIT_N_R(0, h, H);
BIT_N_R(0, l, L);
BIT_N_R(0, a, A);

BIT_N_R(1, b, B);
BIT_N_R(1, c, C);
BIT_N_R(1, d, D);
BIT_N_R(1, e, E);
BIT_N_R(1, h, H);
BIT_N_R(1, l, L);
BIT_N_R(1, a, A);

BIT_N_R(2, b, B);
BIT_N_R(2, c, C);
BIT_N_R(2, d, D);
BIT_N_R(2, e, E);
BIT_N_R(2, h, H);
BIT_N_R(2, l, L);
BIT_N_R(2, a, A);

BIT_N_R(3, b, B);
BIT_N_R(3, c, C);
BIT_N_R(3, d, D);
BIT_N_R(3, e, E);
BIT_N_R(3, h, H);
BIT_N_R(3, l, L);
BIT_N_R(3, a, A);

BIT_N_R(4, b, B);
BIT_N_R(4, c, C);
BIT_N_R(4, d, D);
BIT_N_R(4, e, E);
BIT_N_R(4, h, H);
BIT_N_R(4, l, L);
BIT_N_R(4, a, A);

BIT_N_R(5, b, B);
BIT_N_R(5, c, C);
BIT_N_R(5, d, D);
BIT_N_R(5, e, E);
BIT_N_R(5, h, H);
BIT_N_R(5, l, L);
BIT_N_R(5, a, A);

BIT_N_R(6, b, B);
BIT_N_R(6, c, C);
BIT_N_R(6, d, D);
BIT_N_R(6, e, E);
BIT_N_R(6, h, H);
BIT_N_R(6, l, L);
BIT_N_R(6, a, A);

BIT_N_R(7, b, B);
BIT_N_R(7, c, C);
BIT_N_R(7, d, D);
BIT_N_R(7, e, E);
BIT_N_R(7, h, H);
BIT_N_R(7, l, L);
BIT_N_R(7, a, A);

RES_N_R(0, b, B);
RES_N_R(0, c, C);
RES_N_R(0, d, D);
RES_N_R(0, e, E);
RES_N_R(0, h, H);
RES_N_R(0, l, L);
RES_N_R(0, a, A);

RES_N_R(1, b, B);
RES_N_R(1, c, C);
RES_N_R(1, d, D);
RES_N_R(1, e, E);
RES_N_R(1, h, H);
RES_N_R(1, l, L);
RES_N_R(1, a, A);

RES_N_R(2, b, B);
RES_N_R(2, c, C);
RES_N_R(2, d, D);
RES_N_R(2, e, E);
RES_N_R(2, h, H);
RES_N_R(2, l, L);
RES_N_R(2, a, A);

RES_N_R(3, b, B);
RES_N_R(3, c, C);
RES_N_R(3, d, D);
RES_N_R(3, e, E);
RES_N_R(3, h, H);
RES_N_R(3, l, L);
RES_N_R(3, a, A);

RES_N_R(4, b, B);
RES_N_R(4, c, C);
RES_N_R(4, d, D);
RES_N_R(4, e, E);
RES_N_R(4, h, H);
RES_N_R(4, l, L);
RES_N_R(4, a, A);

RES_N_R(5, b, B);
RES_N_R(5, c, C);
RES_N_R(5, d, D);
RES_N_R(5, e, E);
RES_N_R(5, h, H);
RES_N_R(5, l, L);
RES_N_R(5, a, A);

RES_N_R(6, b, B);
RES_N_R(6, c, C);
RES_N_R(6, d, D);
RES_N_R(6, e, E);
RES_N_R(6, h, H);
RES_N_R(6, l, L);
RES_N_R(6, a, A);

RES_N_R(7, b, B);
RES_N_R(7, c, C);
RES_N_R(7, d, D);
RES_N_R(7, e, E);
RES_N_R(7, h, H);
RES_N_R(7, l, L);
RES_N_R(7, a, A);

//INSTRUCTION PROCESSEURS --------------

void (*opcodes[256])(CPU *cpu);
void (*cb_opcodes[256])(CPU *cpu);

void op_unknow(CPU *cpu) {
    FILE *log = fopen("unknown_opcodes.log", "a");
    if (log) {
        fprintf(log, "0x%02X à PC=0x%04X\n", read(cpu->PC), cpu->PC);
        fclose(log);
    }
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

void op_ld_hl_nn(CPU *cpu) {
    uint8_t lo = read(cpu->PC + 1);
    uint8_t hi = read(cpu->PC + 2);
    cpu->HL = lo | (hi << 8);
    cpu->PC += 2;
}

void op_jp_nn(CPU *cpu) {
    uint8_t lo = read(cpu->PC + 1);
    uint8_t hi = read(cpu->PC + 2);
    cpu->PC = lo | (hi << 8);
    cpu->PC--;
}

void op_jp_nz_nn(CPU *cpu) {
    if (cpu->fZ == 0) {
        uint8_t lo = read(cpu->PC + 1);
        uint8_t hi = read(cpu->PC + 2);
        cpu->PC = lo | (hi << 8);
        cpu->PC--;
    }
    else {
        cpu->PC += 2;
    }
}

void op_jp_z_nn(CPU *cpu) {
    if (cpu->fZ == 1) {
        uint8_t lo = read(cpu->PC + 1);
        uint8_t hi = read(cpu->PC + 2);
        cpu->PC = lo | (hi << 8);
        cpu->PC--;
    }
    else {
        cpu->PC += 2;
    }
}

void op_jp_nc_nn(CPU *cpu) {
    if (cpu->fC == 0) {
        uint8_t lo = read(cpu->PC + 1);
        uint8_t hi = read(cpu->PC + 2);
        cpu->PC = lo | (hi << 8);
        cpu->PC--;
    }
    else {
        cpu->PC += 2;
    }
}

void op_jp_c_nn(CPU *cpu) {
    if (cpu->fC == 1) {
        uint8_t lo = read(cpu->PC + 1);
        uint8_t hi = read(cpu->PC + 2);
        cpu->PC = lo | (hi << 8);
        cpu->PC--;
    }
    else {
        cpu->PC += 2;
    }
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

void op_call_nn(CPU *cpu) {
    uint16_t return_addr = cpu->PC + 3;
    cpu->SP -= 2;
    write(cpu->SP + 1, return_addr >> 8);
    write(cpu->SP, return_addr & 0xFF);

    uint8_t lo = read(cpu->PC + 1);
    uint8_t hi = read(cpu->PC + 2);
    cpu->PC = lo | (hi << 8);
    cpu->PC --;
}

void op_ret(CPU *cpu) {
    uint8_t lo = read(cpu->SP);
    uint8_t hi = read(cpu->SP + 1);
    cpu->PC = lo | (hi << 8);
    cpu->SP += 2;
    cpu->PC --;
}

void op_di(CPU *cpu) {
    //Interruptuin ignoré pour le moment
}

void op_ei(CPU *cpu) {
    // Interruption ignoré pour le moment
}

void op_ld_sp_nn(CPU *cpu) {
    uint8_t lo = read(cpu->PC + 1);
    uint8_t hi = read(cpu->PC + 2);
    cpu->SP = lo | (hi << 8);
    cpu->PC += 2;
}

void op_ld_a_nn(CPU *cpu) {
    uint8_t lo = read(cpu->PC + 1);
    uint8_t hi = read(cpu->PC + 2);
    uint16_t addresse = lo | (hi << 8);
    write(addresse, cpu->A);
    cpu->PC += 2;
}

void op_ldh_a_n(CPU *cpu) {
    uint16_t n = read(cpu->PC + 1);
    n += 0xFF00;
    write(n, cpu->A);
    cpu->PC++;
}

void op_ldh_n_a(CPU *cpu) {
    uint16_t n = read(cpu->PC + 1);
    n += 0xFF00;
    cpu->A = read(n);
    cpu->A ++;
}

void op_cp_n(CPU *cpu) {
    uint8_t n = read(cpu->PC + 1);
    uint16_t res = cpu->A - n;
    cpu->fZ = (res == 0);
    cpu->fN = 1;
    cpu->fH = ((cpu->A & 0xF) < (n & 0xF));
    cpu->fC = (cpu->A < n);
    cpu->PC++;
}

void op_jr_e(CPU *cpu) {
    int8_t offset = (int8_t)read(cpu->PC + 1);
    cpu->PC ++;
    cpu->PC += offset;
    cpu->PC--;
}

void op_jr_nz(CPU *cpu) {
    if (cpu->fZ == 0) {
        int8_t offset = (int8_t)read(cpu->PC + 1);
        cpu->PC ++;
        cpu->PC += offset;
        cpu->PC--;
    }
    else {
        cpu->PC++;
    }
}

void op_jr_z_e(CPU *cpu) {
    if (cpu->fZ == 1) {
        int8_t offset = (int8_t)read(cpu->PC + 1);
        cpu->PC ++;
        cpu->PC += offset;
        cpu->PC--;
    }
    else {
        cpu->PC++;
    }
}

void op_ld_bc_a(CPU *cpu) {
    write(cpu->BC, cpu->A);
}

void op_ld_a_bc(CPU *cpu) {
    cpu->A = read(cpu->BC);
}

void op_ldi_a_hl(CPU *cpu) {
    cpu->A = read(cpu->HL);
    cpu->HL++;
}

void op_cb(CPU *cpu) {
    uint8_t cb_opcode = read(cpu->PC + 1);
    cb_opcodes[cb_opcode](cpu);
    cpu->PC++;
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
        cb_opcodes[i] = op_unknow;
    }

    opcodes[0x00] = op_nop;
    opcodes[0x01] = op_ld_bc_nn;
    opcodes[0xC3] = op_jp_nn;
    opcodes[0x76] = op_halted;

    opcodes[0xC2] = op_jp_nz_nn;
    opcodes[0xCA] = op_jp_z_nn;
    opcodes[0xD2] = op_jp_nc_nn;
    opcodes[0xDA] = op_jp_c_nn;

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

    opcodes[0x90] = op_sub_a_b;
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

    opcodes[0x04] = op_inc_b;
    opcodes[0x0C] = op_inc_c;
    opcodes[0x14] = op_inc_d;
    opcodes[0x1C] = op_inc_e;
    opcodes[0x24] = op_inc_h;
    opcodes[0x2C] = op_inc_l;
    opcodes[0x3C] = op_inc_a;

    opcodes[0x05] = op_dec_b;
    opcodes[0x0D] = op_dec_c;
    opcodes[0x15] = op_dec_d;
    opcodes[0x1D] = op_dec_e;
    opcodes[0x25] = op_dec_h;
    opcodes[0x2D] = op_dec_l;
    opcodes[0x3D] = op_dec_a;

    opcodes[0xCD] = op_call_nn;
    opcodes[0xC9] = op_ret;

    opcodes[0xC5] = op_push_bc;
    opcodes[0xD5] = op_push_de;
    opcodes[0xE5] = op_push_hl;
    opcodes[0xF5] = op_push_af;

    opcodes[0xC1] = op_pop_bc;
    opcodes[0xD1] = op_pop_de;
    opcodes[0xE1] = op_pop_hl;
    opcodes[0xF1] = op_pop_af;

    opcodes[0x70] = op_ld_hl_b;
    opcodes[0x71] = op_ld_hl_c;
    opcodes[0x72] = op_ld_hl_d;
    opcodes[0x73] = op_ld_hl_e;
    opcodes[0x74] = op_ld_hl_h;
    opcodes[0x75] = op_ld_hl_l;
    opcodes[0x77] = op_ld_hl_a;

    opcodes[0x46] = op_ld_b_hl;
    opcodes[0x4E] = op_ld_c_hl;
    opcodes[0x56] = op_ld_d_hl;
    opcodes[0x5E] = op_ld_e_hl;
    opcodes[0x66] = op_ld_h_hl;
    opcodes[0x6E] = op_ld_l_hl;
    opcodes[0x7E] = op_ld_a_hl;

    opcodes[0xF3] = op_di;
    opcodes[0xFB] = op_ei;

    opcodes[0x31] = op_ld_sp_nn;
    opcodes[0x21] = op_ld_hl_nn;
    opcodes[0x21] = op_ld_hl_nn;
    opcodes[0xEA] = op_ld_a_nn;
    opcodes[0xE0] = op_ldh_a_n;
    opcodes[0xF0] = op_ldh_n_a;

    opcodes[0xFE] = op_cp_n;
    opcodes[0x18] = op_jr_e;
    opcodes[0x20] = op_jr_nz;
    opcodes[0x28] = op_jr_z_e;

    opcodes[0x03] = op_inc_bc;
    opcodes[0x13] = op_inc_de;
    opcodes[0x23] = op_inc_hl;
    opcodes[0x33] = op_inc_sp;

    opcodes[0x02] = op_ld_bc_a;
    opcodes[0x0A] = op_ld_a_bc;
    opcodes[0x2A] = op_ldi_a_hl;
    opcodes[0xCB] = op_cb;

    cb_opcodes[0x00] = op_rlc_b;
    cb_opcodes[0x01] = op_rlc_c;
    cb_opcodes[0x02] = op_rlc_d;
    cb_opcodes[0x03] = op_rlc_e;
    cb_opcodes[0x04] = op_rlc_h;
    cb_opcodes[0x05] = op_rlc_l;
    cb_opcodes[0x07] = op_rlc_a;

    cb_opcodes[0x08] = op_rrc_b;
    cb_opcodes[0x09] = op_rrc_c;
    cb_opcodes[0x0A] = op_rrc_d;
    cb_opcodes[0x0B] = op_rrc_e;
    cb_opcodes[0x0C] = op_rrc_h;
    cb_opcodes[0x0D] = op_rrc_l;
    cb_opcodes[0x0F] = op_rrc_a;

    cb_opcodes[0x10] = op_rl_b;
    cb_opcodes[0x11] = op_rl_c;
    cb_opcodes[0x12] = op_rl_d;
    cb_opcodes[0x13] = op_rl_e;
    cb_opcodes[0x14] = op_rl_h;
    cb_opcodes[0x15] = op_rl_l;
    cb_opcodes[0x17] = op_rl_a;

    cb_opcodes[0x18] = op_rr_b;
    cb_opcodes[0x19] = op_rr_c;
    cb_opcodes[0x1A] = op_rr_d;
    cb_opcodes[0x1B] = op_rr_e;
    cb_opcodes[0x1C] = op_rr_h;
    cb_opcodes[0x1D] = op_rr_l;
    cb_opcodes[0x1F] = op_rr_a;

    cb_opcodes[0x20] = op_sla_b;
    cb_opcodes[0x21] = op_sla_c;
    cb_opcodes[0x22] = op_sla_d;
    cb_opcodes[0x23] = op_sla_e;
    cb_opcodes[0x24] = op_sla_h;
    cb_opcodes[0x25] = op_sla_l;
    cb_opcodes[0x27] = op_sla_a;

    cb_opcodes[0x28] = op_sra_b;
    cb_opcodes[0x29] = op_sra_c;
    cb_opcodes[0x2A] = op_sra_d;
    cb_opcodes[0x2B] = op_sra_e;
    cb_opcodes[0x2C] = op_sra_h;
    cb_opcodes[0x2D] = op_sra_l;
    cb_opcodes[0x2F] = op_sra_a;

    cb_opcodes[0x38] = op_srl_b;
    cb_opcodes[0x39] = op_srl_c;
    cb_opcodes[0x3A] = op_srl_d;
    cb_opcodes[0x3B] = op_srl_e;
    cb_opcodes[0x3C] = op_srl_h;
    cb_opcodes[0x3D] = op_srl_l;
    cb_opcodes[0x3F] = op_srl_a;

    cb_opcodes[0x30] = op_swap_b;
    cb_opcodes[0x31] = op_swap_c;
    cb_opcodes[0x32] = op_swap_d;
    cb_opcodes[0x33] = op_swap_e;
    cb_opcodes[0x34] = op_swap_h;
    cb_opcodes[0x35] = op_swap_l;
    cb_opcodes[0x37] = op_swap_a;

    cb_opcodes[0x40] = op_bit_0_b;
    cb_opcodes[0x41] = op_bit_0_c;
    cb_opcodes[0x42] = op_bit_0_d;
    cb_opcodes[0x43] = op_bit_0_e;
    cb_opcodes[0x44] = op_bit_0_h;
    cb_opcodes[0x45] = op_bit_0_l;
    cb_opcodes[0x47] = op_bit_0_a;

    cb_opcodes[0x48] = op_bit_1_b;
    cb_opcodes[0x49] = op_bit_1_c;
    cb_opcodes[0x4A] = op_bit_1_d;
    cb_opcodes[0x4B] = op_bit_1_e;
    cb_opcodes[0x4C] = op_bit_1_h;
    cb_opcodes[0x4D] = op_bit_1_l;
    cb_opcodes[0x4F] = op_bit_1_a;

    cb_opcodes[0x50] = op_bit_2_b;
    cb_opcodes[0x51] = op_bit_2_c;
    cb_opcodes[0x52] = op_bit_2_d;
    cb_opcodes[0x53] = op_bit_2_e;
    cb_opcodes[0x54] = op_bit_2_h;
    cb_opcodes[0x55] = op_bit_2_l;
    cb_opcodes[0x57] = op_bit_2_a;

    cb_opcodes[0x58] = op_bit_3_b;
    cb_opcodes[0x59] = op_bit_3_c;
    cb_opcodes[0x5A] = op_bit_3_d;
    cb_opcodes[0x5B] = op_bit_3_e;
    cb_opcodes[0x5C] = op_bit_3_h;
    cb_opcodes[0x5D] = op_bit_3_l;
    cb_opcodes[0x5F] = op_bit_3_a;

    cb_opcodes[0x60] = op_bit_4_b;
    cb_opcodes[0x61] = op_bit_4_c;
    cb_opcodes[0x62] = op_bit_4_d;
    cb_opcodes[0x63] = op_bit_4_e;
    cb_opcodes[0x64] = op_bit_4_h;
    cb_opcodes[0x65] = op_bit_4_l;
    cb_opcodes[0x67] = op_bit_4_a;

    cb_opcodes[0x68] = op_bit_5_b;
    cb_opcodes[0x69] = op_bit_5_c;
    cb_opcodes[0x6A] = op_bit_5_d;
    cb_opcodes[0x6B] = op_bit_5_e;
    cb_opcodes[0x6C] = op_bit_5_h;
    cb_opcodes[0x6D] = op_bit_5_l;
    cb_opcodes[0x6F] = op_bit_5_a;

    cb_opcodes[0x70] = op_bit_6_b;
    cb_opcodes[0x71] = op_bit_6_c;
    cb_opcodes[0x72] = op_bit_6_d;
    cb_opcodes[0x73] = op_bit_6_e;
    cb_opcodes[0x74] = op_bit_6_h;
    cb_opcodes[0x75] = op_bit_6_l;
    cb_opcodes[0x77] = op_bit_6_a;

    cb_opcodes[0x78] = op_bit_7_b;
    cb_opcodes[0x79] = op_bit_7_c;
    cb_opcodes[0x7A] = op_bit_7_d;
    cb_opcodes[0x7B] = op_bit_7_e;
    cb_opcodes[0x7C] = op_bit_7_h;
    cb_opcodes[0x7D] = op_bit_7_l;
    cb_opcodes[0x7F] = op_bit_7_a;

    cb_opcodes[0x80] = op_res_0_b;
    cb_opcodes[0x81] = op_res_0_c;
    cb_opcodes[0x82] = op_res_0_d;
    cb_opcodes[0x83] = op_res_0_e;
    cb_opcodes[0x84] = op_res_0_h;
    cb_opcodes[0x85] = op_res_0_l;
    cb_opcodes[0x87] = op_res_0_a;

    cb_opcodes[0x88] = op_res_1_b;
    cb_opcodes[0x89] = op_res_1_c;
    cb_opcodes[0x8A] = op_res_1_d;
    cb_opcodes[0x8B] = op_res_1_e;
    cb_opcodes[0x8C] = op_res_1_h;
    cb_opcodes[0x8D] = op_res_1_l;
    cb_opcodes[0x8F] = op_res_1_a;

    cb_opcodes[0x90] = op_res_2_b;
    cb_opcodes[0x91] = op_res_2_c;
    cb_opcodes[0x92] = op_res_2_d;
    cb_opcodes[0x93] = op_res_2_e;
    cb_opcodes[0x94] = op_res_2_h;
    cb_opcodes[0x95] = op_res_2_l;
    cb_opcodes[0x97] = op_res_2_a;

    cb_opcodes[0x98] = op_res_3_b;
    cb_opcodes[0x99] = op_res_3_c;
    cb_opcodes[0x9A] = op_res_3_d;
    cb_opcodes[0x9B] = op_res_3_e;
    cb_opcodes[0x9C] = op_res_3_h;
    cb_opcodes[0x9D] = op_res_3_l;
    cb_opcodes[0x9F] = op_res_3_a;

    cb_opcodes[0xA0] = op_res_4_b;
    cb_opcodes[0xA1] = op_res_4_c;
    cb_opcodes[0xA2] = op_res_4_d;
    cb_opcodes[0xA3] = op_res_4_e;
    cb_opcodes[0xA4] = op_res_4_h;
    cb_opcodes[0xA5] = op_res_4_l;
    cb_opcodes[0xA7] = op_res_4_a;

    cb_opcodes[0xA8] = op_res_5_b;
    cb_opcodes[0xA9] = op_res_5_c;
    cb_opcodes[0xAA] = op_res_5_d;
    cb_opcodes[0xAB] = op_res_5_e;
    cb_opcodes[0xAC] = op_res_5_h;
    cb_opcodes[0xAD] = op_res_5_l;
    cb_opcodes[0xAF] = op_res_5_a;

    cb_opcodes[0xB0] = op_res_6_b;
    cb_opcodes[0xB1] = op_res_6_c;
    cb_opcodes[0xB2] = op_res_6_d;
    cb_opcodes[0xB3] = op_res_6_e;
    cb_opcodes[0xB4] = op_res_6_h;
    cb_opcodes[0xB5] = op_res_6_l;
    cb_opcodes[0xB7] = op_res_6_a;

    cb_opcodes[0xB8] = op_res_7_b;
    cb_opcodes[0xB9] = op_res_7_c;
    cb_opcodes[0xBA] = op_res_7_d;
    cb_opcodes[0xBB] = op_res_7_e;
    cb_opcodes[0xBC] = op_res_7_h;
    cb_opcodes[0xBD] = op_res_7_l;
    cb_opcodes[0xBF] = op_res_7_a;

}

void cpu_step(CPU *cpu) {
    if (cpu->halted == 1) return;
    uint16_t pc = cpu->PC;
    uint8_t lecture_pc = read(pc);
    opcodes[lecture_pc](cpu);
    cpu->PC++;
}

void cpu_check(void) {
    int count = 0;
    for (int i = 0; i < 256; i++) {
        if (opcodes[i] == op_unknow) count++;
    }
    printf("%d opcodes implémentés\n", 256 - count);
    printf("%d opcodes manquants\n", count);
}

// -------------------