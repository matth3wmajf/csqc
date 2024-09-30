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

	int l_result0 = parser_parse_conditional_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result0 < 0)
	{
		/* Expected a `conditional-expression`! */
		return -1;
	}

	/* ... */
	*index = l_index;

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
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_QUESTION_MARK))
	{
		l_index++;
	}
	else
	{
		*index = l_index;

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

	/*
	 *	If the parsing was successful, then set the official index counter to
	 *	the value of the bottom-most index value.
	 */
	*index = l_index;

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

	uintmax_t l_index = *index;

	/* Check for a `logical-and-expression`, and if it's there, then exit as successful. */
	int l_result0 = parser_parse_logical_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	/*
	 *	Check for a `logical-or-expression`, and if it's there, continue.
	 */
	int l_result2 = parser_parse_logical_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}
	
	/*
	 *	Check for a `||`, and if so, consume the token.
	 *	If it's not there, then it's not correctly following the second option
	 *	of the rule, and therefore we must exit with an error.
	 */
	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_OR))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	/*
	 *	Check for a `logical-and-expression`, and if it's there, then
	 *	continue & exit.
	 */
	int l_result3 = parser_parse_logical_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result3 < 0)
	{
		return -1;
	}

	/* ... */
	*index = l_index;

	return 0;
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
	
	uintmax_t l_index = *index;
	
	int l_result0 = parser_parse_inclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_logical_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_LOGICAL_AND))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_inclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
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

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_exclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_inclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_OR))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_inclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
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

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_exclusive_or_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_XOR))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_and_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	<and-expression> ::= <equality-expression>
	 *	                   | <and-expression> "&" <equality-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_equality_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_and_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && (input_token_buffer[l_index].value.symbol == SYMBOL_BITWISE_AND))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_equality_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_equality_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	<equality-expression> ::= <relational-expression>
	 *	                        | <equality-expression> "==" <relational-expression>
	 *	                        | <equality-expression> "!=" <relational-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_relational_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_equality_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && ((input_token_buffer[l_index].value.symbol == SYMBOL_EQUAL) || (input_token_buffer[l_index].value.symbol == SYMBOL_NOT_EQUAL)))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_relational_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_relational_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	<relational-expression> ::= <shift-expression>
	 *	                          | <relational-expression> "<" <shift-expression>
	 *	                          | <relational-expression> ">" <shift-expression>
	 *	                          | <relational-expression> "<=" <shift-expression>
	 *	                          | <relational-expression> ">=" <shift-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_shift_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_relational_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && ((input_token_buffer[l_index].value.symbol == SYMBOL_LESS_EQUAL) || (input_token_buffer[l_index].value.symbol == SYMBOL_GREATER_EQUAL) || (input_token_buffer[l_index].value.symbol == SYMBOL_LESS_THAN) || (input_token_buffer[l_index].value.symbol == SYMBOL_GREATER_THAN)))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_shift_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_shift_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	<shift-expression> ::= <additive-expression>
	 *	                     | <shift-expression> "<<" <additive-expression>
	 *	                     | <shift-expression> ">>" <additive-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_additive_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_shift_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && ((input_token_buffer[l_index].value.symbol == SYMBOL_LEFT_SHIFT) || (input_token_buffer[l_index].value.symbol == SYMBOL_RIGHT_SHIFT)))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_additive_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_additive_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	<additive-expression> ::= <multiplicative-expression>
	 *	                        | <additive-expression> "+" <multiplicative-expression>
	 *	                        | <additive-expression> "-" <multiplicative-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_multiplicative_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_additive_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && ((input_token_buffer[l_index].value.symbol == SYMBOL_ADD) || (input_token_buffer[l_index].value.symbol == SYMBOL_SUB)))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_multiplicative_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_multiplicative_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	<multiplicative-expression> ::= <cast-expression>
	 *	                              | <multiplicative-expression> "*" <cast-expression>
	 *	                              | <multiplicative-expression> "/" <cast-expression>
	 *	                              | <multiplicative-expression> "%" <cast-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_cast_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	int l_result1 = parser_parse_multiplicative_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result1 < 0)
	{
		return -1;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && ((input_token_buffer[l_index].value.symbol == SYMBOL_MUL) || (input_token_buffer[l_index].value.symbol == SYMBOL_DIV) || (input_token_buffer[l_index].value.symbol == SYMBOL_MOD)))
	{
		l_index++;
	}
	else
	{
		return -1;
	}

	int l_result2 = parser_parse_cast_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(l_result2 < 0)
	{
		return -1;
	}

	*index = l_index;

	return 0;
}

int parser_parse_cast_expression(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	/*
	 *	<cast-expression> ::= <unary-expression>
	 *	                    | "(" <type-name> ")" <cast-expression>
	 */

	uintmax_t l_index = *index;

	int l_result0 = parser_parse_unary_expression(input_token_buffer, input_token_buffer_size, output_object_buffer, output_object_buffer_size, &l_index);
	if(!(l_result0 < 0))
	{
		*index = l_index;

		return 0;
	}

	if(l_index >= *input_token_buffer_size && input_token_buffer[l_index].token_type == TOKEN_TYPE_SYMBOL_LITERAL && input_token_buffer[l_index].value.symbol == SYMBOL_OPEN_PARENTHESIS)
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

int parser_parse_type_name(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size, uintmax_t *index)
{
	uintmax_t l_index = *index;

	/* ... */

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