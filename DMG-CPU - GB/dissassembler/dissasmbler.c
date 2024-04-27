#include "dissasmbler.h"



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
        printf("[*] error when parsing args\nusage:\n\tdisassemble.exe <file>\n");
        return 1;
    }

    uint8_t* bin = NULL;
    long binLen = dw_fread(filename, &bin);

    // printf("%x%x%x%x\n",bin[0],bin[1],bin[2],bin[3]);

    


    int pc = 0;
    while (pc < binLen)
    {
        uint8_t opcode = bin[pc];
        OPCODE curOpcode = opcodes[opcode];

        char instBytes[9];

        if (curOpcode.len > 1)
        {
            char opcodeStr[24];
            uint16_t opcodeData = 0x0;

            if (curOpcode.len == 2)
            {
                opcodeData = bin[pc+1];
                snprintf(instBytes,sizeof(instBytes),"%02x %02x   ",bin[pc],bin[pc+1]);
            }
            else if (curOpcode.len == 3)
            {
                opcodeData = (bin[pc+2] << 8) | bin[pc+1];
                snprintf(instBytes,sizeof(instBytes),"%02x %02x %02x",bin[pc],bin[pc+1],bin[pc+2]);
            }

            snprintf(opcodeStr,sizeof(opcodeStr),curOpcode.name,opcodeData);
            printf("%04x: %s %s\n",pc,instBytes,opcodeStr);
        }
        else
        {
            snprintf(instBytes,sizeof(instBytes),"%02x      ",bin[pc]);
            printf("%04x: %s %s\n",pc,instBytes,curOpcode.name);
        }
        
        pc = pc + curOpcode.len;
    }


    free(bin);


    return 0;
}