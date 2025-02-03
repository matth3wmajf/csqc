#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <csqc/scanner.h>

/*
 *	The keywords, the symbols, and their respective enumerations.
 *	This time, we re-ordered the symbol array and it's respective enumeraton
 *	so that the scanner considers double-equals to be a single symbol, before
 *	considering the double-equals to be two separate symbols.
 *	This same logic applies to most other symbols, such as `<` and `<<`.
 */
const char *pg_keywords[] = {"auto", "break", "case", "byte", "const", "continue", "default", "do", "else", "enum", "extern", "for", "goto", "if", "register", "return", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "signed", "void", "volatile", "while"};
const char *pg_symbols[] = {"*=", "/=", "%=", "+=", "-=", "<<=", ">>=", "&=", "^=", "|=", "->", "++", "--", "...", "==", "!=", "<=", ">=", "&&", "||", "<<", ">>", "+", "-", "*", "/", "=", "<", ">", "!", "&", "|", "^", "~", "(", ")", "{", "}", "[", "]", ";", ",", ".", "%", "?", ":"};
 
/* Analyze the inputted source code, and output an array of tokens. */
int scanner_main(char *pt_input_source_buffer, uintmax_t *pt_input_source_buffer_size, token_t **ppt_output_token_buffer, uintmax_t *pt_output_token_buffer_size)
{
	uintmax_t l_i = 0;

	while(l_i < *pt_input_source_buffer_size)
	{
		/* Skip whitespace. */
		if(is_whitespace(pt_input_source_buffer[l_i]))
		{
			l_i++;
			continue;
		}

		/* Check for keywords. */
		for(uintmax_t l_j = 0; l_j < sizeof(pg_keywords) / sizeof(pg_keywords[0]); l_j++)
		{
			char l_delimiter = pt_input_source_buffer[l_i + strlen(pg_keywords[l_j])];

			if(l_i + strlen(pg_keywords[l_j]) <= *pt_input_source_buffer_size && strncmp(pg_keywords[l_j], pt_input_source_buffer + l_i, strlen(pg_keywords[l_j])) == 0 && (l_i + strlen(pg_keywords[l_j]) == *pt_input_source_buffer_size || !is_valid_identifier_character(pt_input_source_buffer[l_i + strlen(pg_keywords[l_j])])))
			{
				/* Resize the buffer of scanned tokens. */
				(*pt_output_token_buffer_size)++;
				*ppt_output_token_buffer = realloc(*ppt_output_token_buffer, *pt_output_token_buffer_size * sizeof(token_t));

				/* Set the token type. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = TOKEN_TYPE_KEYWORD;

				/* Add the plaintext version of the token to the buffer. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].pt_plaintext_buffer = (char *)pg_keywords[l_j];
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_plaintext_buffer_size = strlen(pg_keywords[l_j]);

				/* Add the token to the buffer. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_keyword = l_j;

				/* Skip over the keyword. */
				l_i += strlen(pg_keywords[l_j]);

				/* Break out of the loop. */
				continue;
			}
		}

		/* Check for symbols. */
		for(uintmax_t l_j = 0; l_j < sizeof(pg_symbols) / sizeof(pg_symbols[0]); l_j++)
		{
			if(l_i + strlen(pg_symbols[l_j]) <= *pt_input_source_buffer_size && 
			strncmp(pg_symbols[l_j], pt_input_source_buffer + l_i, strlen(pg_symbols[l_j])) == 0)
			{
				/* Resize the buffer of scanned tokens. */
				(*pt_output_token_buffer_size)++;
				*ppt_output_token_buffer = realloc(*ppt_output_token_buffer, *pt_output_token_buffer_size * sizeof(token_t));

				/* Set the token type. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_SYMBOL;

				/* Add the plaintext to the buffer. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].pt_plaintext_buffer = (char *)pg_symbols[l_j];
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_plaintext_buffer_size = strlen(pg_symbols[l_j]);

				/* Add the token to the buffer. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_symbol = l_j;

				/* Skip over the symbol. */
				l_i += strlen(pg_symbols[l_j]);

				/* Break out of the loop. */
				break;
			}
		}

		/* Handle character literals. */
		if(pt_input_source_buffer[l_i] == '\'')
		{
			/* Move past the opening single quote. */
			l_i++;
			char l_character;

			/* Backslash detected! */
			if(pt_input_source_buffer[l_i] == '\\')
			{
				/* Move past the backslash. */
				l_i++;
				
				/* Handle escape sequences. */
				switch (pt_input_source_buffer[l_i])
				{
					case 'n': l_character = '\n'; break;
					case 't': l_character = '\t'; break;
					case 'r': l_character = '\r'; break;
					case '\\': l_character = '\\'; break;
					case '\'': l_character = '\''; break;
					
					/* Invalid escape sequence, terminate the scanning process. */
					fprintf(stderr, "error: Unknown escape sequence found while scanning a character literal!\n");
					default: return -1;
				}
			}
			else
			{
				l_character = pt_input_source_buffer[l_i];
			}

			/* Move to the closing quote. */
			l_i++;

			if (pt_input_source_buffer[l_i] != '\'')
			{
				/*
				 *	Unterminated character literal, terminate the scanning
				 *	process.
				 */
				fprintf(stderr, "error: Encountered unterminated character literal!\n");
				return -1;
			}

			/* Resize the buffer of scanned tokens. */
			(*pt_output_token_buffer_size)++;
			*ppt_output_token_buffer = realloc(*ppt_output_token_buffer, *pt_output_token_buffer_size * sizeof(token_t));

			/* Set the token type. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_CHARACTER8_LITERAL;

			/* Add the plaintext to the buffer. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].pt_plaintext_buffer = malloc(sizeof(char));
			*(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].pt_plaintext_buffer = l_character;
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_plaintext_buffer_size = sizeof(char);

			/* Add the token to the buffer. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_character8_literal = l_character;

			/* Move past the closing quote. */
			l_i++;
		}

		/* Handle string literals. */
		if(pt_input_source_buffer[l_i] == '"')
		{
			/* Move past the opening quote. */
			l_i++;

			/* Initialize a dynamic buffer for the string literal. */
			char *l_string_buffer = NULL;
			uintmax_t l_string_length = 0;

			while(pt_input_source_buffer[l_i] != '"' && pt_input_source_buffer[l_i] != '\0')
			{
				char l_character;
				if(pt_input_source_buffer[l_i] == '\\')
				{
					/* Handle escape sequences. */
					l_i++;
					switch (pt_input_source_buffer[l_i])
					{
						case 'n': l_character = '\n'; break;
						case 't': l_character = '\t'; break;
						case 'r': l_character = '\r'; break;
						case '\\': l_character = '\\'; break;
						case '"': l_character = '"'; break;
						default: 
							/* Invalid escape sequence, terminate the scanning process. */
							free(l_string_buffer);
							fprintf(stderr, "error: Encountered an invalid escape sequence while scanning a string literal!\n");
							return -1;
					}
				}
				else
				{
					l_character = pt_input_source_buffer[l_i];
				}

				/* Append the character to the string buffer. */
				l_string_buffer = realloc(l_string_buffer, l_string_length + 1);
				l_string_buffer[l_string_length++] = l_character;

				l_i++;
			}

			if (pt_input_source_buffer[l_i] != '"')
			{
				/* Unterminated string literal, terminate the scanning process. */
				free(l_string_buffer);
				fprintf(stderr, "error: Encountered an unterminated string literal!\n");
				return -1;
			}

			/* Resize the buffer of scanned tokens. */
			(*pt_output_token_buffer_size)++;
			*ppt_output_token_buffer = realloc(*ppt_output_token_buffer, *pt_output_token_buffer_size * sizeof(token_t));

			/* Set the token type. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_STRING8_LITERAL;

			/* Add the plaintext to the buffer. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].pt_plaintext_buffer = l_string_buffer;
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_plaintext_buffer_size = l_string_length;

			/* Add the token to the buffer. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.pt_string8_literal = l_string_buffer;
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_buffer_size = l_string_length;

			/* Move past the closing quote. */
			l_i++;
		}

		/* Handle identifiers. */
		if(is_alphabet(pt_input_source_buffer[l_i]) || pt_input_source_buffer[l_i] == '_')
		{
			/* Store the start of the identifier's name in memory. */
			uintmax_t l_start = l_i;

			/*
			 *	Keep adding characters to the identifier's name until a
			 *	non-identifier character is encountered.
			 */
			while (l_i < *pt_input_source_buffer_size && is_valid_identifier_character(pt_input_source_buffer[l_i]))
			{
				l_i++;
			}

			/* Calculate the length of the identifier. */
			uintmax_t l_length = l_i - l_start;

			/* Resize the buffer of scanned tokens. */
			(*pt_output_token_buffer_size)++;
			*ppt_output_token_buffer = realloc(*ppt_output_token_buffer, *pt_output_token_buffer_size * sizeof(token_t));

			/* Set the token type. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_IDENTIFIER;

			/* Add the plaintext to the buffer. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].pt_plaintext_buffer = pt_input_source_buffer + l_start;
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_plaintext_buffer_size = l_length;

			/* Add the token to the buffer. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.pt_identifier = pt_input_source_buffer + l_start;
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_buffer_size = l_length;
		}

		/* Handle numbers. */
		if(is_digit(pt_input_source_buffer[l_i]) || (pt_input_source_buffer[l_i] == '.' && is_digit(pt_input_source_buffer[l_i + 1])))
		{
			/* Store the start of the number in memory. */
			uintmax_t l_start = l_i;

			/* Flag to determine whether the number is a floating point or an integer. */
			bool l_is_floating_point = false;

			/* Parse the integer or floating point part. */
			while(l_i < *pt_input_source_buffer_size && (is_digit(pt_input_source_buffer[l_i]) || pt_input_source_buffer[l_i] == '.'))
			{
				if(pt_input_source_buffer[l_i] == '.')
				{
					/* If there's a dot, mark it as a floating-point number. */
					l_is_floating_point = true;
				}

				l_i++;
			}

			/* Store the number literal without the suffix first. */
			uintmax_t l_number_length = l_i - l_start;
			char *pl_number_literal = malloc(l_number_length + 1);
			if(pl_number_literal == NULL)
			{
				fprintf(stderr, "error: Memory allocation failed for storing the number literal's value in string form!\n");
				return -1;
			}

			memcpy(pl_number_literal, pt_input_source_buffer + l_start, l_number_length);
			pl_number_literal[l_number_length] = '\0';

			/* Now process any suffixes. */
			uintmax_t l_suffix_start = l_i;

			/* Check for integer suffixes (U, L, LL, UL, etc.) or floating-point suffixes (f, l). */
			while(l_i < *pt_input_source_buffer_size && (is_alphabet(pt_input_source_buffer[l_i])))
			{
				l_i++;
			}

			/* Extract the suffix if there is one. */
			uintmax_t l_suffix_length = l_i - l_suffix_start;
			char *pl_suffix_literal = malloc(l_suffix_length + 1);
			if(pl_suffix_literal == NULL)
			{
				free(pl_number_literal);
				fprintf(stderr, "error: Memory allocation failed for storing the suffix of the number literal!\n");
				return -1;
			}

			memcpy(pl_suffix_literal, pt_input_source_buffer + l_suffix_start, l_suffix_length);
			pl_suffix_literal[l_suffix_length] = '\0';

			/* Resize the buffer of scanned tokens. */
			(*pt_output_token_buffer_size)++;
			*ppt_output_token_buffer = realloc(*ppt_output_token_buffer, *pt_output_token_buffer_size * sizeof(token_t));

			/* Add the plaintext (number + suffix) to the token's buffer. */
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].pt_plaintext_buffer = pl_number_literal;
			(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_plaintext_buffer_size = l_number_length + l_suffix_length;

			/* Set the vague token type. */
			if(l_is_floating_point)
			{
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_FLOAT32_LITERAL;
			}
			else if(!l_is_floating_point)
			{
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_INT32_LITERAL;
			}

			

			/*
			 *	Narrow down the token type based on the suffix.
			 *	Also make sure the default type is set, that being a 32-bit
			 *	integer literal.
			 */
			uintmax_t l_j = 0;

			while(l_j < l_suffix_length)
			{
				if((pl_suffix_literal[l_j] == 'f' || pl_suffix_literal[l_j] == 'F') && l_is_floating_point)
				{
					/* It's a 32-bit float literal. */
					(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)(TOKEN_PREFIX_FLOAT_LITERAL << 4) | (TOKEN_SUBTYPE_FLOAT & 0x0F);

					l_j++;
				}
				else if((pl_suffix_literal[l_j] == 'l' || pl_suffix_literal[l_j] == 'L') && l_is_floating_point)
				{
					/* It's a 64-bit long double literal. */
					(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)(TOKEN_PREFIX_FLOAT_LITERAL << 4) | (TOKEN_SUBTYPE_DOUBLE & 0x0F);

					l_j++;
				}
				else if(((pl_suffix_literal[l_j] == 'l' || pl_suffix_literal[l_j] == 'L') && (pl_suffix_literal[l_j + 1] == 'l' || pl_suffix_literal[l_j + 1] == 'L')) && !l_is_floating_point)
				{
					/*
					 *	We're dealing with a long long literal, which is
					 *	guaranteed to be 64-bit.
					 *	We must also preserve it's signedness, just like
					 *	the long literal's handling above has done so.
					 */
					uint8_t l_existing_signedness = (*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type & 0b00001000;

					(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (TOKEN_PREFIX_INTEGER_LITERAL << 1) | (l_existing_signedness << 3) | (TOKEN_SUBTYPE_INT64 << 4); 

					l_j += 2;
				}
				else if ((pl_suffix_literal[l_j] == 'l' || pl_suffix_literal[l_j] == 'L') && !l_is_floating_point)
				{
					/*
					 *	It's a long literal, however we're not sure yet if
					 *	it's a 32-bit or 64-bit integer, and therefore, we
					 *	must check the size of the long type.
					 *	We must also preserve it's signedness, instead of
					 *	overriding it.
					 */
					uint8_t l_existing_signedness = (*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type & 0b1;

					if(sizeof(long) == 8)
						(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (TOKEN_PREFIX_INTEGER_LITERAL << 1) | (l_existing_signedness << 3) | (TOKEN_SUBTYPE_INT64 << 4);
					else if(sizeof(long) == 4)
						(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (TOKEN_PREFIX_INTEGER_LITERAL << 1) | (l_existing_signedness << 3) | (TOKEN_SUBTYPE_INT32 << 4);

					l_j++;
				}
				
				else if((pl_suffix_literal[l_j] == 'u' || pl_suffix_literal[l_j] == 'U') && !l_is_floating_point)
				{
					/*
					 *  Suffix contains a `u`, so it must be unsigned.
					 *  Therefore, only change it's signedness attribute, but
					 *  nothing else.
					 */
					(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type |= (1 << 4);

					l_j++;
				}
				else if ((pl_suffix_literal[l_j] == 's' || pl_suffix_literal[l_j] == 'S') && !l_is_floating_point)
				{
					/* Same goes to this... */
					(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type &= ~(1 << 4);

					l_j++;
				}
			}

			/*
			 *	If there's no suffix, but a floating point number was
			 *	detected, then simply submit the token as a floating point
			 *	literal, but without a known size.
			 *	If there's no suffix, but an integer was detected, then simply
			 *	submit the token as a 32-bit integer literal.
			 */
			if(l_suffix_length == 0 && l_is_floating_point)
			{
				/* It's an unknown floating point literal. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_FLOAT64_LITERAL;
			}
			else if(l_suffix_length == 0 && !l_is_floating_point)
			{
				/* It's an unknown integer literal. */
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type = (uint8_t)TOKEN_TYPE_INT32_LITERAL;
			}

			/* Now, time to set the literal's value based on the precise type. */
			switch((uint8_t)(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_token_type)
			{
			case (uint8_t)TOKEN_TYPE_INT8_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_int8_literal = (int8_t)strtol(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_UINT8_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_uint8_literal = (uint8_t)strtol(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_INT16_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_int16_literal = (int16_t)strtol(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_UINT16_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_uint16_literal = (uint16_t)strtol(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_INT32_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_int32_literal = (int32_t)strtol(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_UINT32_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_uint32_literal = (uint32_t)strtol(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_INT64_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_int64_literal = (int64_t)strtoll(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_UINT64_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_uint64_literal = (uint64_t)strtoull(pl_number_literal, NULL, 10);
				break;
			case (uint8_t)TOKEN_TYPE_FLOAT32_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_float32_literal = (float)strtof(pl_number_literal, NULL);
				break;
			case (uint8_t)TOKEN_TYPE_FLOAT64_LITERAL:
				(*ppt_output_token_buffer)[(*pt_output_token_buffer_size) - 1].t_value.t_float64_literal = (double)strtod(pl_number_literal, NULL);
				break;
			}

			/* Free the suffix literal memory. */
			free(pl_suffix_literal);

			/* Move past the number and suffix. */
			free(pl_number_literal);
		}
	}

	return 0;
}