#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees dogs
 * @d: The struct dog to free
 */
void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
