#include "main.h"
/**
 * get_size - Calculates the size of arg
 * @format: Formatted string
 * @i: List of args te print
 * Return:precision
 */
int get_size(const char *format, int *i)
{
	int cr = *i + 1;
	int size = 00;

	if (format[cr] == 'l')
		size = S_LONG;
	else if (format[cr] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = cr - 1;
	else
		*i = cr;
	return (size);
}
