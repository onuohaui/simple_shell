#include "headers.h"

/**
 * execute_command - Execute a given command.
 * @line: Command to execute.
 * Return: 0 is successful and 1 if not successful
 */
int execute_command(char *line)
{
	pid_t child_pid;
	int status;
	char **args = parse_input(line);

	/* Handle built-in commands */
	if (is_builtin(args[0]))
	{
		execute_builtin(args[0]);
		free(args);
		return (2);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		}
	}
	else if (child_pid < 0)
	{
		perror("Error forking");
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(args);
		return (WEXITSTATUS(status));
	}
	return (0);
}

