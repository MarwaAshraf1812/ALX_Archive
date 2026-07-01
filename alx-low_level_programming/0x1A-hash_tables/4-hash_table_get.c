#include "hash_tables.h"
/**
 * hash_table_ - Adds an element to the hash table
 * @ht: the hash table
 * @key: Key
 *
 * Return: Value, NULL otherwise
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *current_node;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	current_node = ht->array[index];


	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			return (current_node->value);
		}
		current_node = current_node->next;
	}
	return (NULL);
}
