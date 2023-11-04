#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *hashNode;
	unsigned long int i;
	unsigned char separator = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (separator == 1)
				printf(", ");

			hashNode = ht->array[i];

			while (hashNode != NULL)
			{
				printf("'%s': '%s'", hashNode->key, hashNode->value);
				hashNode = hashNode->next;

				if (hashNode != NULL)
					printf(", ");
			}
			separator = 1;
		}
	}
	printf("}\n");
}
