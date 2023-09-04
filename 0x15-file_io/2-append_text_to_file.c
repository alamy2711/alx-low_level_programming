#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: File name
 * @text_content: Text content
 *
 * Return: 1 if the file exists and -1 if the file does not exist
 * or if you do not have the required permissions to write the file
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_return;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);

	if (fd == -1)
	{
		close(fd);
		return (-1);
	}

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	write_return = write(fd, text_content, strlen(text_content));

	if (write_return == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
