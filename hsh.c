#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>

#define BUFFER_SIZE 1024

/**
 * handle_empty_input_error - handles error when no input is given.
 * @prog_name: the name of the program being executed.
 * @c: the number of commands executed so far.
 *
 * Return: void.
 */
void handle_empty_input_error(char *prog_name, int c)
{
	int i = 0, prog_name_len = 0;

	while (prog_name[prog_name_len] != '\0')
		prog_name_len++;

	char *error_msg = "Error: No command was entered\n";
	char *line_num_msg = " at line ";
	char line_num[10];
	int line_num_len = 0, c_copy = c;

	while (c_copy > 0)
	{
		line_num_len++;
		c_copy /= 10;
	}
	for (i = line_num_len - 1; i >= 0; i--)
	{
		line_num[i] = '0' + (c % 10);
		c /= 10;
	}
	line_num[line_num_len] = '\0';

	write(STDERR_FILENO, prog_name, prog_name_len);
	write(STDERR_FILENO, line_num_msg, sizeof(line_num_msg) - 1);
	write(STDERR_FILENO, line_num, line_num_len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
}

/**
 * _prompt - Displays a prompt to the user.
 *
 * Return: Nothing.
 */
void _prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * loop - main loop of the hsh.
 * @argc: number of arguments passed to the hsh.
 * @argv: array of arguments passed to the hsh.
 *
 * Return: void
 */
void loop(int argc, char **argv)
{
	char *input, **comd;
	int c = 0, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);

	signal(SIGINT, sigint_sig);

	while (1)
	{
		c++;

		if (isatty(STDIN_FILENO))
			_prompt();

		input = my_getline();

		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "exit\n", 5);
			break;
		}

		if (input[0] == '\0')
		{
			handle_empty_input_error(argv[0], c);
			free(input);
			continue;
		}

		history(input);

		comd = parse_comd(input);
		st = handle_comd(comd, input, c, argc, argv);
		free_all(comd, input);

		if (st == -1)
			break;
	}
}

/**
 * handle_input - handles input from user.
 * @argc: the number of arguments passed to the shell.
 * @argv: array of arguments passed to the shell.
 *
 * Return: int.
 */
int handle_input(int argc, char **argv)
{
	loop(argc, argv);
	return (1);
}

/**
 * main - entry point of the program.
 * @argc: the number of arguments passed to the shell.
 * @argv: array of arguments passed to the shell.
 *
 * Return: int.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int status = handle_input(argc, argv);

	if (status == 0)
	{
		handle_empty_input_error(argv[0], 0);
	}
	print_environ();
	return (0);
}
