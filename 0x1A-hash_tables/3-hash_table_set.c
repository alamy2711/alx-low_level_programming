
#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *newHashNode;
	char *valueCopy;
	unsigned long int idx, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	valueCopy = strdup(value);
	if (valueCopy == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	for (i = idx; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = valueCopy;
			return (1);
		}
	}

	newHashNode = malloc(sizeof(hash_node_t));
	if (newHashNode == NULL)
	{
		free(valueCopy);
		return (0);
	}
	newHashNode->key = strdup(key);
	if (newHashNode->key == NULL)
	{
		free(newHashNode);
		return (0);
	}
	newHashNode->value = valueCopy;
	newHashNode->next = ht->array[idx];
	ht->array[idx] = newHashNode;

	return (1);
}
