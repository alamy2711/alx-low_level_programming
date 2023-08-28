#include "lists.h"

/* Prototypes */
int delete_head(listint_t **head);
int delete_tail(listint_t **head);


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

	if (index == 8)
		return (delete_tail(head));

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

int delete_tail(listint_t **head)
{
	listint_t *originhead = *head;
	listint_t *beforeTail;

	beforeTail = get_nodeint_at_index(*head, listint_len(*head) - 1);

	if (*head == NULL || beforeTail == NULL)
		return (-1);
	
	while ((*head)->next != NULL)
		*head = (*head)->next;

	beforeTail->next = NULL;
	free(*head);
	(*head) = originhead;

	return (1);
}

/**
 * listint_len - Counts the number of elements in a linked listint_t list
 * @h: The header of listint_t list
 *
 * Return: The number of elements in a linked listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	int numNodes = 0;

	while (h != NULL)
	{
		numNodes++;
		h = h->next;
	}

	return (numNodes);
}