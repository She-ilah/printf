#include <stdio.h>
#include "main.h"
/**
 * get_width - a function that calculate the width
 * @format: the format
 * @i: the pointer integer that takes the parameter
 * @list: the list
 * Return: width
 */
int get_width(const char *format, int *i, __attribute__((unused))va_list list)
{
	int wid, b;

	wid = 0;
	b = *i;/*store them in a position*/

	b++;/* move to the next character */

	/*check if the character is a number */
	if (format[b] >= '0' && format[b] <= '9')
	{
		/* extracting the width by parsing the num */
		while (format[b] >= '0' && format[b] <= '9')
		{
			wid = wid * 10 + (format[b] - '0');
			b++;
		}
	}
	*i = b;/* updating the width */
	return (wid);
}
