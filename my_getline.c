#include "main.h"

/**
 * _realloc - reallocates memory block using malloc and free
 * @ptr: pointer to memory previously allocated
 * @old_size: size in bytes of allocated space for ptr
 * @new_size: size in bytes for new memory block
 *
 * Return: pointer to new memory block
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *new_ptr;
	size_t i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new_ptr[i] = ((char *)ptr)[i];
	}
	free(ptr);
	return (new_ptr);
}

/**
 * my_getline - reads an entire line from a file descriptor.
 * @fd: file descriptor
 *
 * Return: pointer to the line read, or NULL on failure or end-of-file
 */
char *my_getline(const int fd)
{
	static char *line;
	static size_t line_len;
	static size_t line_cap;
	static char buffer[READ_SIZE];
	ssize_t bytes_read;
	size_t i;

	if (fd < 0)
		return (NULL);
	while (1)
	{
		if (line_len == 0 || line_len >= line_cap)
		{
			line_cap += READ_SIZE;
			line = _realloc(line, line_len, line_cap);
			if (line == NULL)
				return (NULL);
		}
		bytes_read = read(fd, buffer, READ_SIZE);
		if (bytes_read == 0 && line_len == 0)
			return (NULL);
		if (bytes_read == 0 || bytes_read == -1)
			break;
		for (i = 0; i < (size_t)bytes_read; i++)
		{
			if (buffer[i] == '\n')
			{
				line[line_len] = '\0';
				return (line);
			}
			line[line_len++] = buffer[i];
		}
	}
	if (line_len == 0)
		return (NULL);
	line[line_len] = '\0';
	return (line);
}
