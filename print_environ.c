#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * print_environ - prints environment variables.
 * @env: array of environment variables.
 *
 * Description: prints all environment variables in the format "VAR=value".
 *
 * Return: Nothing.
 */
void print_environ(char **env)
{
	int j = 0;

	while (env[j] != NULL)
	{
		size_t len = my_strlen(env[j]);

		write(STDOUT_FILENO, env[j], len);
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}
