#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocates memory for array
 * @nmemb: number of elements in array
 * @size: size of elements
 * Return: void printer to array
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *c;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	c = malloc(nmemb * size);
	if (c == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		c[i] = 0;
	return (c);
}
