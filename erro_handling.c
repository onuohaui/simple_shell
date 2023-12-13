#include "headers.h"

/**
 * print_error - prints error messages to stderr
 * @message: error message to print
 */
void print_error(char *message)
{
	write(STDERR_FILENO, message, _strlen(message));
}

/**
 * _strlen - get length of a string
 * @str: string to evaluate
 * Return: length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

