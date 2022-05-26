#include "main.h"

/**
 * rev_str - Reverses string
 * @str: Passed string
 *
 * Return: Number of chars
 */
int rev_str(char *str)
{
	const char *s = str;
	char *ptr = NULL;
	int len = _strlen(s), index;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (0);
	for (len--, index = 0; len > -1; len--, index++)
	{
		ptr[index] = s[len];
	}
	ptr[index] = '\0';
	write(1, ptr, index);
	free(ptr);
	return (index);
}
