#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <malloc.h>
#include <inttypes.h>

#include <csquared/scanner.h>
#include <csquared/logger.h>
#include <csquared/escape.h>
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
	/* Loop for every command-line argument. */
	for(uintmax_t l_i = 1; l_i < (uintmax_t)argc; l_i++)
	{
		if(strcmp(argv[l_i], "-c") == 0 && l_i + 1 < (uintmax_t)argc)
		{
			g_input_file_name = (char *)argv[l_i + 1];
			l_i++;
		}
		else if(strcmp(argv[l_i], "-S") == 0 && l_i + 1 < (uintmax_t)argc)
		{
			g_output_file_name = (char *)argv[l_i + 1];
			l_i++;
		}
		else
		{
			/* If the command-line argument flag is unknown, then log an error & quit. */
			loggerf(stderr, (log_entry_t[]){{ESC_BOLD "error" ESC_RESET, "Unknown or wrongly-typed argument!"}, {ESC_BOLD "subject" ESC_RESET, "Could not understand \"%s\"!"}}, 2, argv[l_i]);
			return -1;
		}
	}

	/*
	 *	Check if the source code's filename is set. If not, log an error, and
	 *	exit.
	 */
	if(g_input_file_name == NULL)
	{
		loggerf(stderr, (log_entry_t[]){{ESC_BOLD "error" ESC_RESET, "The source code's filename has not been inputted!"}, {ESC_BOLD "subject" ESC_RESET, "Could not open file \"%s\"!"}}, 2, g_input_file_name);
		return -1;
	}

	/*
	 *	Attempt to open the source code file with the intention of reading it,
	 *	and if it failed to do so, then log an error & quit.
	 */
	g_input_file_handle = fopen(g_input_file_name, "rb");
	if(g_input_file_handle == NULL)
	{
		loggerf(stderr, (log_entry_t[]){{ESC_BOLD "error" ESC_RESET, "Failed to open the source code's file!"}, {ESC_BOLD "subject" ESC_RESET, "Could not open \"%s\" for reading!"}}, 2, g_input_file_name);
		return -1;
	}

	/* Obtain the size of the source code's file. */
	fseek(g_input_file_handle, 0, SEEK_END);
	g_input_file_size = ftell(g_input_file_handle);
	fseek(g_input_file_handle, 0, SEEK_SET);

	/*
	 *	Allocate enough memory to store the source code file's contents into
	 *	memory.
	 */
	g_input_file_buffer = malloc(g_input_file_size);
	fread(g_input_file_buffer, 1, g_input_file_size, g_input_file_handle);
	fclose(g_input_file_handle);

	/*
	 *	Create a buffer which will contain our tokens.
	 *	One thing you'll commonly see in this project, is the fact that
	 *	buffers will consist of two things; the pointer to the first element
	 *	of the buffer, and the size of the buffer.
	 */
	token_t *l_token_buffer = NULL;
	uintmax_t l_token_buffer_size = 0;

	/*
	 *	Dispatch the scanner.
	 *	The scanner scans our newly-loaded raw source code while outputting
	 *	the tokens into the token buffer. We store the return code, as we want
	 *	to ensure that no error occured during the scanning process.
	 *	If the return code is zero, then everything went well, however if the
	 *	return code is a negative integer, it means we've encountered some
	 *	sort of error, and must therefore log an error & exit the program.
	 *	You'll commonly see this approach to error handling here.
	 */
	int l_scan_status = scanner_main(g_input_file_buffer, &g_input_file_size, &l_token_buffer, &l_token_buffer_size);
	if(l_scan_status != 0)
	{
		loggerf(stderr, (log_entry_t[]){{ESC_BOLD "error" ESC_RESET, "Scanning the source code's file failed!"}, {ESC_BOLD "subject" ESC_RESET, "The scanner returned an error code of `%d`."}}, 2, l_scan_status);
		return -1;
	}

	/* Create a buffer of log entries. */
	log_entry_t *l_log_entry_buffer = NULL;
	uintmax_t l_log_entry_buffer_size = 0;

	/* Re-size the buffer of log entries by one. */
	l_log_entry_buffer_size++;
	l_log_entry_buffer = realloc(l_log_entry_buffer, l_log_entry_buffer_size * sizeof(log_entry_t));

	/* Set the header of the log entry buffer. */
	l_log_entry_buffer[l_log_entry_buffer_size - 1].key = ESC_BOLD "debug" ESC_RESET;
	l_log_entry_buffer[l_log_entry_buffer_size - 1].value = "Successfully scanned all tokens!";

	/*
	 *	For each token in the token buffer, log it's type, and if it comes
	 *	with a value, log the value as well.
	 */
	for(uintmax_t i = 0; i < l_token_buffer_size; i++)
	{
		/* Increase the size of the buffer of log entries by one. */
		l_log_entry_buffer_size += 1;
		l_log_entry_buffer = realloc(l_log_entry_buffer, l_log_entry_buffer_size * sizeof(log_entry_t));

		/* The buffer to store the formatted string. */
		char *l_formatted_buffer = NULL;
		uintmax_t l_formatted_buffer_size = 0;

		switch((uint8_t)l_token_buffer[i].token_type)
		{
		case TOKEN_TYPE_INT8_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%d", l_token_buffer[i].value.int8_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%d", l_token_buffer[i].value.int8_literal);
			break;
		case TOKEN_TYPE_INT16_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%d", l_token_buffer[i].value.int16_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%d", l_token_buffer[i].value.int16_literal);
			break;
		case TOKEN_TYPE_INT32_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%d", l_token_buffer[i].value.int32_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%d", l_token_buffer[i].value.int32_literal);
			break;
		case TOKEN_TYPE_INT64_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%lld", l_token_buffer[i].value.int64_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%lld", l_token_buffer[i].value.int64_literal);
			break;
		case TOKEN_TYPE_UINT8_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%u", l_token_buffer[i].value.uint8_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%u", l_token_buffer[i].value.uint8_literal);
			break;
		case TOKEN_TYPE_UINT16_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%u", l_token_buffer[i].value.uint16_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%u", l_token_buffer[i].value.uint16_literal);
			break;
		case TOKEN_TYPE_UINT32_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%u", l_token_buffer[i].value.uint32_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%u", l_token_buffer[i].value.uint32_literal);
			break;
		case TOKEN_TYPE_UINT64_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%llu", l_token_buffer[i].value.uint64_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%llu", l_token_buffer[i].value.uint64_literal);
			break;
		case TOKEN_TYPE_FLOAT32_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%f", l_token_buffer[i].value.float32_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%f", l_token_buffer[i].value.float32_literal);
			break;
		case TOKEN_TYPE_FLOAT64_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%lf", l_token_buffer[i].value.float64_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%lf", l_token_buffer[i].value.float64_literal);
			break;
		case TOKEN_TYPE_CHARACTER8_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "'%c'", l_token_buffer[i].value.character8_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "'%c'", l_token_buffer[i].value.character8_literal);
			break;
		case TOKEN_TYPE_STRING8_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "\"%.*s\"", (int)l_token_buffer[i].value.buffer_size, l_token_buffer[i].value.string8_literal) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "\"%.*s\"", (int)l_token_buffer[i].value.buffer_size, l_token_buffer[i].value.string8_literal);
			break;
		case TOKEN_TYPE_IDENTIFIER_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%.*s", (int)l_token_buffer[i].value.buffer_size, l_token_buffer[i].value.identifier) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%.*s", (int)l_token_buffer[i].value.buffer_size, l_token_buffer[i].value.identifier);
			break;
		case TOKEN_TYPE_KEYWORD_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%s", g_keywords[l_token_buffer[i].value.keyword]) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%s", g_keywords[l_token_buffer[i].value.keyword]);
			break;
		case TOKEN_TYPE_SYMBOL_LITERAL:
			l_formatted_buffer_size = snprintf(NULL, 0, "%s", g_symbols[l_token_buffer[i].value.symbol]) + 1;
			l_formatted_buffer = malloc(l_formatted_buffer_size);
			sprintf(l_formatted_buffer, "%s", g_symbols[l_token_buffer[i].value.symbol]);
			break;
		}

		l_log_entry_buffer[l_log_entry_buffer_size - 1].key = ESC_BOLD "value" ESC_RESET;
		l_log_entry_buffer[l_log_entry_buffer_size - 1].value = l_formatted_buffer;
	}

	loggerf(stdout, l_log_entry_buffer, l_log_entry_buffer_size);

	/* Free the memory allocated for the formatted values. */
	for(size_t i = 0; i < l_log_entry_buffer_size; i++)
	{
		free(l_log_entry_buffer[i].value);
	}

	/* Free the memory allocated for the token buffer. */
	free(l_log_entry_buffer);

	/*
	 *	Create a buffer for storing the objects that make up the
	 *	abstract-syntax-tree.
	 *	This buffer is to be given to the parser, as the parser will output
	 *	data into this buffer.
	 */
	object_t *l_object_buffer = NULL;
	uintmax_t l_object_buffer_size = 0;

	/* Digest the array of tokens into an abstract-syntax-tree. */
	int l_parse_status = parser_main(l_token_buffer, &l_token_buffer_size, &l_object_buffer, &l_object_buffer_size);
	if(l_parse_status != 0)
	{
		loggerf(stderr, (log_entry_t[]){{ESC_BOLD "error" ESC_RESET, "Parsing the tokens failed!"}, {ESC_BOLD "subject" ESC_RESET, "The parser returned an error code of `%d`."}}, 2, l_parse_status);
		return -1;
	}

	print_objects(l_object_buffer, l_object_buffer_size);

	/* If the token buffer is still allocated, then de-allocate it. */
	if(l_token_buffer != NULL)
		free(l_token_buffer);

	/* If the object buffer is still allocated, then de-allocate it. */
	if(l_object_buffer != NULL)
		free(l_object_buffer);

	/* Free the source code's file's buffer, as we no longer need it. */
	free(g_input_file_buffer);

	return 0;
}