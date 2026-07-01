#include "main.h"
/**
 *_strcmp - compares two strings.
 *@s1: pointer to first string.
 *@s2: pointer to second string.
 *
 *Return: value less than 0 if string is less than the other.
 *value greater than 0 if string is greater than the other.
 *0 if strings are equal.
 */
int _strcmp(char *s1, char *s2)
{
	int cmp, diff;

	cmp = 0;
	while (s1[cmp] == s2[cmp] && s1[cmp] != '\0')
		cmp++;
	diff = s1[cmp] - s2[cmp];
	return (diff);
}
