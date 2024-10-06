#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <csquared/scanner.h>

extern const char *g_type_qualifier_buffer[];
extern const uintmax_t g_type_qualifier_buffer_size;

extern const char *g_struct_or_union_buffer[];
extern const uintmax_t g_struct_or_union_buffer_size;

extern const char *g_type_specifier_buffer[];
extern const uintmax_t g_type_specifier_buffer_size;

extern const char *g_unary_operator_buffer[];
extern const uintmax_t g_unary_operator_buffer_size;

extern const char *g_preunary_operator_buffer[];
extern const uintmax_t g_preunary_operator_buffer_size;

extern const char *g_parenthesis_buffer[];
extern const uintmax_t g_parenthesis_buffer_size;

extern const char *g_braces_buffer[];
extern const uintmax_t g_braces_buffer_size;

extern const char *g_brackets_buffer[];
extern const uintmax_t g_brackets_buffer_size;

extern const char *g_semicolon_buffer[];
extern const uintmax_t g_semicolon_buffer_size;

extern const char *g_postunary_operator_buffer[];
extern const uintmax_t g_postunary_operator_buffer_size;

extern const char *g_binary_operator_buffer[];
extern const uintmax_t g_binary_operator_buffer_size;

extern char **g_typedef_buffer;
extern uintmax_t g_typedef_buffer_size;

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
	return token->token_type == (uint8_t)TOKEN_TYPE_IDENTIFIER;
}

/*
 *	Is the token a symbol?
 *	If so, then return `true`. Otherwise, return `false`.
 */
static inline bool is_symbol(token_t *token)
{
	return token->token_type == (uint8_t)TOKEN_TYPE_SYMBOL;
}

