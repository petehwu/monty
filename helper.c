#include "monty.h"

/**
 * clean_up_exit - cleans up all resources and exits program
 * @e_stat: exit status to use
 * @stack: the stack
 */
void clean_up_exit(int e_stat, stack_t **stack)
{
	if (e_stat == WRONG_ARGS)
		fprintf(stderr, "USAGE: monty file\n");
	else if (e_stat == FILE_ERR)
		fprintf(stderr, "Error: Can't open file %s\n", gloval->filename);
	else if (e_stat == MALLOC_FAIL)
		fprintf(stderr, "Error: malloc failed\n");
	if (gloval)
	{
		if (gloval->fd)
			fclose(gloval->fd);
		if (gloval->buffer)
			free(gloval->buffer);
		if (stack && *stack)
			free_stack(stack);
		free(gloval);
	}
	if (e_stat == GOOD_EXIT)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
/**
 * free_stack - frees all nodes in the  stack
 * @stack: the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack, *tempnext;

	if (temp)
	{
		do {
			tempnext = temp->next;
			free(temp);
			temp = tempnext;
		} while (tempnext);
	}
}
