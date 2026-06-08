#include <stdio.h>
#include <SDL2/SDL.h>
#include "cpu.h"
#include "memory.h"
#include "ppu.h"


int main(void) {
    CPU *cpu = malloc(sizeof(CPU));
    PPU *ppu = malloc(sizeof(PPU));

    cpu_init(cpu);
    ppu_init(ppu);
    cpu_check();

    FILE *f = fopen("rom.gb", "rb");
    if (f) {
        fread(memory, 1, 0x10000, f);
        fclose(f);
        printf("ROM chargée, premier octet : 0x%02X\n", memory[0x0100]);
    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window * window = SDL_CreateWindow(
        "Game Boy",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
        );
    if (!window) {
        printf("Erreur window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        return 1;
    }

    SDL_Texture *texture = SDL_CreateTexture(
      renderer,
      SDL_PIXELFORMAT_RGBA8888,
      SDL_TEXTUREACCESS_STATIC,
      160,
      144);
    if (!texture)
    {
        printf("Erreur texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (SDL_UpdateTexture(texture, NULL, ppu->pixels, 160 * sizeof(uint32_t)) != 0)
    {
        printf("Erreur SDL_UpdateTexture: %s\n", SDL_GetError());
        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        for (int i = 0; i < 70000; i++) {
            cpu_step(cpu);
            ppu_step(ppu);
        }

        SDL_UpdateTexture(texture, NULL, ppu->pixels, 160 * sizeof(uint32_t));
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, NULL, NULL);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
