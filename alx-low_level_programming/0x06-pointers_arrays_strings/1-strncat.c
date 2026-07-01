#include "main.h"
/**
 *_strncat - function that concatenates two strings. it will use
 * at most n bytes from src. src does not need to be null terminated.
 *@dest: pointer to destination string.
 *@src: pointer to source string.
 *@n: number of bytes to be concatenated.
 *
 *Return: pointer to destination string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int l, c;

	l = 0;
	while (dest[l])
		l++;
	for (c = 0; c < n && src[c] != '\0'; c++)
		dest[l + c] = src[c];
	dest[l + c] = '\0';
	return (dest);
}
