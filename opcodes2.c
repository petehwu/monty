#include "monty.h"
/**
 * opc_swap - swaps top two element from the stack
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_swap(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *temp = *stack, *tempnext;

	if (temp && temp->next)
	{
		tempnext = temp->next;
		temp->next = tempnext->next;
		tempnext->next = temp;
		temp->prev = tempnext;
		tempnext->prev = NULL;
		if (temp->next)
			temp->next->prev  = temp;
		*stack = tempnext;
	}
	else
	{
		clean_up_exit(SWAP_ERR, stack);
	}
}
/**
 * opc_add - adds the top 2element from the stack
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0;

	if (temp && temp->next)
	{
		sum = temp->n + temp->next->n;
		opc_pop(stack, line_number);
		(*stack)->n = sum;
	}
	else
	{
		clean_up_exit(ADD_ERR, stack);
	}
}
/**
 * opc_nop -  function does nothing
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * opc_notfound - dummy function when opcode is not found
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_notfound(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	clean_up_exit(INVAL_OP, stack);
}
