#include "main.h"

/**
 * octal_write - Write integers in base 8
 * @num: Number passed
 * @ptr: Pointer to variable count
 *
 * Return: Number of digits
 */
int octal_write(unsigned int num, int *ptr)
{
	unsigned int temp;
	char c;

	(*ptr)++;
	if ((int)num < 0)
	{
		temp = UINT_MAX + 1 + num;
		num  = temp;
	}
	if (num  / 8 > 0)
		octal_write(num / 8, ptr);
	c = (num % 8) + '0';
	write(1, &c, 1);
	return (*ptr);
}

/**
 * octal_write_long - Write unsigned long int
 * @num: Unsigned long int
 * @ptr: Pointer to variable count
 *
 * Return: Variable count
 */
int octal_write_long(unsigned long int num, int *ptr)
{
	unsigned long int temp;
	char c;

	(*ptr)++;
	if ((int)num < 0)
	{
		temp = ULONG_MAX + 1 + num;
		num  = temp;
	}
	if (num  / 8 > 0)
		octal_write_long(num / 8, ptr);
	c = (num % 8) + '0';
	write(1, &c, 1);
	return (*ptr);
}



/**
 * octal_write_short - Write unsigned short int
 * @num: Unsigned short int
 * @ptr: Pointer to variable count
 *
 * Return: Variable count
 */
int octal_write_short(unsigned short int num, int *ptr)
{
	unsigned short int temp;
	char c;

	(*ptr)++;
	if ((short int)num < 0)
	{
		temp = USHRT_MAX + 1 + num;
		num  = temp;
	}
	if (num  / 8 > 0)
		octal_write_short(num / 8, ptr);
	c = (num % 8) + '0';
	write(1, &c, 1);
	return (*ptr);
}



/**
 * len_write_oct - Write integers in base 8
 * @num: Number passed
 * @ptr: Pointer to variable count
 *
 * Return: Number of digits
 */
int len_write_oct(unsigned int num, int *ptr)
{
	unsigned int temp;

	(*ptr)++;
	if ((int)num < 0)
	{
		temp = UINT_MAX + 1 + num;
		num  = temp;
	}
	if (num  / 8 > 0)
		len_write_oct(num / 8, ptr);
	return (*ptr);
}
