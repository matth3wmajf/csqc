#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <csquared/scanner.h>

/* The object type enum. */
typedef enum
{
	/*
	 *	The prefix types, they express the different vague types of objects we
	 *	can have.
	 */
	OBJECT_TYPE_PREFIX_DECLARATION = 0x3,
	OBJECT_TYPE_PREFIX_EXPRESSION = 0x2,
	OBJECT_TYPE_PREFIX_CONSTANT = 0x1,
	OBJECT_TYPE_PREFIX_UNKNOWN = 0x0,
	OBJECT_TYPE_PREFIX_SYMBOL = 0x4,

	/* The unknown suffix type. */
	OBJECT_TYPE_SUFFIX_UNKNOWN = 0x00,

	/* The suffix type for constants. */
	OBJECT_TYPE_SUFFIX_CHARACTER8 = 0x0B,
	OBJECT_TYPE_SUFFIX_FLOAT32 = 0x09,
	OBJECT_TYPE_SUFFIX_FLOAT64 = 0x0A,
	OBJECT_TYPE_SUFFIX_STRING8 = 0x0C,
	OBJECT_TYPE_SUFFIX_UINT64 = 0x08,
	OBJECT_TYPE_SUFFIX_UINT32 = 0x06,
	OBJECT_TYPE_SUFFIX_UINT16 = 0x04,
	OBJECT_TYPE_SUFFIX_UINT8 = 0x02,
	OBJECT_TYPE_SUFFIX_INT16 = 0x03,
	OBJECT_TYPE_SUFFIX_INT32 = 0x05,
	OBJECT_TYPE_SUFFIX_INT64 = 0x07,
	OBJECT_TYPE_SUFFIX_INT8 = 0x01,

	/*
	 *	The suffix type(s) for expressions.
	 *	The `object_type_t` type has now become a 12-bit type due to the need
	 *	of more number combinations for expressions.
	 */
	OBJECT_TYPE_SUFFIX_MULTIPLICATIVE_EXPRESSION = 0x08,
	OBJECT_TYPE_SUFFIX_EXCLUSIVE_OR_EXPRESSION = 0x0E,
	OBJECT_TYPE_SUFFIX_INCLUSIVE_OR_EXPRESSION = 0x0F,
	OBJECT_TYPE_SUFFIX_CONDITIONAL_EXPRESSION = 0x03,
	OBJECT_TYPE_SUFFIX_LOGICAL_AND_EXPRESSION = 0x10,
	OBJECT_TYPE_SUFFIX_LOGICAL_OR_EXPRESSION = 0x11,
	OBJECT_TYPE_SUFFIX_ASSIGNMENT_EXPRESSION = 0x02,
	OBJECT_TYPE_SUFFIX_RELATIONAL_EXPRESSION = 0x0B,
	OBJECT_TYPE_SUFFIX_CONSTANT_EXPRESSION = 0x12,
	OBJECT_TYPE_SUFFIX_EQUALITY_EXPRESSION = 0x0C,
	OBJECT_TYPE_SUFFIX_ADDITIVE_EXPRESSION = 0x09,
	OBJECT_TYPE_SUFFIX_PRIMARY_EXPRESSION = 0x07,
	OBJECT_TYPE_SUFFIX_POSTFIX_EXPRESSION = 0x05,
	OBJECT_TYPE_SUFFIX_SHIFT_EXPRESSION = 0x0A,
	OBJECT_TYPE_SUFFIX_UNARY_EXPRESSION = 0x04,
	OBJECT_TYPE_SUFFIX_CAST_EXPRESSION = 0x06,
	OBJECT_TYPE_SUFFIX_AND_EXPRESSION = 0x0D,
	OBJECT_TYPE_SUFFIX_EXPRESSION = 0x01,

	/* The sufffix type(s) for declarations. */
	OBJECT_TYPE_SUFFIX_EXTERNAL_DECLARATION = 0x00,
	OBJECT_TYPE_SUFFIX_STRUCT_DECLARATION = 0x01,
	OBJECT_TYPE_SUFFIX_PARAMETER_DECLARATION = 0x02,
	OBJECT_TYPE_SUFFIX_DECLARATION = 0x03,

	/* The suffix type(s) for symbols. */
	OBJECT_TYPE_SUFFIX_ELLIPSIS_SYMBOL = 0x00,
	OBJECT_TYPE_SUFFIX_EQUAL_TO_SYMBOL = 0x01,
	OBJECT_TYPE_SUFFIX_NOT_EQUAL_TO_SYMBOL = 0x02,
	OBJECT_TYPE_SUFFIX_LESS_THAN_OR_EQUAL_TO_SYMBOL = 0x03,
	OBJECT_TYPE_SUFFIX_GREATER_THAN_OR_EQUAL_TO_SYMBOL = 0x04,
	OBJECT_TYPE_SUFFIX_LOGICAL_AND_SYMBOL = 0x05,
	OBJECT_TYPE_SUFFIX_LOGICAL_OR_SYMBOL = 0x06,
	OBJECT_TYPE_SUFFIX_LEFT_SHIFT_SYMBOL = 0x07,
	OBJECT_TYPE_SUFFIX_RIGHT_SHIFT_SYMBOL = 0x08,
	OBJECT_TYPE_SUFFIX_ADD_SYMBOL = 0x09,
	OBJECT_TYPE_SUFFIX_SUBTRACT_SYMBOL = 0x0A,
	OBJECT_TYPE_SUFFIX_DIVIDE_SYMBOL = 0x0B,
	OBJECT_TYPE_SUFFIX_MULTIPLY_SYMBOL = 0x1C,
	OBJECT_TYPE_SUFFIX_ASSIGN_SYMBOL = 0x0C,
	OBJECT_TYPE_SUFFIX_MULTIPLY_ASSIGN_SYMBOL = 0x0D,
	OBJECT_TYPE_SUFFIX_DIVIDE_ASSIGN_SYMBOL = 0x0E,
	OBJECT_TYPE_SUFFIX_MODULO_ASSIGN_SYMBOL = 0x0F,
	OBJECT_TYPE_SUFFIX_ADDITION_ASSIGN_SYMBOL = 0x10,
	OBJECT_TYPE_SUFFIX_SUBTRACTION_ASSIGN_SYMBOL = 0x11,
	OBJECT_TYPE_SUFFIX_LEFT_SHIFT_ASSIGN_SYMBOL = 0x12,
	OBJECT_TYPE_SUFFIX_RIGHT_SHIFT_ASSIGN_SYMBOL = 0x13,
	OBJECT_TYPE_SUFFIX_BITWISE_AND_ASSIGN_SYMBOL = 0x14,
	OBJECT_TYPE_SUFFIX_BITWISE_XOR_ASSIGN_SYMBOL = 0x15,
	OBJECT_TYPE_SUFFIX_BITWISE_OR_ASSIGN_SYMBOL = 0x16,
	OBJECT_TYPE_SUFFIX_LESS_THAN_SYMBOL = 0x17,
	OBJECT_TYPE_SUFFIX_GREATER_THAN_SYMBOL = 0x18,
	OBJECT_TYPE_SUFFIX_LOGICAL_NOT_SYMBOL = 0x19,
	OBJECT_TYPE_SUFFIX_BITWISE_AND_SYMBOL = 0x1A,
	OBJECT_TYPE_SUFFIX_BITWISE_OR_SYMBOL = 0x1B,

	/* The different symbol type(s). */
	OBJECT_TYPE_SYMBOL = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_UNKNOWN,
	OBJECT_TYPE_SYMBOL_ELLIPSIS = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_ELLIPSIS_SYMBOL,
	OBJECT_TYPE_SYMBOL_EQUAL_TO = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_EQUAL_TO_SYMBOL,
	OBJECT_TYPE_SYMBOL_NOT_EQUAL_TO = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_NOT_EQUAL_TO_SYMBOL,
	OBJECT_TYPE_SYMBOL_LESS_THAN_OR_EQUAL_TO = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_LESS_THAN_OR_EQUAL_TO_SYMBOL,
	OBJECT_TYPE_SYMBOL_GREATER_THAN_OR_EQUAL_TO = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_GREATER_THAN_OR_EQUAL_TO_SYMBOL,
	OBJECT_TYPE_SYMBOL_LOGICAL_AND = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_LOGICAL_AND_SYMBOL,
	OBJECT_TYPE_SYMBOL_LOGICAL_OR = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_LOGICAL_OR_SYMBOL,
	OBJECT_TYPE_SYMBOL_LEFT_SHIFT = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_LEFT_SHIFT_SYMBOL,
	OBJECT_TYPE_SYMBOL_RIGHT_SHIFT = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_RIGHT_SHIFT_SYMBOL,
	OBJECT_TYPE_SYMBOL_ADD = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_ADD_SYMBOL,
	OBJECT_TYPE_SYMBOL_SUBTRACT = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_SUBTRACT_SYMBOL,
	OBJECT_TYPE_SYMBOL_DIVIDE = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_DIVIDE_SYMBOL,
	OBJECT_TYPE_SYMBOL_MULTIPLY = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_MULTIPLY_SYMBOL,
	OBJECT_TYPE_SYMBOL_ASSIGN = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_ASSIGN_SYMBOL,
	OBJECT_TYPE_SYMBOL_MULTIPLY_ASSIGN = (OBJECT_TYPE_PREFIX_SYMBOL << 8) | OBJECT_TYPE_SUFFIX_MULTIPLY_ASSIGN_SYMBOL,
} object_type_t;

