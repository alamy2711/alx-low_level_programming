#include "3-calc.h"

/**
 * get_op_func - Selects the correct function
 * to perform the operation asked by the user
 * @s: The operator
 *
 * Return: Pointer to the function that corresponds to the operator given in s
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}};
	int i;

	i = 0;
	while (i < 5)
	{
		if (ops[i].op[0] == *s)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
