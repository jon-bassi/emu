#pragma once

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

struct Regs_T
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t f;
    uint8_t g;
    uint8_t h;
    uint8_t l;
};

extern struct Regs_T regs;

enum FLAGS
{
    FLG_ZERO    = 0x80,
    FLG_SUB     = 0x40,
    FLG_HCARRY  = 0x20,
    FLG_CARRY   = 0x10
};

typedef struct
{
    bool zero;
    bool subtract;
    bool half_carry;
    bool carry;
} Flags_T;

static void reg_initialize();

static void get_af(uint16_t*);
static void set_af(uint16_t);

static void get_bc(uint16_t*);
static void set_bc(uint16_t);

static void get_de(uint16_t*);
static void set_de(uint16_t);

static void get_hl(uint16_t*);
static void set_hl(uint16_t);

static void u8_to_Flags(uint8_t, Flags_T*);
static void Flags_to_u8(Flags_T*, uint8_t*);