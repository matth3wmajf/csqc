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
	 *	5. Modulo
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