#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: The header of the list_t list
 * @str: String to be add to the new added node
 *
 * Return: The address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *curr = *head;
	list_t *newNode;

	newNode = malloc(sizeof(list_t));

	if (newNode == NULL)
		return (NULL);
	newNode->str = strdup(str);
	newNode->len = strlen(str);
	newNode->next = *head;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	while (curr->next != NULL)
		curr = curr->next;

	*head = newNode;

	return (newNode);
}
