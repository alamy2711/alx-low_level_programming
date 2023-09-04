#include "main.h"

/**
 * create_file - Creates a file
 * @filename: File name
 * @text_content: Text content
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, write_return;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT, 0600);

	if (fd == -1)
		return (-1);

	write_return = write(fd, text_content, strlen(text_content));

	if (write_return == -1)
		return (-1);

	return (1);
}
