//
// Created by Karim Makhlouf on 08/06/2026.
//

#include "ppu.h"

void ppu_init(PPU *ppu) {
    ppu->current_line = 0;

    for (int i = 0; i < 160 * 144; i++) {
        ppu->pixels[i] = 0;
    }
}

void ppu_render_line(PPU *ppu) {
    int line = ppu->current_line;
    if (line >= 144) return;

    for (int x = 0; x < 160; x++) {

        int tile_x = x / 8;
        int tile_y = line / 8;
        uint8_t tile_index = memory[0x9800 + tile_y * 32 + tile_x];

        uint16_t tile_addr = 0x8000 + tile_index * 16;

        int line_in_tile = line % 8;

        uint8_t lo = memory[tile_addr + line_in_tile * 2];
        uint8_t hi = memory[tile_addr + line_in_tile * 2 + 1];

        int bit = 7 - (x % 8);
        uint8_t color = ((hi >> bit) & 1) << 1 | ((lo >> bit) & 1);

        uint32_t palette[] = {0xFFFFFFFF, 0xAAAAAAFF, 0x555555FF, 0x000000FF};
        ppu->pixels[line * 160 + x] = palette[color];
    }
}

void ppu_step(PPU *ppu) {
    ppu_render_line(ppu);
    ppu->current_line++;
    if (ppu->current_line > 153)
        ppu->current_line = 0;
    memory[0xFF44] = ppu->current_line;
}
