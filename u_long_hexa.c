#include "main.h"
#include <stdio.h>

/**
 * hexa_ulong_write - write numbers in base 16
 * @num: Number passed
 * @ptr: Pointer to variable counter
 *
 * Return: Number of digits or letters
 */
int hexa_ulong_write(unsigned long int num, int *ptr)
{
	unsigned long int temp;
	unsigned long int arr[6] = {10, 11, 12, 13, 14, 15};
	char ar[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int i;
	char c;

	(*ptr)++;
	if ((int)num < 0)
	{
		temp = ULONG_MAX + 1 + num;
		num = temp;
	}
	if (num / 16 > 0)
		hexa_ulong_write(num / 16, ptr);
	temp = num % 16;
	if (temp > 9)
	{
		for (i = 0; i < 6; i++)
		{
			if (temp == arr[i])
			{
				write(1, &ar[i], 1);
				break;
			}
		}
	}
	else
	{
		c = temp + '0';
		write(1, &c, 1);
	}
	return (*ptr);
}
