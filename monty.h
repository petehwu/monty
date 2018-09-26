#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GOOD_EXIT 0
#define BAD_EXIT 1
#define WRONG_ARGS 2
#define FILE_ERR 3
#define MALLOC_FAIL 4
/**
 * struct global_var - global varariable holding pointers to everything needed
 * @val: pointer to integer
 * @fd: file stream
 * @buffer: pointer to the buffer
 * @filename: pointer to filename
 * @opcode: pointer to opcode
 */
typedef struct global_var
{
	char *filename;
	FILE *fd;
	char *buffer;
	char *opcode;
	char *val;
} global_var;
extern global_var *gloval;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_instt_func(char **s, stack_t **stack, unsigned int
	line_number))(stack_t **stack, unsigned int line_number);
void opc_push(stack_t **stack, unsigned int line_number);
void opc_pall(stack_t **stack, unsigned int line_number);
void opc_pint(stack_t **stack, unsigned int line_number);
void opc_pop(stack_t **stack, unsigned int line_number);
void opc_swap(stack_t **stack, unsigned int line_number);
void opc_add(stack_t **stack, unsigned int line_number);
void opc_nop(stack_t **stack, unsigned int line_number);
void opc_mul(stack_t **stack, unsigned int line_number);
void opc_mod(stack_t **stack, unsigned int line_number);
void opc_pchar(stack_t **stack, unsigned int line_number);
void opc_pstr(stack_t **stack, unsigned int line_number);
void opc_sub(stack_t **stack, unsigned int line_number);
void opc_div(stack_t **stack, unsigned int line_number);

void  clean_up_exit(int e_stat, stack_t **stack);
void free_stack(stack_t **stack);

#endif /* MONTY_H */
