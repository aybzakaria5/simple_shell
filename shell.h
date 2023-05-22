#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
extern char **environ;
char *_getenv(const char *env_name);
char **parse(char *buffer, char *delim);
void execute_command(char **ar_parsed);
void readPrompt();
char *getpath(char *cmd);