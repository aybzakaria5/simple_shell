#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string
 * @str: The string to print
*/

void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string
 * @s2: Second string
 *
 * Return: integer
*/
int _strcmp(const char *s1, const char *s2)
{
	int k;

	k = 0;
	while (s1[k] != '\0' || s2[k] != '\0')
	{
		if (s1[k] != s2[k])
			return (s1[k] - s2[k]);
		k++;
	}
	return (0);
}

/**
 * _strcpy - Copies a string to buffer
 * @dest: destination string
 * @src: source string
 *
 * Return: A pointer
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		*(dest + i) = src[i];
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The string to append to
 * @src: The string to append
 *
 * Return: Pointer to resulting string
*/
char *_strcat(char *dest, char *src)
{
	int i, j, k;

	i = j = k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	for (k = 0; k < j; k++)
	{
		*(dest + i) = src[k];
		i++;
	}
	*(dest + (i + 1)) = '\0';
	return (dest);
}
