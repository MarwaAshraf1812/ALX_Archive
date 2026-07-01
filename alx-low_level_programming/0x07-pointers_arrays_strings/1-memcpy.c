#include "main.h"
/**
 * _memcpy - function that copies memory area
 * @dest: destination
 * @src: source
 * @n: number of bytes
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int size = n;
	int k;

	for (k = 0; k < size; k++)
	{
		dest[k] = src[k];
	}
	return (dest);
}
