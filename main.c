#include "shell.h"

int is_interactive;

/**
 * main - entry point
 * @ac: args counter
 * @av: args values
 * Return: returns 0 if success
 */
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	readPrompt();
	return (0);
}
