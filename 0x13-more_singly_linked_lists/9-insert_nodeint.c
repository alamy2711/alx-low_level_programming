#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: The head of the listint_t list
 * @idx: Index where to insert the new node
 * @n: Data to add to the new added node
 *
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newNode;
	listint_t *originHead = *head;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = get_nodeint_at_index(*head, idx);
	*head = get_nodeint_at_index(*head, idx - 1);

	if (newNode->next == NULL || *head == NULL)
	{
		*head = originHead;
		free(newNode);
		return (NULL);
	}

	(*head)->next = newNode;
	*head = originHead;

	return (newNode);
}

/* Helper Function */

/**
 * get_nodeint_at_index - Gets the nth node of a listint_t linked list
 * @head: The head of the listint_t list
 * @index: The idndex to search for
 *
 * Return: The nth node of a listint_t linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	for (i = 0; head != NULL && i != index; i++)
		head = head->next;

	if (i != index)
		return (NULL);

	return (head);
}

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list
 * @head: The header of listint_t list
 * @n: The integer to add to the new added node
 *
 * Return: The address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = *head;
	*head = newNode;

	return (newNode);
}
