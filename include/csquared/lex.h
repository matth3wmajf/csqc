#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#include "string.h"
#include "vector.h"

static inline bool is_whitespace(char character)
{
	return character == ' ' || character == '\t' || character == '\f' || character == '\v' || character == '\n' || character == '\r';
}

static inline bool is_alphabet(char character)
{
	return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

static inline bool is_alphanumeric(char character)
{
	return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9');
}

static inline bool is_digit(char character)
{
	return character >= '0' && character <= '9';
}

static inline bool is_valid_identifier_char(char character)
{
	return is_alphanumeric(character) || character == '_';
}

typedef enum
{
	TYPE_STRING,
	TYPE_IDENTIFIER,
	TYPE_KEYWORD,
	TYPE_SYMBOL,
	TYPE_CHAR,
	TYPE_INTEGER,
	TYPE_FLOAT
} type_t;

typedef struct
{
	union
	{
		string_t stringlit;
		string_t identifier;
		string_t keyword;
		string_t symbol;
		char charlit;
		string_t integerlit;
		string_t floatlit;
	} value;
	type_t type;
} token_t;

int lex(string_t *code, vector_t *tokens);