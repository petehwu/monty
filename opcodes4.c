#include "monty.h"

/**
 * opc_rotl - top elelment in stack becomes last, 2nd element becomes top
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head = *stack, *temp_tail = gloval->tail;

	(void) line_number;
	if (temp_head && temp_head->next)
	{
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		temp_tail->next = temp_head;
		temp_head->next = NULL;
		temp_head->prev = temp_tail;
		gloval->tail = temp_head;
	}
}
/**
 * opc_rotr - last element becomes top, everything else shifts over
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head = *stack, *temp_tail = gloval->tail;

	(void) line_number;
	if (temp_head && temp_head->next)
	{
		gloval->tail = temp_tail->prev;
		temp_head->prev = temp_tail;
		temp_tail->next = temp_head;
		temp_tail->prev->next = NULL;
		temp_tail->prev = NULL;
		*stack = temp_tail;
	}
}
/**
 * opc_stack - change to stack operation
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	gloval->is_stack = 1;
}
/**
 * opc_queue - change to queue operation
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	gloval->is_stack = 0;
}
