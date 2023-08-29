#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list
 * @head: Head of the listint_t list
 *
 * Return: A pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *currNode = *head;
	listint_t *nextNode;

	if (head == NULL || *head == NULL)
		return (NULL);

	if ((*head)->next == NULL)
		return (*head);

	*head = (*head)->next;
	nextNode = (*head)->next;
	currNode->next = NULL;

	while (*head != currNode)
	{
		(*head)->next = currNode;
		currNode = *head;

		if (nextNode != NULL)
		{
			*head = nextNode;
			nextNode = nextNode->next;
		}
	}

	return (*head);
}
