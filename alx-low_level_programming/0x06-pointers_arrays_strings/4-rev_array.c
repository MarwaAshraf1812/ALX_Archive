#include "main.h"
/**
 *reverse_array - revereses an array.
 *@a: pointer to array.
 *@n: number of elements of an array.
 *
 *Return: void.
 */
void reverse_array(int *a, int n)
{
	int cmp, rev, t;

	for (cmp = 0, rev = (n - 1); cmp < rev; cmp++, rev--)
		t = a[cmp];
		a[cmp] = a[rev];
		a[rev] = t;
}
