#include "shell.h"

/**
 * specmds - Check for special commands, such as 'exit' and 'env'
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

	switch (buf[0])
	{
	case 'e':
		if (strncmp(buf, "exit", 4) == 0)
			return (1);

		if (strncmp(buf, "env", 3) == 0)
		{
			current_env(av); /* Print the current environment */
			return (1);
		}
		break;
	default:
		break;
	}

	return (0);
}
