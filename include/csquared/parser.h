#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <csquared/scanner.h>

typedef enum {PRIMITIVE_TYPE_BYTE, PRIMITIVE_TYPE_DWORD, PRIMITIVE_TYPE_FLOAT, PRIMITIVE_TYPE_DOUBLE, PRIMITIVE_TYPE_VOID, PRIMITIVE_TYPE_WORD, PRIMITIVE_TYPE_QWORD} primitive_type_t;
typedef enum {TYPE_QUALIFIER_CONST, TYPE_QUALIFIER_VOLATILE, TYPE_QUALIFIER_STATIC, TYPE_QUALIFIER_EXTERN, TYPE_QUALIFIER_INLINE, TYPE_QUALIFIER_REGISTER, TYPE_QUALIFIER_AUTO, TYPE_QUALIFIER_RESTRICT} type_qualifier_t;

extern const char *g_primitive_type_buffer[];
extern const uintmax_t g_primitive_type_buffer_size;

extern const char *g_type_qualifier_buffer[];
extern const uintmax_t g_type_qualifier_buffer_size;

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

static inline bool is_identifier(token_t *identifier)
{
	return identifier->token_type == TOKEN_TYPE_IDENTIFIER;
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
	BINARY_OPERATOR_ADD,
	BINARY_OPERATOR_SUBTRACT,
	BINARY_OPERATOR_MULTIPLY,
	BINARY_OPERATOR_DIVIDE
} binary_operator_t;

typedef struct object_t
{
	/* Store the pointer(s) to the object's children node(s). */
	struct object_t *children_object_buffer;
	uintmax_t children_object_buffer_size;

	/* Store the object's type. */
	object_type_t object_type;

	union
	{
		struct
		{
			primitive_type_t primitive_type;

			uintmax_t type_qualifier_buffer_size;
			type_qualifier_t *type_qualifier_buffer;

			uintmax_t identifier_buffer_size;
			char *identifier;

			union
			{
				int8_t byte_value;
				int16_t word_value;
				int32_t dword_value;
				int64_t qword_value;
				float float_value;
				double double_value;
			};
		} declaration;
		struct
		{
			binary_operator_t binary_operator;
		} binary_expression;
	};
} object_t;

int parser(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size);