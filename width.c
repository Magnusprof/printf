#include "main.h"

/**
 * get_width - The function calculates the width for printing
 * @format: It use for formating string in which to print the arguments.
 * @i: List of arguments that will be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_k;
	int width = 0;

	for (curr_k = *i + 1; format[curr_k] != '\0'; curr_k++)
	{
		if (is_digit(format[curr_k]))
		{
			width *= 10;
			width += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_k - 1;

	return (width);
}
