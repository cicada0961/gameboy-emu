cmake_minimum_required(VERSION 3.10)
project(gameboy C)

set(CMAKE_C_STANDARD 11)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

add_executable(gameboy main.c
        cpu.c
        cpu.h
        memory.c
        memory.h
        ppu.c
        ppu.h)

target_link_libraries(gameboy SDL2)