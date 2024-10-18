#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <csquared/scanner.h>

typedef enum
{
	/*
	 *	The vague object types, and their prefix.
	 *	This includes the following...
	 *	1. Constant
	 *	2. Ellipsis
	 *	3. Equality
	 */
	OBJECT_PREFIX_CONSTANT = 0b00000000,
	OBJECT_PREFIX_ELLIPSIS = 0b00000001,
	OBJECT_PREFIX_EQUALITY = 0b00000010,

	/*
	 *	Unary operators for expressions.
	 *	This includes the following...
	 *	1. Increment
	 *	2. Decrement
	 *	3. Positive
	 *	4. Negative
	 */
	OBJECT_SUBTYPE_UNARY_INCREMENT = 0b00000000,
	OBJECT_SUBTYPE_UNARY_DECREMENT = 0b00000001,
	OBJECT_SUBTYPE_UNARY_POSITIVE = 0b00000010,
	OBJECT_SUBTYPE_UNARY_NEGATIVE = 0b00000011,

	/*
	 *	Binary operators for expressions.
	 *	This includes the following...
	 *	1. Addition
	 *	2. Subtraction
	 *	3. Multiplication
	 *	4. Division
	 *	5. Modulo
	 *	6. Exponent
	 */
	OBJECT_SUBTYPE_BINARY_ADDITION = 0b01000100,
	OBJECT_SUBTYPE_BINARY_SUBTRACTION = 0b01000101,
	OBJECT_SUBTYPE_BINARY_MULTIPLICATION = 0b01000110,
	OBJECT_SUBTYPE_BINARY_DIVISION = 0b01000111,
	OBJECT_SUBTYPE_BINARY_MODULO = 0b01001000,
	OBJECT_SUBTYPE_BINARY_EXPONENT = 0b01001001,

	/*
	 *	Ternary operators for expressions.
	 *	We only plan on implementing one for now, however we may implement
	 *	more in the future...
	 *	1. Conditional
	 */
	OBJECT_SUBTYPE_CONDITIONAL = 0b10000000,

	/*
	 *	The types of scopes out there.
	 *	These include the following...
	 *	1. Function
	 *	2. File
	 *	3. Block
	 *	4. Prototype
	 */
	OBJECT_SUBTYPE_SCOPE_FUNCTION = 0b00000000,
	OBJECT_SUBTYPE_SCOPE_FILE = 0b00000001,
	OBJECT_SUBTYPE_SCOPE_BLOCK = 0b00000010,
	OBJECT_SUBTYPE_SCOPE_PROTOTYPE = 0b00000011,

	/* The types of equality expressions. */
	OBJECT_SUBTYPE_EQUALITY_EXPRESSION_EQUALS_TO = 0b00000000,
	OBJECT_SUBTYPE_EQUALITY_EXPRESSION_NOT_EQUALS_TO = 0b00000001,
	OBJECT_SUBTYPE_RELATIONAL_EXPRESSION_LESS_THAN = 0b00000010,
	OBJECT_SUBTYPE_RELATIONAL_EXPRESSION_GREATER_THAN = 0b00000011,
	OBJECT_SUBTYPE_RELATIONAL_EXPRESSION_LESS_THAN_OR_EQUAL_TO = 0b00000100,
	OBJECT_SUBTYPE_RELATIONAL_eXPRESSION_GREATER_THAN_OR_EQUAL_TO = 0b00000101,
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

		union
		{
			struct
			{
				/* The `typedef` object. */
				struct object *type_definition_keyword_object;

				/* The definition. */
				struct object *type_definition_object;

				/* The defined type names. */
				struct object *type_name_object_buffer;
				uintmax_t type_name_object_buffer_size;
			} type;
		} declaration;
	};
} object_t;

int parser_main(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size);