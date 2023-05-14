#include "main.h"

/**
 * my_strlen - Computes the length of a null-terminated string.
 * @str: Pointer to the string.
 *
 * Return: The length of the string.
 */
size_t my_strlen(const char *str)
{
	size_t i = 0;

	while (*str++)
	{
		i++;
	}
	return (i);
}

/**
 * read_file - Reads and writes the contents of a file to standard output.
 * @file_name: Name of the file to read.
 * @buffer: Pointer to a buffer where the contents of the file will be stored.
 * @buf: Size of the buffer.
 *
 * Return: Number of bytes read.
 */
ssize_t read_file(const char *file_name, char **buffer, size_t buf)
{
	struct stat st;
	size_t t_b_read = 0;
	ssize_t bytes_read;

	int fd = open(file_name, O_RDONLY);

	if (fd < 0)
	{
		perror("open");
		return (-1);
	}

	if (fstat(fd, &st) < 0 || !S_ISREG(st.st_mode))
	{
		perror("fstat");
		close(fd);
		return (-1);
	}

	*buffer = malloc(buf * sizeof(char));

	if (*buffer == NULL)
	{
		perror("malloc");
		close(fd);
		return (-1);
	}

	while ((bytes_red = read(fd, *buffer + t_b_read, buf - t_b_read)) > 0)
	{
		t_b_read += bytes_read;

		if (t_b_read >= buf)
		{
			break;
		}
		if (bytes_read < 0)
		{
			perror("read");
			free(*buffer);
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (t_b_read);
}
