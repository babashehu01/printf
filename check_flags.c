#include "main.h"

/**
 * check_flag - check for flags
 * @flag: Flag passed
 *
 * Return: 1 - if present
 *         0 - not present
 */
int check_flag(char c)
{
	char *s = "+# ";
	int i;

	for (i = 0; s[i]; i++)
	{
		if (c == s[i])
			return (1);
	}
	return (0);
}
