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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clean_up_exit(BAD_EXIT, stack);
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
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean_up_exit(BAD_EXIT, stack);
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
 * opc_sub - subtract top element from 2nd element on the stack
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub = 0;

	if (temp && temp->next)
	{
		sub = temp->next->n - temp->n;
		opc_pop(stack, line_number);
		(*stack)->n = sub;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clean_up_exit(BAD_EXIT, stack);
	}
}
/**
 * opc_div - divides 2nd elemnt on the stack by the top element
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int div = 0;

	if (temp && temp->next)
	{
		if (!temp->n)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			clean_up_exit(BAD_EXIT, stack);
		}
		else
		{
			div = temp->next->n / temp->n;
			opc_pop(stack, line_number);
			(*stack)->n = div;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clean_up_exit(BAD_EXIT, stack);

	}
}
