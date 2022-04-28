#include "main.h"

/**
 * write_uint - write unsigned integer
 * @n: inputed unsigned integer
 * @ptr: pointer to variable count
 *
 * Return: Number of diigts of unsigned integer
 */
int write_uint(unsigned int n, int *ptr)
{
	char c;
	unsigned int temp;

	(*ptr)++;
	if ((int)n < 0)
	{
		temp = UINT_MAX + 1 + n;
		n = temp;
	}
	if (n / 10 > 0)
		write_uint(n / 10, ptr);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (*ptr);

}
