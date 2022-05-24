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

/**
 * write_int_long - Wrint long int to stdout
 * @n: input long int
 * @ptr: Pointer to variable count
 *
 * Return: Length of integer
 */
int write_int_long(long int n, int *ptr)
{
	char c;
	char *s;

	if (n == LONG_MIN)
	{
		s = "-9223372036854775808";
		write(1, s, 20);
		return (20);
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
		write_int_long(n / 10, ptr);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (*ptr);
}



/**
 * write_int_short - Wrint long int to stdout
 * @n: input short int
 * @ptr: Pointer to variable count
 *
 * Return: Length of integer
 */
int write_int_short(short int n, int *ptr)
{
	char c;
	char *s;

	if (n == SHRT_MIN)
	{
		s = "-32768";
		write(1, s, 6);
		return (6);
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
		write_int_short(n / 10, ptr);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (*ptr);
}


/**
 * len_int - Write integer to stdout
 * @n: inputed integer
 * @ptr: pointer to varaible count
 *
 * Return: Length of integer
 */
int len_int(int n, int *ptr)
{

	if (n == -2147483648)
	{
		return (11);
	}
	(*ptr)++;
	if (n < 0)
	{
		(*ptr)++;
		n = -n;
	}
	if (n / 10 > 0)
		len_int(n / 10, ptr);
	return (*ptr);
}
