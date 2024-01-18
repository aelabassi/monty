#include "monty.h"
/**
 * add_dnodeint_end - Adds a new node at the end
 *
 * @head: struct
 *
 * @n: const int
 *
 * Return: dlistint_t
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *list = NULL, *end = *head;

	list = malloc(sizeof(stack_t));

	if (list == NULL)
	{
		return (NULL);
	}
	list->n = n;
	list->prev = NULL;
	list->next = NULL;

	if (*head == NULL)
	{
		*head = list;
		return (*head);
	}

	while (end->next != NULL)
	{
		end = end->next;
	}
	list->prev = end;
	end->next = list;

	return (list);
}
/**
 * add_dnodeint - adds a new node at the beginning of dlistint_t list
 * @head: pointer to dlistint_t node
 * @n: integer
 * Return: the address of the new element, or NULL if it fails
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp, *node = malloc(sizeof(stack_t));


	if (node == NULL)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
		return (*head);
	}
	temp = *head;
	node->next = temp;
	temp->prev = node;
	*head = node;
	return (node);
}

