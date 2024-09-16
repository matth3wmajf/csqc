#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <malloc.h>
#include <inttypes.h>

#include <csquared/scanner.h>
#include <csquared/parser.h>

/* The input file's data. */
char *g_input_file_name = NULL;
FILE *g_input_file_handle = NULL;
intmax_t g_input_file_size = -1;
char *g_input_file_buffer = NULL;

/* The output file's data. */
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

	for (uintmax_t l_i = 0; l_i < l_token_buffer_size; l_i++)
	{
		switch (l_token_buffer[l_i].token_type)
		{
		case TOKEN_TYPE_UINT8_LITERAL:
			printf("debug: Detected an unsigned 8-bit integer literal (literal: `%hhu`)!\n", l_token_buffer[l_i].value.uint8_literal);
			break;
		case TOKEN_TYPE_INT8_LITERAL:
			printf("debug: Detected a signed 8-bit integer literal (literal: `%hhd`)!\n", l_token_buffer[l_i].value.int8_literal);
			break;
		case TOKEN_TYPE_UINT16_LITERAL:
			printf("debug: Detected an unsigned 16-bit integer literal (literal: `%hu`)!\n", l_token_buffer[l_i].value.uint16_literal);
			break;
		case TOKEN_TYPE_INT16_LITERAL:
			printf("debug: Detected a signed 16-bit integer literal (literal: `%hd`)!\n", l_token_buffer[l_i].value.int16_literal);
			break;
		case TOKEN_TYPE_UINT32_LITERAL:
			printf("debug: Detected an unsigned 32-bit integer literal (literal: `%u`)!\n", l_token_buffer[l_i].value.uint32_literal);
			break;
		case TOKEN_TYPE_INT32_LITERAL:
			printf("debug: Detected a signed 32-bit integer literal (literal: `%d`)!\n", l_token_buffer[l_i].value.int32_literal);
			break;
		case TOKEN_TYPE_UINT64_LITERAL:
			printf("debug: Detected an unsigned 64-bit integer literal (literal: `%" PRIu64 "`)!\n", l_token_buffer[l_i].value.uint64_literal);
			break;
		case TOKEN_TYPE_INT64_LITERAL:
			printf("debug: Detected a signed 64-bit integer literal (literal: `%" PRId64 "`)!\n", l_token_buffer[l_i].value.int64_literal);
			break;
		case TOKEN_TYPE_FLOAT32_LITERAL:
			printf("debug: Detected a 32-bit float literal (literal: `%f`)!\n", l_token_buffer[l_i].value.float_literal_32);
			break;
		case TOKEN_TYPE_FLOAT64_LITERAL:
			printf("debug: Detected a 64-bit double literal (literal: `%f`)!\n", l_token_buffer[l_i].value.float_literal_64);
			break;
		case TOKEN_TYPE_CHARACTER8_LITERAL:
			printf("debug: Detected a character literal (literal: `%c`)!\n", l_token_buffer[l_i].value.character_literal);
			break;
		case TOKEN_TYPE_STRING8_LITERAL:
			printf("debug: Detected a string literal (literal: `%.*s`)!\n", (int)l_token_buffer[l_i].value.buffer_size, l_token_buffer[l_i].value.string_literal);
			break;
		case TOKEN_TYPE_IDENTIFIER_LITERAL:
			printf("debug: Detected an identifier (identifier: `%.*s`)!\n", (int)l_token_buffer[l_i].value.buffer_size, l_token_buffer[l_i].value.identifier);
			break;
		case TOKEN_TYPE_KEYWORD_LITERAL:
			printf("debug: Detected a keyword (keyword: `%s`)!\n", g_keywords[l_token_buffer[l_i].value.keyword]);
			break;
		case TOKEN_TYPE_SYMBOL_LITERAL:
			printf("debug: Detected a symbol (symbol: `%s`)!\n", g_symbols[l_token_buffer[l_i].value.symbol]);
			break;
		default:
			printf("debug: Detected an unknown token (type: `%d`)!\n", l_token_buffer[l_i].token_type);
			break;
		}
	}


	object_t *l_object_buffer = NULL;
	uintmax_t l_object_buffer_size = 0;

//	int l_parse_status = parser(l_token_buffer, &l_token_buffer_size, &l_object_buffer, &l_object_buffer_size);
//	if(l_parse_status != 0)
//	{
//		fprintf(stderr, "error: Failed to successfully parse the file completely (error: `%d`)!\n", l_parse_status);
//		return -1;
//	}
//
//	for(uintmax_t l_i = 0; l_i < l_object_buffer_size; l_i++)
//	{
//		printf("debug: Detected an object (error: `%d`)!\n", l_object_buffer[l_i].object_type);
//	}

	if(g_output_file_name != NULL)

	if(l_token_buffer != NULL)
		free(l_token_buffer);

	if(l_object_buffer != NULL)
		free(l_object_buffer);

	free(g_input_file_buffer);

	return 0;
}