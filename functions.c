#include "main.h"
/*done by ANAS OUBAHA & ACHRAF ZAKI*/
/**
 * _strlen - count the string len
 * @s: the string to be counted
 * Return: the len value
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * check_percent - writes a percent sign to standard output.
 *
 * @count_char: pointer to integer that keeps
 * track of number of characters written.
 */
void check_percent(int *count_char)
{
	my_putchar('%');
	(*count_char) += 1;
}

/**
 * num_len - returns the length of an integer
 *
 * @num: the integer to measure
 * Return: the length of the integer
 */
int num_len(int num)
{
	int len = 0;

	if (num == 0)
		return (1);

	while (num != 0)
	{
		num /= 10;
		len++;
	}

	return (len);
}

/**
 * int_to_str - converts an integer to a string
 *
 * @n: the integer to convert
 * Return: a pointer to the resulting string
 */
int int_to_str(int n)
{
	int i = 0;

	if (n < 0)
	{
		i += my_putchar('-');
		if (n == -2147483648)
		{
			i += my_putchar('2');
			n %= 1000000000;
		}

		i += int_to_str(-n);
	}
	else if (n >= 0 && n <= 9)
		i += my_putchar(n + '0');
	else
	{
		i += int_to_str(n / 10);
		i += int_to_str(n % 10);
	}
	return (i);

}
