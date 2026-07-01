#include "main.h"
/**
 * _memset - function that fills memory with a constant byte
 * @s: memory area pointed to by s
 * @b: constant value
 * @n: nulber of byte
 * Return: pointer to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	int size = n;

	if (size > 0)
	{
		int u;

		for (u = 0; u < size; u++)
		{
			s[u] = b;
		}
	}
	return (s);
}
