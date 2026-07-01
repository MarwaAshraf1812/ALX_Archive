#include "function_pointers.h"
/**
 * array_iterator - excutes a function given as prmtr on each element of array
 * @size: size of array
 * @array: array to excute function on
 * @action: pointer to the function to use
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array != NULL && action != NULL)
		while (size--)
			action(*array++);
}
