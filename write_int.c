#include "main.h"

/**
 * write_int - Write integer to stdout
 * @n: Integer passed
 */
int write_int(int n, int *ptr)
{
	char c;
	
	(*ptr)++;
	if (n < 0)
	{
		c = '-';
		(*ptr)++;
		write(1, &c, 1);
		n = -n;
	}
	if (n / 10 > 0)
		write_int(n / 10, ptr);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (*ptr);
}
