#include "reg.h"

struct Regs_T regs;

/**
 * @brief initialize
 * 
 */
static void reg_initialize()
{
    memset(&regs,0x0,sizeof(regs));
}

static void get_af(uint16_t* var)
{
    *var = regs.a << 8 | regs.f;
}

static void set_af(uint16_t val)
{
    regs.a = (val & 0xFF00) >> 8;
    regs.f = (val & 0xFF);
}

static void get_bc(uint16_t* var)
{
    *var = regs.b << 8 | regs.c;
}

static void set_bc(uint16_t val)
{
    regs.b = (val & 0xFF00) >> 8;
    regs.c = (val & 0xFF);
}

static void get_de(uint16_t* var)
{
    *var = regs.d << 8 | regs.e;
}

static void set_de(uint16_t val)
{
    regs.d = (val & 0xFF00) >> 8;
    regs.e = (val & 0xFF);
}

static void get_hl(uint16_t* var)
{
    *var = regs.h << 8 | regs.l;
}

static void set_hl(uint16_t val)
{
    regs.h = (val & 0xFF00) >> 8;
    regs.l = (val & 0xFF);
}

static void u8_to_Flags(uint8_t u8, Flags_T* var)
{
    var->zero       = u8 & FLG_ZERO;
    var->subtract   = u8 & FLG_SUB;
    var->half_carry = u8 & FLG_HCARRY;
    var->carry      = u8 & FLG_CARRY;
}

static void Flags_to_u8(Flags_T* val, uint8_t* var)
{
    *var = 0;
    if (val->zero)
    {
        *var |= FLG_ZERO;
    }
    if (val->subtract)
    {
        *var |= FLG_SUB;
    }
    if (val->half_carry)
    {
        *var |= FLG_HCARRY;
    }
    if (val->carry)
    {
        *var |= FLG_CARRY;
    }
}