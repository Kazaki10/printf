#include "main.h"

/**
 * get_flags - Calculates flags needed
 * @format: Format strings 
 * @i:parameter
 * Return: The flag
 */
int get_flags(const char *format, int *i)
{
	int j, cr;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cr = *i + 1; format[cr] != '\0'; cr++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cr] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = cr - 1;
	return (flags);
}
