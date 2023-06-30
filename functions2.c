#include "main.h"

/**
 * printf_pointers - Function prints a dereferenced value of pointer.
 * @argv: argument vector
 * @buffer: Buffer main display.
 * @flags: flag specifier.
 * @width: width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, chars printed on the buffer.
 */
int printf_pointers(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	char modu = 0, separator = ' ';
	int ind = BUFF_SIZE - 2, len = 2, b_separator = 1;
	unsigned long num_value;
	char direct[] = "0123456789abcdef";
	void *p_value = va_arg(argv, void *);

	UNUSED(width);
	UNUSED(size);

	if (p_value == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_value = (unsigned long)p_value;

	while (num_value > 0)
	{
		buffer[ind--] = direct[num_value % 16];
		num_value /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		separator = '0';
	if (flags & F_PLUS)
		modu = '+', len++;
	else if (flags & F_SPACE)
		modu = ' ', len++;

	ind++;

	return (write_pointers(buffer, ind, len,
		width, flags, separator, modu, b_separator));
}

/**
 * printf_nprint - Function writes ascii codes in hexa of non printables.
 * @argv: argument vector
 * @buffer: Buffer main display
 * @flags: flag specifier
 * @width: width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, amount of chars printed on buffer
 */
int printf_nprint(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = 0, start = 0;
	char *str = va_arg(argv, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[n] != '\0')
	{
		if (print_chars(str[n]))
			buffer[n + start] = str[n];
		else
			start += hex_cat(str[n], buffer, n + start);

		n++;
	}
	buffer[n + start] = '\0';
	return (write(1, buffer, n + start));
}

/**
 * printf_strev - Function reverses the string and prints it.
 * @argv: argument vectors
 * @buffer: Buffer main display
 * @flags: flag specifier
 * @width: width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, amount of chars printed to buffer.
 */
int printf_strev(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int n, check = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(argv, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (n = 0; str[n]; n++)
		;

	for (n = n - 1; n >= 0; n--)
	{
		char z = str[n];

		write(1, &z, 1);
		check++;
	}
	return (check);
}
/**
 * printf_rot13 - Function prints a string in rot13.
 * @argv: argument vector
 * @buffer: Buffer main display
 * @flags: flag specifier
 * @width: width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, amount of chars printed to buffer.
 */
int printf_rot13(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, n;
	int check = 0;
	char norm[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(argv, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (n = 0; norm[n]; n++)
		{
			if (norm[n] == str[i])
			{
				x = rot[n];
				write(1, &x, 1);
				check++;
				break;
			}
		}
		if (!norm[n])
		{
			x = str[i];
			write(1, &x, 1);
			check++;
		}
	}
	return (check);
}

