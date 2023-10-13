#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list
 * @h: List head
 *
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t numNodes = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        numNodes++;
    }

    return (numNodes);
}
