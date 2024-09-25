#pragma once

#include <stdbool.h>
#include <stdint.h>

/* The token & symbol enumerations, respective to their plaintext buffers. */
typedef enum {KEYWORD_AUTO, KEYWORD_BREAK, KEYWORD_CASE, KEYWORD_CHAR, KEYWORD_CONST, KEYWORD_CONTINUE, KEYWORD_DEFAULT, KEYWORD_DO, KEYWORD_DOUBLE, KEYWORD_ELSE, KEYWORD_ENUM, KEYWORD_EXTERN, KEYWORD_FLOAT, KEYWORD_FOR, KEYWORD_GOTO, KEYWORD_IF, KEYWORD_INT, KEYWORD_LONG, KEYWORD_REGISTER, KEYWORD_RETURN, KEYWORD_SHORT, KEYWORD_SIGNED, KEYWORD_SIZEOF, KEYWORD_STATIC, KEYWORD_STRUCT, KEYWORD_SWITCH, KEYWORD_TYPEDEF, KEYWORD_UNION, KEYWORD_UNSIGNED, KEYWORD_VOID, KEYWORD_VOLATILE, KEYWORD_WHILE} keyword_t;
typedef enum {SYMBOL_EQUAL, SYMBOL_NOT_EQUAL, SYMBOL_LESS_EQUAL, SYMBOL_GREATER_EQUAL, SYMBOL_LOGICAL_AND, SYMBOL_LOGICAL_OR, SYMBOL_LEFT_SHIFT, SYMBOL_RIGHT_SHIFT, SYMBOL_ADD, SYMBOL_SUB, SYMBOL_MUL, SYMBOL_DIV, SYMBOL_ASSIGN, SYMBOL_LESS_THAN, SYMBOL_GREATER_THAN, SYMBOL_LOGICAL_NOT, SYMBOL_BITWISE_AND, SYMBOL_BITWISE_OR, SYMBOL_BITWISE_XOR, SYMBOL_BITWISE_NOT, SYMBOL_OPEN_PAREN, SYMBOL_CLOSE_PAREN, SYMBOL_OPEN_BRACE, SYMBOL_CLOSE_BRACE, SYMBOL_OPEN_BRACKET, SYMBOL_CLOSE_BRACKET, SYMBOL_SEMICOLON, SYMBOL_COMMA, SYMBOL_PERIOD} symbol_t;

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
	TOKEN_PREFIX_CHARACTER_LITERAL = 0b0001,
	TOKEN_PREFIX_INTEGER_LITERAL = 0b0010,
	TOKEN_PREFIX_FLOAT_LITERAL = 0b0011,
	TOKEN_PREFIX_STRING_LITERAL = 0b0100,
	TOKEN_PREFIX_IDENTIFIER = 0b0101,
	TOKEN_PREFIX_KEYWORD = 0b0110,
	TOKEN_PREFIX_SYMBOL = 0b0111,

	/* Are the integers signed or unsigned? */
	TOKEN_SUBTYPE_SIGNED = 0b0,
	TOKEN_SUBTYPE_UNSIGNED = 0b1,

	/*
	 *	What are the available sizes for integers?
	 *	There is 8-bit, 16-bit, 32-bit, and 64-bit support for integers.
	 */
	TOKEN_SUBTYPE_INT8 = 0b000,
	TOKEN_SUBTYPE_INT16 = 0b010,
	TOKEN_SUBTYPE_INT32 = 0b100,
	TOKEN_SUBTYPE_INT64 = 0b110,

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
	TOKEN_TYPE_INT8_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_SIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT8 & 0x07),
	TOKEN_TYPE_INT16_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_SIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT16 & 0x07),
	TOKEN_TYPE_INT32_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_SIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT32 & 0x07),
	TOKEN_TYPE_INT64_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_SIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT64 & 0x07),
	TOKEN_TYPE_UINT8_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_UNSIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT8 & 0x07),
	TOKEN_TYPE_UINT16_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_UNSIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT16 & 0x07),
	TOKEN_TYPE_UINT32_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_UNSIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT32 & 0x07),
	TOKEN_TYPE_UINT64_LITERAL = (TOKEN_PREFIX_INTEGER_LITERAL << 4) | ((TOKEN_SUBTYPE_UNSIGNED & 0x01) << 3) | (TOKEN_SUBTYPE_INT64 & 0x07),
	TOKEN_TYPE_FLOAT32_LITERAL = (TOKEN_PREFIX_FLOAT_LITERAL << 4) | (TOKEN_SUBTYPE_FLOAT & 0xF),
	TOKEN_TYPE_FLOAT64_LITERAL = (TOKEN_PREFIX_FLOAT_LITERAL << 4) | (TOKEN_SUBTYPE_DOUBLE & 0xF),
	TOKEN_TYPE_CHARACTER8_LITERAL = (TOKEN_PREFIX_CHARACTER_LITERAL << 4) | (TOKEN_SUBTYPE_CHAR & 0xF),
	TOKEN_TYPE_STRING8_LITERAL = (TOKEN_SUBTYPE_STRING << 4) | (TOKEN_SUBTYPE_STRING & 0xF),
	TOKEN_TYPE_IDENTIFIER_LITERAL = (TOKEN_PREFIX_IDENTIFIER << 4) | (0b0000 & 0xF),
	TOKEN_TYPE_KEYWORD_LITERAL = (TOKEN_PREFIX_KEYWORD << 4) | (0b0000 & 0xF),
	TOKEN_TYPE_SYMBOL_LITERAL = (TOKEN_PREFIX_SYMBOL << 4) | (0b0000 & 0xF)
} token_type_t;

typedef struct
{
	/*
	 *	The type of token.
	 *	The token type is expected to be a single byte, so we clarify it's
	 *	size as one byte by using bitfields, as it's one of the only ways
	 *	to do so.
	 */
	token_type_t token_type : 8;

	/* The buffer storing our token in plaintext, and it's size. */
	char *plaintext_buffer;
	uintmax_t plaintext_buffer_size;

	/* The buffer storing our token in tokenized form, and it's size. */
	struct
	{
		union
		{
			/* Character literal(s). */
			char character8_literal;

			/* String literal(s). */
			char *string8_literal;

			/* Identifier. */
			char *identifier;

			/* Keyword. */
			keyword_t keyword;

			/* Symbol. */
			symbol_t symbol;

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
		};

		/* Only applies to string literals & identifiers. */
		uintmax_t buffer_size;
	} value;
} token_t;

int scanner_main(char *input_source_buffer, uintmax_t *input_source_buffer_size, token_t **output_token_buffer, uintmax_t *output_token_buffer_size);