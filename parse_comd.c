#include "main.h"

/**
 * parse_comd - Parses a command string and stores args in an array.
 * @comd: Pointer to the command string to be parsed.
 * @args: Pointer to an array to store the parsed arguments.
 *
 * Return: Number of arguments parsed.
 */
int parse_comd(char *comd, char **args)
{
	int argc = 0;

	while (*comd != '\0')
	{
		while (*comd == ' ' || *comd == '\t' || *comd == '\n')
			*comd++ = '\0';
		if (*comd != '\0')
		{
			args[argc++] = comd;
		}
		while (*comd != '\0' && *comd != ' ' && *comd != '\t' && *comd != '\n')
			comd++;
	}
	args[argc] = NULL;
	return (argc);
}
