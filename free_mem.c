#include "main.h"

/**
 * free_mem - Frees an array of strings and sets the pointer to NULL.
 *
 * @argc: Number of elements in the array.
 * @argv: Array of strings to free.
 *
 * Return: Nothing.
 */
void free_mem(int argc, char **argv)
{
	int j;

	if (argv == NULL)
		return;

	for (j = 0; j < argc; j++)
	{
		free(argv[j]);
		argv[j] = NULL;
	}

	free(argv);
	argv = NULL;
}
