#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HISTORY_SIZE 100

/**
 * my_strcpy - copies a string from source to destination.
 * @dest: destination string.
 * @src: source string.
 *
 * Return: pointer to destination string.
 */
char *my_strcpy(char *dest, const char *src)
{
	char *dest_ptr = dest;
	const char *src_ptr = src;

	while (*src_ptr)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}

	*dest_ptr = '\0';

	return (dest);
}

/**
 * history - adds the given command to the command history.
 * @input: the user's command input.
 * @hist_buf: buffer to store the command history.
 * @hist_count: pointer to the number of commands stored in the history buffer.
 *
 * Return: void.
 */
void history(char *input, char **hist_buf, int *hist_count)
{
	if (input != NULL && input[0] != '\0')
	{
		char *input_copy = malloc(my_strlen(input) + 1);

		if (input_copy != NULL)
		{
			my_strcpy(input_copy, input);

			if (*hist_count == MAX_HISTORY_SIZE)
			{
				free(hist_buf[0]);
				for (int i = 1; i < MAX_HISTORY_SIZE; i++)
				{
					hist_buf[i - 1] = hist_buf[i];
				}
				(*hist_count)--;
			}
			hist_buf[*hist_count] = input_copy;
			(*hist_count)++;
		}
	}
}
