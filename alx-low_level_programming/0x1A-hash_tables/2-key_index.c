#include "hash_tables.h"
/**
 * key_index - Gives the index of a key.
 * @key: Key
 * @size: Size of the array
 *
 * Return: The index
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_op = hash_djb2(key);

	return (hash_op % size);
}
