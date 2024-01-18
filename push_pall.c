#include "monty.h"

/**
 * push_to_stack - adds a node on top of the stack
 * @stack: stack of doubly linked lists
*/

void push_to_stack(stack_t **stack)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *stack;
		return;
	}
	tmp = head;
	head = *stack;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pall_stack - prints all the values on the stack,
 * starting from top of the stack
 * @stack: stack of doubly linked lists
*/
void pall_stack(stack_t **stack)
{
	stack_t *tmp;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

