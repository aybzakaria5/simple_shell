#include "shell.h"
/**
 * _memcpy - Copies memory area
 * @dest:memory destination
 * @src:memory source
 * @n:number of bytes to copy
 *
 * Return: Always pointer to dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = src[i];
	}
	return (dest);
}

/**
 * _strdup - Returns a pointer to a newly allocated
 * space in memory, which contains a copy of the
 * string given as a parameter.
 * @str: the string to copy
 *
 * Return: Pointer to the created dstring (Success)
 * NULL on failure
*/
char *_strdup(char *str)
{
	char *strin;
	int i = 1;

	if (str != NULL)
	{
		while (*(str + i) != '\0')
		{
			i++;
		}
		strin = malloc(sizeof(char) * (i + 1));
		i = 0;
		if (strin != NULL)
		{
			while (*(str + i) != '\0')
			{
				*(strin + i) = *(str + i);
				i++;
			}
			return (strin);
		}
	}
	return (NULL);
}

/**
 * _strlen - Return the length of a string
 * @s: The string to calculate its length
 *
 * Return: The length of the the string
*/

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
