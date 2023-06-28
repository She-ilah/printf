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
	int p;

	p = -1;/* the default prescision value*/
	(*i)++;/*this will make it move past the % char*/
	/* check if the character is dot or asterisk*/
	if (format[*i] == '.')
	{
		(*i)++; /*move past the dot*/

		/*to check if the next character is digit*/
		if (format[*i] >= '0' && format[*i] <= '9')
		{
			/* Extracting the precision value */
			p = 0;
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				p = p * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}
	else if (format[*i] == '*')
	{
		(*i)++;
		p = va_arg(list, int);
	}
	return (p);
}
