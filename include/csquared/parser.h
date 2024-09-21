#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <csquared/scanner.h>

typedef enum {PRIMITIVE_TYPE_CHAR, PRIMITIVE_TYPE_VOID} primitive_type_t;
typedef enum {TYPE_QUALIFIER_CONST, TYPE_QUALIFIER_VOLATILE, TYPE_QUALIFIER_STATIC, TYPE_QUALIFIER_EXTERN, TYPE_QUALIFIER_INLINE, TYPE_QUALIFIER_REGISTER, TYPE_QUALIFIER_AUTO, TYPE_QUALIFIER_RESTRICT} type_qualifier_t;
typedef enum {UNARY_OPERATOR_POSITIVE, UNARY_OPERATOR_NEGATIVE, UNARY_OPERATOR_LOGICAL_NOT, UNARY_OPERATOR_BITWISE_NOT, UNARY_OPERATOR_INCREMENT, UNARY_OPERATOR_DECREMENT, UNARY_OPERATOR_ADDRESS, UNARY_OPERATOR_DEREFERENCE} unary_operator_t;
typedef enum {BINARY_OPERATOR_ADD, BINARY_OPERATOR_SUBTRACT, BINARY_OPERATOR_MULTIPLY, BINARY_OPERATOR_DIVIDE, BINARY_OPERATOR_EXPONENT, BINARY_OPERATOR_MOD} binary_operator_t;

extern const char *g_primitive_type_buffer[];
extern const uintmax_t g_primitive_type_buffer_size;

extern const char *g_type_qualifier_buffer[];
extern const uintmax_t g_type_qualifier_buffer_size;

extern const char *g_unary_operator_buffer[];
extern const uintmax_t g_unary_operator_buffer_size;

extern const char *g_binary_operator_buffer[];
extern const uintmax_t g_binary_operator_buffer_size;

extern char **g_typedef_buffer;
extern uintmax_t g_typedef_buffer_size;

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

	return false;
}

/* Is the token a type defined by `typedef`? */
static inline bool is_typedef(token_t *token)
{
	for(int i = 0; i < g_typedef_buffer_size; i++)
	{
		if(strncmp(token->plaintext_buffer, g_typedef_buffer[i], token->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}

	return false;
}



/* Is the token an identifier? */
static inline bool is_identifier(token_t *token)
{
	return token->token_type == TOKEN_TYPE_PREFIX_IDENTIFIER;
}

/*
 *	Is the token a number?
 *	This function will check whether the token is a integer literal, unsigned
 *	integer literal, or a floating point literal.
 */
static inline bool is_number(token_t* token)
{
	return token->token_type == TOKEN_TYPE_INT32_LITERAL || token->token_type == TOKEN_TYPE_UINT32_LITERAL || token->token_type == TOKEN_TYPE_INT64_LITERAL || token->token_type == TOKEN_TYPE_UINT64_LITERAL || token->token_type == TOKEN_TYPE_FLOAT32_LITERAL || token->token_type == TOKEN_TYPE_FLOAT64_LITERAL;
}

/*
 *	Is the token part of a mathematical expression?
 *	Although it's true that things such as functions & function declarations
 *	contain parenthesis, this will not be considered by the parser.
 */
static bool is_expression_token(token_t *token)
{
	return is_number(token) || (token->token_type == TOKEN_TYPE_PREFIX_SYMBOL && (token->value.symbol == ADD || token->value.symbol == SUB || token->value.symbol == MUL || token->value.symbol == DIV || token->value.symbol == OPEN_PAREN || token->value.symbol == CLOSE_PAREN));
}

typedef enum
{
	OBJECT_TYPE_NONE,
	OBJECT_TYPE_OPERATOR,
	OBJECT_TYPE_CONSTANT,
	OBJECT_TYPE_TERM,
	OBJECT_TYPE_EXPRESSION
} object_type_t;

typedef struct object
{
	/* Store the object's type. */
	object_type_t object_type;

	union
	{
		struct
		{
			/*
			 *	This union should be identical to the union for storing
			 *	numerical literals found in the scanner's header file.
			 */
			union
			{
				
				/*
				 *	Integer types, both signed & unsigned, includes the 8-bit,
				 *	16-bit, 32-bit, and 64-bit sizes.
				 */
				int8_t int8_literal;
				int16_t int16_literal;
				int32_t int32_literal;
				int64_t int64_literal;
				uint8_t uint8_literal;
				uint16_t uint16_literal;
				uint32_t uint32_literal;
				uint64_t uint64_literal;

				/* Floating-point types, both 32-bit & 64-bit float literals. */
				float float32_literal;
				double float64_literal;
			} value;
		} term;
		
	};
} object_t;

int parser(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size);