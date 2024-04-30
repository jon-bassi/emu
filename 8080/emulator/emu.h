#pragma once

#include <stdint.h>
#include <Windows.h>

#include "dw_io.h"
#include <ncurses/ncurses.h>



#define ROM_START 0x0000
#define RAM_START 0x2000
#define VRAM_START 0x2400


typedef struct
{
    uint8_t s;   // sign
    uint8_t z;   // zero
    uint8_t ac;  // aux carry
    uint8_t p;   // parity
    uint8_t c;   // carry
} Flags;


typedef struct
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint16_t sp;
    uint16_t pc;
    Flags flags;
} Registers;


typedef struct __attribute__((packed))
{
    uint8_t rom[0x2000];
    uint8_t ram[0x400];
    uint8_t vram[0x1c00];
} Memory;

typedef struct
{
    Memory memory;
    Registers registers;
} State;
