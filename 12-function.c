#include "main.h"

/*** PRINT POINTER **/
/**
 * print_pointer - Program to prints the value of a pointer variable
 * @types: Is a list of arguments
 * @buffer: Buffer array to be use to print
 * @flags:  active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: Number of character to be printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/*** PRINT NON PRINTABLE **/
/**
 * print_non_printable - the program will prints ascii codes in
 * hexa of non printable character
 * @types: Is the list of arguments
 * @buffer: Buffer array to be used to print
 * @flags:  active flags
 * @width: width
 * @precision: Precision to specification
 * @size: Size of specifier
 * Return: Number of character to be printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[k] != '\0')
	{
		if (is_printable(str[i]))
			buffer[k + offset] = str[k];
		else
			offset += append_hexa_code(str[k], buffer, k + offset);

		k++;
	}

	buffer[k + offset] = '\0';

	return (write(1, buffer, k + offset));
}

/*** PRINT REVERSE ***/
/**
 * print_reverse - To prints reverse string.
 * @types: Is the list of arguments
 * @buffer: Buffer array to be used to print
 * @flags:  active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: Number of character to be printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int k, count = 0;

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
		;

	for (k = i - 1; k >= 0; k--)
	{
		char z = str[k];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**** PRINT A STRING IN ROT13 **/
/**
 * print_rot13string - Program to print a string in rot13.
 * @types: Is a list of arguments
 * @buffer: Buffer array to be used to be printed
 * @flags: active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: Numbers of characters to be printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char r;
	char *str;
	unsigned int p, k;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(precision);

	if (str == NULL)
		str = "(AHYY)";
	for (p = 0; str[p]; p++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[p])
			{
				r = out[k];
				write(1, &r, 1);
				count++;
				break;
			}
		}
		if (!in[k])
		{
			r = str[p];
			write(1, &r, 1);
			count++;
		}
	}
	return (count);
}
