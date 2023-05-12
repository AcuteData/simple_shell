#include "main.h"

/**
 * handle_comd - Executes a command entered by the user.
 *
 * @comd: An array of strings containing the command and its arguments.
 *
 * Description: handles exec of command passed in the `comd` parameter.
 * If command is `cd`, `pwd`, or `exit`, it's executed by the function.
 * Otherwise, a child process created to exec command using `execvp()`.
 *
 * Return: Nothing.
 */
void handle_comd(char **comd)
{
	if (comd[0] == NULL)
		return;
	else if (my_strcmp(comd[0], "cd") == 0)
	{
		if (comd[1] == NULL)
		{
			write(STDERR_FILENO, "cd: missing an argument\n", 21);
		}
		else if (chdir(comd[1]) != 0)
		{
			perror("cd failed");
		}
		else if (my_strcmp(comd[0], "pwd") == 0)
		{
			char *cwd = getcwd(NULL, 0);
		}

			if (cwd == NULL)
			{
				perror("pwd failed");
			}
			else
			{
				write(STDOUT_FILENO, cwd, my_strlen(cwd));
				write(STDOUT_FILENO, "\n", 1);
				free(cwd);
			}
		}
		else if (my_strcmp(comd[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				execvp(comd[0], comd);
				perror("execvp failed");
				_exit(EXIT_FAILURE);
			}
			else
				wait(NULL);
		}
	}
}
