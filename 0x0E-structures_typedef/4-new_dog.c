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
	dog_name = malloc((strlen(name) + 1) * sizeof(char));
	dog_owner = malloc((strlen(owner) + 1) * sizeof(char));

	if (dog == NULL || dog_name == NULL || dog_owner == NULL)
	{
		free(dog_name);
		free(dog_owner);
		return (NULL);
	}

	strcpy(dog_name, name);
	strcpy(dog_owner, owner);

	dog->name = dog_name;
	dog->age = age;
	dog->owner = dog_owner;

	return (dog);
}
