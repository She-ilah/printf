#include <stdio.h>
#include "main.h"
/**
 * get_size - a function tha calculate the lenght
 * @format: the format
 * @i: the integer taking the parameter
 * Return: the size
 */
int get_size(const char *format, int *i)
{
	int s = *i + 1;
	int size = 0;

	if (format[s] == 'l')
		size = S_LONG;
	else if (format[s] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = s - 1;
	else
		*i = s;

	return (size);
}

