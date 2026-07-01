#include <stdlib.h>
#include "main.h"
/**
 * array_range - creates array of integers from min to max
 * @min: minimum int in array
 * @max: maximum int in array
 *
 * Return: pointer to array or null
 */

int *array_range(int min, int max)
{
	int *a;
	int i, size;

	if (min > max)
		return (NULL);
	size = (max - min) + 1;
	a = malloc(sizeof(int) * size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		a[i] = min++;
	return (a);
}
