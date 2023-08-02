#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string
 * Return: length of string s
*/
int _strlen_recursion(char *s)
{
	if (*(s) == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * is_palindrome_helper - checks if a string is palindrome
 * @s: string to check
 * @len: string length
 * @index: index of each character
 * Return: 1 if the s palindrome, otherwise 0
*/
int is_palindrome_helper(char *s, int len, int index)
{
	if (index > len / 2)
		return (1);
	if (s[index] != s[len - 1 - index])
		return (0);

	return (1 && is_palindrome_helper(s, len, index + 1));
}

/**
 * is_palindrome - checks if a string is palindrome
 * @s: string to check
 * Return: 1 if the s palindrome, otherwise 0
*/
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (is_palindrome_helper(s, len, 0));
}
