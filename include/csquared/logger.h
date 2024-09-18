#pragma once

#include <stdio.h>

typedef struct
{
	const char *key;
	const char *value;
} log_entry_t;

void loggerf(FILE *stream, const log_entry_t entry_buffer[], int entry_buffer_size, ...);