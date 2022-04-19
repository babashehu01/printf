#include "main.h"

/**
 * write_int - Write integer to stdout
 * @n: Integer passed
 */
void write_int(int n)
{
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		n = -n;
	}
	if (n / 10 > 0)
		write_int(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