/* Is the token part of a unary or binary operator? */
static inline bool is_operator(token_t *token)
{
	for(int i = 0; i < g_unary_operator_buffer_size; i++)
	{
		if(strncmp(token->plaintext_buffer, g_unary_operator_buffer[i], token->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}

	for(int i = 0; i < g_binary_operator_buffer_size; i++)
	{
		if(strncmp(token->plaintext_buffer, g_binary_operator_buffer[i], token->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}

	return false;
}

static inline bool is_possible_preunary_operator(token_t *token)
{
	for(int i = 0; i < g_preunary_operator_buffer_size; i++)
	{
		if(strncmp(token->plaintext_buffer, g_preunary_operator_buffer[i], token->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}

	return false;
}

static inline bool is_possible_postunary_operator(token_t *token)
{
	for(int i = 0; i < g_postunary_operator_buffer_size; i++)
	{
		if(strncmp(token->plaintext_buffer, g_postunary_operator_buffer[i], token->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}

	return false;
}

static inline bool is_possible_unary_operator(token_t *token)
{
	return is_possible_preunary_operator(token) || is_possible_postunary_operator(token);
}

static inline bool is_possible_binary_operator(token_t *token)
{
	for(int i = 0; i < g_binary_operator_buffer_size; i++)
	{
		if(strncmp(token->plaintext_buffer, g_binary_operator_buffer[i], token->plaintext_buffer_size) == 0)
		{
			return true;
		}
	}

	return false;
}

static inline bool is_integer_literal(token_t *token)
{
	return (token->token_type & 0xF0) == (uint8_t)TOKEN_PREFIX_INTEGER_LITERAL;
}

static inline bool is_float_literal(token_t *token)
{
	return (token->token_type & 0xF0) == (uint8_t)TOKEN_PREFIX_FLOAT_LITERAL;
}

static inline bool is_possible_term(token_t *token)
{
	return is_integer_literal(token) || is_float_literal(token);
}

/*
 *	Is the token a number?
 *	This function will check whether the token is a integer literal, unsigned
 *	integer literal, or a floating point literal.
 */
static inline bool is_number(token_t* token)
{
	return is_integer_literal(token) || is_float_literal(token);
}

/* The type of phase of processing the parser is currently in. */
typedef enum
{
	PHASE_TYPE_CONSTANT_EXPRESSION,
	PHASE_TYPE_CONDITIONAL_EXPRESSION,
	PHASE_TYPE_LOGICAL_OR_EXPRESSION,
	PHASE_TYPE_LOGICAL_AND_EXPRESSION,
	PHASE_TYPE_INCLUSIVE_OR_EXPRESSION,
	PHASE_TYPE_EXCLUSIVE_OR_EXPRESSION,
	PHASE_TYPE_AND_EXPRESSION,
	PHASE_TYPE_EQUALITY_EXPRESSION,
	PHASE_TYPE_RELATIONAL_EXPRESSION,
	PHASE_TYPE_SHIFT_EXPRESSION,
	PHASE_TYPE_ADDITIVE_EXPRESSION,
	PHASE_TYPE_MULTIPLICATIVE_EXPRESSION,
	PHASE_TYPE_CAST_EXPRESSION,
	PHASE_TYPE_UNARY_EXPRESSION,
	PHASE_TYPE_POSTFIX_EXPRESSION,
	PHASE_TYPE_PRIMARY_EXPRESSION,
	PHASE_TYPE_EXPRESSION,
	PHASE_TYPE_ASSIGNMENT_EXPRESSION,
	PHASE_TYPE_ERROR
} phase_type_t;

typedef enum
{
	/*
	 *	The vague object types, and their prefix.
	 *	This includes the following...
	 *	1. Constants
	 *	2. Expressions
	 *	3. Scopes
	 */
	OBJECT_PREFIX_CST = 0b00000000,
	OBJECT_PREFIX_EXP = 0b00000001,
	OBJECT_PREFIX_SCP = 0b00000010,

	/*
	 *	Unary operators for expressions.
	 *	This includes the following...
	 *	1. Increment
	 *	2. Decrement
	 *	3. Positive
	 *	4. Negative
	 */
	OBJECT_SUBTYPE_UNARY_INC = 0b00000000,
	OBJECT_SUBTYPE_UNARY_DEC = 0b00000001,
	OBJECT_SUBTYPE_UNARY_POS = 0b00000010,
	OBJECT_SUBTYPE_UNARY_NEG = 0b00000011,

	/*
	 *	Binary operators for expressions.
	 *	This includes the following...
	 *	1. Addition
	 *	2. Subtraction
	 *	3. Multiplication
	 *	4. Division
	 *	5. Modulus
	 *	6. Exponent
	 */
	OBJECT_SUBTYPE_BINARY_ADD = 0b01000100,
	OBJECT_SUBTYPE_BINARY_SUB = 0b01000101,
	OBJECT_SUBTYPE_BINARY_MUL = 0b01000110,
	OBJECT_SUBTYPE_BINARY_DIV = 0b01000111,
	OBJECT_SUBTYPE_BINARY_MOD = 0b01001000,
	OBJECT_SUBTYPE_BINARY_EXP = 0b01001001,

	/*
	 *	Ternary operators for expressions.
	 *	We only plan on implementing one for now, however we may implement
	 *	more in the future...
	 *	1. Conditional
	 */
	OBJECT_SUBTYPE_TERNARY_CON = 0b10000000,

	/*
	 *	The types of scopes out there.
	 *	These include the following...
	 *	1. Function
	 *	2. File
	 *	3. Block
	 *	4. Prototype
	 */
	OBJECT_SUBTYPE_SCOPE_FUN = 0b00000000,
	OBJECT_SUBTYPE_SCOPE_FLE = 0b00000001,
	OBJECT_SUBTYPE_SCOPE_BLK = 0b00000010,
	OBJECT_SUBTYPE_SCOPE_PRO = 0b00000011
} object_type_t;

typedef struct object
{
	/*
	 *	Store the object's type.
	 *	Unlike `token_type_t`, which is 8-bits, `object_type_t` is meant to be
	 *	16-bits, and therefore we set it's bit size to 16 here using bitfields.
	 */
	object_type_t object_type : 16;

	union
	{
		/*
		 *	Constants can be either literals, or identifiers of constants. But
		 *	for now, we only support literals.
		 */
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

				/*
				 *	Floating-point types, both 32-bit & 64-bit float literals.
				 */
				float float32_literal;
				double float64_literal;
			} value;
		} constant;
		
		/* Expressions consist of identifiers of variables, or expressions. */
		struct
		{
			/*
			 *	The buffer of operands, and the size of the buffer. The buffer
			 *	tends to be 1, 2, or 3 units in size.
			 */
			struct object *operand_buffer;
			uintmax_t operand_buffer_size;
		} expression;

		/*
		 *	Scopes, consist of the file scope, the function scope, the block
		 *	scope, and the function prototype scope.
		 */
		struct
		{
			/*
			 *	The buffer of child objects, which may be scopes, or pretty
			 *	much any other type of object.
			 */
			struct object *child_buffer;
			uintmax_t child_buffer_size;
		} scope;
	};
} object_t;

int parser_main(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size);