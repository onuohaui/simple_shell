#include "headers.h"
#include <string.h>

/**
 * parse_input - parse the user's input to separate the command
 * @line: input line from the user
 * Return: command without trailing newline or spaces
 */
char **parse_input(char *line)
{
	int buffer_size = 64;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char **new_tokens;
	char *token;

	if (!tokens)
	{
		print_error("Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n\t\r\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffer_size)
		{
			buffer_size += 64;
			new_tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!new_tokens)
			{
				free(tokens);
				print_error("Allocation error\n");
				exit(EXIT_FAILURE);
			}
			tokens = new_tokens;
		}

		token = strtok(NULL, " \n\t\r\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

