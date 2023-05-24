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
 * _strdup - duplicate a string
 * @str: the string to duplicate
 *
 * Return: pointer to newely allocated memory containing
 * the s copy
 * NULL if s is NULL
*/
char *_strdup(char *str)
{
	size_t len = _strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str != NULL)
	{
		memcpy(new_str, str, len);
	}
	return (new_str);
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
