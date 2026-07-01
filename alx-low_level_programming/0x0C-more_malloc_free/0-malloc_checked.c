#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - allocates memory
 * @b: number of byte to be malloced
 * Return: pointer, 98 if fails
 */
void *malloc_checked(unsigned int b)
{
	int *n;

	n = malloc(b);

	if (n == NULL)
		exit(98);
	return (n);
}
