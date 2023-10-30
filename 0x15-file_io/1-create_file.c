#include "main.h"

/**
 * create_file - Create a file and write text content.
 * @filename: Name of the file to create.
 * @text_content: string to write to the file.
 *
 * Return: 1 for success, otherwise -1.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int n;
	int j;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (n = 0; text_content[n]; n++)
		;

	j = write(fd, text_content, n);

	if (j == -1)
		return (-1);

	close(fd);

	return (1);
}
