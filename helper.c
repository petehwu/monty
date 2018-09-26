#include "monty.h"

/**
 * clean_up_exit - cleans up all resources and exits program
 * @e_stat: exit status to use
 * @stack: the stack
 */
void clean_up_exit(int e_stat, stack_t **stack)
{
	if (gloval)
	{
		if (gloval->fd)
			fclose(gloval->fd);
		if (gloval->buffer)
			free(gloval->buffer);
		if (stack && *stack)
			free_stack(stack);
	}
	if (e_stat)
	{
		if (e_stat == WRONG_ARGS)
			fprintf(stderr, "USAGE: monty file\n");
		else if (e_stat == FILE_ERR)
			fprintf(stderr, "Error: Can't open file %s\n", gloval->filename);
		else if (e_stat == INVAL_OP)
			fprintf(stderr, "L%u: unknown instruction %s\n",
					gloval->ln, gloval->opcode);
		else if (e_stat == PUSH_ERR)
			fprintf(stderr, "L%u: usage: push integer\n", gloval->ln);
		else if (e_stat == MALLOC_FAIL)
			fprintf(stderr, "Error: malloc failed\n");
		else if (e_stat == PINT_ERR)
			fprintf(stderr, "L%u: can't pint, stack empty\n", gloval->ln);
		else if (e_stat == POP_ERR)
			fprintf(stderr, "L%u: can't pop an empty stack\n", gloval->ln);
		else if (e_stat == SWAP_ERR)
			fprintf(stderr, "L%u: can't swap, stack too short\n", gloval->ln);
		else if (e_stat == ADD_ERR)
			fprintf(stderr, "L%u: can't add, stack too short\n", gloval->ln);
		if (gloval)
			free(gloval);
		exit(EXIT_FAILURE);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
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
