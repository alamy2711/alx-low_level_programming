#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - Creates a new dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 *
 * Return: New dog, otherwise NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc((strlen(name) + 1) * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog->name);
		return (NULL);
	}

	dog->owner = malloc((strlen(owner) + 1) * sizeof(char));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog->owner);
		return (NULL);
	}

	dog->name = strcpy(dog->name, name);
	dog->age = age;
	dog->owner = strcpy(dog->owner, owner);

	return (dog);
}
