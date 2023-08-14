#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints a struct dog
 * @d: The struct dog to print
 */
void print_dog(struct dog *d)
{
	if (d)
	{
		if (d->name)
			printf("Name: %s\n", d->name);
		else
			printf("Name: (nil)");

		if (d->age && d->age != 0)
			printf("Age: %f\n", d->age);
		else
			printf("Age: (nil)");

		if (d->owner)
			printf("Owner: %s\n", d->owner);
		else
			printf("Owner: (nil)");
	}
}
