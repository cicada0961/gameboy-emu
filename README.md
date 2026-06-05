# gameboy-emu

A Game Boy emulator written in C, built from scratch as a learning project.

## État actuel

Squelette fonctionnel :
- Espace mémoire 64Ko (`memory.c`)
- Registres CPU complets avec unions/bit-fields (`cpu.h`)
- Fenêtre SDL2 avec framebuffer (`main.c`)
- Chargement de ROM binaire

## Structure

```
gameboy/
├── main.c       — boucle principale, SDL2, chargement ROM
├── cpu.h        — registres AF/BC/DE/HL/SP/PC, flags Z/N/H/C
├── cpu.c        — initialisation CPU
├── memory.h     — déclarations read/write
└── memory.c     — espace d'adressage 0x0000-0xFFFF
```

## Dépendances

- SDL2 (`brew install sdl2`)
- CMake 3.10+
- Compilateur C11

## Compilation

```bash
mkdir build && cd build
cmake ..
make
./gameboy
```

## Roadmap

- [ ] Boucle CPU — fetch / decode / execute
- [ ] Implémentation des opcodes (instruction set SM83)
- [ ] PPU — rendu des tuiles et sprites
- [ ] Timers et interruptions
- [ ] Joypad
- [ ] Son (APU)

## Ressources

- [Pan Docs](https://gbdev.io/pandocs/) — documentation complète du hardware Game Boy
- [SM83 Instruction Set](https://gbdev.io/gb-opcodes/optables/) — table des opcodes
- [Game Boy CPU Manual](http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf)