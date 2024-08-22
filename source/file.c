#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include <csquared/file.h>

/* Basic input & output files. */
char *g_file_name = NULL;
FILE *g_file_handle = NULL;
intmax_t g_file_size = -1;