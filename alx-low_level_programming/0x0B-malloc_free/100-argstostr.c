#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all arguments
 * @ac: number of argument
 * @av: double pointer arguments
 * Return: pointer to new string, NULL if fails
 */
char *argstostr(int ac, char **av)
{
	int i, j, c = 0, b = 0;

	char *ns;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			c++;
		c++;
	}
	c++;
	ns = malloc(c * sizeof(char));
	if (ns == NULL)
		return (NULL);
	for (i = 0; i < ac ; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			ns[b] = av[i][j];
			b++;
		}
		ns[b] = '\n';
		b++;
	}
	ns[b] = '\0';
	return (ns);
}
