#include "main.h"

/**
 * printf_unsigned_num - Function prints an unsigned number.
 * @argv: Argumnet vectors - shows the arguments.
 * @buffer: Buffer
 * @flags: flag specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, the amount of chars printed to buffer.
 */
int printf_unsigned_num(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int len = va_arg(argv, unsigned long int);

	len = size_to_unsign(len, size);

	if (len == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (len > 0)
	{
		buffer[i--] = (len % 10) + '0';
		len /= 10;
	}

	i++;

	return (write_unsigned_num(0, i, buffer, flags, width, precision, size));
}

/**
 * printf_oct_num - Function writes unsigned number in octal notation.
 * @argv: argument vector
 * @buffer: Main display buffer
 * @flags:  flag specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, amount of chars printed.
 */
int printf_oct_num(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int len = va_arg(argv, unsigned long int);
	unsigned long int init_len = len;

	UNUSED(width);

	len = size_to_unsign(len, size);

	if (len == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (len > 0)
	{
		buffer[i--] = (len % 8) + '0';
		len /= 8;
	}

	if (flags & F_HASH && init_len != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned_num(0, i, buffer, flags, width, precision, size));
}

/**
 * printf_hex_num - Function writes an unsigned number in hexadecimal notation.
 * @argv: arguments vectors
 * @buffer: main display buffer
 * @flags: flag specifier
 * @width: width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, number of chars printed to the buffer.
 */
int printf_hex_num(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_main_hex(argv, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * printf_upper _hex - Function wirites an unsigned num in upper hexadecimal
 * @argv: argument vector
 * @buffer: Buffer main display
 * @flags: flag specifier
 * @width: width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Int, number of chars printed to buffer.
 */
int printf_upper_hex(va_list argv, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_main_hex(argv, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * printf_main_hex - Function writes a hexadecimal number in  lower or upper.
 * @argv: argument vector
 * @direct: Array of values to map the number to
 * @buffer: Buffer main display
 * @flags:  flag specifier
 * @active_flag: active flag specifier.
 * @width: Width specifier
 * @precision: Precision specifier.
 * @size: Size specifier
 * Return: Int, amount of chars to buffer.
 */
int printf_main_hex(va_list argv, char direct[], char buffer[],
	int flags, char active_flag, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int len = va_arg(argv, unsigned long int);
	unsigned long int start = len;

	UNUSED(width);

	len = size_to_unsign(len, size);

	if (len == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (len > 0)
	{
		buffer[i--] = direct[len % 16];
		len /= 16;
	}

	if (flags & F_HASH && start != 0)
	{
		buffer[i--] = active_flag;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsigned_num(0, i, buffer, flags, width, precision, size));
}

