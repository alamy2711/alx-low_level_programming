#include "main.h"

/* Prototypes*/
void printCloseError(int close_return);

/**
 * main - A program that displays the information contained
 * in the ELF header at the start of an ELF file
 * @ac: Arguments count
 * @av: Arguments vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	Elf64_Ehdr *elf_header;
	int fd;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(98);
	}

	elf_header = malloc(sizeof(Elf64_Ehdr));

	if (elf_header == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		printCloseError(close(fd));
		exit(98);
	}

	if (read(fd, elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		printCloseError(close(fd));
		exit(98);
	}

	if (elf_header->e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header->e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header->e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header->e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		printCloseError(close(fd));
		exit(98);
	}

	/* Print functions here... */

	printCloseError(close(fd));

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
		exit(98);
	}
}
