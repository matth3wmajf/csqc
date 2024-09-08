#include <string.h>
#include <stdint.h>
#include <malloc.h>

#include <csquared/token.h>

/* The keywords, the symbols, and their respective enumerations. */
const char *g_keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
const char *g_symbols[] = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "(", ")", "{", "}", "[", "]", ";", ",", "."};
typedef enum {AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, REGISTER, RETURN, SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE} keyword_t;
typedef enum {ADD, SUB, MUL, DIV, ASSIGN, EQUAL, NOT_EQUAL, LESS_THAN, GREATER_THAN, LESS_EQUAL, GREATER_EQUAL, LOGICAL_AND, LOGICAL_OR, LOGICAL_NOT, BITWISE_AND, BITWISE_OR, BITWISE_XOR, BITWISE_NOT, LEFT_SHIFT, RIGHT_SHIFT, OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE, OPEN_BRACKET, CLOSE_BRACKET, SEMICOLON, COMMA, PERIOD} symbol_t;

/* Analyze the inputted source code, and output an array of tokens. */
int scan(char *input_source_buffer, uintmax_t *input_source_buffer_size, token_t **output_token_buffer, uintmax_t *output_token_buffer_size)
{
	for(uintmax_t l_i = 0; l_i < *input_source_buffer_size;)
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
	}

	return 0;
}