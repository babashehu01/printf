#include "main.h"
/**
 * write_int - Write integer to stdout
 * @n: inputed integer
 * @ptr: pointer to varaible count
 *
 * Return: Length of integer
 */
int write_int(int n, int *ptr)
{
	char c;
	char *s;

	if (n == -2147483648)
	{
		s = "-2147483648";
		write(1, s, 11);
		return (11);
	}
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
