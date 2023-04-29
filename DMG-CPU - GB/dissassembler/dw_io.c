#include "dw_io.h"




uint8_t* dw_fread(const char* filename)
{
    uint8_t* data = NULL;
    
    FILE *fp = fopen(filename,"r");

    if (fp != NULL)
    {
        if (fseek(fp, 0L, SEEK_END) == 0)
        {
            long bufsize = ftell(fp);
            if (bufsize == -1 || bufsize > MAX_BUFFER_SIZE)
            {
                printf("[!] error when seeking to EOF: %i\n",bufsize);
                fclose(fp);
                return NULL;
            }

            data = malloc(bufsize + 1);
            memset(data, 0x0, bufsize + 1);

            if (fseek(fp, 0L, SEEK_SET) != 0)
            {
                printf("[!] error when seeking to Start OF\n");
                fclose(fp);
                free(data);
                return NULL;
            }

            size_t newlen = fread(data, sizeof(uint8_t), bufsize, fp);
            if (ferror(fp) != 0)
            {
                printf("[!] error reading file\n");
                fclose(fp);
                free(data);
                return NULL;
            }
        }
        fclose(fp);
        return data;
    }
    
    return NULL;
}