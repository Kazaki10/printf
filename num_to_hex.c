#include "main.h"

/**
*num_to_b -converts numbersr to binary.
*@number: numbers to convert.
*Return:nothing.
*/
int num_to_b(unsigned int number)
{
char dig;
int counter;

if (number == 0)
{
	write(1, "0", 1);
	return (1);
}

	counter = 0;

	if (number > 1)
	counter += num_to_b(number / 2);

	dig = (number % 2) ? '1' : '0';
	write(1, &digit, 1);
	counter++;


	return (counter);
}
/**
*print_hex - prints a number in hexa
*@numb: numbers to be printed
*Return:nothing
*/
void print_hex(unsigned int numb)
{
	const char hx_dg[] = "0123456789ABCDEF";
	char buff[2];
	int index = 0, r, i;

	while (numb != 0)
{
		r = numb % 16;
		buff[index++] = hx_dg[r];
		numb /= 16;
}

	if (index == 1)
{
		my_putchar('0');
}

	for (i = index - 1; i >= 0; i--)
{
	if (buff[i] == '0' && i == index - 1)
		my_putchar('0');
	else if (buff[i] <= 0xF)
{
		my_putchar('0');
		my_putchar(buff[i]);
}
	else
		my_putchar(buff[i]);
}
}
