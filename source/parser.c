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

int parser_parse_constant_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_conditional_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_logical_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_logical_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_inclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_exclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_equality_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_relational_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_shift_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_additive_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_multiplicative_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_cast_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_unary_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_postfix_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_primary_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);
int parser_parse_assignment_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index);

int parser_parse_constant_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	As the syntax below suggests, this function just links directly to the
	 *	`conditional-expression` parser...
	 *	<constant-expression> ::= <conditional-expression>
	 */

	uintmax_t l_index = *index;

	int l_result = parser_parse_conditional_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);

	if(l_result < 0)
	{
		/* Expected a `conditional-expression`! */
		return -1;
	}

	return 0;
}

int parser_parse_conditional_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	As the syntax below suggests, this function will check if we're
	 *	working with a logical or expression, or a logical or expression, but
	 *	with a "?", an expression, a ":", and a conditional expression
	 *	following it...
	 *	<conditional-expression> ::= <logical-or-expression>
	 *                             | <logical-or-expression> "?" <expression> ":" <conditional-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_logical_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result0 < 0)
	{
		/*
		 *	Expected a `logical-or-expression`!
		 *	We need a `logical-or-expression` in both cases, so if it doesn't
		 *	exist, then return an error, as we're not dealing with a
		 *	`conditional-expression`.
		 */
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_QUESTION_MARK))
	{
		l_index++;
	}
	else
	{
		/*
		 *	Looks like the next token disqualifies us from us applying for the
		 *	second possibility in the BNF rule, so we just return as success
		 *	here, since our first possibility passed anyways.
		 */
		return 0;
	}

	int l_result1 = parser_parse_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		/*
		 *	Looks like we were taking our route to the second possibility, but
		 *	it turns out that we were lied to...
		 */
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_COLON))
	{
		l_index++;
	}
	else
	{
		/* Expected a colon, but instead got something else... */
		return -1;
	}

	int l_result2 = parser_parse_conditional_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		/*
		 *	Looks like we were taking our route to the second possibility, but
		 *	it turns out that we were lied to...
		 */
		return -1;
	}

	/* Passed all checks for the second possibility, return success. */
	return 0;
}

int parser_parse_logical_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	As the syntax below suggests, this function will check if we're
	 *	working with a `logical and expression`, or a `logical-or-expression`
	 *	followed by "||" and a `logical-and-expression`...
	 *	<logical-or-expression> ::= <logical-and-expression>
	 *	                          | <logical-or-expression> "||" <logical-and-expression>
	 */
	
	return -1;
}

int parser_parse_logical_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	As the syntax below suggests, this function will check if we're
	 *	working with an `exclusive-or-expression`, or a `logical-and-
	 *	expression` followed by `&&` and an `exclusive-or-expression`...
	 *	<logical-and-expression> ::= <inclusive-or-expression>
	 *	                           | <logical-and-expression> "&&" <inclusive-or-expression>
	 */

	return -1;
}

int parser_parse_inclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *  As the syntax below suggests, this function will check if we're
	 *  working with an `exclusive-or-expression`, or an `inclusive-or-
	 *  expression` followed by "|" and an `exclusive-or-expression`...
	 *  <inclusive-or-expression> ::= <exclusive-or-expression>
	 *                              | <inclusive-or-expression> "|" <exclusive-or-expression>
	 */

	return -1;
}

int parser_parse_exclusive_or_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *  As the syntax below suggests, this function will check if we're
	 *  working with an `and-expression`, or an `exclusive-or-expression`
	 *  followed by "^" and an `and-expression`...
	 *  <exclusive-or-expression> ::= <and-expression>
	 *                              | <exclusive-or-expression> "^" <and-expression>
	 */

	return -1;
}

int parser_parse_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_equality_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_relational_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_shift_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_additive_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_multiplicative_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_cast_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_unary_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_postfix_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_primary_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
}

int parser_parse_assignment_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	return -1;
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