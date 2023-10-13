#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 * @head: List head
 * @n: The value
 *
 * Return: Address of the newly created node, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode;
	dlistint_t *curr = *head;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return (newNode);
	}

	while (curr->next != NULL)
		curr = curr->next;

	curr->next = newNode;
	newNode->prev = curr;

	return (newNode);
}
