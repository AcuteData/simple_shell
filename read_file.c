#include "main.h"

/**
 * my_strlen - Computes the length of a null-terminated string.
 * @str: Pointer to the string
 *
 * Return: The length of the string
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
 *
 * Return: Void.
 */
void read_file(const char *file_name, int output_fd)
{
	int fd = open(file_name, O_RDONLY);

	if (fd < 0)
	{
		char *error_msg = "open: No such file or directory\n";

		write(STDERR_FILENO, error_msg, my_strlen(error_msg));
		return;
	}
	struct stat st;

	if (fstat(fd, &st) < 0 || !S_ISREG(st.st_mode))
	{
		char *error_msg = "This is not a regular file\n";

		write(STDERR_FILENO, error_msg, my_strlen(error_msg));
		close(fd);
		return;
	}
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(output_fd, buffer, bytes_read) < 0)
		{
			char *error_msg = "write: Failed to write to output file descriptor\n";

			write(STDERR_FILENO, error_msg, my_strlen(error_msg));
			break;
		}
	}
	if (bytes_read < 0)
	{
		char *error_msg = "read: Failed to read file\n";

		write(STDERR_FILENO, error_msg, my_strlen(error_msg));
	}
	close(fd);
}
