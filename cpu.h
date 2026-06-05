//
// Created by Karim Makhlouf on 05/06/2026.
//

#ifndef GAMEBOY_CPU_H
#define GAMEBOY_CPU_H

#include <stdint.h>

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
}CPU;

void cpu_init(CPU *cpu);

#endif //GAMEBOY_CPU_H