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
	char *line = NULL;
	char **args;
	size_t bufsize = 0;
	ssize_t nreads;
	(void)ac;
	(void)av;
	is_interactive = isatty(STDIN_FILENO);
	if (is_interactive)
	{
		readPrompt();
	}
	else
	{

		while ((nreads = getline(&line, &bufsize, stdin)) != -1)
		{
			if (nreads > 0 && line[nreads - 1] == '\n')
				line[nreads - 1] = '\0';

			args = parse(line, " \t\n");
			execute_command(args);
			free(args);
		}

		free(line);
	}

	return (0);
}
