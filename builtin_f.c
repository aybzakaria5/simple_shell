#include "shell.h"
char *builtin_cmd[] = { "exit", "env", "cd" };
int (*builtin_functions[]) (char **) = { &bi_exit, &bi_env, &bi_cd };
/**
 * bi_exit - exit the programm
 * @args: program arguments
 *
 * Return: 0
*/
int bi_exit(char **args)
{
	(void) args;
	return (0);
}
/**
 * bi_env - prints the environment variables
 * @args: program arguments
 *
 * Return: 1
*/
int bi_env(char **args)
{
	int i = 0;

	(void) args;
	while (environ[i])
	{
		puts(environ[i]);
		i++;
	}
	return (1);
}
/**
 * bi_cd - change the current working directory
 * @args: program arguments
 *
 * Return: 1 on Success
 * 0 upon failure
*/
int bi_cd(char **args)
{
	int i = 0;
	char *path, buf[100], *before = "-";
	char *current_path;
	size_t size = 100 * sizeof(char);

	while (args[i])
		i++;
	if (i > 2)
		perror("Usage: cd [DIRECTORY]");
	else if (i == 1)
		path = "/home";
	else if (args[1] == before)
		path = getenv("OLDPWD");
	else
		path = args[1];
	current_path = getcwd(buf, size);
	if (path)
	{
		setenv("PWD", path, 1);
		setenv("OLDPWD", current_path, 1);
		chdir(path);
		return (1);
	}
	return (-1);
}
