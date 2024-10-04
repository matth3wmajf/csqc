#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

#include <csquared/scanner.h>
#include <csquared/parser.h>
#include <csquared/logger.h>
#include <csquared/escape.h>

const char *g_type_qualifier_buffer[] = {"const", "volatile"};
const uintmax_t g_type_qualifier_buffer_size = sizeof(g_type_qualifier_buffer) / sizeof(g_type_qualifier_buffer[0]);

const char *g_struct_or_union_buffer[] = {"struct", "union"};
const uintmax_t g_struct_or_union_buffer_size = sizeof(g_struct_or_union_buffer) / sizeof(g_struct_or_union_buffer[0]);

const char *g_type_specifier_buffer[] = {"void", "byte", "signed", "unsigned"};
const uintmax_t g_type_specifier_buffer_size = sizeof(g_type_specifier_buffer) / sizeof(g_type_specifier_buffer[0]);

const char *g_unary_operator_buffer[] = {"+", "-", "!", "~", "++", "--", "&", "*"};
const uintmax_t g_unary_operator_buffer_size = sizeof(g_unary_operator_buffer) / sizeof(g_unary_operator_buffer[0]);

const char *g_preunary_operator_buffer[] = {"+", "-", "!", "~", "++", "--", "&", "*"};
const uintmax_t g_preunary_operator_buffer_size = sizeof(g_preunary_operator_buffer) / sizeof(g_preunary_operator_buffer[0]);

const char *g_parenthesis_buffer[] = {"(", ")"};
const uintmax_t g_parentheses_buffer_size = sizeof(g_parenthesis_buffer) / sizeof(g_parenthesis_buffer[0]);

const char *g_braces_buffer[] = {"{", "}"};
const uintmax_t g_braces_buffer_size = sizeof(g_braces_buffer) / sizeof(g_braces_buffer[0]);

const char *g_brackets_buffer[] = {"[", "]"};
const uintmax_t g_brackets_buffer_size = sizeof(g_brackets_buffer) / sizeof(g_brackets_buffer[0]);

const char *g_semicolon_buffer[] = {";"};
const uintmax_t g_semicolon_buffer_size = sizeof(g_semicolon_buffer) / sizeof(g_semicolon_buffer[0]);

const char *g_postunary_operator_buffer[] = {"++", "--"};
const uintmax_t g_postunary_operator_buffer_size = sizeof(g_postunary_operator_buffer) / sizeof(g_postunary_operator_buffer[0]);

const char *g_binary_operator_buffer[] = {"+", "-", "*", "/", "^", "%"};
const uintmax_t g_binary_operator_buffer_size = sizeof(g_binary_operator_buffer) / sizeof(g_binary_operator_buffer[0]);

const char *g_assignment_operator_buffer[] = {"=", "*=", "/=", "%=", "+=", "-=", "<<=", ">>=", "&=", "^=", "|="};
const uintmax_t g_assignment_operator_buffer_size = sizeof(g_assignment_operator_buffer) / sizeof(g_assignment_operator_buffer[0]);

char **g_typedef_buffer = NULL;
uintmax_t g_typedef_buffer_size = 0;

int parser_parse_ellipsis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_ELLIPSIS))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_EQUAL_TO))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_not_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_NOT_EQUAL_TO))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_less_than_or_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LESS_THAN_OR_EQUAL_TO))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_greater_than_or_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_GREATER_THAN_OR_EQUAL_TO))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_logical_and(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_AND))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_logical_or(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_OR))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_left_shift(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LEFT_SHIFT))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_right_shift(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_RIGHT_SHIFT))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_add(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_ADD))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_subtract(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_SUBTRACT))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_multiply(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_MULTIPLY))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_divide(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_DIVIDE))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_assign(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_ASSIGN))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_less_than(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LESS_THAN))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_greater_than(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_GREATER_THAN))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_logical_not(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_NOT))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_bitwise_and(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_AND))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_bitwise_or(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_OR))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_bitwise_not(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_NOT))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_open_parenthesis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_OPEN_PARENTHESIS))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_close_parenthesis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_CLOSE_PARENTHESIS))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_open_brace(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_OPEN_BRACE))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_close_brace(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_CLOSE_BRACE))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_open_bracket(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_OPEN_BRACKET))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_close_bracket(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_CLOSE_BRACKET))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_semicolon(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_SEMICOLON))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_comma(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_COMMA))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_period(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_PERIOD))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_modulus(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_MODULUS))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_conditional(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_CONDITIONAL))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_colon(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_COLON))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_main(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size)
{
	uintmax_t l_index = 0;

	uintmax_t l_depth = 0;

	while(l_index < *input_token_buffer_size)
	{
		
	}

	return 0;
}