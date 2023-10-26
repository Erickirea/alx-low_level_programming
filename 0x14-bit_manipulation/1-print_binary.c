#include "main.h"

/**
 * print_binary - prints the binary representation of a certain number
 * @n: an unsigned long int
 * Return: nothing
 */

void print_binary(unsigned long int n)
{
	int bit_count;
	int k;
	int flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	bit_count = sizeof(n) * 8;

	for (k = bit_count - 1; k >= 0; k--)
	{
		if ((n >> k) & 1)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
	}
}
