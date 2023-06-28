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
	int s;
	int size;

	s = *i + 1;
	size = 0;

	if (format[s] == 'l')
	{
		size = 4;
	}
	else if (format[s] == 'h')
	{
		size = 2;
	}
	if (size == 0)
	{
		*i = s - 1;
	}
	else
	{
		*i = s;
	}
	return (size);
}
