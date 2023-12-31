#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if the file exists. otherwise -1 if it fails.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int n;
	int j;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (n = 0; text_content[n]; n++)
			;

		j = write(fd, text_content, n);

		if (j == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
