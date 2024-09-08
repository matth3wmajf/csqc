#pragma once

#include <stdbool.h>
#include <stdint.h>

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
	char *token_buffer;
	uintmax_t token_buffer_size;
} token_t;

int scan(char *input_source_buffer, uintmax_t *input_source_buffer_size, token_t **output_token_buffer, uintmax_t *output_token_buffer_size);