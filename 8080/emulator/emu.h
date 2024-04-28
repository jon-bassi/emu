#pragma once

#include <stdint.h>

#include "dw_io.h"



#define ROM_START 0x0000
#define RAM_START 0x2000
#define VRAM_START 0x2400


typedef struct
{
    uint8_t s;  // sign
    uint8_t z;  // zero
    uint8_t a;  // aux carry
    uint8_t p;  // parity
    uint8_t c;  // carry
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


typedef struct
{
    uint8_t* rom;
    uint8_t ram[0x400];
    uint8_t vram[0x1c00];
} Memory;

typedef struct
{
    Registers registers;
    Memory memory;
} State;