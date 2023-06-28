#include "main.h"
/**
 * printf_type - Function prints arguments according to type.
 * @fmt: Formatted string that prints the arguments.
 * @argv: argument vectors to print.
 * @ind: ind
 * @buffer: Buffer main display
 * @flags: flag specifier
 * @width: width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: 1 or 2
 */
int printf_type(const char *fmt, int *ind, va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	int n, len = 0, printf_chars = -1;
	fmt_t printf_array[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percentage},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', printf_unsigned_num}, {'o', printf_oct_num}, {'x', printf_hex_num},
		{'X', printf_upper_hex}, {'p', printf_pointers}, {'S', printf_nprint},
		{'r', printf_strev}, {'R', printf_rot13}, {'\0', NULL}
	};
	/*Array contains printf functionality denoted by specified characters*/
	for (n = 0; printf_array[n].fmt != '\0'; n++)
		if (fmt[*ind] == printf_array[n].fmt)
			return (printf_array[n].fn(argv, buffer, flags, width, precision, size));

	if (printf_array[n].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (printf_chars);
	/* Returns printed characters according to their specified types*/
}

