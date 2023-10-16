#include "main.h"

void print_buffer(char buffer[], int *baf_ed);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	iint flags, width, precision, size, baf_ed = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[baf_ed++] = format[i];
			if (baf_ed == BUFF_SIZE)
				print_buffer(buffer, &baf_ed);

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &baf_ed);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &baf_ed);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @baf_ed: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *baf_ed)
{
	if (*baf_ed > 0)
		write(1, &buffer[0], *baf_ed);

	*baf_ed = 0;
}
