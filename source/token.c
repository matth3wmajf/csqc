#include <string.h>
#include <stdint.h>
#include <malloc.h>

#include <csquared/token.h>

/*
 *	The keywords, the symbols, and their respective enumerations.
 *	This time, we re-ordered the symbol array and it's respective enumeraton
 *	so that the scanner considers double-equals to be a single symbol, before
 *	considering the double-equals to be two separate symbols.
 *	This same logic applies to most other symbols, such as `<` and `<<`.
 */
const char *g_keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
const char *g_symbols[] = {"==", "!=", "<=", ">=", "&&", "||", "<<", ">>", "+", "-", "*", "/", "=", "<", ">", "!", "&", "|", "^", "~", "(", ")", "{", "}", "[", "]", ";", ",", "."};
typedef enum {AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, REGISTER, RETURN, SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE} keyword_t;
typedef enum {EQUAL, NOT_EQUAL, LESS_EQUAL, GREATER_EQUAL, LOGICAL_AND, LOGICAL_OR, LEFT_SHIFT, RIGHT_SHIFT, ADD, SUB, MUL, DIV, ASSIGN, LESS_THAN, GREATER_THAN, LOGICAL_NOT, BITWISE_AND, BITWISE_OR, BITWISE_XOR, BITWISE_NOT, OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE, OPEN_BRACKET, CLOSE_BRACKET, SEMICOLON, COMMA, PERIOD} symbol_t;

/* Analyze the inputted source code, and output an array of tokens. */
int scan(char *input_source_buffer, uintmax_t *input_source_buffer_size, token_t **output_token_buffer, uintmax_t *output_token_buffer_size)
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

				/* Add the token to the buffer. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_KEYWORD;
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer = (char *)g_keywords[l_j];
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer_size = strlen(g_keywords[l_j]);

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

				/* Add the token to the buffer. */
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_SYMBOL;
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer = (char *)g_symbols[l_j];
				(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer_size = strlen(g_symbols[l_j]);

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

			/* Add the token to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_CHARACTER_LITERAL;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer = malloc(sizeof(char));
			*(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer = l_character;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer_size = sizeof(char);

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

			/* Add the token to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_STRING_LITERAL;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer = l_string_buffer;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer_size = l_string_length;

			/* Move past the closing quote. */
			l_i++;
		}

		/* Inside the main scanning loop */
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

			/* Add the token to the buffer. */
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_type = TOKEN_TYPE_IDENTIFIER;
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer = malloc(l_length + 1);
			strncpy((*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer, input_source_buffer + l_start, l_length);
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer[l_length] = '\0';
			(*output_token_buffer)[(*output_token_buffer_size) - 1].token_buffer_size = l_length;
		}
	}

	return 0;
}