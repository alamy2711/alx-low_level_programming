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
	char *dog_name, *dog_owner;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog_name = malloc((strlen(name) + 1) * sizeof(char));
	if (dog_name == NULL)
	{
		free(dog_name);
		return (NULL);
	}

	dog_owner = malloc((strlen(owner) + 1) * sizeof(char));
	if (dog_owner == NULL)
	{
		free(dog_name);
		free(dog_owner);
		return (NULL);
	}

	dog->name = strcpy(dog_name, name);
	dog->age = age;
	dog->owner = strcpy(dog_owner, owner);

	return (dog);
}
