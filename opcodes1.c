#include "monty.h"
/**
 * get_instt_func - wrapper function to get the correct opcode function
 * @s: opcode to search for
 * Return: 0 if successful, 1 if failed
 */
void (*get_instt_func(char **s))(stack_t **stack, unsigned int line_number)
{
	instruction_t instt[] = {
		{"push", opc_push},
		{"pall", opc_pall},
		{"pint", opc_pint},
		{"pop", opc_pop},
		{"swap", opc_swap},
		{"add", opc_add},
		{"nop", opc_nop},
		{NULL, opc_notfound}
	};
	int i = 0;

	while (instt[i].opcode)
	{
		if (strcmp(instt[i].opcode, s[0]) == 0)
			return (instt[i].f);
		i++;

	}
	return (instt[i].f);
}
/**
 * opc_push - pushes a value onto the stack
 * @stack: pointer to pointer of stack
 * @line_number: linenumber in the file
 * Return: 0 if successful or PUSH_ERR if operation fails
 */
void opc_push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *newnode;
	int i = 0;

	if (!gloval->val)
		clean_up_exit(PUSH_ERR, stack);
	while (gloval->val[i])
	{
		if (gloval->val[i] < '0' || gloval->val[i] > '9')
			clean_up_exit(PUSH_ERR, stack);
		i++;
	}
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
		clean_up_exit(MALLOC_FAIL, stack);
	newnode->n = atoi(gloval->val);
	newnode->prev = NULL;
	if (!*stack)
	{
		newnode->next = NULL;
		*stack = newnode;
	}
	else
	{
		newnode->next = *stack;
		*stack = newnode;
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
	(void) line_number;
	stack_t *temp = *stack;

	if (temp)
		printf("%d\n", temp->n);
	else
	{
		clean_up_exit(PINT_ERR, stack);
	}
}

/**
 * opc_pop - remove top element from the stack
 * @stack: pointer to pointer of stack
 * @line_number: linenumber in the file
 */
void opc_pop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *temp = *stack;

	if (temp)
	{
		if (temp->next)
		{
			temp->next->prev = NULL;
			*stack = temp->next;
		}
		else
		{
			*stack = NULL;
		}
		free(temp);
	}
	else
	{
		clean_up_exit(POP_ERR, stack);
	}
}
