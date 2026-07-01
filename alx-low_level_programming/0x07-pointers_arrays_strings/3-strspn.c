#include "main.h"
/**
 * _strspn - function that get the length of the prefix substring
 * @s: string
 * @accept: prefix
 * Return: number of byte
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0;
	int j;
	int numbyte = 0;

	while (s[i] != '\0')
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
			numbyte++;
			break;
			}
			if (accept[j + 1] == '\0' && s[i] != accept[j])
			return (numbyte);
		}
	i++;
	}
	return (numbyte);
}
