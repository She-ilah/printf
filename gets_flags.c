#include "main.h"
#include <stdio.h>
/**
 * get_flags - Function determines the flags.
 * @format: format specifier
 * @i: integer
 * Return: Int type,the flags
 */
int get_flags(const char *format, int *i)
{
	int n, current_int;
	int fl = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_int = *i + 1; format[current_int] != '\0'; current_int++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[current_int] == FLAGS_CH[n])
			{
				fl |= FLAGS_ARR[n];
				break;
			}

		if (FLAGS_CH[n] == 0)
			break;
	}
	*i = current_int - 1;
	return (fl);
}

