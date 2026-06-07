//
// Created by Karim Makhlouf on 05/06/2026.
//

#ifndef GAMEBOY_CPU_H
#define GAMEBOY_CPU_H

#include <stdint.h>
#include <stdio.h>

typedef struct {
    union {
        uint16_t AF;
        struct {
            uint8_t F;
            uint8_t A;
        };
        struct {
            uint8_t unused : 4;
            uint8_t fC : 1;
            uint8_t fH : 1;
            uint8_t fN : 1;
            uint8_t fZ : 1;
        };
    };
    union {
        uint16_t BC;
        struct {
            uint8_t C;
            uint8_t B;
        };
    };
    union {
        uint16_t DE;
        struct {
            uint8_t E;
            uint8_t D;
        };
    };
    union {
        uint16_t HL;
        struct {
            uint8_t L;
            uint8_t H;
        };
    };
    uint16_t SP;
    uint16_t PC;
    int halted;
}CPU;

//MACRO
#define LD_R_R(name, dst, src) \
void op_ld_##name(CPU *cpu) { cpu->dst = cpu->src; }

#define LD_R_N(name, dst) \
void op_ld_##name##_n(CPU *cpu) { \
    uint8_t n = read(cpu->PC + 1); \
    cpu->dst = n; \
    cpu->PC++; \
}


#define ADD_A_R(name, src) \
void op_add_##name(CPU *cpu) { \
uint16_t res = cpu->A + cpu->src; \
cpu->fZ = (res == 0); \
cpu->fN = 0; \
cpu->fH = ((cpu->A & 0xF) + (cpu->src & 0xF) > 0xF); \
cpu->fC = (res > 0xFF); \
cpu->A = (uint8_t)res; \
}

#define SUB_A_R(name, src) \
void op_sub_##name(CPU *cpu){ \
uint16_t res = cpu->A - cpu->src; \
cpu->fZ = (res == 0); \
cpu->fN = 1; \
cpu->fH = ((cpu->A & 0xF) < (cpu->src & 0xF)); \
cpu->fC = (cpu->A < cpu->src); \
cpu->A = (uint8_t)res; \
}

#define AND_A_R(name, src) \
void op_and_##name(CPU *cpu){ \
cpu->A = cpu->A & cpu->src; \
cpu->fZ = (cpu->A == 0); \
cpu->fN = 0; \
cpu->fH = 1; \
cpu->fC = 0; \
}

#define OR_A_R(name, src) \
void op_or_##name(CPU *cpu){ \
cpu->A = cpu->A | cpu->src; \
cpu->fZ = (cpu->A == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
cpu->fC = 0; \
}

extern void (*opcodes[256])(CPU *cpu);

void cpu_init(CPU *cpu);
void cpu_step(CPU *cpu);

void op_unknow(CPU *cpu);
void op_nop(CPU *cpu);
void op_ld_bc_nn(CPU *cpu);
void op_jp_nn(CPU *cpu);
void op_halted(CPU *cpu);

// ========== LD R_R ========== //

//B
void op_ld_b_b(CPU *cpu);
void op_ld_b_c(CPU *cpu);
void op_ld_b_d(CPU *cpu);
void op_ld_b_e(CPU *cpu);
void op_ld_b_h(CPU *cpu);
void op_ld_b_l(CPU *cpu);
void op_ld_b_a(CPU *cpu);

//C
void op_ld_c_b(CPU *cpu);
void op_ld_c_c(CPU *cpu);
void op_ld_c_d(CPU *cpu);
void op_ld_c_e(CPU *cpu);
void op_ld_c_h(CPU *cpu);
void op_ld_c_l(CPU *cpu);
void op_ld_c_a(CPU *cpu);

//D
void op_ld_d_b(CPU *cpu);
void op_ld_d_c(CPU *cpu);
void op_ld_d_d(CPU *cpu);
void op_ld_d_e(CPU *cpu);
void op_ld_d_h(CPU *cpu);
void op_ld_d_l(CPU *cpu);
void op_ld_d_a(CPU *cpu);

//E
void op_ld_e_b(CPU *cpu);
void op_ld_e_c(CPU *cpu);
void op_ld_e_d(CPU *cpu);
void op_ld_e_e(CPU *cpu);
void op_ld_e_h(CPU *cpu);
void op_ld_e_l(CPU *cpu);
void op_ld_e_a(CPU *cpu);


//H
void op_ld_h_b(CPU *cpu);
void op_ld_h_c(CPU *cpu);
void op_ld_h_d(CPU *cpu);
void op_ld_h_e(CPU *cpu);
void op_ld_h_h(CPU *cpu);
void op_ld_h_l(CPU *cpu);
void op_ld_h_a(CPU *cpu);

//L
void op_ld_l_b(CPU *cpu);
void op_ld_l_c(CPU *cpu);
void op_ld_l_d(CPU *cpu);
void op_ld_l_e(CPU *cpu);
void op_ld_l_h(CPU *cpu);
void op_ld_l_l(CPU *cpu);
void op_ld_l_a(CPU *cpu);

//A
void op_ld_a_b(CPU *cpu);
void op_ld_a_c(CPU *cpu);
void op_ld_a_d(CPU *cpu);
void op_ld_a_e(CPU *cpu);
void op_ld_a_h(CPU *cpu);
void op_ld_a_l(CPU *cpu);
void op_ld_a_a(CPU *cpu);

// ========== LD R_N ========== //
void op_ld_b_n(CPU *cpu);
void op_ld_c_n(CPU *cpu);
void op_ld_d_n(CPU *cpu);
void op_ld_e_n(CPU *cpu);
void op_ld_h_n(CPU *cpu);
void op_ld_l_n(CPU *cpu);
void op_ld_a_n(CPU *cpu);

// ========== ADD A_R ========== //
void op_add_a_b(CPU *cpu);
void op_add_a_c(CPU *cpu);
void op_add_a_d(CPU *cpu);
void op_add_a_e(CPU *cpu);
void op_add_a_h(CPU *cpu);
void op_add_a_l(CPU *cpu);
void op_add_a_a(CPU *cpu);

// ========== SUB A_R ========== //
void op_sub_a_b(CPU *cpu);
void op_sub_a_c(CPU *cpu);
void op_sub_a_d(CPU *cpu);
void op_sub_a_e(CPU *cpu);
void op_sub_a_h(CPU *cpu);
void op_sub_a_l(CPU *cpu);
void op_sub_a_a(CPU *cpu);

// ========== AND A_R ========== //
void op_and_a_b(CPU *cpu);
void op_and_a_c(CPU *cpu);
void op_and_a_d(CPU *cpu);
void op_and_a_e(CPU *cpu);
void op_and_a_h(CPU *cpu);
void op_and_a_l(CPU *cpu);
void op_and_a_a(CPU *cpu);

// ========== OR A_R ========== //
void op_or_a_b(CPU *cpu);
void op_or_a_c(CPU *cpu);
void op_or_a_d(CPU *cpu);
void op_or_a_e(CPU *cpu);
void op_or_a_h(CPU *cpu);
void op_or_a_l(CPU *cpu);
void op_or_a_a(CPU *cpu);

#endif //GAMEBOY_CPU_H