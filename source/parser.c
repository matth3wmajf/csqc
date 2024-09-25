#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

#include <csquared/scanner.h>
#include <csquared/parser.h>
#include <csquared/logger.h>
#include <csquared/escape.h>

const char *g_primitive_type_buffer[] = {"byte", "void"};
const uintmax_t g_primitive_type_buffer_size = sizeof(g_primitive_type_buffer) / sizeof(g_primitive_type_buffer[0]);

const char *g_type_qualifier_buffer[] = {"const", "volatile", "static", "extern", "inline", "register", "auto", "restrict"};
const uintmax_t g_type_qualifier_buffer_size = sizeof(g_type_qualifier_buffer) / sizeof(g_type_qualifier_buffer[0]);

const char *g_unary_operator_buffer[] = {"+", "-", "!", "~", "++", "--", "&", "*"};
const uintmax_t g_unary_operator_buffer_size = sizeof(g_unary_operator_buffer) / sizeof(g_unary_operator_buffer[0]);

const char *g_preunary_operator_buffer[] = {"+", "-", "!", "~", "++", "--", "&", "*"};
const uintmax_t g_preunary_operator_buffer_size = sizeof(g_preunary_operator_buffer) / sizeof(g_preunary_operator_buffer[0]);

const char *g_postunary_operator_buffer[] = {"++", "--"};
const uintmax_t g_postunary_operator_buffer_size = sizeof(g_postunary_operator_buffer) / sizeof(g_postunary_operator_buffer[0]);

const char *g_binary_operator_buffer[] = {"+", "-", "*", "/", "^", "%"};
const uintmax_t g_binary_operator_buffer_size = sizeof(g_binary_operator_buffer) / sizeof(g_binary_operator_buffer[0]);

char **g_typedef_buffer = NULL;
uintmax_t g_typedef_buffer_size = 0;

int parser_main(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size)
{
	/* The index of the current token we're working with. */
	uintmax_t l_i = 0;

	(*output_object_buffer_size)++;
	*output_object_buffer = realloc(*output_object_buffer, *output_object_buffer_size * sizeof(object_t));

	/* The file scope, also the root of all other nodes in the AST. */
	object_t *l_root_object = &(*output_object_buffer)[(*output_object_buffer_size) - 1];
	l_root_object->object_type = (uint16_t)(((uint16_t)OBJECT_PREFIX_SCP << 8) | (uint16_t)OBJECT_SUBTYPE_SCOPE_FLE);

	while(l_i < *input_token_buffer_size)
	{
		/* Parse constant(s)... */
lbl_handle_constants:
		if(is_possible_term(&input_token_buffer[l_i]))
		{
			/* Re-size the buffer of objects. */
			(*output_object_buffer_size)++;
			*output_object_buffer = realloc(*output_object_buffer, *output_object_buffer_size * sizeof(object_t));

			/* Write the object's data to the buffer of objects. */
			object_t *l_object = &(*output_object_buffer)[(*output_object_buffer_size) - 1];
			l_object->object_type = (uint16_t)(((uint16_t)OBJECT_PREFIX_CST << 8) | (uint16_t)input_token_buffer[l_i].token_type);
			memcpy(&input_token_buffer[l_i].value, &l_object->constant.value, sizeof(l_object->constant.value));

			/* Let's work with the next token. */
			l_i++;
		}
	}

	return 0;
}