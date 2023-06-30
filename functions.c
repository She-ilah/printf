#include "main.h"
/**
 * print_char - a function that print character
 * @types: the arguments
 * @buffer: the temporary storage area
 * @flags: the flags
 * @width: the width
 * @precision: the presicion specifier
 * @size: the size
 * Return: the character
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c;

	c = va_arg(types, int);
	return (write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_str - a function that print string
 * @types: the argument
 * @buffer: the temporary storage area
 * @flags: the flags
 * @width: the width
 * @precision: the precision specifier
 * @size: the size
 * Return: the string
 */
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_percentage - a function that print percentage
 * @types: the arguments types
 * @buffer: the temporary storage size
 * @flags: the flags
 * @width: the width
 * @precision: the precision specifier
 * @size: the size
 * Return: the percent sign
 */
int print_percentage(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
/**
 * print_int - a functions that handle conversion specifier
 * @types: the arguments types
 * @buffer: the temporary storage size
 * @flags: the flags
 * @width: the width
 * @precision: the precision specifier
 * @size: the size
 * Return: succees
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int end;

	 /* calculate the lenght and convert it to string */
	n = size_to_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	end = (unsigned long int)n;

	if (n < 0)
	{
		end = (unsigned long int)((-1) * n);
		/* convert negative to positive*/
		neg = 1;
	}
	while (end > 0)
	{
		buffer[i--] = (end % 10) + '0';
		end /= 10;
	}
	i++;

	return (write_numone(neg, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - a function that print binary
 * @types:the arguements types
 * @buffer: the temporary storage
 * @flags: the flags
 * @width: the width
 * @precision: the precision specifier
 * @size: the size
 * Return: the conversion
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, end;
	unsigned int a[32];
	int check;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	 /* convert the number to binary */
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, end = 0, check = 0; i < 32; i++)
	{
		end += a[i];
		 /* extract the least significant bit and convert it to char */
		if (end || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			check++;
		}
	}
	return (check);
}
