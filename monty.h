#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern stack_t *head;
typedef void (*opcode_func)(stack_t **, unsigned int);

void push_to_stack(stack_t **stack);
void pall_stack(stack_t **stack);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void _errors(int code_error, ...);
void read_file(char *filename);
int parse_line(char *buffer, int ln, int format);
void _opcode_func(char *opcode_, char *value, int ln, int format);
void _op(opcode_func func, char *opcode_, char *value, int ln, int format);


#endif
