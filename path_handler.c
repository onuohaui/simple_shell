#include "headers.h"
#include <string.h>

/**
 * resolve_command_path - Resolves the full path of a command.
 * @command: The command to resolve.
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *resolve_command_path(char *command)
{
	char *PATH;
	char *dir;
	char full_path[1024];
	int cmd_found = 0;

	PATH = getenv("PATH");
	if (!PATH)
		return (NULL);

	dir = strtok(PATH, ":");
	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, F_OK) == 0 && access(full_path, X_OK) == 0)
		{
			cmd_found = 1;
			break;
		}
		dir = strtok(NULL, ":");
	}

	if (cmd_found)
		return (strdup(full_path));
	return (NULL);
}

