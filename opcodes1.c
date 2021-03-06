#include "monty.h"
/**
 * get_instt_func - wrapper function to get the correct opcode function
 * @s: opcode to search for
 * @stack: pointer to pointer to the stack
 * @line_number: the line_number that is being processed
 * Return: 0 if successful, 1 if failed
 */
void (*get_instt_func(char **s, stack_t **stack, unsigned int line_number))(
		stack_t **stack, unsigned int line_number)
{
	instruction_t instt[] = {
		{"push", opc_push},
		{"pall", opc_pall},
		{"pint", opc_pint},
		{"pop", opc_pop},
		{"swap", opc_swap},
		{"add", opc_add},
		{"nop", opc_nop},
		{"mul", opc_mul},
		{"mod", opc_mod},
		{"pchar", opc_pchar},
		{"pstr", opc_pstr},
		{"sub", opc_sub},
		{"div", opc_div},
		{"rotl", opc_rotl},
		{"rotr", opc_rotr},
		{"stack", opc_stack},
		{"queue", opc_queue},
		{NULL, NULL}
	};
	int i = 0;

	while (instt[i].opcode)
	{
		if (strcmp(instt[i].opcode, s[0]) == 0)
			return (instt[i].f);
		i++;

	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, s[0]);
	clean_up_exit(BAD_EXIT, stack);
	return (NULL);
}
/**
 * opc_push - pushes a value onto the stack
 * @stack: pointer to pointer of stack
 * @line_number: linenumber in the file
 * Return: 0 if successful or PUSH_ERR if operation fails
 */
void opc_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode, *old_tail = gloval->tail;

	check_val(stack, line_number);
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
		clean_up_exit(MALLOC_FAIL, stack);
	newnode->n = atoi(gloval->val);
	if (!*stack)
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		*stack = newnode;
		gloval->tail = newnode;
	}
	else
	{
		if (gloval->is_stack == 1)
		{
			(*stack)->prev = newnode;
			newnode->next = *stack;
			*stack = newnode;
		}
		else
		{
			gloval->tail = newnode;
			old_tail->next = newnode;
			newnode->prev = old_tail;
			newnode->next = NULL;

		}
	}
}

/**
 * opc_pall - prints all values in the stack
 * @stack: pointer to pointer of stack
 * @line_number: linenumber in the file
 */
void opc_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	if (temp)
	{
		do {
			printf("%d\n", temp->n);
			temp = temp->next;
		} while (temp);
	}
}

/**
 * opc_pint - prints the value at the top of the stack
 * @stack: pointer to pointer of stack
 * @line_number: linenumber in the file
 */
void opc_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	if (temp)
		printf("%d\n", temp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		clean_up_exit(BAD_EXIT, stack);
	}
}

/**
 * opc_pop - remove top element from the stack
 * @stack: pointer to pointer of stack
 * @line_number: linenumber in the file
 */
void opc_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	if (temp)
	{
		if (temp->next)
		{
			temp->next->prev = NULL;
			*stack = temp->next;
		}
		else
		{
			gloval->tail = NULL;
			*stack = NULL;
		}
		free(temp);

	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		clean_up_exit(BAD_EXIT, stack);
	}
}
