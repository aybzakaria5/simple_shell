#include "shell.h"

/**
 * getpath - a function that gets the path to add it the comamnd
 *@cmd : the comamand
 *Return: returns the pathif success null if nto
 */
char *getpath(char *cmd)
{
	char *path = _getenv("PATH");
	char *dir_check;
	char *full_path;
	struct stat st;
	int path_exists = 0;


	if (cmd && strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
		{
			full_path = malloc(strlen(cmd) + 1);
			strcpy(full_path, cmd);
			path_exists = 1;

		}
	}
	else
	{
		dir_check = strtok(path, ":");

		while (dir_check)
		{
			full_path = malloc(strlen(dir_check) + strlen(cmd) + 2);
			strcpy(full_path, dir_check);
			strcat(full_path, "/");
			strcat(full_path, cmd);

			if (stat(full_path, &st) == 0)
			{
				path_exists = 1;
				break;
			}
			free(full_path);
			dir_check = strtok(NULL, ":");
		}
	}
	free(path);
	return (path_exists ? full_path : NULL);
}

/**
 *_getenv - a fucntion that gets the path value
 *@env_name:  the variable we wnat to get it's value
 *Return: returns the value of the env
 */
char *_getenv(const char *env_name)
{
	int env_count = 0;
	char *key_finder;
	char *env_copy;
	char *value = NULL;

	while (environ[env_count])
	{
		env_copy = strdup(environ[env_count]);
		key_finder = strtok(env_copy, "=");

		if (_strcmp(env_name, key_finder) == 0)
		{
			value = strdup(strtok(NULL, "\n"));
		}
		free(env_copy);
		env_count++;
	}
	return (value);
}

/**
 *parse - a function to parse the string
 *@buffer:  the buffer we want to pasre
 *@delim:  the delimetres
 *Return: the array of the parsed string
 */
char **parse(char *buffer, char *delim)
{
	char **ar_prs = NULL;
	char *token;
	int i = 0;

	token = strtok(buffer, delim);

	while (token)
	{
		ar_prs = realloc(ar_prs, sizeof(char *) * (i + 1));
		ar_prs[i] = token;
		token = strtok(NULL, delim);
		++i;
	}
	ar_prs = realloc(ar_prs, sizeof(char *) * (i + 1));
	ar_prs[i] = NULL;
	if (!ar_prs)
		return (NULL);
	return (ar_prs);
}
