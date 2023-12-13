#include "headers.h"

/**
 * main - Entry point to the simple shell.
 * @argc: Number of arguments passed.
 * @argv: Arguments passed to the program.
 *
 * Return: 0 on success, other values on various failures.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int statbar;

	(void)argc; /* Unused parameter */
	(void)argv; /* Unused parameter */

	while (1)
	{
		/* display_prompt(); */
		read = getline(&line, &len, stdin);
		if (read == -1) /* Ctrl+D pressed */
			break;
		statbar = execute_command(line);
		if (statbar == 1)
		{
			free(line);
			return (127);
		}
		else if (statbar == 2)
		{
			free(line);
			return (2);
		}
	}
	free(line);
	return (0);
}


