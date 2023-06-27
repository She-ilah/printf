#include "main.h"
#include <stdio.h>
/**
 * get_flags - a function tha will calculate the flags
 * @format: the format specifier
 * @i: the integer
 * Return: the flags
 */
int get_flags(const char *format, int *i)
{
	char fl;

	if (format != NULL && format[0] == '%' && format[1] != '\0')
	{
		fl = format[1];
		if (fl == '+')
		{
			*i = 1;
			return (1);
		}
		else if (fl == ' ')
		{
			*i = 2;
			return (1);
		}
		else if (fl == '#')
		{
			*i = 3;
			return (1);
		}
	}
	*i = 0; /* if it is invalid flag return 0 as failure */
	return (0);
}
