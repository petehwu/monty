#include "monty.h"

global_var *gloval = NULL;
/**
 * main - main entry point into program.
 * @argc: number of arguments
 * @argv: list of input parameters
 * Return: 0
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	ssize_t read;
	size_t cread = 0;
	char *buffer = NULL, *opcode = NULL, *val = NULL;
	FILE *fd = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
		clean_up_exit(WRONG_ARGS, &stack);
	gloval = malloc(sizeof(global_var));
	if (!gloval)
		clean_up_exit(MALLOC_FAIL, &stack);
	fd = fopen(argv[1], "r");
	gloval->filename = argv[1];
	gloval->fd = fd;
	gloval->buffer = buffer;
	if (!fd)
		clean_up_exit(FILE_ERR, &stack);
	gloval->fd = fd;
	do {
		read = getline(&buffer, &cread, fd);
		line_number++;
		gloval->buffer = buffer;
		gloval->ln = line_number;
		if (read >= 1)
		{
			opcode = strtok(buffer, " \n");
			val = strtok(NULL, " \n");
			gloval->opcode = opcode;
			gloval->val = val;
			if (!opcode)
				continue;
			get_instt_func(&opcode)(&stack, line_number);
		}
	} while (read >= 1);
	clean_up_exit(0, &stack);
	return (0);
}
