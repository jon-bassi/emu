#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// 200 MB
#define MAX_BUFFER_SIZE     200000000

long dw_fread(const char* filname, uint8_t** data);
