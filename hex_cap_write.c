#include "main.h"
#include <stdio.h>

/**
 * hexa_x_write - write numbers in base 16
 * @num: Number passed
 * @ptr: Pointer to variable counter
 *
 * Return: Number of digits or letters
 */
int hexa_x_write(unsigned int num, int *ptr)
{
	unsigned int temp;
	unsigned int arr[6] = {10, 11, 12, 13, 14, 15};
	char ar[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int i;
	char c;

	(*ptr)++;
	if ((int)num < 0)
	{
		temp = UINT_MAX + 1 + num;
		num = temp;
	}
	if (num / 16 > 0)
		hexa_x_write(num / 16, ptr);
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
