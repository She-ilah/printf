#include "main.h"

/**
 * print_chars - Function prints printable characters.
 * @a: Character to be assesed.
 * Return: 1 if c is printable, 0 otherwise
 */
int print_chars(char a)
{
	if (a >= 32 && a < 127)
		return (1);

	return (0);
}

/**
 * hex_cat - Function adds ascci in hexadecimal code to buffer.
 * @buffer: buffer which is an array of characters.
 * @index: Index
 * @ascii: code to be appended.
 * Return: Always 3
 */
int hex_cat(char ascii, char buffer[], int index)
{
	char direct[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = direct[ascii / 16];
	buffer[index] = direct[ascii % 16];

	return (3);
}

/**
 * is_digit - Asseses whether a character is a digit
 * @n: Char to be assesed
 * Return: 1 if n is a digit or 0 upon failure.
 */
int is_digit(char n)
{
	if (n >= '0' && n <= '9')
		return (1);

	return (0);
}

/**
 * size_to_num - Function allocates a number to a specified size
 * @num: Number to be allocated
 * @size: indicator
 * Return: Allocated value to num.
 */
long int size_to_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * size_to_unsign - Function allocates an unsigned numb to the specified size
 * @num: Number to be allocated
 * @size: indicator
 * Return: Allocated value to num.
 */
long int size_to_unsign(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

