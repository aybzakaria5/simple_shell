#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <signal.h>
extern char **environ;
void _puts(char *str);
int _putchar(char c);
char *_getenv(const char *env_name);
char **parse(char *buffer, char *delim);
void execute_command(char **ar_parsed);
void readPrompt(void);
void handl_ctrlc(int signal);
char *getpath(char *cmd);
void builtin_env(void);
void _puts(char *str);
int _putchar(char c);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strdup(char *str);
int _strlen(char *s);
void *_realloc(void *ptr, unsigned int new_size);
#endif /* #define SHELL_H */
