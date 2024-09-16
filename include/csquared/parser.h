#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <csquared/scanner.h>

typedef enum {PRIMITIVE_TYPE_CHAR, PRIMITIVE_TYPE_INT, PRIMITIVE_TYPE_FLOAT, PRIMITIVE_TYPE_DOUBLE, PRIMITIVE_TYPE_VOID, PRIMITIVE_TYPE_SHORT, PRIMITIVE_TYPE_LONG} primitive_type_t;
typedef enum {TYPE_QUALIFIER_CONST, TYPE_QUALIFIER_VOLATILE, TYPE_QUALIFIER_STATIC, TYPE_QUALIFIER_EXTERN, TYPE_QUALIFIER_INLINE, TYPE_QUALIFIER_REGISTER, TYPE_QUALIFIER_AUTO, TYPE_QUALIFIER_RESTRICT} type_qualifier_t;
typedef enum {OPERATOR_ADD, OPERATOR_SUBTRACT, OPERATOR_MULTIPLY, OPERATOR_DIVIDE, OPERATOR_EXPONENT, OPERATOR_MOD} operator_t;

extern const char *g_primitive_type_buffer[];
extern const uintmax_t g_primitive_type_buffer_size;

extern const char *g_type_qualifier_buffer[];
extern const uintmax_t g_type_qualifier_buffer_size;

extern const char *g_operator_buffer[];
extern const uintmax_t g_operator_buffer_size;

/* Is the keyword token a primitive type? */
static inline bool is_primitive_type(token_t *keyword)
{
	for(int i = 0; i < g_primitive_type_buffer_size; i++)
	{
		if(strncmp(keyword->plaintext_buffer, g_primitive_type_buffer[i], keyword->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}

	return false;
}

/* Is the keyword token a type qualifier? */
static inline bool is_type_qualifier(token_t *keyword)
{
	for(int i = 0; i < g_type_qualifier_buffer_size; i++)
	{
		if(strncmp(keyword->plaintext_buffer, g_type_qualifier_buffer[i], keyword->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}
}

/* Is the token an identifier? */
static inline bool is_identifier(token_t *token)
{
	return token->token_type == TOKEN_TYPE_IDENTIFIER;
}

/*
 *	Is the token a number?
 *	This function will check whether the token is a integer literal, unsigned
 *	integer literal, or a floating point literal.
 */
static inline bool is_number(token_t* token)
{
	return token->token_type == TOKEN_TYPE_INT32_LITERAL || token->token_type == TOKEN_TYPE_UINT32_LITERAL || token->token_type == TOKEN_TYPE_INT64_LITERAL || token->token_type == TOKEN_TYPE_UINT64_LITERAL || token->token_type == TOKEN_TYPE_FLOAT_LITERAL_32 || token->token_type == TOKEN_TYPE_FLOAT_LITERAL_64;
}

/*
 *	Is the token part of a mathematical expression?
 *	Although it's true that things such as functions & function declarations
 *	contain parenthesis, this will not be considered by the parser.
 */
static bool is_expression_token(token_t *token)
{
	return is_number(token) || (token->token_type == TOKEN_TYPE_SYMBOL && (token->value.symbol == ADD || token->value.symbol == SUB || token->value.symbol == MUL || token->value.symbol == DIV || token->value.symbol == OPEN_PAREN || token->value.symbol == CLOSE_PAREN));
}

typedef enum
{
	OBJECT_TYPE_NONE,
	OBJECT_TYPE_DECLARATION,
	OBJECT_TYPE_EXPRESSION,
	OBJECT_TYPE_BINARY_EXPRESSION
} object_type_t;

typedef enum
{
	STATE_INITIAL,
	STATE_EXPRESSION,
	STATE_TERM,
	STATE_FACTOR,
	STATE_DECLARATION
} state_t;

typedef struct object_t
{
	/* Store the object's type. */
	object_type_t object_type;

	union
	{
		

		struct
		{
			union
			{
				intmax_t integer;
				double floating;
			} value;
		} term;
		struct
		{
			operator_t operator;
			struct object_t *left_child;
			struct object_t *right_child;
		} expression;
	};
} object_t;

int parser(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size);