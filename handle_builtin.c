#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_strcmp - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 *
 * Return: 0 if strings are equal, negative value if str1 is less than str2,
 * positive value if str1 is greater than str2.
 */
int my_strcmp(const char *str1, const char *str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return(str1[i] - str2[i]);
		}
		i++;
	}
	return(0);
}

/**
 * my_getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 * @environ: Pointer to an array of strings with the environment variable.
 *
 * Return: Pointer to the value of the environment variable,
 *         or NULL if the environment variable is not found.
 */
char *my_getenv(const char *name, char **environ)
{
	int j, k, len;
	char *env_var, *value;

	len = my_strlen(name);

	for (j = 0; environ[j] != NULL; j++)
	{
		env_var = environ[j];
		k = 0;

		while (name[k] != '\0' && env_var[k] == name[k])
		{
			k++;
		}
		if (k == len && env_var[k] == '=')
		{
			value = &env_var[k + 1];
			return (value);
		}
	}
	return (NULL);
}

/**
 * handle_builtin - Executes built-in commands of the hsh.
 * @args: Pointer to an array of arguments.
 *
 * Return: 1 if command is a built-in command, 0 if not
 */
int handle_builtin(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	if (args[1] == NULL && my_strcmp(args[0], "cd") == 0)
	{
		chdir(my_getenv("HOME"));
		return (1);
	}

	if (args[2] == NULL && my_strcmp(args[0], "cd") == 0)
	{
		if (chdir(args[1]) != 0)
		{
			perror("chdir");
		}
		return (1);
	}

	if (my_strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}
