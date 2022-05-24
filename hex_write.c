#include "main.h"
#include <stdio.h>

/**
 * hexa_write - write numbers in base 16
 * @num: Number passed
 * @ptr: Pointer to variable counter
 *
 * Return: Number of digits or letters
 */
int hexa_write(unsigned int num, int *ptr)
{
	unsigned int temp;
	unsigned int arr[6] = {10, 11, 12, 13, 14, 15};
	char ar[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int i;
	char c;

	(*ptr)++;
	if ((int)num < 0)
	{
		temp = UINT_MAX + 1 + num;
		num = temp;
	}
	if (num / 16 > 0)
		hexa_write(num / 16, ptr);
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

/**
 * hexa_write_long - Write unsigned long int in hexa
 * @num: unsigned long int
 * @ptr: Variable count
 *
 * Return: Variable count
 */

int hexa_write_long(unsigned long int num, int *ptr)
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
		hexa_write_long(num / 16, ptr);
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



/**
 * hexa_write_short - Write unsigned short int in hexa
 * @num: unsigned short int
 * @ptr: Variable count
 *
 * Return: Variable count
 */

int hexa_write_short(unsigned short int num, int *ptr)
{
	unsigned short int temp;
	unsigned short int arr[6] = {10, 11, 12, 13, 14, 15};
	char ar[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int i;
	char c;

	(*ptr)++;
	if ((short int)num < 0)
	{
		temp = USHRT_MAX + 1 + num;
		num = temp;
	}
	if (num / 16 > 0)
		hexa_write_short(num / 16, ptr);
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



/**
 * len_write_hexa - write numbers in base 16
 * @num: Number passed
 * @ptr: Pointer to variable counter
 *
 * Return: Number of digits or letters
 */
int len_write_hexa(unsigned int num, int *ptr)
{
	unsigned int temp;

	(*ptr)++;
	if ((int)num < 0)
	{
		temp = UINT_MAX + 1 + num;
		num = temp;
	}
	if (num / 16 > 0)
		len_write_hexa(num / 16, ptr);
	temp = num % 16;
	return (*ptr);
}
