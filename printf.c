#include "main.h"

void buffer_prints(char buffer[], int *buff_ind);

/**
 * _printf - This is the main printf function.
 * @format: format parameter in the variadic function.
 * Return: Returns the printed chars in the printf
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, p_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				buffer_prints(buffer, &buff_ind);
			p_chars++;
		}
		else
		{
			buffer_prints(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = printf_type(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			p_chars += printed;
		}
	}

	buffer_prints(buffer, &buff_ind);
	va_end(list);
	return (p_chars);
}

/**
 * buffer_prints - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void buffer_prints(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

