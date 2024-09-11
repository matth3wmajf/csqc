#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>

#include <csquared/scanner.h>
#include <csquared/parser.h>

const char *g_primitive_type_buffer[] = {"char", "int", "float", "double", "void", "short", "long"};
const uintmax_t g_primitive_type_buffer_size = sizeof(g_primitive_type_buffer) / sizeof(g_primitive_type_buffer[0]);

const char *g_type_qualifier_buffer[] = {"const", "volatile", "static", "extern", "inline", "register", "auto", "restrict"};
const uintmax_t g_type_qualifier_buffer_size = sizeof(g_type_qualifier_buffer) / sizeof(g_type_qualifier_buffer[0]);

const char *g_operator_buffer[] = {"+", "-", "*", "/", "^", "%"};
const uintmax_t g_operator_buffer_size = sizeof(g_operator_buffer) / sizeof(g_operator_buffer[0]);

int parser(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size)
{
	uintmax_t l_i = 0;

	while(l_i < *input_token_buffer_size)
	{
		if()
	}

	return -1;
}