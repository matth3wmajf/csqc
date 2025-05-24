/*
 *	                         .d8888b.    o    .d8888b.                         
 *	                        d88P  Y88b  d8b  d88P  Y88b                        
 *	                        888    888 d888b        888                        
 *	                        888       d8P"Y8b     .d88P                        
 *	                        888               .od888P"                         
 *	                        888    888       d88P"                             
 *	                        Y88b  d88P       888"                              
 *	                         "Y8888P"        888888888                         
 *	 Copyright (C) 2024-2025, Matthew E. Majfud-Wilinski. All Rights Reserved. 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <malloc.h>
#include <inttypes.h>

#include <csqc/scanner.h>
#include <csqc/parser.h>

int main(int t_argc, const char *pt_argv[])
{
/*
 *	The input file's data.
 *	These variables include the file's name, the file's handle, the file's size
 *	and the file's contents.
 */
	char *pl_input_file_name = NULL;
	FILE *pl_input_file_handle = NULL;
	intmax_t l_input_file_size = -1;
	char *pl_input_file_buffer = NULL;

/*
 *	The output file's data.
 *	Same thing from the input file applies here for the output file.
 */
	char *pl_output_file_name = NULL;
	FILE *pl_output_file_handle = NULL;
	intmax_t l_output_file_size = -1;
	char *pl_output_file_buffer = NULL;

/* Loop for every command-line argument. */
	for(uintmax_t l_i = 1; l_i < (uintmax_t)t_argc; l_i++)
	{
/* Compare the command-line argument flag(s). */
		if(strcmp(pt_argv[l_i], "-c") == 0 && l_i + 1 < (uintmax_t)t_argc)
		{
			pl_input_file_name = (char *)pt_argv[l_i + 1];
			l_i++;
		}
		else if(strcmp(pt_argv[l_i], "-S") == 0 && l_i + 1 < (uintmax_t)t_argc)
		{
			pl_output_file_name = (char *)pt_argv[l_i + 1];
			l_i++;
		}
		else
		{
/* If the command-line argument flag is unknown, then log an error & quit. */
			fprintf(stderr, "error: Unknown command-line argument flag!\n");
			return -1;
		}
	}

/*
 *	Check if the source code's filename is set. If not, log an error, and
 *	exit.
 */
	if(pl_input_file_name == NULL)
	{
		fprintf(stderr, "error: Source code filename not provided!\n");
		return -1;
	}

/*
 *	Attempt to open the source code file with the intention of reading it, and
 *	if it failed to do so, then log an error & quit.
 */
	pl_input_file_handle = fopen(pl_input_file_name, "rb");
	if(pl_input_file_handle == NULL)
	{
		fprintf(stderr, "error: Failed to open the source code file for reading!\n");
		return -1;
	}

/* Obtain the size of the source code's file. */
	fseek(pl_input_file_handle, 0, SEEK_END);
	l_input_file_size = ftell(pl_input_file_handle);
	fseek(pl_input_file_handle, 0, SEEK_SET);

/*
 *	Allocate enough memory to store the source code file's contents into
 *	memory.
 */
	pl_input_file_buffer = malloc(l_input_file_size);
	fread(pl_input_file_buffer, 1, l_input_file_size, pl_input_file_handle);

/*
 *	Create a buffer which will contain our tokens.
 *	One thing you'll commonly see in this project, is the fact that buffers
 *	will consist of two things; the pointer to the first element of the
 *	buffer, and the size of the buffer.
 */
	token_t *pl_token_buffer = NULL;
	uintmax_t l_token_buffer_size = 0;

/*
 *	Dispatch the scanner.
 *	The scanner scans our newly-loaded raw source code while outputting the
 *	tokens into the token buffer. We store the return code, as we want to
 *	ensure that no error occured during the scanning process. If the return
 *	code is zero, then everything went well, however if the return code is a
 *	negative integer, it means we've encountered some sort of error, and must
 *	therefore log an error & exit the program. You'll commonly see this
 *	approach to error handling here.
 */
	uintmax_t l_input_file_buffer_size = (uintmax_t)l_input_file_size;

	int l_result = scanner_main(pl_input_file_buffer, &l_input_file_buffer_size, &pl_token_buffer, &l_token_buffer_size);
	if(l_result < 0)
	{
		fprintf(stderr, "error: Failed to scan the source code file's contents!\n");
		return -1;
	}

/*
 *	Create a buffer for storing the objects that make up the
 *	abstract-syntax-tree.
 *	This buffer is to be given to the parser, as the parser will output data
 *	into this buffer.
 */
	object_t *pl_object_buffer = NULL;
	uintmax_t l_object_buffer_size = 0;

/* Create a buffer of name(s), also known as a symbol table. */
	name_t *pl_name_buffer = NULL;
	uintmax_t l_name_buffer_size = 0;

/* Digest the array of tokens into an abstract-syntax-tree. */
	l_result = parser_main(pl_token_buffer, &l_token_buffer_size, &pl_object_buffer, &l_object_buffer_size, &pl_name_buffer, &l_name_buffer_size);
	if(l_result < 0)
	{
		fprintf(stderr, "error: Failed to parse the tokens!\n");
		return -1;
	}

/* Free the symbol table if it's allocated, we no longer need it. */
	if(pl_name_buffer != NULL)
	{
		free(pl_name_buffer);
		pl_name_buffer = NULL;
	}

/* Free the token buffer, as we no longer need it. */
	if(l_token_buffer_size > 0)
	{
		free(pl_token_buffer);
		pl_token_buffer = NULL;
	}

/* Free the object buffer, as we no longer need it. */
	if(l_object_buffer_size > 0)
	{
		free(pl_object_buffer);
		pl_object_buffer = NULL;
	}

/* Free the source code's file's buffer, as we no longer need it. */
	free(pl_input_file_buffer);
	pl_input_file_buffer = NULL;

/* Close the source code's input file. */
	fclose(pl_input_file_handle);
	pl_input_file_handle = NULL;

/* Return with success. */
	return 0;
}