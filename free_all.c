#include "main.h"

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
