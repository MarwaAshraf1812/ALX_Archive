#include "main.h"
#define NULL 0
/**
 * _strpbrk - function that searches a string for any of a set of bytes
 * @s: string
 * @accept: bytes
 * Return: pointer to the byte in s
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0;
	int j = 0;

	while (s[i] != '\0')
	{
		for (j = 0; accept[j] != 0; j++)
		{
			if (s[i] == accept[j])
				return (&s[i]);
		}
	i++;
	}
	return (NULL);
}
