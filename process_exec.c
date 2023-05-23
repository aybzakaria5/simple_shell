#include "shell.h"

<<<<<<< HEAD
=======


/**
 * handl_ctrlc - handls the ctrl c signal
 * *@signal: the signal
*/

 void handl_ctrlc(int signal)
{
    (void)signal;
    puts("($) ");
}


      
>>>>>>> ayoub
/**
 * handl_ctrlc - handls the ctrl c signal
 * @signal: the signal
*/

void handl_ctrlc(int signal)
{
    (void)signal;
    puts("($) ");
}

/**
 *readPrompt - reads the input from the user and sends it
 *to be excuted
 */
void readPrompt(void)
{
    size_t buf_size = 0;
    char **ar_parsed;
    int n_reads;
    char *buf = NULL;
<<<<<<< HEAD
    signal(SIGINT, handl_ctrlc);
=======

  signal(SIGINT, handl_ctrlc);

>>>>>>> ayoub

    while (1)
    {
        /* type prompt */
        puts("($) ");
        /* reads input */
        n_reads = getline(&buf, &buf_size, stdin);
<<<<<<< HEAD
    
=======

>>>>>>> ayoub
        /* handle empty input */

        if (strcmp(buf, "\n") == 0)
        {
            continue;
        }
        if (n_reads == -1)
        {
            putchar('\n');
            free(buf);
            exit(1);
        }
        /* parse command */
        ar_parsed = parse(buf, " \t\n");

        /* handle exit command */
        if (strcmp(ar_parsed[0], "exit") == 0)
        {
            free(buf);
            free(ar_parsed);
            exit(0);
        }
        /*handl the builtin env*/

<<<<<<< HEAD
=======

>>>>>>> ayoub
        /* start command invoking */
        execute_command(ar_parsed);
        /* free args before next parsing */
        free(ar_parsed);
    }
}
/**
 * execute_command - a function that executes the command line
 * @ar_parsed: the array of commands we want to excute
 *
 */
/**
 * builtin_env - a fucntion that prints the envirment vars in the current path
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
            exit(0);
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
<<<<<<< HEAD
    if (cmd != ar_parsed[0])
        free(cmd);
}
=======
    free(cmd);
}
>>>>>>> ayoub
