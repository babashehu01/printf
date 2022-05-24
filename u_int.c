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

/**
 * write_uint_long - Write unsigned long int
 * @n: unsigned long int
 * @ptr: Pointer to variable count
 *
 * Return: Variable count
 */
int write_uint_long(unsigned long int n, int *ptr)
{
	char c;
	unsigned long int temp;

	(*ptr)++;
	if ((int)n < 0)
	{
		temp = ULONG_MAX + 1 + n;
		n = temp;
	}
	if (n / 10 > 0)
		write_uint_long(n / 10, ptr);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (*ptr);

}



/**
 * write_uint_short - Write unsigned short int
 * @n: unsigned short int
 * @ptr: Pointer to variable count
 *
 * Return: Variable count
 */
int write_uint_short(unsigned short int n, int *ptr)
{
	char c;
	unsigned short int temp;

	(*ptr)++;
	if ((short int)n < 0)
	{
		temp = USHRT_MAX + 1 + n;
		n = temp;
	}
	if (n / 10 > 0)
		write_uint_short(n / 10, ptr);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (*ptr);

}



/**
 * len_uint - write unsigned integer
 * @n: inputed unsigned integer
 * @ptr: pointer to variable count
 *
 * Return: Number of diigts of unsigned integer
 */
int len_uint(unsigned int n, int *ptr)
{
	unsigned int temp;

	(*ptr)++;
	if ((int)n < 0)
	{
		temp = UINT_MAX + 1 + n;
		n = temp;
	}
	if (n / 10 > 0)
		len_uint(n / 10, ptr);
	return (*ptr);

}
