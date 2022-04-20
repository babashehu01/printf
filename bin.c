#include "main.h"
/**
 * bin - converts to binary
 * @n: input
 * Return: No return value
 */
void bin(unsigned int n)
{
	char c;

	if (n / 2 > 0)
	{
		bin(n / 2);
	}
	c = (n % 2) + '0';
	write(1, &c, 1);
}
