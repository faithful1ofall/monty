#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>

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

/**
 * struct fvar_s - variables -args, file, line content
 * @ag: value
 * @file: pointer to monty file
 * @con: line content
 * @fque: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct fvar_s
{
	char *ag;
	FILE *file;
	char *con;
	int fque;
}  fvar_t;

int fexe(char *, stack_t, size_t, FILE *);
void f_push(stack_t, unsigned int);
void f_pall(stack_t, unsigned int);

#endif /* MONTY_H */
