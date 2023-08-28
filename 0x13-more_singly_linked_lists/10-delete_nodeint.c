#include "lists.h"

/* Prototypes */
int delete_head(listint_t **head);

/**
 * delete_nodeint_at_index - Deletes the node at index index
 * of a listint_t linked list
 * @head: Head of the listint_t list
 * @index: Index where to delete the node
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *originhead = *head;
	listint_t *deletedNode;
	listint_t *nextNode;

	if (index == 0)
		return (delete_head(head));

	deletedNode = get_nodeint_at_index(*head, index);
	nextNode = get_nodeint_at_index(*head, index + 1);
	*head = get_nodeint_at_index(*head, index - 1);

	if (deletedNode == NULL || nextNode == NULL || *head == NULL)
	{
		*head = originhead;
		return (-1);
	}

	free(deletedNode);
	(*head)->next = nextNode;
	*head = originhead;

	return (1);
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
 * delete_head - Deletes the head node of a listint_t linked list
 * @head: The header of listint_t list
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_head(listint_t **head)
{
	listint_t *secondNode;

	if (*head == NULL)
		return (-1);

	secondNode = (*head)->next;
	free(*head);
	(*head) = secondNode;

	return (1);
}
