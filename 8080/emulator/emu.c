#include "emu.h"



void UndefinedInstruction(State* programState)
{
    printf("[!] error: Undefined Instruciton at PC: %04x\n",programState->registers.pc);
    exit(1);
}






int main(int argc, void** argv)
{
    // parse args
    char* filename = '\0';

    if (argc > 1)
    {
        filename = argv[1];
    }
    if (argc != 2)
    {
        printf("[*] error when parsing args\nusage:\n\temu.exe <file>\n");
        return 1;
    }

    uint8_t* bin = NULL;
    long binLen = dw_fread(filename, &bin);


    // init memory
    State progState;
    memset(&progState,0x0,sizeof(progState));

    progState.memory.rom = bin;
    
    
    while (1)
    {
        uint8_t* opcode = &(progState.memory.rom[progState.registers.pc]);
        
        switch (*opcode)
        {
            case 0x00: // NOP
                progState.registers.pc += 1;
                break;
            case 0x01: // LXI B,d16
                progState.registers.pc += 3;

                progState.registers.c = opcode[1];  // lo
                progState.registers.b = opcode[2];  // hi
                break;
            case 0x02: // STAX B
                progState.registers.pc += 1;

                uint16_t addr = ((progState.registers.b << 8) | progState.registers.c) - RAM_START;
                progState.memory.ram[addr] = progState.registers.a;
                break;
            case 0x03: // INX B
                progState.registers.pc += 1;

                uint16_t value = ((progState.registers.b << 8) | progState.registers.c) + 1;
                progState.registers.b = (value >> 8) && 0xff;
                progState.registers.c = value & 0xff;
                break;
            case 0x04: UndefinedInstruction(&progState); break;
            case 0x05: UndefinedInstruction(&progState); break;
            case 0x06: UndefinedInstruction(&progState); break;
            case 0x07: UndefinedInstruction(&progState); break;
            case 0x08: UndefinedInstruction(&progState); break;
            case 0x09: UndefinedInstruction(&progState); break;
            case 0x0A: UndefinedInstruction(&progState); break;
            case 0x0B: UndefinedInstruction(&progState); break;
            case 0x0C: UndefinedInstruction(&progState); break;
            case 0x0D: UndefinedInstruction(&progState); break;
            case 0x0E: UndefinedInstruction(&progState); break;
            case 0x0F: UndefinedInstruction(&progState); break;
            case 0x10: UndefinedInstruction(&progState); break;
            case 0x11: UndefinedInstruction(&progState); break;
            case 0x12: UndefinedInstruction(&progState); break;
            case 0x13: UndefinedInstruction(&progState); break;
            case 0x14: UndefinedInstruction(&progState); break;
            case 0x15: UndefinedInstruction(&progState); break;
            case 0x16: UndefinedInstruction(&progState); break;
            case 0x17: UndefinedInstruction(&progState); break;
            case 0x18: UndefinedInstruction(&progState); break;
            case 0x19: UndefinedInstruction(&progState); break;
            case 0x1A: UndefinedInstruction(&progState); break;
            case 0x1B: UndefinedInstruction(&progState); break;
            case 0x1C: UndefinedInstruction(&progState); break;
            case 0x1D: UndefinedInstruction(&progState); break;
            case 0x1E: UndefinedInstruction(&progState); break;
            case 0x1F: UndefinedInstruction(&progState); break;
            case 0x20: UndefinedInstruction(&progState); break;
            case 0x21: UndefinedInstruction(&progState); break;
            case 0x22: UndefinedInstruction(&progState); break;
            case 0x23: UndefinedInstruction(&progState); break;
            case 0x24: UndefinedInstruction(&progState); break;
            case 0x25: UndefinedInstruction(&progState); break;
            case 0x26: UndefinedInstruction(&progState); break;
            case 0x27: UndefinedInstruction(&progState); break;
            case 0x28: UndefinedInstruction(&progState); break;
            case 0x29: UndefinedInstruction(&progState); break;
            case 0x2A: UndefinedInstruction(&progState); break;
            case 0x2B: UndefinedInstruction(&progState); break;
            case 0x2C: UndefinedInstruction(&progState); break;
            case 0x2D: UndefinedInstruction(&progState); break;
            case 0x2E: UndefinedInstruction(&progState); break;
            case 0x2F: UndefinedInstruction(&progState); break;
            case 0x30: UndefinedInstruction(&progState); break;
            case 0x31: UndefinedInstruction(&progState); break;
            case 0x32: UndefinedInstruction(&progState); break;
            case 0x33: UndefinedInstruction(&progState); break;
            case 0x34: UndefinedInstruction(&progState); break;
            case 0x35: UndefinedInstruction(&progState); break;
            case 0x36: UndefinedInstruction(&progState); break;
            case 0x37: UndefinedInstruction(&progState); break;
            case 0x38: UndefinedInstruction(&progState); break;
            case 0x39: UndefinedInstruction(&progState); break;
            case 0x3A: UndefinedInstruction(&progState); break;
            case 0x3B: UndefinedInstruction(&progState); break;
            case 0x3C: UndefinedInstruction(&progState); break;
            case 0x3D: UndefinedInstruction(&progState); break;
            case 0x3E: UndefinedInstruction(&progState); break;
            case 0x3F: UndefinedInstruction(&progState); break;
            
            /* MOV GROUP */
            case 0x40: UndefinedInstruction(&progState); break;
            case 0x41: UndefinedInstruction(&progState); break;
            case 0x42: UndefinedInstruction(&progState); break;
            case 0x43: UndefinedInstruction(&progState); break;
            case 0x44: UndefinedInstruction(&progState); break;
            case 0x45: UndefinedInstruction(&progState); break;
            case 0x46: UndefinedInstruction(&progState); break;
            case 0x47: UndefinedInstruction(&progState); break;
            case 0x48: UndefinedInstruction(&progState); break;
            case 0x49: UndefinedInstruction(&progState); break;
            case 0x4A: UndefinedInstruction(&progState); break;
            case 0x4B: UndefinedInstruction(&progState); break;
            case 0x4C: UndefinedInstruction(&progState); break;
            case 0x4D: UndefinedInstruction(&progState); break;
            case 0x4E: UndefinedInstruction(&progState); break;
            case 0x4F: UndefinedInstruction(&progState); break;
            case 0x50: UndefinedInstruction(&progState); break;
            case 0x51: UndefinedInstruction(&progState); break;
            case 0x52: UndefinedInstruction(&progState); break;
            case 0x53: UndefinedInstruction(&progState); break;
            case 0x54: UndefinedInstruction(&progState); break;
            case 0x55: UndefinedInstruction(&progState); break;
            case 0x56: UndefinedInstruction(&progState); break;
            case 0x57: UndefinedInstruction(&progState); break;
            case 0x58: UndefinedInstruction(&progState); break;
            case 0x59: UndefinedInstruction(&progState); break;
            case 0x5A: UndefinedInstruction(&progState); break;
            case 0x5B: UndefinedInstruction(&progState); break;
            case 0x5C: UndefinedInstruction(&progState); break;
            case 0x5D: UndefinedInstruction(&progState); break;
            case 0x5E: UndefinedInstruction(&progState); break;
            case 0x5F: UndefinedInstruction(&progState); break;
            case 0x60: UndefinedInstruction(&progState); break;
            case 0x61: UndefinedInstruction(&progState); break;
            case 0x62: UndefinedInstruction(&progState); break;
            case 0x63: UndefinedInstruction(&progState); break;
            case 0x64: UndefinedInstruction(&progState); break;
            case 0x65: UndefinedInstruction(&progState); break;
            case 0x66: UndefinedInstruction(&progState); break;
            case 0x67: UndefinedInstruction(&progState); break;
            case 0x68: UndefinedInstruction(&progState); break;
            case 0x69: UndefinedInstruction(&progState); break;
            case 0x6A: UndefinedInstruction(&progState); break;
            case 0x6B: UndefinedInstruction(&progState); break;
            case 0x6C: UndefinedInstruction(&progState); break;
            case 0x6D: UndefinedInstruction(&progState); break;
            case 0x6E: UndefinedInstruction(&progState); break;
            case 0x6F: UndefinedInstruction(&progState); break;
            case 0x70: UndefinedInstruction(&progState); break;
            case 0x71: UndefinedInstruction(&progState); break;
            case 0x72: UndefinedInstruction(&progState); break;
            case 0x73: UndefinedInstruction(&progState); break;
            case 0x74: UndefinedInstruction(&progState); break;
            case 0x75: UndefinedInstruction(&progState); break;
            case 0x76: UndefinedInstruction(&progState); break;
            case 0x77: UndefinedInstruction(&progState); break;
            case 0x78: UndefinedInstruction(&progState); break;
            case 0x79: UndefinedInstruction(&progState); break;
            case 0x7A: UndefinedInstruction(&progState); break;
            case 0x7B: UndefinedInstruction(&progState); break;
            case 0x7C: UndefinedInstruction(&progState); break;
            case 0x7D: UndefinedInstruction(&progState); break;
            case 0x7E: UndefinedInstruction(&progState); break;
            case 0x7F: UndefinedInstruction(&progState); break;

            /* ARITHMETIC GROUP */
            case 0x80: UndefinedInstruction(&progState); break;
            case 0x81: UndefinedInstruction(&progState); break;
            case 0x82: UndefinedInstruction(&progState); break;
            case 0x83: UndefinedInstruction(&progState); break;
            case 0x84: UndefinedInstruction(&progState); break;
            case 0x85: UndefinedInstruction(&progState); break;
            case 0x86: UndefinedInstruction(&progState); break;
            case 0x87: UndefinedInstruction(&progState); break;
            case 0x88: UndefinedInstruction(&progState); break;
            case 0x89: UndefinedInstruction(&progState); break;
            case 0x8A: UndefinedInstruction(&progState); break;
            case 0x8B: UndefinedInstruction(&progState); break;
            case 0x8C: UndefinedInstruction(&progState); break;
            case 0x8D: UndefinedInstruction(&progState); break;
            case 0x8E: UndefinedInstruction(&progState); break;
            case 0x8F: UndefinedInstruction(&progState); break;
            case 0x90: UndefinedInstruction(&progState); break;
            case 0x91: UndefinedInstruction(&progState); break;
            case 0x92: UndefinedInstruction(&progState); break;
            case 0x93: UndefinedInstruction(&progState); break;
            case 0x94: UndefinedInstruction(&progState); break;
            case 0x95: UndefinedInstruction(&progState); break;
            case 0x96: UndefinedInstruction(&progState); break;
            case 0x97: UndefinedInstruction(&progState); break;
            case 0x98: UndefinedInstruction(&progState); break;
            case 0x99: UndefinedInstruction(&progState); break;
            case 0x9A: UndefinedInstruction(&progState); break;
            case 0x9B: UndefinedInstruction(&progState); break;
            case 0x9C: UndefinedInstruction(&progState); break;
            case 0x9D: UndefinedInstruction(&progState); break;
            case 0x9E: UndefinedInstruction(&progState); break;
            case 0x9F: UndefinedInstruction(&progState); break;
            case 0xA0: UndefinedInstruction(&progState); break;
            case 0xA1: UndefinedInstruction(&progState); break;
            case 0xA2: UndefinedInstruction(&progState); break;
            case 0xA3: UndefinedInstruction(&progState); break;
            case 0xA4: UndefinedInstruction(&progState); break;
            case 0xA5: UndefinedInstruction(&progState); break;
            case 0xA6: UndefinedInstruction(&progState); break;
            case 0xA7: UndefinedInstruction(&progState); break;
            case 0xA8: UndefinedInstruction(&progState); break;
            case 0xA9: UndefinedInstruction(&progState); break;
            case 0xAA: UndefinedInstruction(&progState); break;
            case 0xAB: UndefinedInstruction(&progState); break;
            case 0xAC: UndefinedInstruction(&progState); break;
            case 0xAD: UndefinedInstruction(&progState); break;
            case 0xAE: UndefinedInstruction(&progState); break;
            case 0xAF: UndefinedInstruction(&progState); break;
            case 0xB0: UndefinedInstruction(&progState); break;
            case 0xB1: UndefinedInstruction(&progState); break;
            case 0xB2: UndefinedInstruction(&progState); break;
            case 0xB3: UndefinedInstruction(&progState); break;
            case 0xB4: UndefinedInstruction(&progState); break;
            case 0xB5: UndefinedInstruction(&progState); break;
            case 0xB6: UndefinedInstruction(&progState); break;
            case 0xB7: UndefinedInstruction(&progState); break;
            case 0xB8: UndefinedInstruction(&progState); break;
            case 0xB9: UndefinedInstruction(&progState); break;
            case 0xBA: UndefinedInstruction(&progState); break;
            case 0xBB: UndefinedInstruction(&progState); break;
            case 0xBC: UndefinedInstruction(&progState); break;
            case 0xBD: UndefinedInstruction(&progState); break;
            case 0xBE: UndefinedInstruction(&progState); break;
            case 0xBF: UndefinedInstruction(&progState); break;
            case 0xC0: UndefinedInstruction(&progState); break;
            case 0xC1: UndefinedInstruction(&progState); break;
            case 0xC2: UndefinedInstruction(&progState); break;
            case 0xC3: UndefinedInstruction(&progState); break;
            case 0xC4: UndefinedInstruction(&progState); break;
            case 0xC5: UndefinedInstruction(&progState); break;
            case 0xC6: UndefinedInstruction(&progState); break;
            case 0xC7: UndefinedInstruction(&progState); break;
            case 0xC8: UndefinedInstruction(&progState); break;
            case 0xC9: UndefinedInstruction(&progState); break;
            case 0xCA: UndefinedInstruction(&progState); break;
            case 0xCB: UndefinedInstruction(&progState); break;
            case 0xCC: UndefinedInstruction(&progState); break;
            case 0xCD: UndefinedInstruction(&progState); break;
            case 0xCE: UndefinedInstruction(&progState); break;
            case 0xCF: UndefinedInstruction(&progState); break;
            case 0xD0: UndefinedInstruction(&progState); break;
            case 0xD1: UndefinedInstruction(&progState); break;
            case 0xD2: UndefinedInstruction(&progState); break;
            case 0xD3: UndefinedInstruction(&progState); break;
            case 0xD4: UndefinedInstruction(&progState); break;
            case 0xD5: UndefinedInstruction(&progState); break;
            case 0xD6: UndefinedInstruction(&progState); break;
            case 0xD7: UndefinedInstruction(&progState); break;
            case 0xD8: UndefinedInstruction(&progState); break;
            case 0xD9: UndefinedInstruction(&progState); break;
            case 0xDA: UndefinedInstruction(&progState); break;
            case 0xDB: UndefinedInstruction(&progState); break;
            case 0xDC: UndefinedInstruction(&progState); break;
            case 0xDD: UndefinedInstruction(&progState); break;
            case 0xDE: UndefinedInstruction(&progState); break;
            case 0xDF: UndefinedInstruction(&progState); break;
            case 0xE0: UndefinedInstruction(&progState); break;
            case 0xE1: UndefinedInstruction(&progState); break;
            case 0xE2: UndefinedInstruction(&progState); break;
            case 0xE3: UndefinedInstruction(&progState); break;
            case 0xE4: UndefinedInstruction(&progState); break;
            case 0xE5: UndefinedInstruction(&progState); break;
            case 0xE6: UndefinedInstruction(&progState); break;
            case 0xE7: UndefinedInstruction(&progState); break;
            case 0xE8: UndefinedInstruction(&progState); break;
            case 0xE9: UndefinedInstruction(&progState); break;
            case 0xEA: UndefinedInstruction(&progState); break;
            case 0xEB: UndefinedInstruction(&progState); break;
            case 0xEC: UndefinedInstruction(&progState); break;
            case 0xED: UndefinedInstruction(&progState); break;
            case 0xEE: UndefinedInstruction(&progState); break;
            case 0xEF: UndefinedInstruction(&progState); break;
            case 0xF0: UndefinedInstruction(&progState); break;
            case 0xF1: UndefinedInstruction(&progState); break;
            case 0xF2: UndefinedInstruction(&progState); break;
            case 0xF3: UndefinedInstruction(&progState); break;
            case 0xF4: UndefinedInstruction(&progState); break;
            case 0xF5: UndefinedInstruction(&progState); break;
            case 0xF6: UndefinedInstruction(&progState); break;
            case 0xF7: UndefinedInstruction(&progState); break;
            case 0xF8: UndefinedInstruction(&progState); break;
            case 0xF9: UndefinedInstruction(&progState); break;
            case 0xFA: UndefinedInstruction(&progState); break;
            case 0xFB: UndefinedInstruction(&progState); break;
            case 0xFC: UndefinedInstruction(&progState); break;
            case 0xFD: UndefinedInstruction(&progState); break;
            case 0xFE: UndefinedInstruction(&progState); break;
            case 0xFF: UndefinedInstruction(&progState); break;
            default: UndefinedInstruction(&progState); break;
        }
    }
    
    
    
    
    return 0;
}