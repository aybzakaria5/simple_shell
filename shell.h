#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;
void _puts(char *str);
int _putchar(char c);
char *_getenv(const char *env_name);
char **parse(char *buffer, char *delim);
void execute_command(char **ar_parsed);
void readPrompt();
void handl_ctrlc(int signal);
char *getpath(char *cmd);
