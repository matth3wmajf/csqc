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
	int l_scan_status = scanner(g_input_file_buffer, &g_input_file_size, &l_token_buffer, &l_token_buffer_size);
	if(l_scan_status != 0)
	{
		loggerf(stderr, (log_entry_t[]){{ESC_BOLD "error" ESC_RESET, "Scanning the source code's file failed!"}, {ESC_BOLD "subject" ESC_RESET, "The scanner returned an error code of `%d`."}}, 2, l_scan_status);
		return -1;
	}

	/*
	 *	Create a buffer for storing the objects that make up the
	 *	abstract-syntax-tree.
	 *	This buffer is to be given to the parser, as the parser will output
	 *	data into this buffer.
	 */
	object_t *l_object_buffer = NULL;
	uintmax_t l_object_buffer_size = 0;

	/* Digest the array of tokens into an abstract-syntax-tree. */
	int l_parse_status = parser(l_token_buffer, &l_token_buffer_size, &l_object_buffer, &l_object_buffer_size);
	if(l_parse_status != 0)
	{
		loggerf(stderr, (log_entry_t[]){{ESC_BOLD "error" ESC_RESET, "Parsing the tokens failed!"}, {ESC_BOLD "subject" ESC_RESET, "The parser returned an error code of `%d`."}}, 2, l_parse_status);
		return -1;
	}

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