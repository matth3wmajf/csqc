#include <string.h>
#include <stdint.h>
#include <malloc.h>

#include <csquared/scanner.h>

/*
 *	The keywords, the symbols, and their respective enumerations.
 *	This time, we re-ordered the symbol array and it's respective enumeraton
 *	so that the scanner considers double-equals to be a single symbol, before
 *	considering the double-equals to be two separate symbols.
 *	This same logic applies to most other symbols, such as `<` and `<<`.
 */
const char *g_keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
const char *g_symbols[] = {"==", "!=", "<=", ">=", "&&", "||", "<<", ">>", "+", "-", "*", "/", "=", "<", ">", "!", "&", "|", "^", "~", "(", ")", "{", "}", "[", "]", ";", ",", "."};

/* Analyze the inputted source code, and output an array of tokens. */
int scanner(char *input_source_buffer, uintmax_t *input_source_buffer_size, token_t **output_token_buffer, uintmax_t *output_token_buffer_size)
{
	uintmax_t l_i = 0;

	while(l_i < *input_source_buffer_size)
	{
		/* Skip whitespace. */
		if(is_whitespace(input_source_buffer[l_i]))
		{
			l_i++;
			continue;
		}

		/* Check for keywords. */
		for(uintmax_t l_j = 0; l_j < sizeof(g_keywords) / sizeof(g_keywords[0]); l_j++)
		{
			char l_delimiter = input_source_buffer[l_i + strlen(g_keywords[l_j])];

			if(l_i + strlen(g_keywords[l_j]) <= *input_source_buffer_size && strncmp(g_keywords[l_j], input_source_buffer + l_i, strlen(g_keywords[l_j])) == 0 && (l_i + strlen(g_keywords[l_j]) == *input_source_buffer_size || !is_valid_identifier_character(input_source_buffer[l_i + strlen(g_keywords[l_j])])))
			{
				/* Resize the buffer of scanned tokens. */
				(*output_token_buffer_size)++;
				*output_token_buffer = realloc(*output_token_buffer, *output_token_buffer_size * sizeof(token_t));

				/* Set the token type. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_KEYWORD;

				/* Add the plaintext version of the token to the buffer. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer = (char *)g_keywords[l_j];
				(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer_size = strlen(g_keywords[l_j]);

				/* Add the token to the buffer. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].value.keyword = l_j;

				/* Skip over the keyword. */
				l_i += strlen(g_keywords[l_j]);

				/* Break out of the loop. */
				continue;
			}
		}

		/* Check for symbols. */
		for(uintmax_t l_j = 0; l_j < sizeof(g_symbols) / sizeof(g_symbols[0]); l_j++)
		{
			if(l_i + strlen(g_symbols[l_j]) <= *input_source_buffer_size && 
			strncmp(g_symbols[l_j], input_source_buffer + l_i, strlen(g_symbols[l_j])) == 0)
			{
				/* Resize the buffer of scanned tokens. */
				(*output_token_buffer_size)++;
				*output_token_buffer = realloc(*output_token_buffer, *output_token_buffer_size * sizeof(token_t));

				/* Set the token type. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_SYMBOL;

				/* Add the plaintext to the buffer. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer = (char *)g_symbols[l_j];
				(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer_size = strlen(g_symbols[l_j]);

				/* Add the token to the buffer. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].value.symbol = l_j;

				/* Skip over the symbol. */
				l_i += strlen(g_symbols[l_j]);

				/* Break out of the loop. */
				break;
			}
		}

		/* Handle character literals. */
		if(input_source_buffer[l_i] == '\'')
		{
			/* Move past the opening single quote. */
			l_i++;
			char l_character;

			/* Backslash detected! */
			if(input_source_buffer[l_i] == '\\')
			{
				/* Move past the backslash. */
				l_i++;
				
				/* Handle escape sequences. */
				switch (input_source_buffer[l_i])
				{
					case 'n': l_character = '\n'; break;
					case 't': l_character = '\t'; break;
					case 'r': l_character = '\r'; break;
					case '\\': l_character = '\\'; break;
					case '\'': l_character = '\''; break;
					
					/* Invalid escape sequence, terminate the scanning process. */
					default: return -1;
				}
			}
			else
			{
				l_character = input_source_buffer[l_i];
			}

			/* Move to the closing quote. */
			l_i++;

			if (input_source_buffer[l_i] != '\'')
			{
				/*
				*	Unterminated character literal, terminate the scanning
				*	process.
				*/
				return -1;
			}

			/* Resize the buffer of scanned tokens. */
			(*output_token_buffer_size)++;
			*output_token_buffer = realloc(*output_token_buffer, *output_token_buffer_size * sizeof(token_t));

			/* Set the token type. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_CHARACTER_LITERAL;

			/* Add the plaintext to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer = malloc(sizeof(char));
			*(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer = l_character;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer_size = sizeof(char);

			/* Add the token to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].value.character_literal = l_character;

			/* Move past the closing quote. */
			l_i++;
		}

		/* Handle string literals. */
		if(input_source_buffer[l_i] == '"')
		{
			/* Move past the opening quote. */
			l_i++;

			/* Initialize a dynamic buffer for the string literal. */
			char *l_string_buffer = NULL;
			uintmax_t l_string_length = 0;

			while (input_source_buffer[l_i] != '"' && input_source_buffer[l_i] != '\0')
			{
				char l_character;
				if (input_source_buffer[l_i] == '\\')
				{
					/* Handle escape sequences. */
					l_i++;
					switch (input_source_buffer[l_i])
					{
						case 'n': l_character = '\n'; break;
						case 't': l_character = '\t'; break;
						case 'r': l_character = '\r'; break;
						case '\\': l_character = '\\'; break;
						case '"': l_character = '"'; break;
						default: 
							/* Invalid escape sequence, terminate the scanning process. */
							free(l_string_buffer);
							return -1;
					}
				}
				else
				{
					l_character = input_source_buffer[l_i];
				}

				/* Append the character to the string buffer. */
				l_string_buffer = realloc(l_string_buffer, l_string_length + 1);
				l_string_buffer[l_string_length++] = l_character;

				l_i++;
			}

			if (input_source_buffer[l_i] != '"')
			{
				/* Unterminated string literal, terminate the scanning process. */
				free(l_string_buffer);
				return -1;
			}

			/* Resize the buffer of scanned tokens. */
			(*output_token_buffer_size)++;
			*output_token_buffer = realloc(*output_token_buffer, *output_token_buffer_size * sizeof(token_t));

			/* Set the token type. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_STRING_LITERAL;

			/* Add the plaintext to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer = l_string_buffer;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer_size = l_string_length;

			/* Add the token to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].value.string_literal = l_string_buffer;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].value.buffer_size = l_string_length;

			/* Move past the closing quote. */
			l_i++;
		}

		/* Handle identifiers. */
		if(is_alphabet(input_source_buffer[l_i]) || input_source_buffer[l_i] == '_')
		{
			/* Store the start of the identifier's name in memory. */
			uintmax_t l_start = l_i;

			/*
			 *	Keep adding characters to the identifier's name until a
			 *	non-identifier character is encountered.
			 */
			while (l_i < *input_source_buffer_size && is_valid_identifier_character(input_source_buffer[l_i]))
			{
				l_i++;
			}

			/* Calculate the length of the identifier. */
			uintmax_t l_length = l_i - l_start;

			/* Resize the buffer of scanned tokens. */
			(*output_token_buffer_size)++;
			*output_token_buffer = realloc(*output_token_buffer, *output_token_buffer_size * sizeof(token_t));

			/* Set the token type. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_IDENTIFIER;

			/* Add the plaintext to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer = input_source_buffer + l_start;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer_size = l_length;

			/* Add the token to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].value.identifier = input_source_buffer + l_start;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].value.buffer_size = l_length;
		}

		/*
		 *	Handle numbers.
		 *	At first, we are not certain whether the number is a floating
		 *	point number, an integer, or whether it's signed or unsigned.
		 *	We will determine this later inside this logic.
		 */
		if(is_digit(input_source_buffer[l_i]) || (input_source_buffer[l_i] == '.' && is_digit(input_source_buffer[l_i + 1])))
		{
			uintmax_t l_start = l_i;
			bool l_is_float = false;
			bool l_is_unsigned = false;

			while(l_i < *input_source_buffer_size && (is_digit(input_source_buffer[l_i]) || input_source_buffer[l_i] == '.' || input_source_buffer[l_i] == 'e' || input_source_buffer[l_i] == 'E' || input_source_buffer[l_i] == '+' || input_source_buffer[l_i] == '-'))
			{
				if(input_source_buffer[l_i] == '.')
					l_is_float = true;
				l_i++;
			}

			if(input_source_buffer[l_i] == 'f' || input_source_buffer[l_i] == 'F')
			{
				l_is_float = true;
				l_i++;
			}
			else if(input_source_buffer[l_i] == 'u' || input_source_buffer[l_i] == 'U')
			{
				l_is_unsigned = true;
				l_i++;
			}

			uintmax_t l_length = l_i - l_start;

			/* Resize the buffer of scanned tokens. */
			(*output_token_buffer_size)++;
			*output_token_buffer = realloc(*output_token_buffer, *output_token_buffer_size * sizeof(token_t));

			/* Set the token type. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = l_is_float ? TOKEN_TYPE_FLOAT_LITERAL : (l_is_unsigned ? TOKEN_TYPE_UNSIGNED_INTEGER_LITERAL : TOKEN_TYPE_INTEGER_LITERAL);

			/* Add the plaintext to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer = input_source_buffer + l_start;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer_size = l_length;

			/*
			 *	Add the token to the buffer.
			 *	Yes, I know `sscanf` is a bit of a hack, but it's the method
			 *	we're using now.
			 *	We've got bigger things to worry about.
			 */
			if(l_is_float)
			{
				sscanf((*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer, "%lf", &((*output_token_buffer)[(*output_token_buffer_size) - 1].value.float_literal));
			}
			else if(l_is_unsigned)
			{
				sscanf((*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer, "%ju", &((*output_token_buffer)[(*output_token_buffer_size) - 1].value.unsigned_integer_literal));
			}
			else
			{
				sscanf((*output_token_buffer)[(*output_token_buffer_size) - 1].plaintext_buffer, "%jd", &((*output_token_buffer)[(*output_token_buffer_size) - 1].value.signed_integer_literal));
			}
		}
	}

	return 0;
}