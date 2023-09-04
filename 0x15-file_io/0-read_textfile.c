#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Path of the file
 * @letters: Number of letters it should read and print
 *
 * Return: The actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, write_return, numLetters;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(letters * sizeof(char));

	if (buffer == NULL)
		return (0);

	numLetters = read(fd, buffer, letters);
	if (numLetters == -1)
	{
		free(buffer);
		return (0);
	}

	write_return = write(STDOUT_FILENO, buffer, numLetters);

	if (write_return == -1)
	{
		free(buffer);
		return (0);
	}

	close(fd);

	return (write_return);
}
