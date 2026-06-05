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

#define LD_R_R(name, dst, src) \
void op_ld_##name(CPU *cpu) { cpu->dst = cpu->src; }

extern void (*opcodes[256])(CPU *cpu);

void cpu_init(CPU *cpu);
void cpu_step(CPU *cpu);

void op_unknow(CPU *cpu);
void op_nop(CPU *cpu);
void op_ld_bc_nn(CPU *cpu);
void op_jp_nn(CPU *cpu);
void op_halted(CPU *cpu);

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

#endif //GAMEBOY_CPU_H