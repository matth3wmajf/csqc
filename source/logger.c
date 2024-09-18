#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include <csquared/logger.h>

void loggerf(FILE *stream, const log_entry_t entry_buffer[], int entry_buffer_size, ...)
{
	va_list l_args;
	va_start(l_args, entry_buffer_size);

	uintmax_t l_max_key_length = 0;
	for (uintmax_t l_i = 0; l_i < entry_buffer_size; l_i++)
	{
		uintmax_t l_key_length = strlen(entry_buffer[l_i].key);
		if(l_key_length > l_max_key_length)
		{
			l_max_key_length = l_key_length;
		}
	}

	for(int i = 0; i < entry_buffer_size; i++)
	{
		const char *l_key = entry_buffer[i].key;
		const char *l_value_format = entry_buffer[i].value;

		char l_buffer[1024];
		va_list l_args_copy;
		va_copy(l_args_copy, l_args);
		vsnprintf(l_buffer, sizeof(l_buffer), l_value_format, l_args_copy);
		va_end(l_args_copy);

		fprintf(stream, "%s:", l_key);

		uintmax_t l_space_padding = (uintmax_t)(l_max_key_length - strlen(l_key) + 1);

		for (int j = 0; j < l_space_padding; j++)
		{
			fputc(' ', stream);
		}

		uintmax_t l_wrap_width = 80 - (uintmax_t)l_max_key_length - 2;

		uintmax_t l_first_line_end = strlen(l_buffer) > l_wrap_width ? l_wrap_width : strlen(l_buffer);
		for(uintmax_t l_j = 0; l_j < l_first_line_end; l_j++)
		{
			fputc(l_buffer[l_j], stream);
		}

		fputc('\n', stream);

		uintmax_t l_start = l_first_line_end;
		while(l_start < strlen(l_buffer))
		{
			uintmax_t l_end = l_start + l_wrap_width;

			if(l_end >= strlen(l_buffer))
			{
				l_end = strlen(l_buffer);
			}
			else
			{
				while(l_end > l_start && l_buffer[l_end] != ' ')
				{
					l_end--;
				}

				if(l_end == l_start)
				{
					l_end = l_start + l_wrap_width;
				}
			}

			for(uintmax_t l_j = 0; l_j < l_max_key_length + 2; l_j++)
			{
				fputc(' ', stream);
			}

			for(uintmax_t l_j = l_start; l_j < l_end; l_j++)
			{
				fputc(l_buffer[l_j], stream);
			}

			fputc('\n', stream);

			l_start = l_end + 1;
		}
	}

	va_end(l_args);
}