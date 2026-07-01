#include "main.h"
#define NULL 0
/**
 * _strchr - function that locates a charachter in string
 * @s: string
 * @c: character
 *
 * Return: pointer o the first ocuurence of the character c in string s
 * or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
