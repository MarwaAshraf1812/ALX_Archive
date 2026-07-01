#include "main.h"
/**
*_strcat - function that concatenates two strings.
*@dest: pointer to destination string.
*@src: pointer to source string.
*
*Return: pointer to destination string.
 */
char *_strcat(char *dest, char *src)
{
	int l, c;

	l = 0;
	while (dest[l])
		l++;
	for (c = 0; src[c]; c++)
		dest[l++] = src[c];
	return (dest);
}
