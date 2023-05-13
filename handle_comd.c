#include "main.h"

/**
 * handle_pwd - Executes the 'pwd' command.
 *
 * Description: prints current working directory to stdout.
 *
 * Return: Nothing.
 */
void handle_pwd(void)
{
	char *cwd = getcwd(NULL, 0);

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
/**
 * handle_cd - Executes the 'cd' command.
 *
 * @comd: An array of strings containing the command and its arguments.
 *
 * Description: changes dir to the spec'd  dir  in `comd` parameter.
 *
 * Return: Nothing.
 */
void handle_cd(char **comd)
{
	if (comd[1] == NULL)
	{
		write(STDERR_FILENO, "cd: missing an argument\n", 21);
	}
	else if (chdir(comd[1]) != 0)
	{
		perror("cd failed");
	}
}

/**
 * h_comd - Executes a command entered by the user.
 *
 * @comd: An array of strings containing the command and its arguments.
 * @input: Pointer to the input str entered by the user.
 * @c: Comd counter.
 * @argc: Number of arguments passed.
 * @argv: Array of strs with the args passed.
 *
 * Description: handles exec of comd passed in the `comd` parameter.
 * If comd is `cd`, `pwd`, or `exit`, it's exec by approp function.
 * Otherwise, a child process created to exec comd using `execvp()`.
 *
 * Return: Status code of the comd execution.
 */
int handle_comd(char **comd, char *input, int argc, char **argv)
{
	if (comd[0] == NULL)
		return (EXIT_SUCCESS);
	else if (my_strcmp(comd[0], "cd") == 0)
	{
		handle_cd(comd);
		return (EXIT_SUCCESS);
	}
	else if (my_strcmp(comd[0], "pwd") == 0)
	{
		handle_pwd();
		return (EXIT_SUCCESS);
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
			perror(input);
			free_mem(argc, argv);
			_exit(EXIT_FAILURE);
			return (EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	return (EXIT_SUCCESS);
}
