#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list
 * @head: The header of the list_t list
 * @str: String to be add to the new added node
 *
 * Return: The address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *origineHead = *head;
	list_t *newNode;

	newNode = malloc(sizeof(list_t));

	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);
	newNode->len = strlen(str);
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	while ((*head)->next != NULL)
		*head = (*head)->next;

	(*head)->next = newNode;
	*head = origineHead;

	return (newNode);
}
