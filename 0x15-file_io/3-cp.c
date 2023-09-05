#include "main.h"

/* prototypes*/
void printCloseError(int close_return);

/**
 * main - A program that copies the content of a file to another file
 * @ac: Arguments count
 * @av: Arguments vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, numLetters = 1, write_return;
	char *buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		printCloseError(close(fd_to));
		exit(98);
	}

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		printCloseError(close(fd_from));
		exit(99);
	}

	while ((numLetters = read(fd_from, buffer, 1024)) > 0)
	{
		write_return = write(fd_to, buffer, numLetters);

		if (write_return == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			printCloseError(close(fd_from));
			printCloseError(close(fd_to));
			exit(99);
		}
	}

	if (numLetters == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		printCloseError(close(fd_from));
		printCloseError(close(fd_to));
		exit(98);
	}

	printCloseError(close(fd_from));
	printCloseError(close(fd_to));

	return (0);
}

/**
 * printCloseError - Prints the an Error if the close function failed
 * @close_return: Close function's return
 */
void printCloseError(int close_return)
{
	if (close_return == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", close_return);
		exit(100);
	}
}
