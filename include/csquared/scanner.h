#pragma once

#include <stdbool.h>
#include <stdint.h>

/* The token & symbol enumerations, respective to their plaintext buffers. */
typedef enum {AUTO, BREAK, CASE, BYTE, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, DWORD, QWORD, REGISTER, RETURN, WORD, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE} keyword_t;
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

/* Is the character a valid identifier character? */
static inline bool is_valid_identifier_character(char character)
{
	return is_alphanumeric(character) || character == '_';
}

/* The different types of tokens. */
typedef enum
{
	TOKEN_TYPE_UNSIGNED_INTEGER_LITERAL,
	TOKEN_TYPE_CHARACTER_LITERAL,
	TOKEN_TYPE_INTEGER_LITERAL,
	TOKEN_TYPE_STRING_LITERAL,
	TOKEN_TYPE_FLOAT_LITERAL,
	TOKEN_TYPE_IDENTIFIER,
	TOKEN_TYPE_KEYWORD,
	TOKEN_TYPE_SYMBOL,
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
			intmax_t signed_integer_literal;
			uintmax_t unsigned_integer_literal;
			double float_literal;
			char character_literal;
			char *string_literal;
			char *identifier;
			keyword_t keyword;
			symbol_t symbol;
		};

		/* Only applies to string literals & identifiers. */
		uintmax_t buffer_size;
	} value;
} token_t;

int scanner(char *input_source_buffer, uintmax_t *input_source_buffer_size, token_t **output_token_buffer, uintmax_t *output_token_buffer_size);