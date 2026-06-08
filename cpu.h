//
// Created by Karim Makhlouf on 05/06/2026.
//

#ifndef GAMEBOY_CPU_H
#define GAMEBOY_CPU_H

#include <stdint.h>
#include <stdio.h>

#include "memory.h"

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

#define XOR_A_R(name, src) \
void op_xor_##name(CPU *cpu){ \
cpu->A = cpu->A ^ cpu->src; \
cpu->fZ = (cpu->A == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
cpu->fC = 0; \
}

#define CP_A_R(name, src) \
void op_cp_##name(CPU *cpu){ \
uint16_t res = cpu->A - cpu->src; \
cpu->fZ = (res == 0); \
cpu->fN = 1; \
cpu->fH = ((cpu->A & 0xF) < (cpu->src & 0xF)); \
cpu->fC = (cpu->A < cpu->src); \
}

#define INC_R(name, src) \
void op_inc_##name(CPU *cpu){ \
cpu->fH = ((cpu->src & 0xF) == 0xF); \
cpu->src++; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
}

#define INC_RR(name, src) \
void op_inc_##name(CPU *cpu){ \
cpu->src++; \
}

#define DEC_R(name, src) \
void op_dec_##name(CPU *cpu){ \
cpu->fH = ((cpu->src & 0xF) == 0x0); \
cpu->src--; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 1; \
}

#define PUSH_R_R(name, src) \
void op_push_##name(CPU *cpu){ \
cpu->SP -= 2; \
write(cpu->SP + 1, cpu->src >> 8); \
write(cpu->SP, cpu->src & 0xFF); \
}

#define POP_R_R(name, src) \
void op_pop_##name(CPU *cpu){ \
uint8_t lo = read(cpu->SP); \
uint8_t hi = read(cpu->SP + 1); \
cpu->src = lo | (hi << 8); \
cpu->SP += 2; \
}

#define LD_R_HL(name, dst) \
void op_ld_##name##_hl(CPU *cpu) { \
cpu->dst = read(cpu->HL); \
}

#define LD_HL_R(name, src) \
void op_ld_hl_##name(CPU *cpu){ \
write(cpu->HL, cpu->src); \
}

#define RLC_R(name, src) \
void op_rlc_##name(CPU *cpu){ \
uint8_t bit7 = (cpu->src >> 7) & 1; \
cpu->src = (cpu->src << 1) | bit7; \
cpu->fC = bit7; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
}

#define RRC_R(name, src) \
void op_rrc_##name(CPU *cpu){ \
uint8_t bit0 = cpu->src & 1; \
cpu->src = (cpu->src >> 1) | (bit0 << 7); \
cpu->fC = bit0; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
}

#define RL_R(name, src) \
void op_rl_##name(CPU *cpu){ \
uint8_t bit7 = (cpu->src >> 7) & 1; \
cpu->src = (cpu->src << 1) | cpu->fC; \
cpu->fC = bit7; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
}

#define RR_R(name, src) \
void op_rr_##name(CPU *cpu){ \
uint8_t bit0 = cpu->src & 1; \
cpu->src = (cpu->src >> 1) | (cpu->fC << 7); \
cpu->fC = bit0; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
}

#define SLA_R(name, src) \
void op_sla_##name(CPU *cpu){ \
cpu->fC = (cpu->src >> 7) & 1; \
cpu->src = cpu->src << 1; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
}

#define SRA_R(name, src) \
void op_sra_##name(CPU *cpu){ \
cpu->fC = cpu->src & 1; \
cpu->src = (cpu->src >> 1) | (cpu->src & 0x80); \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
}

#define SRL_R(name, src) \
void op_srl_##name(CPU *cpu){ \
cpu->fC = cpu->src & 1; \
cpu->src = cpu->src >> 1; \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
}

#define SWAP_R(name, src) \
void op_swap_##name(CPU *cpu){ \
cpu->src = ((cpu->src & 0x0F) << 4) | ((cpu->src & 0xF0) >> 4); \
cpu->fZ = (cpu->src == 0); \
cpu->fN = 0; \
cpu->fH = 0; \
cpu->fC = 0; \
}

#define BIT_N_R(bit, name, src) \
void op_bit_##bit##_##name(CPU *cpu) { \
uint8_t val = (cpu->src >> bit) & 1; \
cpu->fZ = (val == 0); \
cpu->fN = 0; \
cpu->fH = 1; \
}
//====================

extern void (*opcodes[256])(CPU *cpu);
extern void (*cb_opcodes[256])(CPU *cpu);

void cpu_init(CPU *cpu);
void cpu_step(CPU *cpu);
void cpu_check(void);

void op_unknow(CPU *cpu);
void op_nop(CPU *cpu);
void op_ld_bc_nn(CPU *cpu);
void op_ld_hl_nn(CPU *cpu);
void op_jp_nn(CPU *cpu);
void op_halted(CPU *cpu);
void op_ret(CPU *cpu);
void op_call_nn(CPU *cpu);
void op_add_a_B(CPU *cpu);
void op_ld_a_nn(CPU *cpu);
void op_ldh_a_n(CPU *cpu);
void op_ldh_n_a(CPU *cpu);
void op_cp_n(CPU *cpu);
void op_jr_e(CPU *cpu);
void op_jr_nz(CPU *cpu);
void op_jr_z_e(CPU *cpu);
void op_ei(CPU *cpu);
void op_ld_bc_a(CPU *cpu);
void op_ld_a_bc(CPU *cpu);
void op_ldi_a_hl(CPU *cpu);
void op_cb(CPU *cpu);

#endif //GAMBOY_CPU