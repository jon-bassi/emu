#pragma once

#include <stdint.h>

struct OPCODE
{
    uint8_t name[12];
    uint8_t len;
    uint8_t duration;
};

OPCODE opcodes[] = {
    {"NOP",1,4},        // 0x00
    {"LXI B,d16",3,10}, // 0x01
    {"STAX B",1,7},     // 0x02
    {"INX B",1,5},      // 0x03
    {"INR B",1,5},      // 0x04
    {"DCR B",1,5},      // 0x05
    {"MVI B,d8",2,7},   // 0x06
    {"RLC",1,4},        // 0x07
    {"NOP",1,4},        // 0x08
    {"DAD B",1,10},     // 0x09
    {"LDAX B",1,7},     // 0x0A
    {"DCX B",1,5},      // 0x0B
    {"INR C",1,5},      // 0x0C
    {"DCR C",1,5},      // 0x0D
    {"MVI C,d8",2,7},   // 0x0E
    {"RRC",1,4},        // 0x0F

    {"NOP",1,4},        // 0x10
    {"LXI D,d16",3,10}, // 0x11
    {"STAX D",1,7},     // 0x12
    {"INX D",1,5},      // 0x13
    {"INR D",1,5},      // 0x14
    {"DCR D",1,5},      // 0x15
    {"MVI D,d8",2,7},   // 0x16
    {"RAL",1,4},        // 0x17
    {"NOP",1,4},        // 0x18
    {"DAD D",1,10},     // 0x19
    {"LDAX D",1,7},     // 0x1A
    {"DCX D",1,5},      // 0x1B
    {"INR E",1,5},      // 0x1C
    {"DCR E",1,5},      // 0x1D
    {"MVI E,d8",2,7},   // 0x1E
    {"RAR",1,4},        // 0x1F

    {"NOP",1,4},        // 0x20
    {"LXI H,d16",3,10}, // 0x21
    {"SHLD a16",3,16},  // 0x22
    {"INX H",1,5},      // 0x23
    {"INR H",1,5},      // 0x24
    {"DCR H",1,5},      // 0x25
    {"MVI H,d8",2,7},   // 0x26
    {"DAA",1,4},        // 0x27
    {"NOP",1,4},        // 0x28
    {"DAD H",1,10},     // 0x29
    {"LHLD a16",3,16},  // 0x2A
    {"DCX H",1,5},      // 0x2B
    {"INR L",1,5},      // 0x2C
    {"DCR L",1,5},      // 0x2D
    {"MVI L,d8",2,7},   // 0x2E
    {"CMA",1,4},        // 0x2F

    {"NOP",1,4},        // 0x30
    {"LXI SP,d16",3,10},// 0x31
    {"STA a16",3,13},   // 0x32
    {"INX SP",1,5},     // 0x33
    {"INR M",1,10},     // 0x34
    {"DCR M",1,10},     // 0x35
    {"MVI H,d8",2,10},  // 0x36
    {"STC",1,4},        // 0x37
    {"NOP",1,4},        // 0x38
    {"DAD SP",1,10},    // 0x39
    {"LDA a16",3,13},   // 0x3A
    {"DCX SP",1,5},     // 0x3B
    {"INR A",1,5},      // 0x3C
    {"DCR A",1,5},      // 0x3D
    {"MVI A,d8",2,7},   // 0x3E
    {"CMC",1,4},        // 0x3F
};
    


