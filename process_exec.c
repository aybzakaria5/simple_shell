#include "shell.h"

/**
 * handl_ctrlc - handls the ctrl c signal
 * @signal: the signal
 */

void handl_ctrlc(int signal)
{
	(void)signal;
	puts("($) ");
}

void builtin_env()
{
	int i = 0;
	while (environ[i])
	{
		puts(environ[i]);
		i++;
	}
}

/**
 *readPrompt - reads the input from the user and sends it
 *to be excuted
 */
void readPrompt(void)
{
    int exiting = 0;
    int exit_status = EXIT_SUCCESS;
    size_t buf_size = 0;
    char **ar_parsed;
    int n_reads;
    char *buf = NULL;

    signal(SIGINT, handl_ctrlc);

    while (!exiting)
    {
        /* type prompt */
        puts("($) ");

        /* reads input */
        n_reads = getline(&buf, &buf_size, stdin);

        /* handle empty input */
        if (strcmp(buf, "\n") == 0)
            continue;

        if (n_reads == -1)
        {
            putchar('\n');
            exiting = 1;
            exit_status = EXIT_FAILURE;
        }
        else
        {
            ar_parsed = parse(buf, " \t\n");

            if (strcmp(ar_parsed[0], "exit") == 0)
                exiting = 1;
            else if (strcmp(ar_parsed[0], "env") == 0)
                builtin_env();
            else
                execute_command(ar_parsed);

            free(ar_parsed);
        }

        free(buf);
        buf = NULL;
    }

    exit(exit_status);
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