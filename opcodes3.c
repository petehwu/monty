#include "monty.h"
/**
 * opc_mul - multiples top element with second element
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mul = 0;

	if (temp && temp->next)
	{
		mul = temp->next->n * temp->n;
		opc_pop(stack, line_number);
		(*stack)->n = mul;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		clean_up_exit(BAD_EXIT, stack);
	}
}



/**
 * opc_mod -  modulo 2nd elemnt on the stack by the top element
 * @stack: pointer to pointer to stack
 * @line_number: linenumber in the file
 */
void opc_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mod = 0;

	if (temp && temp->next)
	{
		if (!temp->n)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			clean_up_exit(BAD_EXIT, stack);
		}
		else
		{
			mod = temp->next->n % temp->n;
			opc_pop(stack, line_number);
			(*stack)->n = mod;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		clean_up_exit(BAD_EXIT, stack);

	}
}
/**
 * opc_pchar - prints the character at the top of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: linenumber in the file
 */
void opc_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		clean_up_exit(BAD_EXIT, stack);
	}
	else
	{
		if (temp->n < 32 || temp->n > 126)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			clean_up_exit(BAD_EXIT, stack);
		}
		else
		{
			printf("%d", temp->n);
		}
		printf("\n");

	}
}
/**
 * opc_pstr - prints the strig starting at the top of the stack
 * @stack: pointer to pointer to top of the stack
 * @line_number: linenumber in the file
 */
void opc_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	if (!temp)
	{
		printf("\n");
	}
	else
	{
		do {
			if (temp->n >= 32 && temp->n <= 126)
				printf("%c", temp->n);

		} while (temp &&  temp->n > 31 && temp->n < 127);
	}

}

