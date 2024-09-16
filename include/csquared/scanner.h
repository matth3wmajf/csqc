#pragma once

#include <stdbool.h>
#include <stdint.h>

/* The token & symbol enumerations, respective to their plaintext buffers. */
typedef enum {AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, REGISTER, RETURN, SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE} keyword_t;
typedef enum {EQUAL, NOT_EQUAL, LESS_EQUAL, GREATER_EQUAL, LOGICAL_AND, LOGICAL_OR, LEFT_SHIFT, RIGHT_SHIFT, ADD, SUB, MUL, DIV, ASSIGN, LESS_THAN, GREATER_THAN, LOGICAL_NOT, BITWISE_AND, BITWISE_OR, BITWISE_XOR, BITWISE_NOT, OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE, OPEN_BRACKET, CLOSE_BRACKET, SEMICOLON, COMMA, PERIOD} symbol_t;

/* The plaintext buffers for tokens & symbols. */
extern const char *g_keywords[];
extern const char *g_symbols[];

/* Is the character whitespace? */
static inline bool is_whitespace(char character)
{
	return character == ' ' || character == '\t' || character == '\f' || character == '\v' || character == '\n' || character == '\r';
}

/* Is the character a letter? */
static inline bool is_alphabet(char character)
{
	return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

/* Is the character alphanumeric? */
static inline bool is_alphanumeric(char character)
{
	return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9');
}

/* Is the character a digit? */
static inline bool is_digit(char character)
{
	return character >= '0' && character <= '9';
}

static inline bool is_numeric(char character)
{
	return is_digit(character) || character == '.';
}

/* Is the character a valid identifier character? */
static inline bool is_valid_identifier_character(char character)
{
	return is_alphanumeric(character) || character == '_';
}

/*
 *	The different types of tokens.
 *	The first four bits are the token type, and the last four bits are the token subtype.
 *	This allows us to narrow down the token type when scanning the source code.
 */
typedef enum
{
	/* Vague token types, used as prefix(es). */
	TOKEN_TYPE_PREFIX_CHARACTER_LITERAL = (0x1 << 4),
	TOKEN_TYPE_PREFIX_INTEGER_LITERAL = (0x2 << 4),
	TOKEN_TYPE_PREFIX_FLOAT_LITERAL = (0x3 << 4),
	TOKEN_TYPE_PREFIX_STRING_LITERAL = (0x4 << 4),
	TOKEN_TYPE_PREFIX_IDENTIFIER = (0x5 << 4),
	TOKEN_TYPE_PREFIX_KEYWORD = (0x6 << 4),
	TOKEN_TYPE_PREFIX_SYMBOL = (0x7 << 4),

	/* Are the integers signed or unsigned? */
	TOKEN_SUBTYPE_SIGNED = 0b0000,
	TOKEN_SUBTYPE_UNSIGNED = 0b0001,

	/*
	 *	What are the available sizes for integers?
	 *	There is 8-bit, 16-bit, 32-bit, and 64-bit support for integers.
	 */
	TOKEN_SUBTYPE_INT8 = 0b0000,
	TOKEN_SUBTYPE_INT16 = 0b0010,
	TOKEN_SUBTYPE_INT32 = 0b0100,
	TOKEN_SUBTYPE_INT64 = 0b0110,

	/*
	 *	What are the available sizes for characters?
	 *	We've got 8-bit characters, commonly known as characters, and then
	 *	wide characters, which tend to be 16-bit or 32-bit.
	 *	For now, we will only implement the 8-bit character, however we
	 *	may support the wide characters in the future.
	 */
	TOKEN_SUBTYPE_CHAR = 0b0000,
	TOKEN_SUBTYPE_WCHAR = 0b0001,

	/* Same goes for strings. */
	TOKEN_SUBTYPE_STRING = 0b0000,
	TOKEN_SUBTYPE_WSTRING = 0b0001,

	/* Floating point sub-types. Floats are 32-bit, and doubles are 64-bit. */
	TOKEN_SUBTYPE_FLOAT = 0b0000,
	TOKEN_SUBTYPE_DOUBLE = 0b0001,

	/*
	 *	The very-specific types.
	 *	Some of them actually don't even need any suffix(es) or subtypes, such
	 *	as identifiers, keywords, and symbols.
	 */
	TOKEN_TYPE_INT8_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_SIGNED | TOKEN_SUBTYPE_INT8,
	TOKEN_TYPE_INT16_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_SIGNED | TOKEN_SUBTYPE_INT16,
	TOKEN_TYPE_INT32_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_SIGNED | TOKEN_SUBTYPE_INT32,
	TOKEN_TYPE_INT64_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_SIGNED | TOKEN_SUBTYPE_INT64,
	TOKEN_TYPE_UINT8_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_UNSIGNED | TOKEN_SUBTYPE_INT8,
	TOKEN_TYPE_UINT16_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_UNSIGNED | TOKEN_SUBTYPE_INT16,
	TOKEN_TYPE_UINT32_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_UNSIGNED | TOKEN_SUBTYPE_INT32,
	TOKEN_TYPE_UINT64_LITERAL = TOKEN_TYPE_PREFIX_INTEGER_LITERAL | TOKEN_SUBTYPE_UNSIGNED | TOKEN_SUBTYPE_INT64,
	TOKEN_TYPE_FLOAT32_LITERAL = TOKEN_TYPE_PREFIX_FLOAT_LITERAL | TOKEN_SUBTYPE_FLOAT,
	TOKEN_TYPE_FLOAT64_LITERAL = TOKEN_TYPE_PREFIX_FLOAT_LITERAL | TOKEN_SUBTYPE_DOUBLE,
	TOKEN_TYPE_CHARACTER8_LITERAL = TOKEN_TYPE_PREFIX_CHARACTER_LITERAL | TOKEN_SUBTYPE_CHAR,
	TOKEN_TYPE_STRING8_LITERAL = TOKEN_SUBTYPE_STRING | TOKEN_SUBTYPE_STRING,
	TOKEN_TYPE_IDENTIFIER_LITERAL = TOKEN_TYPE_PREFIX_IDENTIFIER | 0b0000,
	TOKEN_TYPE_KEYWORD_LITERAL = TOKEN_TYPE_PREFIX_KEYWORD | 0b0000,
	TOKEN_TYPE_SYMBOL_LITERAL = TOKEN_TYPE_PREFIX_SYMBOL | 0b0000
} token_type_t;

typedef struct
{
	/* The type of token. */
	token_type_t token_type;

	/* The buffer storing our token in plaintext, and it's size. */
	char *plaintext_buffer;
	uintmax_t plaintext_buffer_size;

	/* The buffer storing our token in tokenized form, and it's size. */
	struct
	{
		union
		{
			/* Vague token types. */
			char character_literal;
			int integer_literal;
			float float_literal;
			char *string_literal;
			char *identifier;
			keyword_t keyword;
			symbol_t symbol;

			/* Discrete token types. */
			int8_t int8_literal;
			int16_t int16_literal;
			int32_t int32_literal;
			int64_t int64_literal;
			uint8_t uint8_literal;
			uint16_t uint16_literal;
			uint32_t uint32_literal;
			uint64_t uint64_literal;
			float float_literal_32;
			double float_literal_64;
		};

		/* Only applies to string literals & identifiers. */
		uintmax_t buffer_size;
	} value;
} token_t;

int scanner(char *input_source_buffer, uintmax_t *input_source_buffer_size, token_t **output_token_buffer, uintmax_t *output_token_buffer_size);