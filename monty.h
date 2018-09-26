#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define WRONG_ARGS 1
#define FILE_ERR 2
#define INVAL_OP 3
#define PUSH_ERR 4
#define MALLOC_FAIL 5
#define PINT_ERR 6
#define POP_ERR 7
#define SWAP_ERR 8
#define ADD_ERR 9
/** struct global_var - global varariable holding pointers to everything needed
 * @val: pointer to integer
 * @fd: file stream
 * @buffer: pointer to the buffer
 * @ln: linenumber
 * @e_stat: exit status
 * @filename: pointer to filename
 * @opcode: pointer to opcode
 */
typedef struct global_var
{
	char *filename;
	FILE *fd;
	char *buffer;
	unsigned int ln;
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

void (*get_instt_func(char **s))(stack_t **stack, unsigned int line_number);
void  opc_push(stack_t **stack, unsigned int line_number);
void  opc_pall(stack_t **stack, unsigned int line_number);
void  opc_pint(stack_t **stack, unsigned int line_number);
void  opc_pop(stack_t **stack, unsigned int line_number);
void  opc_swap(stack_t **stack, unsigned int line_number);
void  opc_add(stack_t **stack, unsigned int line_number);
void  opc_nop(stack_t **stack, unsigned int line_number);
void  opc_notfound(stack_t **stack, unsigned int line_number);
void  clean_up_exit(int e_stat, stack_t **stack);
void free_stack(stack_t **stack);

#endif /* MONTY_H */
