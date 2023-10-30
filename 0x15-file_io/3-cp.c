#include "main.h"

/**
 * error_exit - handle errors and exit with a given code.
 * @msg: the error message to print.
 * @code: the exit code.
 */
void error_exit(const char *msg, int code)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * main - Copies the content of one file to another file.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 * Return: 0 on success, other exit codes on error.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
		error_exit("Usage: cp file_from file_to", 97);

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (file_from == -1 || file_to == -1)
		error_exit((file_from == -1)
				? "Error: Can't read from file"
				: "Error: Can't write to file",
				(file_from == -1) ? 98 : 99);

	while ((nchars = read(file_from, buf, 1024)) > 0)
	{
		if (nchars == -1)
			error_exit("Error: Can't read from file", 98);
		nwr = write(file_to, buf, nchars);
		if (nwr == -1)
			error_exit("Error: Can't write to file", 99);
	}

	if (close(file_from) == -1 || close(file_to) == -1)
		error_exit("Error: Can't close fd", 100);

	return (0);
}
