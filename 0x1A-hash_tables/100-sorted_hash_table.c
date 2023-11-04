#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL
 * Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int i;

	table = malloc(sizeof(shash_table_t));

	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(shash_node_t *) * size);

	if (table->array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		table->array[i] = NULL;

	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0
 * Otherwise - 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *newHashNode, *curr;
	char *valueCopy;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	valueCopy = strdup(value);
	if (valueCopy == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	curr = ht->shead;
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = valueCopy;
			return (1);
		}
		curr = curr->snext;
	}

	newHashNode = malloc(sizeof(shash_node_t));
	if (newHashNode == NULL)
	{
		free(valueCopy);
		return (0);
	}
	newHashNode->key = strdup(key);
	if (newHashNode->key == NULL)
	{
		free(valueCopy);
		free(newHashNode);
		return (0);
	}
	newHashNode->value = valueCopy;
	newHashNode->next = ht->array[idx];
	ht->array[idx] = newHashNode;

	if (ht->shead == NULL)
	{
		newHashNode->sprev = NULL;
		newHashNode->snext = NULL;
		ht->shead = newHashNode;
		ht->stail = newHashNode;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		newHashNode->sprev = NULL;
		newHashNode->snext = ht->shead;
		ht->shead->sprev = newHashNode;
		ht->shead = newHashNode;
	}
	else
	{
		curr = ht->shead;
		while (curr->snext != NULL && strcmp(curr->snext->key, key) < 0)
			curr = curr->snext;
		newHashNode->sprev = curr;
		newHashNode->snext = curr->snext;
		if (curr->snext == NULL)
			ht->stail = newHashNode;
		else
			curr->snext->sprev = newHashNode;
		curr->snext = newHashNode;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 * a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL
 * Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *hashNode;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	hashNode = ht->shead;
	while (hashNode != NULL && strcmp(hashNode->key, key) != 0)
		hashNode = hashNode->snext;

	return ((hashNode == NULL) ? NULL : hashNode->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *hashNode;

	if (ht == NULL)
		return;

	hashNode = ht->shead;
	printf("{");
	while (hashNode != NULL)
	{
		printf("'%s': '%s'", hashNode->key, hashNode->value);
		hashNode = hashNode->snext;
		if (hashNode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *hashNode;

	if (ht == NULL)
		return;

	hashNode = ht->stail;
	printf("{");
	while (hashNode != NULL)
	{
		printf("'%s': '%s'", hashNode->key, hashNode->value);
		hashNode = hashNode->sprev;
		if (hashNode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *hashHead = ht;
	shash_node_t *hashNode, *curr;

	if (ht == NULL)
		return;

	hashNode = ht->shead;
	while (hashNode)
	{
		curr = hashNode->snext;
		free(hashNode->key);
		free(hashNode->value);
		free(hashNode);
		hashNode = curr;
	}

	free(hashHead->array);
	free(hashHead);
}
