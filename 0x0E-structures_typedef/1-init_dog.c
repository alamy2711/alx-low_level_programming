#include "dog.h"

/**
 * init_dog - initialize a variable of type struct dog
 * @d: The variable of type struct dog to initialize
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
