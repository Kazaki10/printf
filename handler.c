#include "main.h"

/**
*_putchar -write a char.
*@c:character to write.
*Return:string
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
*handle_char - handle a single character conversion specifier
*@c: conversion specifier
*@args: the va_list of arguments
*@counter: pointer to count characters
*/
void handle_char(char c, va_list args, int *counter)
{
	if (c == 'c')
	{

		char cr = va_arg(args, int);

		write(1, &cr, 1);
		(*counter)++;
	}
	else if (c == 's')
	{
		char *s = va_arg(args, char *);

	if (s == NULL)
			s = "(null)";
		write(1, s, strlen(s));
		(*counter) += strlen(s);
	}
	else if (c == 'd' || c == 'i')
	{
		int nums = va_arg(args, int);
		(*counter) += int_to_string(nums);
	}
	else if (c == 'b')
	{
		unsigned int nums = va_arg(args, unsigned int);

		(*counter) += num_to_b(nums);
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')

		(*counter) += number_to_hx_to_octal(va_arg(args, unsigned int), c);

	else if (c == 'S')
	{
		int p;

		char *str = va_arg(args, char *);

	for (p = 0; str[p] != '\0'; p++)
	{
	if (str[p] < ' ' || str[p] >= 127)
	{
		_putchar('\\');
		_putchar('x');
		print_hex(str[p]);
		(*counter) += 4;
	}
	else
		(*counter) += _putchar(str[p]);
	}
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		(*counter)++;
	}
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		(*counter) += 2;
	}
}
