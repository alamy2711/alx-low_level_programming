#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in list
 * @h: List head
 * @idx: Index
 * @n: Value
 *
 * Return: The ddress of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newNode, *tmp = *h;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;
	newNode->prev = NULL;

	while (i < idx - 1)
	{
		if (tmp == NULL)
		{
			free(newNode);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}

	newNode->next = tmp->next;
	newNode->prev = tmp;

	if (tmp->next != NULL)
		tmp->next->prev = newNode;

	tmp->next = newNode;

	return (newNode);
}
