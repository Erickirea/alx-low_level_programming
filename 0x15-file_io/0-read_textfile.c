#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to be read
 * @letters: the number of letters to be read and print
 *
 * Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t lenrt, lenwt;
	char *buffer = malloc(letters);

	if (filename == NULL)
		return (0); /*if filename is NULL*/
	if (buffer == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	lenrt = read(fd, buffer, letters);
	if (lenrt == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	close(fd);

	lenwt = write(STDOUT_FILENO, buffer, lenrt);
	if (lenwt == -1)
	{
		free(buffer);
	}
		return (lenwt);
}


