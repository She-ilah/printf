#include "main.h"
#include <stdio.h>
/**
 * get_precision - a fuction that get precision
 * @format: the format specifier
 * @i: the integer that store the parameter
 * @list: the variable list
 * Return: the precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int current_int = *i + 1;
	int p = -1;/* the default prescision value*/

	if (format[current_int] != '.')
		return (p);
	/* check if the character is dot or asterisk*/

	p = 0;
	/*to check if the next character is digit*/
	for (current_int += 1; format[current_int] != '\0'; current_int++)
	{
		 /* Extracting the precision value */
		if (is_digit(format[current_int]))
		{
			p *= 10;
			p += format[current_int] - '0';
		}
		else if (format[current_int] == '*')
		{
			current_int++;
			p = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current_int - 1;

	return (p);
}

