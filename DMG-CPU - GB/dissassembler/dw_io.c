#include "dw_io.h"




long dw_fread(const char* filename, uint8_t** data)
{
    long bufsize = -1;
    
    FILE *fp = fopen(filename,"r");

    if (fp != NULL)
    {
        if (fseek(fp, 0L, SEEK_END) == 0)
        {
            bufsize = ftell(fp);
            if (bufsize == -1 || bufsize > MAX_BUFFER_SIZE)
            {
                printf("[!] error when seeking to EOF: %i\n",bufsize);
                fclose(fp);
                return -1;
            }

            *data = malloc(bufsize + 1);
            memset(*data, 0x0, bufsize + 1);

            if (fseek(fp, 0L, SEEK_SET) != 0)
            {
                printf("[!] error when seeking to Start OF\n");
                fclose(fp);
                free(*data);
                return -1;
            }

            size_t newlen = fread(*data, sizeof(uint8_t), bufsize, fp);
            if (ferror(fp) != 0)
            {
                printf("[!] error reading file\n");
                fclose(fp);
                free(*data);
                return -1;
            }
        }
        fclose(fp);
        return bufsize;
    }
    
    return -1;
}