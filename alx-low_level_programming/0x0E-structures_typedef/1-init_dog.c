#include "dog.h"

/**
 * init_dog - intialize a variable of tupe struct dog
 * @d: new variable struc dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * Return: woid
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
