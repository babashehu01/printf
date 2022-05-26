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


/**
 * rot13 - Encode or decode a message using caesar cipher
 * @str: String passed
 *
 * Return: Number of chars
 */
int rot13(char *str)
{
	const char *s = str;
	char *ptr = NULL;
	int len = _strlen(s), index;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (0);
	for (index = 0; s[index]; index++)
	{
		if ((s[index] >= 'A' && s[index] <= 'M') ||
				(s[index] >= 'a' && s[index] <= 'm'))
			ptr[index] = s[index] + 13;
		else if ((s[index] >= 'N' && s[index] <= 'Z') ||
				(s[index] >= 'n' && s[index] <= 'z'))
			ptr[index] = s[index] - 13;
		else
			ptr[index] = s[index];
	}
	ptr[index] = '\0';
	write(1, ptr, index);
	free(ptr);
	return (len);
}
