#include "main.h"
/**
 * _strlen - counts string lenght
 * @s: string to count
 * Return: lenght
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * checker - writes a percent sign
 *
 * @count_char: tacks numbers of characters written.
 */
void checker(int *count_char)
{
	_putchar('%');
	(*count_char) += 1;
}

/**
 * num_lenght - returns the length of an integer
 *
 * @num: int measured
 * Return: the length of the integer
 */
int num_lenght(int num)
{
	int lenght = 0;

	if (num == 0)
		return (1);

	while (num != 0)
	{
		num /= 10;
		lenght++;
	}

	return (lenght);
}

/**
 * int_to_string - makes a string out of integer
 *
 * @n: integer to convert
 * Return: pointer to string
 */
int int_to_string(int n)
{
	int i = 0;

	if (n < 0)
	{
		i += _putchar('-');
		if (n == -2147483648)
		{
			i += _putchar('2');
			n %= 1000000000;
		}

		i += int_to_string(-n);
	}
	else if (n >= 0 && n <= 9)
		i += _putchar(n + '0');
	else
	{
		i += int_to_string(n / 10);
		i += int_to_string(n % 10);
	}
	return (i);

}
