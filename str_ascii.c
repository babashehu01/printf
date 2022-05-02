#include "main.h"
#include <stdio.h>

/**
 * choose_ascii - chose the ascii value in hexadecimal
 * @i: decimal value of character according to ascii
 *
 * Return: A character of the form '\x0A'
 */
char *choose_ascii(int i)
{
	int arr[32], index, value;
	char *ar[] = {"\\x01", "\\x02", "\\x03", "\\x04", "\\x05",
		       "\\x06", "\\x07", "\\x08", "\\x09", "\\x0A",
		       "\\x0B", "\\x0C", "\\x0D", "\\x0E", "\\x0F",
		       "\\x10", "\\x11", "\\x12", "\\x13", "\\x14",
		       "\\x15", "\\x16", "\\x17", "\\x18", "\\x19",
		       "\\x1A", "\\x1B", "\\x1C", "\\x1D", "\\x1E",
		       "\\x1F", "\\x7F"
		};

	for (index = 0, value = 1; index < 31; index++, value++)
		arr[index] = value;
	arr[index] = 127;
	for (index = 0; index < 32; index++)
	{
		if (arr[index] == i)
		{
			return (ar[index]);
		}
	}
	return (NULL);
}


/**
 * str_ascii - Prints string with ascii value of non-printable characters
 * @str: String passed
 *
 * Return: Length of string
 */
int str_ascii(char *str)
{
	int i, num = 0;
	char *c;

	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || (str[i] >= 127))
		{
			c = choose_ascii(str[i]);
			write(1, c, 4);
			num += 4;
		}
		else
		{
			write(1, &str[i], 1);
			num++;

		}
	}
	return (num);
}
