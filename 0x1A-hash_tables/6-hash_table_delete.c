
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hashHead = ht;
	hash_node_t *hashNode, *curr;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			hashNode = ht->array[i];

			while (hashNode != NULL)
			{
				curr = hashNode->next;
				free(hashNode->key);
				free(hashNode->value);
				free(hashNode);
				hashNode = curr;
			}
		}
	}
	free(hashHead->array);
	free(hashHead);
}
