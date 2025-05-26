/*
 *	                         .d8888b.    o    .d8888b.                         
 *	                        d88P  Y88b  d8b  d88P  Y88b                        
 *	                        888    888 d888b        888                        
 *	                        888       d8P"Y8b     .d88P                        
 *	                        888               .od888P"                         
 *	                        888    888       d88P"                             
 *	                        Y88b  d88P       888"                              
 *	                         "Y8888P"        888888888                         
 *	 Copyright (C) 2024-2025, Matthew E. Majfud-Wilinski. All Rights Reserved. 
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

/* The token & symbol enumerations, respective to their plaintext buffers. */
typedef enum {KEYWORD_AUTO, KEYWORD_BREAK, KEYWORD_CASE, KEYWORD_BYTE, KEYWORD_CONST, KEYWORD_CONTINUE, KEYWORD_DEFAULT, KEYWORD_DO, KEYWORD_ELSE, KEYWORD_ENUM, KEYWORD_EXTERN, KEYWORD_FOR, KEYWORD_GOTO, KEYWORD_IF, KEYWORD_REGISTER, KEYWORD_RETURN, KEYWORD_SIZEOF, KEYWORD_STATIC, KEYWORD_STRUCT, KEYWORD_SWITCH, KEYWORD_TYPEDEF, KEYWORD_UNION, KEYWORD_UNSIGNED, KEYWORD_SIGNED, KEYWORD_VOID, KEYWORD_VOLATILE, KEYWORD_WHILE} keyword_t;
typedef enum {SYMBOL_MULTIPLY_ASSIGN, SYMBOL_DIVIDE_ASSIGN, SYMBOL_MODULO_ASSIGN, SYMBOL_ADDITION_ASSIGN, SYMBOL_SUBTRACTION_ASSIGN, SYMBOL_LEFT_SHIFT_ASSIGN, SYMBOL_RIGHT_SHIFT_ASSIGN, SYMBOL_BITWISE_AND_ASSIGN, SYMBOL_BITWISE_XOR_ASSIGN, SYMBOL_BITWISE_OR_ASSIGN, SYMBOL_ARROW, SYMBOL_INCREMENT, SYMBOL_DECREMENT, SYMBOL_ELLIPSIS, SYMBOL_EQUAL_TO, SYMBOL_NOT_EQUAL_TO, SYMBOL_LESS_THAN_OR_EQUAL_TO, SYMBOL_GREATER_THAN_OR_EQUAL_TO, SYMBOL_LOGICAL_AND, SYMBOL_LOGICAL_OR, SYMBOL_LEFT_SHIFT, SYMBOL_RIGHT_SHIFT, SYMBOL_ADD, SYMBOL_SUBTRACT, SYMBOL_MULTIPLY, SYMBOL_DIVIDE, SYMBOL_ASSIGN, SYMBOL_LESS_THAN, SYMBOL_GREATER_THAN, SYMBOL_LOGICAL_NOT, SYMBOL_BITWISE_AND, SYMBOL_BITWISE_OR, SYMBOL_BITWISE_XOR, SYMBOL_BITWISE_NOT, SYMBOL_OPEN_PARENTHESIS, SYMBOL_CLOSE_PARENTHESIS, SYMBOL_OPEN_BRACE, SYMBOL_CLOSE_BRACE, SYMBOL_OPEN_BRACKET, SYMBOL_CLOSE_BRACKET, SYMBOL_SEMICOLON, SYMBOL_COMMA, SYMBOL_PERIOD, SYMBOL_MODULO, SYMBOL_CONDITIONAL, SYMBOL_COLON} symbol_t;

/* The plaintext buffers for tokens & symbols. */
extern const char *pg_keywords[];
extern const char *pg_symbols[];

/* Is the character whitespace? */
static inline bool is_whitespace(char t_character)
{
/* ... */
	return t_character == ' ' || t_character == '\t' || t_character == '\f' || t_character == '\v' || t_character == '\n' || t_character == '\r';
}

/* Is the character a letter? */
static inline bool is_alphabet(char t_character)
{
/* ... */
	return (t_character >= 'a' && t_character <= 'z') || (t_character >= 'A' && t_character <= 'Z');
}

/* Is the character alphanumeric? */
static inline bool is_alphanumeric(char t_character)
{
/* ... */
	return (t_character >= 'a' && t_character <= 'z') || (t_character >= 'A' && t_character <= 'Z') || (t_character >= '0' && t_character <= '9');
}

/* Is the character a digit? */
static inline bool is_digit(char t_character)
{
/* ... */
	return t_character >= '0' && t_character <= '9';
}

static inline bool is_numeric(char t_character)
{
/* ... */
	return is_digit(t_character) || t_character == '.';
}

/* Is the character a valid identifier character? */
static inline bool is_valid_identifier_character(char t_character)
{
/* ... */
	return is_alphanumeric(t_character) || t_character == '_';
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
 *	We've got 8-bit characters, commonly known as characters, and then wide
 *	characters, which tend to be 16-bit or 32-bit.
 *	For now, we will only implement the 8-bit character, however we may support
 *	the wide characters in the future.
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
 *	Some of them actually don't even need any suffix(es) or subtypes, such as
 *	identifiers, keywords, and symbols.
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
	TOKEN_TYPE_IDENTIFIER = (TOKEN_PREFIX_IDENTIFIER << 4) | (0b0000 & 0xF),
	TOKEN_TYPE_KEYWORD = (TOKEN_PREFIX_KEYWORD << 4) | (0b0000 & 0xF),
	TOKEN_TYPE_SYMBOL = (TOKEN_PREFIX_SYMBOL << 4) | (0b0000 & 0xF)
} token_type_t;

typedef struct
{
/*
 *	The type of token.
 *	The token type is expected to be a single byte, so we clarify it's size as
 *	one byte by using bitfields, as it's one of the only ways to do so.
 */
	token_type_t t_token_type : 8;

/* The buffer storing our token in plaintext, and it's size. */
	char *pt_plaintext_buffer;
	uintmax_t t_plaintext_buffer_size;

/* The buffer storing our token in tokenized form, and it's size. */
	struct
	{
		union
		{
/* Character literal(s). */
			char t_character8_literal;

/* String literal(s). */
			char *pt_string8_literal;

/* Identifier. */
			char *pt_identifier;

/* Keyword. */
			keyword_t t_keyword;

/* Symbol. */
			symbol_t t_symbol;

/*
 *	Integer types, both signed & unsigned, includes the 8-bit, 16-bit, 32-bit,
 *	and 64-bit sizes.
 */
			int8_t t_int8_literal;
			int16_t t_int16_literal;
			int32_t t_int32_literal;
			int64_t t_int64_literal;
			uint8_t t_uint8_literal;
			uint16_t t_uint16_literal;
			uint32_t t_uint32_literal;
			uint64_t t_uint64_literal;

/* Floating-point types, both 32-bit & 64-bit float literals. */
			float t_float32_literal;
			double t_float64_literal;
		};

/* Only applies to string literals & identifiers. */
		uintmax_t t_buffer_size;
	} t_value;
} token_t;

int scanner_main(char *pt_input_source_buffer, uintmax_t *pt_input_source_buffer_size, token_t **ppt_output_token_buffer, uintmax_t *pt_output_token_buffer_size);