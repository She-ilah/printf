#include "main.h"

/**
 * write_char - Function prints a string to the buffer.
 * @c: character
 * @buffer: Buffer main display.
 * @flags: flag specifier
 * @width: width specifier
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Int, number of chars printed to the buffer.
 */
int write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = 0;
	char separator = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		separator = '0';

	buffer[index++] = c;
	buffer[index] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (index = 0; index < width - 1; index++)
			buffer[BUFF_SIZE - index - 2] = separator;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - index - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - index - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_numone - Function prints a string of numbers
 * @argv: argument vectors
 * @ind: Types of chars
 * @buffer: Buffer main display
 * @flags: flag specifier
 * @width: width specifier
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Int, number of chars printed on buffer.
 */
int write_numone(int argv, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char separator = ' ', count = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		separator = '0';
	if (argv)
		count = '-';
	else if (flags & F_PLUS)
		count = '+';
	else if (flags & F_SPACE)
		count = ' ';

	return (write_numtwo(ind, buffer, flags, width, precision,
		len, separator, count));
}

/**
 * write_numtwo - Function writes a string of numbers to the buffer
 * @ind: index
 * @buffer: Buffer main display
 * @flags: Flag specifier
 * @width: width specifier
 * @prec: Precision specifier
 * @len: length of the string of numbers
 * @separator: Spacing character
 * @addi: additional charater
 * Return: Int, number of printed chars on buffer.
 */
int write_numtwo(int ind, char buffer[],
	int flags, int width, int prec,
	int len, char separator, char addi)
{
	int i, start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = separator = ' ';
	if (prec > 0 && prec < len)
		separator = ' ';
	while (prec > len)
		buffer[--ind] = '0', len++;
	if (addi != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = separator;
		buffer[i] = '\0';
		if (flags & F_MINUS && separator == ' ')
		{
			if (addi)
				buffer[--ind] = addi;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && separator == ' ')
		{
			if (addi)
				buffer[--ind] = addi;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && separator == '0')
		{
			if (addi)
				buffer[--start] = addi;
			return (write(1, &buffer[start], i - start) +
				write(1, &buffer[ind], len - (1 - start)));
		}
	}
	if (addi)
		buffer[--ind] = addi;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsigned_num - Function writes an unsigned number to the buffer.
 * @negative: indicator, determines whether number is negative.
 * @ind: index
 * @buffer: buffer main display.
 * @flags: Flag specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, number of written chars on the buffer.
 */
int write_unsigned_num(int negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char separator = ' ';

	UNUSED(negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		separator = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		separator = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = separator;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}
	return (write(1, &buffer[ind], len));
}

/**
 * write_pointers - Function writes a memory address on the buffer
 * @buffer: Buffer main display.
 * @ind: index
 * @len: Length of the string of numbers.
 * @width: Width specifier
 * @flags: Flag specifier
 * @separator: Spacing char
 * @addi: additional character
 * @start: Index at which spacing should start.
 * Return: Int, number of written chars on the buffer
 */
int write_pointers(char buffer[], int ind, int len,
	int width, int flags, char separator, char addi, int start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = separator;
		buffer[i] = '\0';
		if (flags & F_MINUS && separator == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (addi)
				buffer[--ind] = addi;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && separator == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (addi)
				buffer[--ind] = addi;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && separator == '0')
		{
			if (addi)
				buffer[--start] = addi;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[start], i - start) +
				write(1, &buffer[ind], len - (1 - start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (addi)
		buffer[--ind] = addi;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

