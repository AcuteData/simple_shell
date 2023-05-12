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

/**
 * free_all - Frees memory alloc for command array and input string.
 * @comd: Double pointer to the command array.
 * @input: Pointer to the input string.
 * @null_term: An integer indicating whether comd is null-terminated or not.
 *
 * Return: Nothing.
 */
void free_all(char **comd, char *input, int null_term)
{
	int k;

	for (k = 0; comd[k] != NULL || (!null_term && k < BUFFER_SIZE); k++)
	{
		free(comd[k]);
	}

	free(comd);

	free(input);
}
