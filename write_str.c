#include "main.h"
/**
 * write_str - writes a string to the stdout
 * @s: input string
 *
 * Return: lenght of integers printed
 */
int write_str(char *s)
{
	int length;

	if (s == (char *)0)
	{
		s = "(null)";
		write(1, s, 6);
		return (6);
	}
	length = _strlen(s);

	write(1, s, length);
	return (length);
}

/**
 * write_str1 - Write string with condition
 * @s: Inputed string
 * @len: Number to chars to write
 *
 * Return: Number of chars written
 */
int write_str1(char *s, int len)
{
	if (s == (char *)0)
	{
		s = "(null)";
		write(1, s, 6);
		return (6);
	}
	write(1, s, len);
	return (len);
}
