#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <malloc.h>

#include <csquared/token.h>

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
		fprintf(stderr, "error: Could not open `%s` for reading!\n", g_input_file_name);
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

	int l_scan_status = scan(g_input_file_buffer, &g_input_file_size, &l_token_buffer, &l_token_buffer_size);
	if(l_scan_status != 0)
	{
		fprintf(stderr, "error: Failed to successfully scan the file completely!\n");
		return -1;
	}

	for(uintmax_t l_i = 0; l_i < l_token_buffer_size; l_i++)
	{
		printf("debug: Detected a token with value \"%.*s\"!\n", (int)l_token_buffer[l_i].token_buffer_size, l_token_buffer[l_i].token_buffer);
	}

	free(g_input_file_buffer);

	return 0;
}