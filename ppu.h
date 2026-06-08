//
// Created by Karim Makhlouf on 08/06/2026.
//

#ifndef GAMEBOY_PPU_H
#define GAMEBOY_PPU_H

#include "memory.h"

typedef struct {
    uint32_t pixels[160 * 144];
    int current_line;
}PPU;

void ppu_init(PPU *ppu);
void ppu_render_line(PPU *ppu);
void ppu_step(PPU *ppu);


#endif //GAMEBOY_PPU_H