typedef struct object
{
	/*
	 *	The object type, made up of vague types (prefixes) and specifiers
	 *	(suffixes).
	 */
	object_type_t object_type : 12;

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

		/* Expressions... */
		union
		{
			/* Multiplicative expressions... */
			struct
			{
				/* The operator for the multiplicative expression. */
				enum
				{
					MULTIPLICATIVE_EXPRESSION_TYPE_MULTIPLY,
					MULTIPLICATIVE_EXPRESSION_TYPE_DIVIDE,
					MULTIPLICATIVE_EXPRESSION_TYPE_MODULO,
				} operator;

				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} multiplicative;

			/* Bitwise XOR expressions... */
			struct
			{
				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} xor;

			/* Bitwise OR expressions... */
			struct
			{
				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} or;

			/* Conditional expressions... */
			struct
			{
				/* The buffer here should always be three units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} conditional;

			/* Logical AND expressions... */
			struct
			{
				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} logical_and;

			/* Logical OR expressions... */
			struct
			{
				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} logical_or;

			/* Bitwise AND expressions... */
			struct
			{
				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} and;

			/* Assignment expressions... */
			struct
			{
				/* The operator for assignment expressions. */
				enum
				{
					ASSIGNMENT_EXPRESSION_TYPE_RIGHT_SHIFT,
					ASSIGNMENT_EXPRESSION_TYPE_BITWISE_AND,
					ASSIGNMENT_EXPRESSION_TYPE_BITWISE_XOR,
					ASSIGNMENT_EXPRESSION_TYPE_LEFT_SHIFT,
					ASSIGNMENT_EXPRESSION_TYPE_BITWISE_OR,
					ASSIGNMENT_EXPRESSION_TYPE_MULTIPLY,
					ASSIGNMENT_EXPRESSION_TYPE_SUBTRACT,
					ASSIGNMENT_EXPRESSION_TYPE_SIMPLE,
					ASSIGNMENT_EXPRESSION_TYPE_DIVIDE,
					ASSIGNMENT_EXPRESSION_TYPE_MODULO,
					ASSIGNMENT_EXPRESSION_TYPE_ADD
				} operator;

				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} assignment;

			/* Assignment expressions... */
			struct
			{
				/* The operator for assignment expressions. */
				enum
				{
					RELATIONAL_EXPRESSION_TYPE_LESS_THAN,
					RELATIONAL_EXPRESSION_TYPE_BIGGER_THAN,
					RELATIONAL_EXPRESSION_TYPE_LESS_THAN_OR_EQUAL_TO,
					RELATIONAL_EXPRESSION_TYPE_BIGGER_THAN_OR_EQUAL_TO
				} operator;

				/* The buffer here should always be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} relational;

			/* Constant expressions... */
			struct
			{
				/* The buffer here can be pretty much any size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} constant;

			/* Equality expressions... */
			struct
			{
				/* The operator for assignment expressions. */
				enum
				{
					EQUALITY_EXPRESSION_TYPE_EQUAL_TO,
					EQUALITY_EXPRESSION_TYPE_NOT_EQUAL_TO
				} operator;

				/* The buffer here must be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} equality;

			/* Additive expressions... */
			struct
			{
				/* The operator for assignment expressions. */
				enum
				{
					ADDITIVE_EXPRESSION_TYPE_ADD,
					ADDITIVE_EXPRESSION_TYPE_SUBTRACT
				} operator;

				/* The buffer here must be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} additive;

			/* Postfix expressions... */
			struct
			{
				/* The operator for assignment expressions. */
				enum
				{
					POSTFIX_EXPRESSION_TYPE_INDIRECT_ACCESS,
					POSTFIX_EXPRESSION_TYPE_DIRECT_ACCCESS,
					POSTFIX_EXPRESSION_TYPE_INCREMENT,
					POSTFIX_EXPRESSION_TYPE_DECREMENT,
					POSTFIX_EXPRESSION_TYPE_ARRAY,
					POSTFIX_EXPRESSION_TYPE_CALL,
				} operator;

				/* ... */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} postfix;

			/* Shift expressions... */
			struct
			{
				/* The operator for assignment expressions. */
				enum
				{
					SHIFT_EXPRESSION_TYPE_RIGHT_SHIFT,
					SHIFT_EXPRESSION_TYPE_LEFT_SHIFT
				} operator;

				/* The buffer here must be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} shift;

			/* Unary expressions... */
			struct
			{
				/* The operator for assignment expressions. */
				enum
				{
					UNARY_EXPRESSION_TYPE_LOGICAL_NOT,
					UNARY_EXPRESSION_TYPE_BITWISE_NOT,
					UNARY_EXPRESSION_TYPE_DEREFERENCE,
					UNARY_EXPRESSION_TYPE_ADDRESS_OF,
					UNARY_EXPRESSION_TYPE_INCREMENT,
					UNARY_EXPRESSION_TYPE_DECREMENT,
					UNARY_EXPRESSION_TYPE_POSITIVE,
					UNARY_EXPRESSION_TYPE_NEGATIVE,
					UNARY_EXPRESSION_TYPE_SIZEOF
				} operator;

				/* The buffer here must be two units in size. */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} unary;

			/* Cast expressions... */
			struct
			{
				/*
				 *	The buffer here must consist of the type name, and another
				 *	cast expression or unary expression.
				 */
				struct object *operand_buffer;
				uintmax_t operand_buffer_size;
			} cast;
		} expression;
	};
} object_t;

int parser_main(token_t *input_token_buffer, uintmax_t *input_token_buffer_size, object_t **output_object_buffer, uintmax_t *output_object_buffer_size);