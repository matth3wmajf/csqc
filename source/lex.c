#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <csquared/string.h>
#include <csquared/vector.h>
#include <csquared/lex.h>
#include <csquared/endl.h>

/*
 *	The keywords we're working with. For now, we only implement the ones used
 *	in C, however there'll likely be new keywords implemented.
 */
const char *g_keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

/*
 *	For this, we use string literals and not character literals, as there are
 *	certain symbols that consist of more than one character.
 */
const char *g_symbols[] = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "(", ")", "{", "}", "[", "]", ";", ",", "."};

/* The enum which represents the `keywords` array respectively, in order. */
typedef enum
{
	AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, REGISTER, RETURN, SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE
} keyword_t;

/* The enum that represents the `symbols` array respectively, in order. */
typedef enum
{
	ADD, SUB, MUL, DIV, ASSIGN, EQUAL, NOT_EQUAL, LESS_THAN, GREATER_THAN, LESS_EQUAL, GREATER_EQUAL, LOGICAL_AND, LOGICAL_OR, LOGICAL_NOT, BITWISE_AND, BITWISE_OR, BITWISE_XOR, BITWISE_NOT, LEFT_SHIFT, RIGHT_SHIFT, OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE, OPEN_BRACKET, CLOSE_BRACKET, SEMICOLON, COMMA, PERIOD
} symbol_t;

