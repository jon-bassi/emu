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

    uint8_t* bin = dw_fread(filename);

    printf("%x%x%x%x\n",bin[0],bin[1],bin[2],bin[3]);

    free(bin);


    return 0;
}