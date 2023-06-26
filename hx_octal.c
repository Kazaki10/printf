#include "main.h"
/**
 * handle_hex - converts  to hexa decimal decimal number
 * @num: number that's going to  be converted
 * @base: base of a number
 * @buffer: buffer that will store us the result
 * Return: void
*/
void handle_hex(unsigned int num, char base, char *buffer)
{
	const char hx_low[] = "0123456789abcdef";
	const char hx_upp[] = "0123456789ABCDEF";
	const char *hx_dg = (base == 'x') ? hx_low : hx_upp;
	int in = 0, r;

	while (num != 0)
	{
		r = num % 16;
		buffer[in++] = hx_dg[r];
		num /= 16;
	}

	buffer[in] = '\0';
}
/**
 * handle_octal - converts the number to an octal
 * @num: number that needs to be converted
 * @buffer: buffer that will store us the result
 * Return: void
*/
void handle_octal(unsigned int num, char *buffer)
{
	int in = 0, r;

	while (num != 0)
	{
		r = num % 8;
		buffer[in++] = r + '0';
		num /= 8;
	}

	buffer[in] = '\0';
}

/**
 * handle_decimal - converts a number to a decimal number
 * @num: number that needs to be converted
 * @buffer: buffer that will store us the result
 * Return: void
*/
void handle_decimal(unsigned int num, char *buffer)
{
	int in = 0, r;

	while (num != 0)
	{
		r = num % 10;
		buffer[in++] = r + '0';
		num /= 10;
	}

	buffer[in] = '\0';
}
/**
 * number_to_hx_to_octal - converts a number to a hex number or an octal number
 * @num: number that needs to be converted
 * @base: base of a number
 * Return: number of digits printed
*/
int number_to_hx_to_octal(unsigned int num, char base)
{
	char buffer[MAX_BUFFER_SIZE];
	int i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (base == 'x' || base == 'X')
		handle_hex(num, base, buffer);
	else if (base == 'o')
		handle_octal(num, buffer);
	else if (base == 'u')
		handle_decimal(num, buffer);
	else
	{
		return (0);
	}
	for (i = _strlen(buffer) - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
	return (_strlen(buffer));
}
