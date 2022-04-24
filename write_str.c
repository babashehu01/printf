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
