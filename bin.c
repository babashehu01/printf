#include "main.h"
/**
 * bin - converts to binary
 * @n: input
 * @ptr: pointer to the count variable
 * Return: No return value
 */
int bin(unsigned int n, int *ptr)
{
	char c;

	(*ptr)++;
	if (n / 2 > 0)
	{
		bin(n / 2, ptr);
	}
	c = (n % 2) + '0';
	write(1, &c, 1);
	return (*ptr);
}
