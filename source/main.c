#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include <csquared/file.h>
#include <csquared/endl.h>

int main(int argc, const char *argv[])
{
	/* Parse command-line argument(s). */
	for(unsigned int i = 0; i < (unsigned int)argc; i++)
	{
		if(strcmp(argv[i], "-c") == 0 && i + 1 < (unsigned int)argc)
		{
			g_file_name = (char *)argv[i + 1];
		}
		else
		{
			fprintf(stderr, "error: Unknown argument!" ENDL);
			return -1;
		}
	}

	/* Verify that the inputted file name is genuine. */
	if(g_file_name == NULL)
	{
		fprintf(stderr, "error: No input file specified!" ENDL);
		return -1;
	}

	/* Open the file. */
	g_file_handle = fopen(g_file_name, "r");
	if(g_file_handle == NULL)
	{
		fprintf(stderr, "error: Failed to open the input file!" ENDL);
		return -1;
	}

	/* Close the file.*/
	fclose(g_file_handle);

	return 0;
}