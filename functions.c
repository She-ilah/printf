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
int print_c(__attribute__((unused))va_list types,
__attribute__((unused))char buffer[],
__attribute__((unused))int flags, __attribute__((unused))int width,
__attribute__((unused))int precision, __attribute__((unused))int size)
{
	char c;

	c = va_arg(types, int);
	return (write(1, &c, 1));
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
int print_str(__attribute__((unused))va_list types,
__attribute__((unused))char buffer[],
__attribute((unused))int flags, __attribute((unused))int width,
__attribute((unused))int precision, __attribute((unused))int size)
{
	const char *p;
	int len;
	const char *str;

	len = 0;
	str = (" ");
	p = str;

	while (*p != '\0')
	{
		len++;
		p++;
	}
	write(STDOUT_FILENO, str, len);
	return (len);
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
int print_percentage(__attribute__((unused))va_list types,
__attribute__((unused))char buffer[], __attribute__((unused))int flags,
__attribute__((unused))int width, __attribute__((unused))int precision,
__attribute((unused))int size)
{
	char sign;

	sign = '%';

	return (write(1, &sign, 1));
	return (0);
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
int print_int(__attribute__((unused))va_list types,
char buffer[], __attribute__((unused))int flags,
__attribute__((unused))int width,
__attribute__((unused))int precision, __attribute__((unused))int size)
{
	int value;
	int len;
	int i;
	int start;
	int end;
	char temp;

	len = 0;
	value = 0;
	start = 0;
	i = 0;

	if (value < 0)
	{
		buffer[i++] = ('-');
		value = (-value);/* convert negative to positive*/
		len++;
	}
	/* calculate the lenght and convert it to string */
	do {
		buffer[i++] = '0' + (value % 10);
		value /= 10;
		len++;
	} while (value != 0);
	end = i - 1;

	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
	buffer[i] = '\0';/* null terminate the string */
	return (len);
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
int print_binary(__attribute__((unused))va_list types, char buffer[],
__attribute__((unused))int flags, __attribute__((unused))int width,
__attribute__((unused))int precision, __attribute__((unused))int size)
{
	int i = 0;
	int temp = 0;
	int isneg = 0;
	int start;
	int end;
	char tchar;
	int num = 0;

	/* check if the number is negative */
	if (num < 0)
	{
		isneg = 1;
		temp = (-temp);
	}
	/* convert the number to binary */
	do {
		buffer[i++] = (temp & 1) + '0';
		/*^ extract the least significant bit and convert it to char */
		temp >>= 1;
		/*^ right the number by 1 */
	} while (temp != 0);
	/* add a null terminator at the end of the buffer */
	buffer[i] = '\0';
	/* reverse the buffer if the number is negative */
	if (isneg)
	{
		start = 0;
		end = i - 1;

		while (start < end)
		{
			tchar = buffer[start];
			buffer[start] = buffer[end];
			buffer[end] = tchar;
			start++;
			end--;
		}
	}
	return (0);
}
