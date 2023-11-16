#include "shell.h"

/**
 * specmds - Checks or special commands, such as 'exit' and 'env'
 *
 * @buf: The input buffer
 * @shel: Shell pointer (not used)
 * @av: Argument vector
 *
 * Return: 1 if a special command is found, 0 otherwise.
 */
int specmds(char *buf, char *shel, char *av[])
{
	(void)shel; /* Unused pointer */

	if (buf[0] == 'e')
	{
		int i;

		for (i = 0; buf[i] != '\0'; i++)
		{
			if (buf[i] != "exit"[i])
				break;
		}

		if (buf[i] == '\0' || buf[i] == ' ' || buf[i] == '\t')
		{
			/* Handling the exit command*/
			exit(0);
		}
	}

	if (buf[0] == 'v')
	{
		int i;

		for (i = 0; buf[i] != '\0'; i++)
		{
			if (buf[i] != "env"[i])
				break;
		}

		if (buf[i] == '\0' || buf[i] == ' ' || buf[i] == '\t')
		{
			/* Handling the env command */
			current_env(av);
			return (1);
		}
	}

	return (0);
}
