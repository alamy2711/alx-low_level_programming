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

	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n",
		   elf_header->e_ident[EI_MAG0], elf_header->e_ident[EI_MAG1],
		   elf_header->e_ident[EI_MAG2], elf_header->e_ident[EI_MAG3]);
	printf("  Class:                             %s\n",
		   elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
		   elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
		   elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "UNIX - System V");
	printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
		   elf_header->e_type == ET_EXEC ? "EXEC (Executable file)" : "EXEC (Executable file)");
	printf("  Entry point address:               0x%lx (bytes into file)\n", elf_header->e_entry);
	printf("  Start of program headers:          %d (bytes into file)\n", (int)elf_header->e_phoff);
	printf("  Start of section headers:          %d (bytes into file)\n", (int)elf_header->e_shoff);
	printf("  Flags:                             0x%x\n", elf_header->e_flags);
	printf("  Size of this header:               %d (bytes)\n", elf_header->e_ehsize);
	printf("  Size of program headers:           %d (bytes)\n", elf_header->e_phentsize);
	printf("  Number of program headers:         %d\n", elf_header->e_phnum);
	printf("  Size of section headers:           %d (bytes)\n", elf_header->e_shentsize);
	printf("  Number of section headers:         %d\n", elf_header->e_shnum);
	printf("  Section header string table index: %d\n", elf_header->e_shstrndx);

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
