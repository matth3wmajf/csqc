#pragma once

#include <stdint.h>

typedef struct
{
	enum
	{
		SYMBOL_EXTERNAL = 0b00000001,
		SYMBOL_FUNCTION = 0b00000101,
		SYMBOL_UNKNOWN = 0b00000000,
		SYMBOL_TYPEDEF = 0b00000011,
		SYMBOL_STATIC = 0b00000100,
		SYMBOL_LABEL = 0b00000010,
	} type;
	char *name;
	uintmax_t name_size;
} symb_t;

extern symb_t *symbol_buffer;
extern uintmax_t symbol_buffer_size;