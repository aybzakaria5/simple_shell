#include "shell.h"
char *buf = NULL;

/**
 * handl_ctrlc - handls the ctrl c signal
 * @signal: the signal
 */

void handl_ctrlc(int signal)
{
	(void)signal;

	free(buf);
	exit(EXIT_SUCCESS);
}
void handle_signale()
{
	if (signal(SIGINT, handl_ctrlc) == SIG_ERR)
	{
		/* If there is an error setting the signal handler*/
		const char *error_message = "An error occurred while setting a signal handler.\n";
		size_t message_length = strlen(error_message);
		ssize_t bytes_written = write(STDERR_FILENO, error_message, message_length);
		if (bytes_written < 0)
		{
			perror("write");
		}
		exit(EXIT_FAILURE);
	}
}

/**
 *readPrompt - reads the input from the user and sends it
 *to be excuted
 */
int readPrompt(void)
{
	int exiting = 0, notfound = 0, i, statu;
	size_t buf_size = 0;
	char **ar_parsed;
	int n_reads;

	/*char *buf = NULL;*/
	signal(SIGINT, handl_ctrlc);

	while (!exiting)
	{
		/* type prompt */
		if (isatty(STDIN_FILENO))
			puts("($) ");

		/* reads input */
		n_reads = getline(&buf, &buf_size, stdin);
		/* handle empty input */

		if (n_reads == -1)
		{

			if (isatty(STDIN_FILENO))
				putchar('\n');
			exiting = 1;
		}
		else if (strcmp(buf, "\n") == 0)
		{
			continue;
		}
		else
		{
			if (n_reads > 0 && buf[n_reads - 1] == '\n')
				buf[n_reads - 1] = '\0';

			ar_parsed = parse(buf, " \t\n");
			for (i = 0; i < 2; i++)
			{
				if (strcmp(ar_parsed[0], builtin_cmd[i]) == 0)
				{
					notfound = 1;
					statu = (*builtin_functions[i])(ar_parsed);
					if (!statu)
					{
						free(ar_parsed);
						free(buf);
						return (statu);
					}
				}
			}
			if (!notfound)
				execute_command(ar_parsed);

			free(ar_parsed);
		}

		free(buf);
		buf = NULL;
	}

	return (1);
}

/**
 * execute_command - a function that executes the command line
 * @ar_parsed: the array of commands we want to excute
 *
 */

void execute_command(char **ar_parsed)
{
	char *cmd;
	int status;
	pid_t pid;

	cmd = getpath(ar_parsed[0]);

	if (cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			/* execute command */
			execve(cmd, ar_parsed, environ);
		}

		else
		{
			wait(&status);
		}
	}
	else
	{
		puts("command not found");
	}
	if (cmd != ar_parsed[0])
		free(cmd);
}
