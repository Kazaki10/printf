#include "main.h"

/**
* _printf - print formatted output.
* @format:string containing format specifiers.
* @...: additional arguments to be printed.
*
* Return:number of characters printed or -1 if error.
*/

int _printf(const char *format, ...)
{
	int counter = 0, i;
	va_list args;

va_start(args, format);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
{
	if (format[i] == '%')
{
		handle_char(format[++i], args, &counter);
}
	else
{
		write(1, &format[i], 1);
		counter++;
}
}
	va_end(args);
	return (counter);
}
