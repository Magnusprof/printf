#include "main.h"

/**
 * get_size - The function calculates the size to cast the argument
 * @format: It is use to format string to print the arguments
 * @i: List of arguments that will be printed
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_k = *i + 1;
	int size = 0;

	if (format[curr_k] == 'l')
		size = S_LONG;
	else if (format[curr_k] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_k - 1;
	else
		*i = curr_k;

	return (size);
}
