#include "main.h"

int check_mode(char c)
{
	int i;
	char arr[] = "csdib\n";

	for (i = 0; arr[i]; i++)
	{
		if (arr[i] == c)
			return (1);
	}
	return (0);
}