int lex(string_t *code, vector_t *tokens)
{
	int l_i = 0;

	while(l_i < code->size)
	{
		/* Skip whitespace. */
		if(is_whitespace(code->memory[l_i]))
		{
			l_i++;
			continue;
		}

		/* Handle keywords. */
		for(int l_j = 0; l_j < sizeof(g_keywords) / sizeof(g_keywords[0]); l_j++)
		{
			if(strncmp(g_keywords[l_j], code->memory + l_i, strlen(g_keywords[l_j])) == 0 && (is_whitespace(*(code->memory + l_i + strlen(g_keywords[l_j]))) || *(code->memory + l_i + strlen(g_keywords[l_j])) == '\0') && (l_i == 0 || is_whitespace(*(code->memory + l_i - 1))))
			{
				token_t *l_token = malloc(sizeof(token_t));
				l_token->type = TYPE_KEYWORD;
				string_create(&l_token->value.keyword);
				string_copy(&l_token->value.keyword, (char *)&g_keywords[l_j]);
				vector_pushback(tokens, l_token);

				printf("%s" ENDL, g_keywords[l_j]);
				l_i += strlen(g_keywords[l_j]);
				
				continue;
			}
		}

		/* Handle symbols. Unlike keywords, we do not check for whitespace padding. */
		for(int l_j = 0; l_j < sizeof(g_symbols) / sizeof(g_symbols[0]); l_j++)
		{
			if(strncmp(g_symbols[l_j], code->memory + l_i, strlen(g_symbols[l_j])) == 0)
			{
				token_t *l_token = malloc(sizeof(token_t));
				l_token->type = TYPE_SYMBOL;
				string_create(&l_token->value.symbol);
				string_copy(&l_token->value.symbol, (char *)&g_keywords[l_j]);
				vector_pushback(tokens, l_token);

				printf("%s" ENDL, g_symbols[l_j]);
				l_i += strlen(g_symbols[l_j]);
				
				continue;
			}
		}

		/* Handle character literals, not all escape sequences supported here. */
		if(code->memory[l_i] == '\'')
		{
			int l_j = l_i + 1;

			token_t *l_token = NULL;

			if(code->memory[l_j] == '\\')
			{
				l_j++;
				switch(code->memory[l_j])
				{
				case 'n':
					printf("'\\n'" ENDL);
					l_j++;
					break;
				case 't':
					printf("'\\t'" ENDL);
					l_j++;
					break;
				case 'r':
					printf("'\\r'" ENDL);
					l_j++;
					break;
				case '\'':
				case '\"':
				case '\\':
					l_token = malloc(sizeof(token_t));
					l_token->type = TYPE_CHAR;
					l_token->value.charlit = code->memory[l_j];
					vector_pushback(tokens, l_token);

					printf("'\\%c'\r\n", code->memory[l_j]);
					l_j++;
					break;
				default:
					/* Unknown escape sequence! */
					return -1;
				}
			}
			else if(code->memory[l_j] == '\'')
			{
				/* Empty character literal! */
				return -2;
			}
			else
			{
				l_token = malloc(sizeof(token_t));
				l_token->type = TYPE_CHAR;
				l_token->value.charlit = code->memory[l_j];
				vector_pushback(tokens, l_token);

				printf("'%c'" ENDL, code->memory[l_j]);
				l_j++;
			}

			if(l_j < code->size && code->memory[l_j] == '\'')
			{
				l_i = l_j + 1;
				continue;
			}
			else
			{
				/* Unterminated character literal! */
				return -3;
			}
		}

		/* Handle string literals. */
		if(code->memory[l_i] == '\"')
		{
			int l_j = l_i + 1;

			token_t *l_token = malloc(sizeof(token_t));
			l_token->type = TYPE_STRING;
			string_create(&l_token->value.stringlit);

			printf("\"");

			while(l_j < code->size && code->memory[l_j] != '\"')
			{
				/* Check for escape sequence(s). */
				if(code->memory[l_j] == '\\')
				{
					l_j++;
					switch(code->memory[l_j])
					{
					case 'n':
					case 't':
					case 'r':
					case '\"':
					case '\'':
					case '\\':
						printf("\\%c", code->memory[l_j]);
						string_concatenate_character(&l_token->value.stringlit, code->memory[l_j]);
						break;
					default:
						/* Invalid escape sequence! */
						return -1;
					}
				}
				else
				{
					/* Handle a regular character. */
					printf("%c", code->memory[l_j]);
					string_concatenate_character(&l_token->value.stringlit, code->memory[l_j]);
				}

				l_j++;
			}

			if(l_j < code->size && code->memory[l_j] == '\"')
			{
				printf("\"" ENDL);
				l_i = l_j + 1;
				continue;
			}
			else
			{
				/* Unterminated string literal! */
				return -2;
			}
		}

		/* Handle identifiers. */
		if(is_alphabet(code->memory[l_i]) || code->memory[l_i] == '_')
		{
			token_t *l_token = malloc(sizeof(token_t));
			l_token->type = TYPE_IDENTIFIER;
			string_create(&l_token->value.identifier);

			int l_j = l_i + 1;
			while(l_j < code->size && is_valid_identifier_char(code->memory[l_j]))
			{
				l_j++;
			}

			/* Might edit this later so that we don't need to use `sprintf`. */
			char l_buffer[128];
			sprintf(l_buffer, "%.*s", l_j - l_i, code->memory + l_i);

			string_copy(&l_token->value.identifier, l_buffer);

			printf("%s" ENDL, l_token->value.identifier.memory);

			l_i = l_j;
			continue;
		}

		/* We still haven't finished handling numbers! This will be implemented very soon. */
		if(is_digit(code->memory[l_i]) || (code->memory[l_i] == '.' && is_digit(code->memory[l_i + 1])))
		{
			int l_j = l_i;
			bool l_is_float = false;

			while (is_digit(code->memory[l_j]) || code->memory[l_j] == '.')
			{
				if(code->memory[l_j] == '.')
				{
					l_is_float = true;
				}

				l_j++;
			}

			if(l_is_float && code->memory[l_j] == 'f')
			{
				l_j++;
			}

			token_t *l_token = malloc(sizeof(token_t));
			l_token->type = l_is_float ? TYPE_FLOAT : (is_valid_identifier_char(code->memory[l_i]) ? TYPE_IDENTIFIER : TYPE_INTEGER);

			if(l_is_float == true)
				string_create(&l_token->value.floatlit);
			else if(l_is_float == false)
				string_create(&l_token->value.integerlit);

			char l_buffer[128];
			strncpy(l_buffer, code->memory + l_i, l_j - l_i);
			l_buffer[l_j - l_i] = '\0';

			if(l_is_float == true)
				string_copy(&l_token->value.floatlit, l_buffer);
			else if(l_is_float == false)
				string_copy(&l_token->value.integerlit, l_buffer);

			vector_pushback(tokens, l_token);

			if(l_is_float == true)
				printf("%s" ENDL, l_token->value.floatlit.memory);
			else if(l_is_float == false)
				printf("%s" ENDL, l_token->value.integerlit.memory);

			l_i = l_j;
			continue;
		}

		if(l_i < code->size)
		{
			l_i++;
		}
	}

	return 0;
}