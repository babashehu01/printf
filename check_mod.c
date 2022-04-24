#include "main.h"
/**
 * check_mode - checks for a ('%') symbol
 * @c: inputed character
 *
 * Return: state of the func
 */
int check_mode(char c)
{
	int i;
	char arr[] = "csdib\n%";

	for (i = 0; arr[i]; i++)
	{
		if (arr[i] == c)
			return (1);
		if (c == '\0')
			return (1);
	}
	return (0);
}
