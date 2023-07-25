#include "main.h"

/*** PRINT UNSIGNED NUMBER */
/**
 * print_unsigned - The program is to Prints an unsigned number
 * @types: Is the list  of arguments
 * @buffer: Buffer array use to print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: Number of character to be printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN OCTAL ***/
/**
 * print_octal - The program prints an unsigned number in octal notation
 * @types: Is the list of arguments
 * @buffer: Buffer array to be used to print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of printed character
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
{

	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[k--] = '0';

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN HEXADECIMAL **/
/**
 * print_hexadecimal - The program Prints an unsigned number
 * in hexadecimal notation
 * @types: Is the list of arguments
 * @buffer: Buffer array to be used to print
 * @flags: active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: Number of character to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **/
/**
 * print_hexa_upper - Program to prints an unsigned number
 * in upper hexadecimal notation
 * @types: Is the list of arguments
 * @buffer: Buffer array to be use to print
 * @flags:  Active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: Number of character of printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Program to prints a hexadecimal number in lower or upper
 * @types: It is a list of arguments
 * @map_to: Array of values to map the number
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * @size: Size of specification
 * Return: Number of character to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[k--] = flag_ch;
		buffer[k--] = '0';
	}

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
