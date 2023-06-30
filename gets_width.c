#include <stdio.h>
#include "main.h"
/**
 * get_width - a function that calculate the width
 * @format: the format
 * @i: the pointer integer that takes the parameter
 * @list: the list
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int b;
	int wid = 0;

	/*store them in a position*/
	/* move to the next character */
	for (b = *i + 1; format[b] != '\0'; b++)
	{
		/* extracting the width by parsing the num */
		if (is_digit(format[b]))
		{
			wid *= 10;
			wid += format[b] - '0';
		}
		else if (format[b] == '*')
		{
			b++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = b - 1;/* updating the width */

	return (wid);
}

