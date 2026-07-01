#include "dog.h"
#include <stdlib.h>
/**
 * new_dog - create new struct dog
 * @name: name of the dog
 * @age: its age
 * @owner: name of its owner
 * Return: new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int i, j, k;
	dog_t *nw_dog;

	if (name == NULL || owner == NULL)
		return (NULL);
	nw_dog = malloc(sizeof(dog_t));
	if (nw_dog == NULL)
		return (NULL);
	for (i = 0; name[i]; i++)
		;
	i++;
	nw_dog->name = malloc(i * sizeof(char));
	if (nw_dog->name == NULL)
	{
		free(nw_dog);
		return (NULL);
	}
	for (j = 0; j < i; j++)
		nw_dog->name[j] = name[j];

	nw_dog->age = age;
	for (k = 0; owner[k]; k++)
		k++;
	k++;
	nw_dog->owner = malloc(k * sizeof(char));
	if (nw_dog->owner == NULL)
	{
		free(nw_dog->name);
		free(nw_dog);
		return (NULL);
	}
	for (j = 0; j < k; j++)
		nw_dog->owner[j] = owner[j];
	return (nw_dog);
}
