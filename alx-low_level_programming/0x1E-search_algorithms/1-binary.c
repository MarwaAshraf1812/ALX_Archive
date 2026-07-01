#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
/**
 * binary_search - searches array using the Binary search algorithm
 * @array: array of integers
 * @size: size
 * @value: value to be searched for
 * Return: -1 if faliure and the index if success
*/
int binary_search(int *array, size_t size, int value)
{
	size_t l = 0, h = size - 1, i, mid;

	while (l <= h && array != NULL)
	{
		printf("Searching in array: ");
		for (i = l; i <= h; i++)
		{
			if (i == h)
			{
				printf("%d\n", array[i]);
				break;
			}
			printf("%d, ", array[i]);
		}
		mid = l + (h - l) / 2;
		if (array[mid] == value)
		{
			return (mid);
		}
		else if (array[mid] < value)
		{
			l = mid + 1;
		}
		else
		{
			h = mid - 1;
		}
	}
	return (-1);
}
