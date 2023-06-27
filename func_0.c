#include "main.h"
/**
 * print_unsigned - Prints an unsigned number
 * @types: List of args
 * @buffer: Buffer of arrays
 * @flags:flags
 * @width: width p
 * @precision: Precision p
 * @size: Size of b
 * Return: Number
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints an unsigned number in octal 8bit
 * @types: Lists of args /type of args
 * @buffer: Buffer of arrays.
 * @flags:flags .
 * @width: width.
 * @precision: Precision.
 * @size:Size.
 * Return: Num
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hex - prints unsigned number in hex
 * @types: Lists of args
 * @buffer: Buffer of arrays
 * @flags:flags
 * @width:width
 * @precision: Precision
 * @size: Size
 * Return:hex
 */
int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_HEX - Prints an unsigned number in upper hexadecimal
 * @types: Lists of args
 * @buffer: Bufferof  array
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return:hex
 */
int print_HEX(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/**
 *print_hexa - Print hexadecimal number in lowercase or uppercase
 * @types: Lissts of args
 * @map_to: Array
 * @buffer: Bufferof arrays
 * @flags:  flags
 * @flag_ch:flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: hex
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
