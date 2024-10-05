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

/* Function prototypes for handling symbols. */

int parser_parse_symbol(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_ellipsis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_not_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_less_than_or_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_greater_than_or_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_logical_and(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_logical_or(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_left_shift(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_right_shift(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_add(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_subtract(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_multiply(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_divide(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_assign(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_less_than(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_greater_than(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_logical_not(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_bitwise_and(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_bitwise_or(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_bitwise_xor(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_bitwise_not(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_open_parenthesis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_close_parenthesis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_open_brace(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_close_brace(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_open_bracket(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_close_bracket(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_semicolon(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_comma(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_period(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_modulus(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_conditional(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_symbol_colon(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);

/* Function prototypes for handling keywords. */

int parser_parse_keyword(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_auto(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_break(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_case(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_byte(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_const(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_continue(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_default(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_do(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_else(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_enum(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_extern(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_for(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_goto(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_if(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_register(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_return(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_signed(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_sizeof(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_static(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_struct(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_switch(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_typedef(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_union(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_unsigned(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_void(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_volatile(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_keyword_while(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);

/* Function prototypes for handling literals. */

int parser_parse_literal(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_literal_float(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_literal_int(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_literal_char(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_literal_string(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);

/* Function prototypes for handling rules. */

int parser_parse_rule_translation_unit(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_external_declaration(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_function_definition(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_declaration(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_storage_class_specifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_type_specifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_struct_or_union_specifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_struct_or_union(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_specifier_qualifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_specifier_qualifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_struct_declarator_list(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_struct_declarator(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_declarator(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_type_qualifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_direct_declarator(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_constant_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_conditional_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_logical_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_logical_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_inclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_exclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_rule_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);

/* Function prototype for handling identifiers.*/

int parser_parse_identifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);

/* Functions for handling symbols. */

int parser_parse_symbol(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL)
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

int parser_parse_symbol_ellipsis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_ELLIPSIS))
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

int parser_parse_symbol_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_EQUAL_TO))
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

int parser_parse_symbol_not_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_NOT_EQUAL_TO))
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

int parser_parse_symbol_less_than_or_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_LESS_THAN_OR_EQUAL_TO))
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

int parser_parse_symbol_greater_than_or_equal_to(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_GREATER_THAN_OR_EQUAL_TO))
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

int parser_parse_symbol_logical_and(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_AND))
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

int parser_parse_symbol_logical_or(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_OR))
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

int parser_parse_symbol_left_shift(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_LEFT_SHIFT))
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

int parser_parse_symbol_right_shift(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_RIGHT_SHIFT))
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

int parser_parse_symbol_add(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_ADD))
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

int parser_parse_symbol_subtract(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_SUBTRACT))
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

int parser_parse_symbol_multiply(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_MULTIPLY))
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

int parser_parse_symbol_divide(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_DIVIDE))
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

int parser_parse_symbol_assign(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_ASSIGN))
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

int parser_parse_symbol_less_than(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_LESS_THAN))
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

int parser_parse_symbol_greater_than(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_GREATER_THAN))
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

int parser_parse_symbol_logical_not(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_NOT))
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

int parser_parse_symbol_bitwise_and(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_AND))
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

int parser_parse_symbol_bitwise_or(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_OR))
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

int parser_parse_symbol_bitwise_xor(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_XOR))
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

int parser_parse_symbol_bitwise_not(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_NOT))
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

int parser_parse_symbol_open_parenthesis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_OPEN_PARENTHESIS))
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

int parser_parse_symbol_close_parenthesis(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_CLOSE_PARENTHESIS))
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

int parser_parse_symbol_open_brace(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_OPEN_BRACE))
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

int parser_parse_symbol_close_brace(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_CLOSE_BRACE))
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

int parser_parse_symbol_open_bracket(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_OPEN_BRACKET))
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

int parser_parse_symbol_close_bracket(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_CLOSE_BRACKET))
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

int parser_parse_symbol_semicolon(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_SEMICOLON))
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

int parser_parse_symbol_comma(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_COMMA))
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

int parser_parse_symbol_period(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_PERIOD))
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

int parser_parse_symbol_modulus(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_MODULUS))
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

int parser_parse_symbol_conditional(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_CONDITIONAL))
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

int parser_parse_symbol_colon(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL && (input_token_buffer[l_index].value.symbol == SYMBOL_COLON))
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

/* Functions for handling keywords. */

int parser_parse_keyword(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD)
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

int parser_parse_keyword_auto(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_AUTO))
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

int parser_parse_keyword_break(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_BREAK))
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

int parser_parse_keyword_case(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_CASE))
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

int parser_parse_keyword_byte(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_BYTE))
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

int parser_parse_keyword_const(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_CONST))
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

int parser_parse_keyword_continue(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_CONTINUE))
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

int parser_parse_keyword_default(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_DEFAULT))
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

int parser_parse_keyword_do(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_DO))
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

int parser_parse_keyword_else(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_ELSE))
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

int parser_parse_keyword_enum(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_ENUM))
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

int parser_parse_keyword_extern(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_EXTERN))
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

int parser_parse_keyword_for(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_FOR))
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

int parser_parse_keyword_goto(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_GOTO))
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

int parser_parse_keyword_if(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_IF))
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

int parser_parse_keyword_register(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_REGISTER))
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

int parser_parse_keyword_return(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_RETURN))
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

int parser_parse_keyword_signed(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_SIGNED))
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

int parser_parse_keyword_sizeof(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_SIZEOF))
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

int parser_parse_keyword_static(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_STATIC))
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

int parser_parse_keyword_struct(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_STRUCT))
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

int parser_parse_keyword_switch(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_SWITCH))
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

int parser_parse_keyword_typedef(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_TYPEDEF))
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

int parser_parse_keyword_union(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_UNION))
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

int parser_parse_keyword_unsigned(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_UNSIGNED))
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

int parser_parse_keyword_void(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_VOID))
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

int parser_parse_keyword_volatile(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_VOLATILE))
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

int parser_parse_keyword_while(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_KEYWORD && (input_token_buffer[l_index].value.keyword == KEYWORD_WHILE))
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

/* Functions for handling literals. */

int parser_parse_literal(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && (input_token_buffer[l_index].token_type == TOKEN_TYPE_INT8_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT8_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_INT16_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT16_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_INT32_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT32_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_INT64_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT64_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_FLOAT32_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_FLOAT64_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_CHARACTER8_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_STRING8_LITERAL))
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

int parser_parse_literal_float(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && (input_token_buffer[l_index].token_type == TOKEN_TYPE_FLOAT32_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_FLOAT64_LITERAL))
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

int parser_parse_literal_int(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && (input_token_buffer[l_index].token_type == TOKEN_TYPE_INT8_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT8_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_INT16_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT16_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_INT32_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT32_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_INT64_LITERAL || input_token_buffer[l_index].token_type == TOKEN_TYPE_UINT64_LITERAL))
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

int parser_parse_literal_char(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_CHARACTER8_LITERAL)
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

int parser_parse_literal_string(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_STRING8_LITERAL)
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

/* Functions for handling rules. */

int parser_parse_rule_translation_unit(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result;

	do
	{
		l_result = parser_parse_rule_external_declaration(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	} while(l_result >= 0);

	*index = l_index;

	return 0;
}

int parser_parse_rule_external_declaration(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_function_definition(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_result = parser_parse_rule_declaration(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_function_definition(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result;

	do
	{
		l_result = parser_parse_rule_declaration_specifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	} while(l_result >= 0);

	l_result = parser_parse_rule_declarator(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result < 0) return -1;

	do
	{
		l_result = parser_parse_rule_declaration(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	} while(l_result >= 0);

	l_result = parser_parse_rule_compound_statement(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result < 0) return -1

	*index = l_index;
	return 0;
}

int parser_parse_rule_declaration_specifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;
	int l_result = parser_parse_rule_storage_class_specifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_rule_type_specifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_rule_type_qualifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_storage_class_specifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;
	int l_result = parser_parse_keyword_auto(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_register(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_static(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_extern(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_typedef(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_type_specifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;
	int l_result = parser_parse_keyword_void(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_byte(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_signed(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_unsigned(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_rule_struct_or_union_specifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_rule_enum_specifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_rule_typedef_name(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_struct_or_union_specifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_struct_or_union(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result < 0) return -1;

	l_result = parser_parse_identifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		l_result = parser_parse_symbol_open_brace(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_rule_struct_declaration(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result < 0) return -1;

			do
			{
				l_result = parser_parse_rule_struct_declaration(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			} while (l_result >= 0);

			l_result = parser_parse_symbol_close_brace(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				*index = l_index;
				return 0;
			}
		}
		else if(l_result < 0)
		{
			*index = l_index;
			return 0;
		}
	}
	else if(l_result < 0)
	{
		l_result = parser_parse_symbol_open_brace(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_rule_struct_declaration(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result < 0) return -1;

			do
			{
				l_result = parser_parse_rule_struct_declaration(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			} while (l_result >= 0);

			l_result = parser_parse_symbol_close_brace(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				*index = l_index;
				return 0;
			}
		}
		else if(l_result < 0)
		{
			*index = l_index;
			return 0;
		}
	}

	return -1;
}

int parser_parse_rule_struct_or_union(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_keyword_struct(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_keyword_union(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_specifier_qualifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result;

	do
	{
		l_result = parser_parse_rule_specifier_qualifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	} while(l_result >= 0);

	l_result = parser_parse_rule_struct_declarator_list(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_specifier_qualifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_type_specifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_rule_type_qualifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_struct_declarator_list(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_struct_declarator(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_rule_struct_declarator_list(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		l_result = parser_parse_symbol_comma(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_rule_struct_declarator(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				*index = l_index;
				return 0;
			}
		}
	}

	return -1;
}

int parser_parse_rule_struct_declarator(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_declarator(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		l_result = parser_parse_symbol_colon(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_rule_constant_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result < 0) return -1;

			*index = l_index;
			return 0;
		}
		else if(l_result < 0)
		{
			*index = l_index;
			return 0;
		}
	}
	else if(l_result < 0)
	{
		l_result = parser_parse_symbol_colon(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result < 0) return -1;

		l_result = parser_parse_constant_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result < 0) return -1;

		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_declarator(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	parser_parse_rule_pointer(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);

	int l_result = parser_parse_rule_direct_declarator(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result < 0) return -1;

	*index = l_index;
	return 0;
}

int parser_parse_rule_type_qualifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_keyword_const(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_result = *index;

	l_result = parser_parse_keyword_volatile(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}
	
	return -1;
}

int parser_parse_rule_direct_declarator(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_identifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	l_index = *index;

	l_result = parser_parse_symbol_open_parenthesis(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		l_result = parser_parse_rule_declarator(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_symbol_close_parenthesis(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				*index = l_index;
				return 0;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0) return -1;
	}

	l_index = *index;

	l_result = parser_parse_rule_direct_declarator(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		l_result = parser_parse_symbol_open_bracket(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			parser_parse_rule_constant_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);

			l_result = parser_parse_symbol_close_bracket(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				*index = l_index;
				return 0;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0)
		{
			l_result = parser_parse_symbol_open_parenthesis(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				l_result = parser_parse_rule_parameter_type_list(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
				if(l_result >= 0)
				{
					l_result = parser_parse_symbol_close_parenthesis(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
					if(l_result >= 0)
					{
						*index = l_index;
						return 0;
					}
					else if(l_result < 0) return -1;
				}
				else if(l_result < 0)
				{
					do
					{
						l_result = parser_parse_identifier(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
					} while(l_result >= 0);

					l_result = parser_parse_symbol_close_parenthesis(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
					if(l_result >= 0)
					{
						*index = l_index;
						return 0;
					}
					else if(l_result < 0) return -1;
				}
			}
			else if(l_result < 0) return -1;
		}
	}
	else if(l_result < 0) return -1;

	return -1;
}

int parser_parse_rule_constant_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_conditional_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}

	return -1;
}

int parser_parse_rule_conditional_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_logical_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		l_result = parser_parse_symbol_question_mark(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_rule_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				l_result = parser_parse_symbol_colon(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
				if(l_result >= 0)
				{
					l_result = parser_parse_rule_conditional_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
					if(l_result >= 0)
					{
						*index = l_index;
						return 0;
					}
					else if(l_result < 0) return -1;
				}
				else if(l_result < 0) return -1;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0)
		{
			*index = l_index;
			return 0;
		}
	}
	else if(l_result < 0) return -1;

	return -1;
}

int parser_parse_rule_logical_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_logical_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}
	else if(l_result < 0)
	{
		l_result = parser_parse_rule_logical_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_symbol_logical_or(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				l_result = parser_parse_rule_logical_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
				if(l_result >= 0)
				{
					*index = l_index;
					return 0;
				}
				else if(l_result < 0) return -1;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0) return -1;
	}

	return -1;
}

int parser_parse_rule_logical_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_inclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}
	else if(l_result < 0)
	{
		l_result = parser_parse_rule_logical_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_symbol_logical_and(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				l_result = parser_parse_rule_inclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
				if(l_result >= 0)
				{
					*index = l_index;
					return 0;
				}
				else if(l_result < 0) return -1;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0) return -1;
	}

	return -1;
}

int parser_parse_rule_inclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_exclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}
	else if(l_result < 0)
	{
		l_result = parser_parse_rule_inclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_symbol_bitwise_or(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				l_result = parser_parse_rule_exclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
				if(l_result >= 0)
				{
					*index = l_index;
					return 0;
				}
				else if(l_result < 0) return -1;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0) return -1;
	}

	return -1;
}

int parser_parse_rule_exclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_rule_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}
	else if(l_result < 0)
	{
		l_result = parser_parse_rule_exclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_symbol_bitwise_xor(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				l_result = parser_parse_rule_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
				if(l_result >= 0)
				{
					*index = l_index;
					return 0;
				}
				else if(l_result < 0) return -1;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0) return -1;
	}

	return -1;
}

int parser_parse_rule_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	int l_result = parser_parse_equality_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result >= 0)
	{
		*index = l_index;
		return 0;
	}
	else if(l_result < 0)
	{
		l_result = parser_parse_rule_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
		if(l_result >= 0)
		{
			l_result = parser_parse_symbol_bitwise_and(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
			if(l_result >= 0)
			{
				l_result = parser_parse_equality_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
				if(l_result >= 0)
				{
					*index = l_index;
					return 0;
				}
				else if(l_result < 0) return -1;
			}
			else if(l_result < 0) return -1;
		}
		else if(l_result < 0) return -1;
	}

	return -1;
}

/* Function for handling identifiers. */

int parser_parse_identifier(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_IDENTIFIER)
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