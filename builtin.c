#include "headers.h"

/**
 * is_builtin - Check if the command is a built-in command.
 * @command: Command to check.
 *
 * Return: 1 if built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	if (_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

/**
 * execute_builtin - Execute the built-in command.
 * @command: Built-in command to execute.
 */
void execute_builtin(char *command)
{
	if (_strcmp(command, "exit") == 0)
		exit(0);
}

/**
 * _strcmp - Compare two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Difference between the two strings.
 */
int _strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

