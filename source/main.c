#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <malloc.h>

#include <csquared/scanner.h>
#include <csquared/parser.h>

char *g_input_file_name = NULL;
FILE *g_input_file_handle = NULL;
intmax_t g_input_file_size = -1;
char *g_input_file_buffer = NULL;

char *g_output_file_name = NULL;
FILE *g_output_file_handle = NULL;
intmax_t g_output_file_size = -1;
char *g_output_file_buffer = NULL;

int main(int argc, const char *argv[])
{
	for(int i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "-c") == 0 && i + 1 < argc)
		{
			g_input_file_name = (char *)argv[i + 1];
			i++;
		}
		else if(strcmp(argv[i], "-S") == 0 && i + 1 < argc)
		{
			g_output_file_name = (char *)argv[i + 1];
			i++;
		}
		else
		{
			fprintf(stderr, "error: Unknown or wrongly-formatted argument!\n");
			return -1;
		}
	}

	if(g_input_file_name == NULL)
	{
		fprintf(stderr, "error: No input file specified!\n");
		return -1;
	}

	g_input_file_handle = fopen(g_input_file_name, "rb");
	if(g_input_file_handle == NULL)
	{
		fprintf(stderr, "error: Could not open file for reading (file: `%s`)!\n", g_input_file_name);
		return -1;
	}

	fseek(g_input_file_handle, 0, SEEK_END);
	g_input_file_size = ftell(g_input_file_handle);
	fseek(g_input_file_handle, 0, SEEK_SET);

	g_input_file_buffer = malloc(g_input_file_size);
	fread(g_input_file_buffer, 1, g_input_file_size, g_input_file_handle);
	fclose(g_input_file_handle);

	token_t *l_token_buffer = NULL;
	uintmax_t l_token_buffer_size = 0;

	int l_scan_status = scanner(g_input_file_buffer, &g_input_file_size, &l_token_buffer, &l_token_buffer_size);
	if(l_scan_status != 0)
	{
		fprintf(stderr, "error: Failed to successfully scan the file completely (%d)!\n", l_scan_status);
		return -1;
	}

	for(uintmax_t l_i = 0; l_i < l_token_buffer_size; l_i++)
	{
		switch(l_token_buffer[l_i].token_type)
		{
		case TOKEN_TYPE_UNSIGNED_INTEGER_LITERAL:
			printf("debug: Detected an unsigned integer literal (literal: `%ju`)!\n", l_token_buffer[l_i].value.unsigned_integer_literal);
			break;
		case TOKEN_TYPE_CHARACTER_LITERAL:
			printf("debug: Detected a character literal (literal: `%c`)!\n", l_token_buffer[l_i].value.character_literal);
			break;
		case TOKEN_TYPE_INTEGER_LITERAL:
			printf("debug: Detected an integer literal (literal: `%jd`)!\n", l_token_buffer[l_i].value.signed_integer_literal);
			break;
		case TOKEN_TYPE_FLOAT_LITERAL:
			printf("debug: Detected a floating point literal (literal: `%e` or `%g`)!\n", l_token_buffer[l_i].value.float_literal, l_token_buffer[l_i].value.float_literal);
			break;
		case TOKEN_TYPE_STRING_LITERAL:
			printf("debug: Detected a string literal (literal: `%.*s`)!\n", (int)l_token_buffer[l_i].value.buffer_size, l_token_buffer[l_i].value.string_literal);
			break;
		case TOKEN_TYPE_IDENTIFIER:
			printf("debug: Detected an identifier (identifier: `%.*s`)!\n", (int)l_token_buffer[l_i].value.buffer_size, l_token_buffer[l_i].value.identifier);
			break;
		case TOKEN_TYPE_KEYWORD:
			printf("debug: Detected a keyword (keyword: `%s`)!\n", g_keywords[l_token_buffer[l_i].value.keyword]);
			break;
		case TOKEN_TYPE_SYMBOL:
			printf("debug: Detected a symbol (symbol: `%s`)!\n", g_symbols[l_token_buffer[l_i].value.symbol]);
			break;
		default:
			printf("debug: Detected an unknown token (type: `%d`)!\n", l_token_buffer[l_i].token_type);
			break;
		}
	}

	object_t *l_object_buffer = NULL;
	uintmax_t l_object_buffer_size = 0;

	int l_parse_status = parser(l_token_buffer, &l_token_buffer_size, &l_object_buffer, &l_object_buffer_size);
	if(l_parse_status != 0)
	{
		fprintf(stderr, "error: Failed to successfully parse the file completely (error: `%d`)!\n", l_parse_status);
		return -1;
	}

	for(uintmax_t l_i = 0; l_i < l_object_buffer_size; l_i++)
	{
		printf("debug: Detected an object (error: `%d`)!\n", l_object_buffer[l_i].object_type);
	}

	if(g_output_file_name != NULL)

	if(l_token_buffer != NULL)
		free(l_token_buffer);

	if(l_object_buffer != NULL)
		free(l_object_buffer);

	free(g_input_file_buffer);

	return 0;
}