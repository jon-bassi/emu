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

    int i = 0;
    while (i < binLen)
    {
        uint8_t opcode = bin[i];
        OPCODE curOpcode = opcodes[opcode];
        printf("%04x: %s\n",i,curOpcode.name);
        i = i + curOpcode.len;
        if (i > 200)
        {
            break;
        }
    }


    free(bin);


    return 0;
}