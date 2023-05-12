#include "main.h"

/**
 * sigint_sig - handles signal interrupt.
 * @sig: The signal number to handle.
 *
 * Return: void.
 */
void sigint_sig(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		_prompt();
		fflush(stdout);
	}
}
