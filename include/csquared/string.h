#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "vector.h"

typedef struct
{
	size_t size;
	char *memory;
	bool allocated;
} string_t;

int string_create(string_t *string);
int string_copy(string_t *string, char *buffer);
int string_concatenate(string_t *string, char *buffer);
int string_concatenate_character(string_t *string, char character);
int string_substring(size_t a, size_t b, string_t *input, string_t *output);
int string_find(string_t *string, char *substring, size_t *index);
int string_split(string_t *input, char *delimiter, vector_t *output_vector);
int string_copy_n(string_t *string, const char *buffer, size_t count);
int string_delete(string_t *string);