#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars
 * @size: size of array
 * @c: char to initialize array with
 * Return: pointer to the array, NULL if fails
 */
char *create_array(unsigned int size, char c)
{
	char *n = malloc(size);

	if (n == 0 || size == 0)
		return (NULL);
	while (size--)
		n[size] = c;
	return (n);
}
