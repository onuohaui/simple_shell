#ifndef HEADERS_H
#define HEADERS_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* function prototypes */
void display_prompt(void);
int execute_command(char *command);

/* ... Previous content ... */

/* function prototypes for error_handling.c */
void print_error(char *message);
int _strlen(char *str);

/* function prototypes for parse_input.c */
char **parse_input(char *line);

/* function prototypes for builtin.c */
int is_builtin(char *command);
void execute_builtin(char *command);
int _strcmp(char *s1, char *s2);

/* function prototypes for wait.c */
void wait_for_child(pid_t pid);

/* function prototypes for path_handler.c */
char *resolve_command_path(char *command);

#endif /* HEADERS_H */

