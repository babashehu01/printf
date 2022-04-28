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
